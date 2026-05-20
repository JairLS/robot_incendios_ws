import smbus2, numpy as np, time, math

BUS = 23
ADDR = 0x33

def read_words(reg, n):
    bus = smbus2.SMBus(BUS)
    msg_w = smbus2.i2c_msg.write(ADDR, [(reg>>8)&0xFF, reg&0xFF])
    msg_r = smbus2.i2c_msg.read(ADDR, n*2)
    bus.i2c_rdwr(msg_w, msg_r)
    data = list(msg_r)
    bus.close()
    words = []
    for i in range(0, n*2, 2):
        w = (data[i]<<8)|data[i+1]
        if w > 32767:
            w -= 65536
        words.append(w)
    return words

print('Leyendo EEPROM...')
ee = read_words(0x2400, 832)
time.sleep(1.0)

def ee_idx(addr):
    return addr - 0x2400

GAIN_cal = ee[ee_idx(0x2430)]
if GAIN_cal > 32767: GAIN_cal -= 65536

kv_ptat_ee = (ee[ee_idx(0x2432)] & 0xFC00) >> 10
if kv_ptat_ee > 31: kv_ptat_ee -= 64
Kv_PTAT = kv_ptat_ee / 4096.0

kt_ptat_ee = ee[ee_idx(0x2432)] & 0x03FF
if kt_ptat_ee > 511: kt_ptat_ee -= 1024
Kt_PTAT = kt_ptat_ee / 8.0

PTAT_25 = ee[ee_idx(0x2431)]
if PTAT_25 > 32767: PTAT_25 -= 65536

alpha_ptat_ee = (ee[ee_idx(0x2410)] & 0xF000) >> 12
Alpha_PTAT = alpha_ptat_ee / 4.0 + 8.0

kv_vdd_ee = (ee[ee_idx(0x2433)] & 0xFF00) >> 8
if kv_vdd_ee > 127: kv_vdd_ee -= 256
Kv_Vdd = kv_vdd_ee * 32

vdd25_ee = ee[ee_idx(0x2433)] & 0x00FF
Vdd_25 = (vdd25_ee - 256) * 32 - (1<<13)

Offset_avg = ee[ee_idx(0x2411)]
if Offset_avg > 32767: Offset_avg -= 65536

scale_occ_rem = ee[ee_idx(0x2410)] & 0x000F
scale_occ_col = (ee[ee_idx(0x2410)] & 0x00F0) >> 4
scale_occ_row = (ee[ee_idx(0x2410)] & 0x0F00) >> 8

occ_rows = []
for i in range(6):
    word = ee[ee_idx(0x2412) + i]
    for j in range(4):
        v = (word >> (j*4)) & 0xF
        if v > 7: v -= 16
        occ_rows.append(v)

occ_cols = []
for i in range(8):
    word = ee[ee_idx(0x2418) + i]
    for j in range(4):
        v = (word >> (j*4)) & 0xF
        if v > 7: v -= 16
        occ_cols.append(v)

pix_os_ref = np.zeros(768)
for i in range(768):
    row = i // 32
    col = i % 32
    pix_ee = ee[ee_idx(0x2440) + i]
    pix_offset = (pix_ee & 0xFC00) >> 10
    if pix_offset > 31: pix_offset -= 64
    pix_os_ref[i] = (Offset_avg +
                     occ_rows[row] * (1 << scale_occ_row) +
                     occ_cols[col] * (1 << scale_occ_col) +
                     pix_offset * (1 << scale_occ_rem))

alpha_ref = ee[ee_idx(0x2421)]
alpha_scale = ((ee[ee_idx(0x2420)] & 0xF000) >> 12) + 30
scale_acc_rem = ee[ee_idx(0x2420)] & 0x000F
scale_acc_col = (ee[ee_idx(0x2420)] & 0x00F0) >> 4
scale_acc_row = (ee[ee_idx(0x2420)] & 0x0F00) >> 8

acc_rows = []
for i in range(6):
    word = ee[ee_idx(0x2422) + i]
    for j in range(4):
        v = (word >> (j*4)) & 0xF
        if v > 7: v -= 16
        acc_rows.append(v)

acc_cols = []
for i in range(8):
    word = ee[ee_idx(0x2428) + i]
    for j in range(4):
        v = (word >> (j*4)) & 0xF
        if v > 7: v -= 16
        acc_cols.append(v)

alpha_pix = np.zeros(768)
for i in range(768):
    row = i // 32
    col = i % 32
    pix_ee = ee[ee_idx(0x2440) + i]
    a_pix = (pix_ee & 0x03F0) >> 4
    if a_pix > 31: a_pix -= 64
    alpha_pix[i] = (alpha_ref +
                    acc_rows[row] * (1 << scale_acc_row) +
                    acc_cols[col] * (1 << scale_acc_col) +
                    a_pix * (1 << scale_acc_rem)) / (1 << alpha_scale)

ksta_ee = (ee[ee_idx(0x243C)] & 0xFF00) >> 8
if ksta_ee > 127: ksta_ee -= 256
KsTa = ksta_ee / (1 << 13)

ksTo_scale = (ee[ee_idx(0x243F)] & 0x000F) + 8
ksTo2_ee = (ee[ee_idx(0x243D)] & 0xFF00) >> 8
if ksTo2_ee > 127: ksTo2_ee -= 256
KsTo2 = ksTo2_ee / (1 << ksTo_scale)

print('Coeficientes cargados. Leyendo temperatura...')

while True:
    try:
        ram = read_words(0x0400, 832)
        time.sleep(1.0)

        VDD_pix = ram[0x072A - 0x0400]
        V_PTAT  = ram[0x0720 - 0x0400]
        V_BE    = ram[0x0700 - 0x0400]
        GAIN_ram = ram[0x070A - 0x0400]

        if GAIN_ram == 0: continue

        Vdd = (VDD_pix - Vdd_25) / Kv_Vdd + 3.3
        V_PTAT_art = (V_PTAT / (V_PTAT * Alpha_PTAT + V_BE)) * (1 << 18)
        Ta = (V_PTAT_art / (1 + Kv_PTAT * (Vdd - 3.3)) - PTAT_25) / Kt_PTAT + 25

        if Ta < -40 or Ta > 85: continue

        K_gain = GAIN_cal / GAIN_ram
        pix_gain = np.array([ram[i] * K_gain for i in range(768)])
        pix_os = pix_gain - pix_os_ref * (1 + KsTa * (Ta - 25))

        Tr = Ta - 8
        TaK4 = (Ta + 273.15) ** 4
        TrK4 = (Tr + 273.15) ** 4
        Ta_r = TrK4 - (TrK4 - TaK4) / 1.0

        To = np.zeros(768)
        for i in range(768):
            if alpha_pix[i] == 0:
                To[i] = -273.15
                continue
            Sx = KsTo2 * (alpha_pix[i]**3 * pix_os[i] + alpha_pix[i]**4 * Ta_r) ** 0.25
            To[i] = ((pix_os[i] / (alpha_pix[i] * (1 - KsTo2 * 273.15) + Sx) + Ta_r) ** 0.25) - 273.15

        valid = To[(To > -40) & (To < 300)]
        if len(valid) == 0: continue

        print(f'Ta={Ta:.1f}°C | To Min={valid.min():.1f}°C Max={valid.max():.1f}°C Mean={valid.mean():.1f}°C')

    except KeyboardInterrupt:
        print('Detenido')
        break
    except Exception as e:
        time.sleep(0.5)
        continue
