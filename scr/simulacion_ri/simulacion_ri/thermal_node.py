#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
import numpy as np
import cv2
import smbus2
import time
import math

MLX_ADDR = 0x33
BUS_NUM = 23

class ThermalNode(Node):

    def __init__(self):
        super().__init__("thermal_node")
        qos = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1
        )
        self.publisher = self.create_publisher(Image, "/thermal/image_raw", qos)
        self.get_logger().info("Esperando que cámara NoIR inicialice...")
        time.sleep(8.0)
        self.get_logger().info("Leyendo EEPROM del MLX90640...")
        self._load_calibration()
        self.get_logger().info("Thermal MLX90640 iniciada")
        self.timer = self.create_timer(2.0, self.timer_callback)

    def _read_words(self, reg, n):
        bus = smbus2.SMBus(BUS_NUM)
        msg_w = smbus2.i2c_msg.write(MLX_ADDR, [(reg>>8)&0xFF, reg&0xFF])
        msg_r = smbus2.i2c_msg.read(MLX_ADDR, n*2)
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

    def _load_calibration(self):
        ee = None
        while ee is None:
            try:
                ee = self._read_words(0x2400, 832)
            except Exception:
                self.get_logger().warn("Reintentando leer EEPROM...")
                time.sleep(2.0)
        time.sleep(1.0)

        def ei(addr): return addr - 0x2400

        self.GAIN_cal = ee[ei(0x2430)]
        if self.GAIN_cal > 32767: self.GAIN_cal -= 65536

        kv_ptat_ee = (ee[ei(0x2432)] & 0xFC00) >> 10
        if kv_ptat_ee > 31: kv_ptat_ee -= 64
        self.Kv_PTAT = kv_ptat_ee / 4096.0

        kt_ptat_ee = ee[ei(0x2432)] & 0x03FF
        if kt_ptat_ee > 511: kt_ptat_ee -= 1024
        self.Kt_PTAT = kt_ptat_ee / 8.0

        self.PTAT_25 = ee[ei(0x2431)]
        if self.PTAT_25 > 32767: self.PTAT_25 -= 65536

        alpha_ptat_ee = (ee[ei(0x2410)] & 0xF000) >> 12
        self.Alpha_PTAT = alpha_ptat_ee / 4.0 + 8.0

        kv_vdd_ee = (ee[ei(0x2433)] & 0xFF00) >> 8
        if kv_vdd_ee > 127: kv_vdd_ee -= 256
        self.Kv_Vdd = kv_vdd_ee * 32

        vdd25_ee = ee[ei(0x2433)] & 0x00FF
        self.Vdd_25 = (vdd25_ee - 256) * 32 - (1<<13)

        Offset_avg = ee[ei(0x2411)]
        if Offset_avg > 32767: Offset_avg -= 65536

        scale_occ_rem = ee[ei(0x2410)] & 0x000F
        scale_occ_col = (ee[ei(0x2410)] & 0x00F0) >> 4
        scale_occ_row = (ee[ei(0x2410)] & 0x0F00) >> 8

        occ_rows = []
        for i in range(6):
            word = ee[ei(0x2412) + i]
            for j in range(4):
                v = (word >> (j*4)) & 0xF
                if v > 7: v -= 16
                occ_rows.append(v)

        occ_cols = []
        for i in range(8):
            word = ee[ei(0x2418) + i]
            for j in range(4):
                v = (word >> (j*4)) & 0xF
                if v > 7: v -= 16
                occ_cols.append(v)

        self.pix_os_ref = np.zeros(768)
        for i in range(768):
            row = i // 32
            col = i % 32
            pix_ee = ee[ei(0x2440) + i]
            pix_offset = (pix_ee & 0xFC00) >> 10
            if pix_offset > 31: pix_offset -= 64
            self.pix_os_ref[i] = (Offset_avg +
                                   occ_rows[row] * (1 << scale_occ_row) +
                                   occ_cols[col] * (1 << scale_occ_col) +
                                   pix_offset * (1 << scale_occ_rem))

        alpha_ref = ee[ei(0x2421)]
        alpha_scale = ((ee[ei(0x2420)] & 0xF000) >> 12) + 30
        scale_acc_rem = ee[ei(0x2420)] & 0x000F
        scale_acc_col = (ee[ei(0x2420)] & 0x00F0) >> 4
        scale_acc_row = (ee[ei(0x2420)] & 0x0F00) >> 8

        acc_rows = []
        for i in range(6):
            word = ee[ei(0x2422) + i]
            for j in range(4):
                v = (word >> (j*4)) & 0xF
                if v > 7: v -= 16
                acc_rows.append(v)

        acc_cols = []
        for i in range(8):
            word = ee[ei(0x2428) + i]
            for j in range(4):
                v = (word >> (j*4)) & 0xF
                if v > 7: v -= 16
                acc_cols.append(v)

        self.alpha_pix = np.zeros(768)
        for i in range(768):
            row = i // 32
            col = i % 32
            pix_ee = ee[ei(0x2440) + i]
            a_pix = (pix_ee & 0x03F0) >> 4
            if a_pix > 31: a_pix -= 64
            self.alpha_pix[i] = (alpha_ref +
                                  acc_rows[row] * (1 << scale_acc_row) +
                                  acc_cols[col] * (1 << scale_acc_col) +
                                  a_pix * (1 << scale_acc_rem)) / (1 << alpha_scale)

        ksta_ee = (ee[ei(0x243C)] & 0xFF00) >> 8
        if ksta_ee > 127: ksta_ee -= 256
        self.KsTa = ksta_ee / (1 << 13)

        ksTo_scale = (ee[ei(0x243F)] & 0x000F) + 8
        ksTo2_ee = (ee[ei(0x243D)] & 0xFF00) >> 8
        if ksTo2_ee > 127: ksTo2_ee -= 256
        self.KsTo2 = ksTo2_ee / (1 << ksTo_scale)

    def _get_temperatures(self):
        ram = self._read_words(0x0400, 832)

        VDD_pix  = ram[0x072A - 0x0400]
        V_PTAT   = ram[0x0720 - 0x0400]
        V_BE     = ram[0x0700 - 0x0400]
        GAIN_ram = ram[0x070A - 0x0400]

        if GAIN_ram == 0:
            return None

        Vdd = (VDD_pix - self.Vdd_25) / self.Kv_Vdd + 3.3
        V_PTAT_art = (V_PTAT / (V_PTAT * self.Alpha_PTAT + V_BE)) * (1 << 18)
        Ta = (V_PTAT_art / (1 + self.Kv_PTAT * (Vdd - 3.3)) - self.PTAT_25) / self.Kt_PTAT + 25

        if Ta < -40 or Ta > 85:
            return None

        K_gain = self.GAIN_cal / GAIN_ram
        pix_gain = np.array([ram[i] * K_gain for i in range(768)])
        pix_os = pix_gain - self.pix_os_ref * (1 + self.KsTa * (Ta - 25))

        Tr = Ta - 8
        TaK4 = (Ta + 273.15) ** 4
        TrK4 = (Tr + 273.15) ** 4
        Ta_r = TrK4 - (TrK4 - TaK4)

        To = np.zeros(768)
        for i in range(768):
            if self.alpha_pix[i] == 0:
                To[i] = Ta
                continue
            Sx = self.KsTo2 * (self.alpha_pix[i]**3 * pix_os[i] + self.alpha_pix[i]**4 * Ta_r) ** 0.25
            To[i] = ((pix_os[i] / (self.alpha_pix[i] * (1 - self.KsTo2 * 273.15) + Sx) + Ta_r) ** 0.25) - 273.15

        return To.reshape(24, 32)

    def timer_callback(self):
        try:
            temps = self._get_temperatures()
            if temps is None:
                return

            temp_min, temp_max = 15.0, 45.0
            normalized = np.clip((temps - temp_min) / (temp_max - temp_min), 0, 1)
            img = (normalized * 255).astype(np.uint8)
            colored = cv2.applyColorMap(img, cv2.COLORMAP_INFERNO)
            colored = cv2.resize(colored, (320, 240))

            msg = Image()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = "thermal"
            msg.height = 240
            msg.width = 320
            msg.encoding = "bgr8"
            msg.step = 320 * 3
            msg.data = colored.tobytes()
            self.publisher.publish(msg)

            self.get_logger().info(
                f"To Min={temps.min():.1f}°C Max={temps.max():.1f}°C Mean={temps.mean():.1f}°C"
            )
        except Exception as e:
            self.get_logger().error(f"Error: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = ThermalNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()