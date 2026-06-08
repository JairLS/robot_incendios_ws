#include <Wire.h>
#include <EnableInterrupt.h>

// ── Direcciones I2C (sin TCA, directo al bus) ────────────────
#define MPU_ADDR 0x68
#define MLX_ADDR 0x33

// ── RC ───────────────────────────────────────────────────────
const int CH1 = 11, CH2 = 4, CH3 = 12, CH4 = 5;
volatile unsigned long ch1_rise = 0, ch3_rise = 0;
volatile int ch1_val = 1500, ch3_val = 1500;

// FAILSAFE: marca de tiempo del ultimo pulso RC valido recibido
volatile unsigned long ultimo_pulso_rc = 0;
const unsigned long RC_TIMEOUT_MS = 150;   // si no hay senal en 150ms -> frenar

void isr_ch1() {
  if (digitalRead(CH1)) ch1_rise = micros();
  else { ch1_val = micros() - ch1_rise; ultimo_pulso_rc = millis(); }
}
void isr_ch3() {
  if (digitalRead(CH3)) ch3_rise = micros();
  else { ch3_val = micros() - ch3_rise; ultimo_pulso_rc = millis(); }
}

int mapearCanal(int raw) {
  if (raw < 500 || raw > 2500) raw = 1500;
  int valor = map(raw, 986, 1959, -100, 100);
  valor = constrain(valor, -100, 100);
  if (abs(valor) < 10) valor = 0;
  return valor;
}

// ── Motores ──────────────────────────────────────────────────
const int RPWM_IZQ = 10, LPWM_IZQ = 6;
const int RPWM_DER = 9, LPWM_DER = 8;

// ── Encoders ─────────────────────────────────────────────────
const int ENC_FL_A = 2,  ENC_FL_B = 22;
const int ENC_RL_A = 3,  ENC_RL_B = 23;
const int ENC_FR_A = 18, ENC_FR_B = 24;
const int ENC_RR_A = 19, ENC_RR_B = 25;

volatile long ticks_izq = 0, ticks_der = 0;

void contarFL() { }
void contarRL() { if (digitalRead(ENC_RL_B) == HIGH) ticks_izq++; else ticks_izq--; }
void contarFR() { }
void contarRR() { if (digitalRead(ENC_RR_B) == LOW)  ticks_der++; else ticks_der--; }

const float TICKS_POR_VUELTA = 491.0;
const float RADIO_RUEDA      = 0.0325;
const float DIST_POR_PULSO   = (2 * PI * RADIO_RUEDA) / TICKS_POR_VUELTA;
const float DIST_ENTRE_EJES  = 0.2814;

float x = 0, y = 0, theta = 0;
long ticks_izq_odo_prev = 0, ticks_der_odo_prev = 0;
unsigned long t_odo_ant = 0;

unsigned long tiempo_anterior = 0;
long ticks_izq_anterior = 0, ticks_der_anterior = 0;
float vel_real_izq = 0, vel_real_der = 0;
int ch1_filtrado = 0, ch3_filtrado = 0;

// ── IMU ──────────────────────────────────────────────────────
float bias_gx = 0, bias_gy = 0, bias_gz = 0;
float yaw_filtro = 0;
unsigned long t_imu_ant = 0;

// Umbral del deadband de gz para la INTEGRACION de yaw.
// Quieto, gz residual (post-bias) vive en ~0.0-0.4 deg/s (drift de bias).
// Girando, gz vive en ~15-40 deg/s. 1.0 separa limpio: mata el drift
// estatico sin tocar un giro real.
const float GZ_DEADBAND = 1.0f;

// ── MLX90640 ─────────────────────────────────────────────────
#define MLX_PIXELS  768
#define MLX_INTERVAL 250

unsigned long t_mlx_ant    = 0;
int  mlx_bloque_actual     = 0;
int  mlx_pixel_count       = 0;
bool mlx_enviando          = false;
int16_t mlx_buffer[MLX_PIXELS];

// ─────────────────────────────────────────────────────────────
// IMU: lectura, calibracion
// ─────────────────────────────────────────────────────────────
void leerIMU(float &ax, float &ay, float &az,
             float &gx, float &gy, float &gz) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14);
  int16_t raw_ax = Wire.read()<<8 | Wire.read();
  int16_t raw_ay = Wire.read()<<8 | Wire.read();
  int16_t raw_az = Wire.read()<<8 | Wire.read();
  Wire.read(); Wire.read();
  int16_t raw_gx = Wire.read()<<8 | Wire.read();
  int16_t raw_gy = Wire.read()<<8 | Wire.read();
  int16_t raw_gz = Wire.read()<<8 | Wire.read();
  ax = raw_ax / 8192.0f;  ay = raw_ay / 8192.0f;  az = raw_az / 8192.0f;
  gx = (raw_gx / 131.0f) - bias_gx;
  gy = (raw_gy / 131.0f) - bias_gy;
  gz = (raw_gz / 131.0f) - bias_gz;
  if (abs(gx) < 0.15f) gx = 0;
  if (abs(gy) < 0.15f) gy = 0;
  // gz NO se filtra aqui: se entrega y se imprime CRUDO (post-bias) para
  // poder diagnosticar el bias del arranque en el test de giro.
  // El deadband de gz se aplica solo a la integracion de yaw (ver loop).
}

bool calibrarIMU() {
  Serial.println("Calibrando IMU...");

  // Despertar el MPU6050 (sale de sleep)
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B); Wire.write(0x00);
  if (Wire.endTransmission() != 0) return false;
  delay(100);

  // Config accel ±4g (coincide con /8192.0)
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x1C); Wire.write(0x08);
  Wire.endTransmission();
  delay(10);

  // Config giro ±250°/s (coincide con /131.0)
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x1B); Wire.write(0x00);
  Wire.endTransmission();
  delay(10);

  double sx = 0, sy = 0, sz = 0;
  for (int i = 0; i < 2000; i++) {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x43);
    Wire.endTransmission(false);
    int n = Wire.requestFrom(MPU_ADDR, 6);
    if (n < 6) {                       // protección anti-cuelgue
      while (Wire.available()) Wire.read();
      return false;
    }
    int16_t gx = Wire.read()<<8 | Wire.read();
    int16_t gy = Wire.read()<<8 | Wire.read();
    int16_t gz = Wire.read()<<8 | Wire.read();
    sx += gx / 131.0; sy += gy / 131.0; sz += gz / 131.0;
    delay(3);
  }
  bias_gx = sx / 2000; bias_gy = sy / 2000; bias_gz = sz / 2000;
  Serial.println("IMU calibrado.");
  return true;
}

// ─────────────────────────────────────────────────────────────
// MLX90640: init, EEPROM, lectura no-bloqueante
// ─────────────────────────────────────────────────────────────
void mlxInit() {
  // La MLX90640 puede necesitar mas tiempo que el MPU para arrancar
  // en frio. Reintentamos hasta 10 veces con 500ms entre intentos.
  uint8_t err = 0xFF;
  for (int intento = 1; intento <= 10; intento++) {
    Wire.beginTransmission(MLX_ADDR);
    err = Wire.endTransmission();
    if (err == 0) {
      Serial.print("MLX90640 OK (intento ");
      Serial.print(intento);
      Serial.println(")");
      break;
    }
    Serial.print("MLX no responde aun (intento ");
    Serial.print(intento);
    Serial.print("/10, error: ");
    Serial.print(err);
    Serial.println("), esperando 500ms...");
    delay(500);
  }

  if (err != 0) {
    Serial.print("MLX no encontrado tras 10 intentos, error: ");
    Serial.println(err);
    return;
  }

  // Configuracion del refresh rate
  Wire.beginTransmission(MLX_ADDR);
  Wire.write(0x80); Wire.write(0x0D);
  Wire.write(0x19); Wire.write(0x01);
  Wire.endTransmission();
  delay(100);
}

void mlxMandarEEPROM() {
  Serial.print("EEPROM:");
  int wordCount = 0;
  for (int bloque = 0; bloque < 52; bloque++) {
    uint16_t addr = 0x2400 + bloque * 16;
    Wire.beginTransmission(MLX_ADDR);
    Wire.write(addr >> 8);
    Wire.write(addr & 0xFF);
    uint8_t err = Wire.endTransmission(false);
    if (err != 0) {
      for (int i = 0; i < 16; i++) {
        Serial.print(0); wordCount++;
        if (wordCount < 832) Serial.print(",");
      }
      continue;
    }
    Wire.requestFrom((uint8_t)MLX_ADDR, (uint8_t)32);
    for (int i = 0; i < 16; i++) {
      int16_t w = (int16_t)((Wire.read() << 8) | Wire.read());
      Serial.print(w); wordCount++;
      if (wordCount < 832) Serial.print(",");
    }
  }
  Serial.println();
}

void mlxTickNB() {
  unsigned long ahora = millis();
  if (!mlx_enviando) {
    if (ahora - t_mlx_ant >= MLX_INTERVAL) {
      t_mlx_ant         = ahora;
      mlx_bloque_actual = 0;
      mlx_pixel_count   = 0;
      mlx_enviando      = true;
    }
    return;
  }
  if (mlx_bloque_actual < 48) {
    uint16_t addr = 0x0400 + mlx_bloque_actual * 16;
    Wire.beginTransmission(MLX_ADDR);
    Wire.write(addr >> 8);
    Wire.write(addr & 0xFF);
    uint8_t err = Wire.endTransmission(false);
    if (err != 0) {
      for (int i = 0; i < 16; i++)
        mlx_buffer[mlx_pixel_count++] = -9999;
    } else {
      int recibidos = Wire.requestFrom((uint8_t)MLX_ADDR, (uint8_t)32);
      if (recibidos < 32) {
        while (Wire.available()) Wire.read();
        for (int i = 0; i < 16; i++)
          mlx_buffer[mlx_pixel_count++] = -9999;
      } else {
        for (int i = 0; i < 16; i++)
          mlx_buffer[mlx_pixel_count++] = (int16_t)((Wire.read() << 8) | Wire.read());
      }
    }
    mlx_bloque_actual++;
    if (mlx_bloque_actual >= 48) {
      Serial.print("T:");
      for (int i = 0; i < MLX_PIXELS; i++) {
        Serial.print(mlx_buffer[i]);
        if (i < MLX_PIXELS - 1) Serial.print(",");
      }
      Serial.println();
      mlx_enviando = false;
    }
  }
}

// ─────────────────────────────────────────────────────────────
// Motores
// ─────────────────────────────────────────────────────────────
void moverLado(int velocidad, int pinRPWM, int pinLPWM) {
  if (abs(velocidad) < 10) {
    analogWrite(pinRPWM, 0); analogWrite(pinLPWM, 0);
    return;
  }
  int pwm = map(abs(velocidad), 10, 100, 0, 255);
  pwm = constrain(pwm, 0, 255);
  if (velocidad > 0) { analogWrite(pinRPWM, pwm); analogWrite(pinLPWM, 0); }
  else               { analogWrite(pinRPWM, 0);   analogWrite(pinLPWM, pwm); }
}

// ─────────────────────────────────────────────────────────────
// SETUP
// ─────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(115200);
  delay(3000);

  pinMode(RPWM_IZQ, OUTPUT); pinMode(LPWM_IZQ, OUTPUT);
  pinMode(RPWM_DER, OUTPUT); pinMode(LPWM_DER, OUTPUT);
  analogWrite(RPWM_IZQ, 0); analogWrite(LPWM_IZQ, 0);
  analogWrite(RPWM_DER, 0); analogWrite(LPWM_DER, 0);

  // Bus I2C directo. Sin TCA, sin bit-bang, sin liberar bus.
  Wire.begin();
  Wire.setClock(100000);
  Wire.setWireTimeout(25000, true);
  delay(500);

  // Verificar que el MPU responde antes de calibrar
  Wire.beginTransmission(MPU_ADDR);
  if (Wire.endTransmission() != 0) {
    Serial.println("IMU_FALLO");
    while (true) delay(1000);
  }

  if (!calibrarIMU()) {
    Serial.println("IMU_FALLO");
    while (true) delay(1000);
  }

  mlxInit();

  Serial.println("LISTO_PARA_R");
  while (true) {
    if (Serial.available()) {
      char cmd = Serial.read();
      if (cmd == 'R') break;
    }
  }

  mlxMandarEEPROM();

  pinMode(CH1, INPUT); enableInterrupt(CH1, isr_ch1, CHANGE);
  pinMode(CH3, INPUT); enableInterrupt(CH3, isr_ch3, CHANGE);

  pinMode(ENC_FL_A, INPUT_PULLUP); pinMode(ENC_FL_B, INPUT_PULLUP);
  pinMode(ENC_RL_A, INPUT_PULLUP); pinMode(ENC_RL_B, INPUT_PULLUP);
  pinMode(ENC_FR_A, INPUT_PULLUP); pinMode(ENC_FR_B, INPUT_PULLUP);
  pinMode(ENC_RR_A, INPUT_PULLUP); pinMode(ENC_RR_B, INPUT_PULLUP);
  enableInterrupt(ENC_FL_A, contarFL, RISING);
  enableInterrupt(ENC_RL_A, contarRL, RISING);
  enableInterrupt(ENC_FR_A, contarFR, RISING);
  enableInterrupt(ENC_RR_A, contarRR, RISING);

  t_imu_ant = t_odo_ant = t_mlx_ant = tiempo_anterior = millis();
  Serial.println("=== ROBOT LISTO ===");
}

// ─────────────────────────────────────────────────────────────
// LOOP
// ─────────────────────────────────────────────────────────────
void loop() {
  unsigned long ahora = millis();

  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == 'E') mlxMandarEEPROM();
  }

  float ax, ay, az, gx, gy, gz;
  leerIMU(ax, ay, az, gx, gy, gz);   // gz viene CRUDO (post-bias, sin deadband)

  float dt_imu = (ahora - t_imu_ant) / 1000.0f;
  t_imu_ant = ahora;

  // ── Integracion de yaw ─────────────────────────────────────
  // Deadband SOLO para integrar (no afecta el gz que se imprime).
  // Integracion simple, SIN leak: ya no hay '*= 0.995f' jalando hacia 0,
  // porque eso borraria el giro real cuando se sube el peso del IMU.
  // El deadband (GZ_DEADBAND) es ahora el unico mecanismo anti-drift estatico.
  float gz_yaw = (fabs(gz) < GZ_DEADBAND) ? 0.0f : gz;
  yaw_filtro += gz_yaw * dt_imu;

  while (yaw_filtro >  180) yaw_filtro -= 360;
  while (yaw_filtro < -180) yaw_filtro += 360;

  int ch1 = mapearCanal(ch1_val);
  int ch3 = mapearCanal(ch3_val);
  ch1_filtrado = (ch1_filtrado + ch1 * 3) / 4;
  ch3_filtrado = (ch3_filtrado + ch3 * 3) / 4;
  if (abs(ch1_filtrado) < 10) ch1_filtrado = 0;
  if (abs(ch3_filtrado) < 10) ch3_filtrado = 0;

  // ── FAILSAFE: si no hay senal RC reciente, frenar ──────────
  noInterrupts();
  unsigned long t_rc = ultimo_pulso_rc;
  interrupts();

  if (millis() - t_rc > RC_TIMEOUT_MS) {
    // Sin senal RC -> motores a cero, ignora valores congelados
    ch1_filtrado = 0;
    ch3_filtrado = 0;
    moverLado(0, RPWM_IZQ, LPWM_IZQ);
    moverLado(0, RPWM_DER, LPWM_DER);
  } else {
    int vel_izq = constrain(-ch3_filtrado - ch1_filtrado, -100, 100);
    int vel_der = constrain(-ch3_filtrado + ch1_filtrado, -100, 100);
    moverLado(vel_izq, RPWM_IZQ, LPWM_IZQ);
    moverLado(vel_der, RPWM_DER, LPWM_DER);
  }

  if (ahora - tiempo_anterior >= 100) {
    float dt = (ahora - tiempo_anterior) / 1000.0f;
    tiempo_anterior = ahora;

    vel_real_izq = (ticks_izq - ticks_izq_anterior) / dt;
    vel_real_der = (ticks_der - ticks_der_anterior) / dt;
    ticks_izq_anterior = ticks_izq;
    ticks_der_anterior = ticks_der;

    noInterrupts();
    long d_izq = ticks_izq - ticks_izq_odo_prev;
    long d_der = ticks_der - ticks_der_odo_prev;
    ticks_izq_odo_prev = ticks_izq;
    ticks_der_odo_prev = ticks_der;
    interrupts();

    float dist_izq = d_izq * DIST_POR_PULSO;
    float dist_der = d_der * DIST_POR_PULSO;
    float V        = (dist_izq + dist_der) / 2.0f;
    float dTheta   = (dist_der - dist_izq) / DIST_ENTRE_EJES;
    float theta_enc = theta + dTheta;
    while (theta_enc >  PI) theta_enc -= 2 * PI;
    while (theta_enc < -PI) theta_enc += 2 * PI;
    float theta_imu = yaw_filtro * PI / 180.0f;

    // ── FUSION (wrap-safe) ─────────────────────────────────
    // Peso del IMU en 0.15 (antes 0.05). El giroscopio mide la rotacion
    // real del chasis y NO patina; los encoders patinan en los giros.
    //
    // CRITICO: NO mezclar como 0.85*theta_enc + 0.15*theta_imu. Eso se
    // ROMPE cerca de +/-180: promediar -179 con +179 da ~0 (basura), y en
    // un giro de 360 el theta cruza +/-180 -> theta da brincos a media
    // vuelta y deforma el SLAM. Se mezcla sobre la DIFERENCIA con wrap:
    // es identico a 0.85/0.15 cuando no hay cruce, pero correcto en el borde.
    // Si el giro aun se desvia, subir el 0.15f (probar 0.20). No pasar de
    // ~0.30 sin replantear: a mas peso de IMU, mas expuesto a un boot con bias malo.
    float diff = theta_imu - theta_enc;
    while (diff >  PI) diff -= 2 * PI;
    while (diff < -PI) diff += 2 * PI;
    theta = theta_enc + 0.15f * diff;
    while (theta >  PI) theta -= 2 * PI;
    while (theta < -PI) theta += 2 * PI;
    x += V * cos(theta);
    y += V * sin(theta);

    Serial.print("ENC:");
    Serial.print(ticks_izq); Serial.print(",");
    Serial.println(ticks_der);

    Serial.print("IMU:");
    Serial.print(ax, 3); Serial.print(",");
    Serial.print(ay, 3); Serial.print(",");
    Serial.print(az, 3); Serial.print(",");
    Serial.print(gx, 3); Serial.print(",");
    Serial.print(gy, 3); Serial.print(",");
    Serial.println(gz, 3);   // gz CRUDO: si quieto marca >1.0 -> bias malo en este boot

    Serial.print("ODO:");
    Serial.print(x, 3); Serial.print(",");
    Serial.print(y, 3); Serial.print(",");
    Serial.println(theta * 180.0f / PI, 1);
  }

  mlxTickNB();
}
