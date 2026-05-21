#include <Wire.h>
#include <EnableInterrupt.h>

// ── RC ──────────────────────────────────────────────
const int CH1 = 11, CH2 = 4, CH3 = 12, CH4 = 5;

volatile unsigned long ch1_rise = 0, ch3_rise = 0;
volatile int ch1_val = 1500, ch3_val = 1500;

void isr_ch1() {
  if (digitalRead(CH1)) ch1_rise = micros();
  else ch1_val = micros() - ch1_rise;
}
void isr_ch3() {
  if (digitalRead(CH3)) ch3_rise = micros();
  else ch3_val = micros() - ch3_rise;
}

int mapearCanal(int raw) {
  if (raw < 500 || raw > 2500) raw = 1500;
  int valor = map(raw, 986, 1959, -100, 100);
  valor = constrain(valor, -100, 100);
  if (abs(valor) < 10) valor = 0;
  return valor;
}

// ── Motores ─────────────────────────────────────────
const int RPWM_IZQ = 7, LPWM_IZQ = 6;
const int RPWM_DER = 9, LPWM_DER = 8;

// ── Encoders ────────────────────────────────────────
const int ENC_FL_A = 2,  ENC_FL_B = 22;
const int ENC_RL_A = 3,  ENC_RL_B = 23;
const int ENC_FR_A = 18, ENC_FR_B = 24;
const int ENC_RR_A = 19, ENC_RR_B = 25;

volatile long ticks_izq = 0, ticks_der = 0;

void contarFL() { }
void contarRL() { if (digitalRead(ENC_RL_B) == HIGH) ticks_izq++; else ticks_izq--; }
void contarFR() { }
void contarRR() { if (digitalRead(ENC_RR_B) == LOW)  ticks_der++; else ticks_der--; }

// ── Parámetros físicos ──────────────────────────────
const float TICKS_POR_VUELTA = 491.0;
const float RADIO_RUEDA      = 0.0325;
const float DIST_POR_PULSO   = (2 * PI * RADIO_RUEDA) / TICKS_POR_VUELTA;
const float DIST_ENTRE_EJES  = 0.2814;

// ── Odometría ───────────────────────────────────────
float x = 0, y = 0, theta = 0;
long ticks_izq_odo_prev = 0, ticks_der_odo_prev = 0;
unsigned long t_odo_ant = 0;

// ── Velocidad ───────────────────────────────────────
unsigned long tiempo_anterior = 0;
long ticks_izq_anterior = 0, ticks_der_anterior = 0;
float vel_real_izq = 0, vel_real_der = 0;
int ch1_filtrado = 0, ch3_filtrado = 0;

// ── IMU ─────────────────────────────────────────────
#define MPU_ADDR 0x68
float bias_gx = 0, bias_gy = 0, bias_gz = 0;
float yaw_filtro = 0;
unsigned long t_imu_ant = 0;

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
  if (abs(gz) < 0.15f) gz = 0;
}

void calibrarIMU() {
  Serial.println("Calibrando IMU...");
  double sx = 0, sy = 0, sz = 0;
  for (int i = 0; i < 2000; i++) {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x43);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_ADDR, 6);
    int16_t gx = Wire.read()<<8 | Wire.read();
    int16_t gy = Wire.read()<<8 | Wire.read();
    int16_t gz = Wire.read()<<8 | Wire.read();
    sx += gx / 131.0; sy += gy / 131.0; sz += gz / 131.0;
    delay(3);
  }
  bias_gx = sx / 2000; bias_gy = sy / 2000; bias_gz = sz / 2000;
  Serial.println("IMU calibrado.");
}

// ── MLX90640 ────────────────────────────────────────
#define MLX_ADDR    0x33
#define MLX_PIXELS  768
unsigned long t_mlx_ant = 0;
#define MLX_INTERVAL 250

void mlxInit() {
  Wire.beginTransmission(MLX_ADDR);
  uint8_t err = Wire.endTransmission();
  if (err != 0) {
    Serial.print("MLX no encontrado, error: ");
    Serial.println(err);
  } else {
    Serial.println("MLX90640 OK");
  }
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
        Serial.print(0);
        wordCount++;
        if (wordCount < 832) Serial.print(",");
      }
      continue;
    }
    Wire.requestFrom((uint8_t)MLX_ADDR, (uint8_t)32);
    for (int i = 0; i < 16; i++) {
      int16_t w = (int16_t)((Wire.read() << 8) | Wire.read());
      Serial.print(w);
      wordCount++;
      if (wordCount < 832) Serial.print(",");
    }
  }
  Serial.println();
}

void mlxLeerYMandar() {
  Serial.print("T:");
  int pixelCount = 0;

  for (int bloque = 0; bloque < 48; bloque++) {
    uint16_t addr = 0x0400 + bloque * 16;
    Wire.beginTransmission(MLX_ADDR);
    Wire.write(addr >> 8);
    Wire.write(addr & 0xFF);
    uint8_t err = Wire.endTransmission(false);

    if (err != 0) {
      for (int i = 0; i < 16; i++) {
        Serial.print(-9999);
        pixelCount++;
        if (pixelCount < MLX_PIXELS) Serial.print(",");
      }
      continue;
    }

    int recibidos = Wire.requestFrom((uint8_t)MLX_ADDR, (uint8_t)32);
    if (recibidos < 32) {
      while (Wire.available()) Wire.read();
      for (int i = 0; i < 16; i++) {
        Serial.print(-9999);
        pixelCount++;
        if (pixelCount < MLX_PIXELS) Serial.print(",");
      }
      continue;
    }

    for (int i = 0; i < 16; i++) {
      int16_t raw = (int16_t)((Wire.read() << 8) | Wire.read());
      Serial.print(raw);
      pixelCount++;
      if (pixelCount < MLX_PIXELS) Serial.print(",");
    }
  }
  Serial.println();
}

// ── Motores ─────────────────────────────────────────
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

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000);
  delay(500);

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B); Wire.write(0x00);
  Wire.endTransmission(); delay(100);
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x1B); Wire.write(0x00);
  Wire.endTransmission();
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x1C); Wire.write(0x08);
  Wire.endTransmission();
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x1A); Wire.write(0x06);
  Wire.endTransmission();
  delay(200);
  calibrarIMU();

  mlxInit();
  mlxMandarEEPROM();

  pinMode(CH1, INPUT); enableInterrupt(CH1, isr_ch1, CHANGE);
  pinMode(CH3, INPUT); enableInterrupt(CH3, isr_ch3, CHANGE);

  pinMode(RPWM_IZQ, OUTPUT); pinMode(LPWM_IZQ, OUTPUT);
  pinMode(RPWM_DER, OUTPUT); pinMode(LPWM_DER, OUTPUT);

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

void loop() {
  // Comando por Serial
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == 'E') {
      mlxMandarEEPROM();
    }
  }

  unsigned long ahora = millis();

  float ax, ay, az, gx, gy, gz;
  leerIMU(ax, ay, az, gx, gy, gz);

  float dt_imu = (ahora - t_imu_ant) / 1000.0f;
  t_imu_ant = ahora;
  if (abs(gz) < 0.3f) {
    yaw_filtro = 0.98f * (yaw_filtro + gz * dt_imu) + 0.02f * yaw_filtro;
    yaw_filtro *= 0.995f;
  } else {
    yaw_filtro += gz * dt_imu;
  }
  while (yaw_filtro >  180) yaw_filtro -= 360;
  while (yaw_filtro < -180) yaw_filtro += 360;

  int ch1 = mapearCanal(ch1_val);
  int ch3 = mapearCanal(ch3_val);
  ch1_filtrado = (ch1_filtrado + ch1 * 3) / 4;
  ch3_filtrado = (ch3_filtrado + ch3 * 3) / 4;
  if (abs(ch1_filtrado) < 10) ch1_filtrado = 0;
  if (abs(ch3_filtrado) < 10) ch3_filtrado = 0;

  int vel_izq = constrain(-ch3_filtrado - ch1_filtrado, -100, 100);
  int vel_der = constrain(-ch3_filtrado + ch1_filtrado, -100, 100);
  moverLado(vel_izq, RPWM_IZQ, LPWM_IZQ);
  moverLado(vel_der, RPWM_DER, LPWM_DER);

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
    float theta_imu = yaw_filtro * PI / 180.0f;
    theta = 0.95f * theta_enc + 0.05f * theta_imu;
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
    Serial.println(gz, 3);

    Serial.print("ODO:");
    Serial.print(x, 3); Serial.print(",");
    Serial.print(y, 3); Serial.print(",");
    Serial.println(theta * 180.0f / PI, 1);
  }

  if (ahora - t_mlx_ant >= MLX_INTERVAL) {
    t_mlx_ant = ahora;
    mlxLeerYMandar();
  }
}