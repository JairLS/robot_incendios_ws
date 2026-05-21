#!/usr/bin/env python3
import time
import threading
import math

import numpy as np
import cv2
import serial

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy

from sensor_msgs.msg import Image, Imu
from nav_msgs.msg import Odometry
from geometry_msgs.msg import TransformStamped, Quaternion
from tf2_ros import TransformBroadcaster

GRAVITY    = 9.80665
DEG_TO_RAD = math.pi / 180.0
T_MIN      = 15.0
T_MAX      = 45.0
OUT_W      = 320
OUT_H      = 240


def extract_calibration(ee):
    def ei(addr): return addr - 0x2400
    c = {}

    c['GAIN_cal'] = ee[ei(0x2430)]
    if c['GAIN_cal'] > 32767: c['GAIN_cal'] -= 65536

    kv_ptat_ee = (ee[ei(0x2432)] & 0xFC00) >> 10
    if kv_ptat_ee > 31: kv_ptat_ee -= 64
    c['Kv_PTAT'] = kv_ptat_ee / 4096.0

    kt_ptat_ee = ee[ei(0x2432)] & 0x03FF
    if kt_ptat_ee > 511: kt_ptat_ee -= 1024
    c['Kt_PTAT'] = kt_ptat_ee / 8.0

    c['PTAT_25'] = ee[ei(0x2431)]
    if c['PTAT_25'] > 32767: c['PTAT_25'] -= 65536

    alpha_ptat_ee = (ee[ei(0x2410)] & 0xF000) >> 12
    c['Alpha_PTAT'] = alpha_ptat_ee / 4.0 + 8.0

    kv_vdd_ee = (ee[ei(0x2433)] & 0xFF00) >> 8
    if kv_vdd_ee > 127: kv_vdd_ee -= 256
    c['Kv_Vdd'] = kv_vdd_ee * 32

    vdd25_ee = ee[ei(0x2433)] & 0x00FF
    c['Vdd_25'] = (vdd25_ee - 256) * 32 - (1 << 13)

    Offset_avg = ee[ei(0x2411)]
    if Offset_avg > 32767: Offset_avg -= 65536

    scale_occ_rem = ee[ei(0x2410)] & 0x000F
    scale_occ_col = (ee[ei(0x2410)] & 0x00F0) >> 4
    scale_occ_row = (ee[ei(0x2410)] & 0x0F00) >> 8

    occ_rows = []
    for i in range(6):
        word = ee[ei(0x2412) + i]
        for j in range(4):
            v = (word >> (j * 4)) & 0xF
            if v > 7: v -= 16
            occ_rows.append(v)

    occ_cols = []
    for i in range(8):
        word = ee[ei(0x2418) + i]
        for j in range(4):
            v = (word >> (j * 4)) & 0xF
            if v > 7: v -= 16
            occ_cols.append(v)

    pix_os_ref = np.zeros(768)
    for i in range(768):
        row = i // 32
        col = i % 32
        pix_ee = ee[ei(0x2440) + i]
        pix_offset = (pix_ee & 0xFC00) >> 10
        if pix_offset > 31: pix_offset -= 64
        pix_os_ref[i] = (Offset_avg +
                         occ_rows[row] * (1 << scale_occ_row) +
                         occ_cols[col] * (1 << scale_occ_col) +
                         pix_offset * (1 << scale_occ_rem))
    c['pix_os_ref'] = pix_os_ref

    alpha_ref = ee[ei(0x2421)]
    alpha_scale = ((ee[ei(0x2420)] & 0xF000) >> 12) + 30
    scale_acc_rem = ee[ei(0x2420)] & 0x000F
    scale_acc_col = (ee[ei(0x2420)] & 0x00F0) >> 4
    scale_acc_row = (ee[ei(0x2420)] & 0x0F00) >> 8

    acc_rows = []
    for i in range(6):
        word = ee[ei(0x2422) + i]
        for j in range(4):
            v = (word >> (j * 4)) & 0xF
            if v > 7: v -= 16
            acc_rows.append(v)

    acc_cols = []
    for i in range(8):
        word = ee[ei(0x2428) + i]
        for j in range(4):
            v = (word >> (j * 4)) & 0xF
            if v > 7: v -= 16
            acc_cols.append(v)

    alpha_pix = np.zeros(768)
    for i in range(768):
        row = i // 32
        col = i % 32
        pix_ee = ee[ei(0x2440) + i]
        a_pix = (pix_ee & 0x03F0) >> 4
        if a_pix > 31: a_pix -= 64
        alpha_pix[i] = (alpha_ref +
                        acc_rows[row] * (1 << scale_acc_row) +
                        acc_cols[col] * (1 << scale_acc_col) +
                        a_pix * (1 << scale_acc_rem)) / (1 << alpha_scale)
    c['alpha_pix'] = alpha_pix

    ksta_ee = (ee[ei(0x243C)] & 0xFF00) >> 8
    if ksta_ee > 127: ksta_ee -= 256
    c['KsTa'] = ksta_ee / (1 << 13)

    ksTo_scale = (ee[ei(0x243F)] & 0x000F) + 8
    ksTo2_ee = (ee[ei(0x243D)] & 0xFF00) >> 8
    if ksTo2_ee > 127: ksTo2_ee -= 256
    c['KsTo2'] = ksTo2_ee / (1 << ksTo_scale)

    return c


def raw_to_celsius(raw, cal):
    Ta = 25.0
    pix_os = raw - cal['pix_os_ref'] * (1 + cal['KsTa'] * (Ta - 25))

    Tr   = Ta - 8
    TaK4 = (Ta + 273.15) ** 4
    TrK4 = (Tr + 273.15) ** 4
    Ta_r = TrK4 - (TrK4 - TaK4)

    alpha = np.where(cal['alpha_pix'] == 0, 1e-10, cal['alpha_pix'])

    inner = alpha ** 3 * pix_os + alpha ** 4 * Ta_r
    inner = np.where(inner < 0, 0, inner)

    Sx = cal['KsTo2'] * inner ** 0.25

    denom = alpha * (1 - cal['KsTo2'] * 273.15) + Sx
    denom = np.where(np.abs(denom) < 1e-10, 1e-10, denom)

    To_4 = pix_os / denom + Ta_r
    To_4 = np.where(To_4 < 0, 0, To_4)

    To = To_4 ** 0.25 - 273.15
    return To.reshape(24, 32)


def temps_to_image(temps):
    temps_clamped = np.clip(temps, T_MIN, T_MAX)
    normalized = (temps_clamped - T_MIN) / (T_MAX - T_MIN)
    gray8   = (normalized * 255).astype(np.uint8)
    colored = cv2.applyColorMap(gray8, cv2.COLORMAP_INFERNO)
    colored = cv2.resize(colored, (OUT_W, OUT_H), interpolation=cv2.INTER_CUBIC)
    colored = cv2.flip(colored, 1)

    # Hotspot usando temps sin clamp para encontrar el pixel más caliente real
    hot_idx          = np.unravel_index(np.argmax(temps), temps.shape)
    hot_row, hot_col = hot_idx
    scale_x = OUT_W / 32
    scale_y = OUT_H / 24
    cx = int((32 - 1 - hot_col) * scale_x + scale_x / 2)
    cy = int(hot_row * scale_y + scale_y / 2)
    bw = int(scale_x * 3)
    bh = int(scale_y * 3)
    cv2.rectangle(colored, (cx - bw, cy - bh), (cx + bw, cy + bh), (0, 0, 255), 2)
    cv2.putText(colored, f"{temps.max():.1f}C",
                (cx - bw, cy - bh - 5),
                cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
    cv2.putText(colored, f"Mean: {temps.mean():.1f}C", (5, 20),
                cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)
    return colored


def euler_to_quaternion(yaw):
    q = Quaternion()
    q.w = math.cos(yaw / 2.0)
    q.x = 0.0
    q.y = 0.0
    q.z = math.sin(yaw / 2.0)
    return q


class ArduinoNode(Node):

    def __init__(self):
        super().__init__('arduino_node')

        qos = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1
        )

        self.pub_thermal = self.create_publisher(Image,    '/thermal/image_raw', qos)
        self.pub_odom    = self.create_publisher(Odometry, '/odom',              10)
        self.pub_imu     = self.create_publisher(Imu,      '/imu',               10)
        self.tf_br       = TransformBroadcaster(self)

        self.cal           = None
        self._thermal_raw  = None
        self._thermal_lock = threading.Lock()
        self._odom_count   = 0
        self._imu_count    = 0

        self.get_logger().info('Esperando reset del Arduino (4s)...')
        time.sleep(4.0)
        try:
            self.ser = serial.Serial('/dev/arduino', 115200, timeout=1.0)
            self.ser.flushInput()
            self.get_logger().info('Serial /dev/arduino abierto OK')
        except Exception as e:
            self.get_logger().error(f'No se pudo abrir /dev/arduino: {e}')
            self.ser = None

        self._running = True
        self._thread  = threading.Thread(target=self._serial_reader, daemon=True)
        self._thread.start()

        self.create_timer(0.5,  self._publish_thermal)
        self.create_timer(15.0, self._request_eeprom_if_needed)
        self.create_timer(5.0,  self._log_status)
        self.get_logger().info('arduino_node listo — esperando EEPROM del Arduino...')

    def _log_status(self):
        self.get_logger().info(
            f'Status — IMU: {self._imu_count} msgs | ODO: {self._odom_count} msgs | '
            f'EEPROM: {"OK" if self.cal else "pendiente"}'
        )
        self._imu_count  = 0
        self._odom_count = 0

    def _request_eeprom_if_needed(self):
        if self.cal is None and self.ser and self.ser.is_open:
            self.get_logger().info('Re-solicitando EEPROM al Arduino...')
            try:
                self.ser.write(b'E')
            except Exception as e:
                self.get_logger().warn(f'Error solicitando EEPROM: {e}')

    def _handle_eeprom(self, payload):
        try:
            words = [int(x) for x in payload.split(',') if x]
        except ValueError:
            self.get_logger().warn('EEPROM: error parseando')
            return
        if len(words) != 832:
            self.get_logger().warn(f'EEPROM: esperaba 832, recibí {len(words)}')
            return
        try:
            self.cal = extract_calibration(words)
            self.get_logger().info('Calibración EEPROM del Arduino OK')
        except Exception as e:
            self.get_logger().error(f'Error calibración: {e}')

    def _serial_reader(self):
        while self._running:
            if self.ser is None:
                time.sleep(0.1)
                continue
            try:
                line = self.ser.readline().decode('ascii', errors='ignore').strip()
            except Exception:
                time.sleep(0.05)
                continue
            if not line:
                continue

            if line.startswith('EEPROM:'):
                self._handle_eeprom(line[7:])
            elif line.startswith('IMU:'):
                self._handle_imu(line[4:])
            elif line.startswith('ODO:'):
                self._handle_odom(line[4:])
            elif line.startswith('T:'):
                self._handle_thermal(line[2:])

    def _handle_imu(self, payload):
        try:
            parts = [float(x) for x in payload.split(',')]
            if len(parts) < 6:
                return
            ax_g, ay_g, az_g, gx_ds, gy_ds, gz_ds = parts[:6]
        except ValueError:
            return

        msg = Imu()
        msg.header.stamp    = self.get_clock().now().to_msg()
        msg.header.frame_id = 'imu_link'
        msg.linear_acceleration.x = ax_g * GRAVITY
        msg.linear_acceleration.y = ay_g * GRAVITY
        msg.linear_acceleration.z = az_g * GRAVITY
        msg.angular_velocity.x = gx_ds * DEG_TO_RAD
        msg.angular_velocity.y = gy_ds * DEG_TO_RAD
        msg.angular_velocity.z = gz_ds * DEG_TO_RAD
        msg.orientation_covariance[0]         = -1.0
        msg.angular_velocity_covariance[0]    = 1e-6
        msg.linear_acceleration_covariance[0] = 1e-6
        self.pub_imu.publish(msg)
        self._imu_count += 1

    def _handle_odom(self, payload):
        try:
            parts = [float(x) for x in payload.split(',')]
            if len(parts) < 3:
                return
            x, y, theta_deg = parts[:3]
        except ValueError:
            return

        theta = theta_deg * DEG_TO_RAD
        q     = euler_to_quaternion(theta)
        now   = self.get_clock().now().to_msg()

        odom = Odometry()
        odom.header.stamp    = now
        odom.header.frame_id = 'odom'
        odom.child_frame_id  = 'base_link'
        odom.pose.pose.position.x  = x
        odom.pose.pose.position.y  = y
        odom.pose.pose.position.z  = 0.0
        odom.pose.pose.orientation = q
        odom.pose.covariance[0]  = 1e-3
        odom.pose.covariance[7]  = 1e-3
        odom.pose.covariance[35] = 1e-3
        self.pub_odom.publish(odom)
        self._odom_count += 1

        tf = TransformStamped()
        tf.header.stamp            = now
        tf.header.frame_id         = 'odom'
        tf.child_frame_id          = 'base_link'
        tf.transform.translation.x = x
        tf.transform.translation.y = y
        tf.transform.translation.z = 0.0
        tf.transform.rotation      = q
        self.tf_br.sendTransform(tf)

    def _handle_thermal(self, payload):
        try:
            values = [int(x) for x in payload.split(',') if x]
        except ValueError:
            return

        if len(values) != 768:
            return

        arr = np.array(values, dtype=np.float32)
        mask = (arr == -9999) | (arr > 3000) | (arr < -3000)
        if np.all(mask):
            return
        arr[mask] = float(np.mean(arr[~mask]))

        with self._thermal_lock:
            self._thermal_raw = arr

    def _publish_thermal(self):
        with self._thermal_lock:
            if self._thermal_raw is None:
                return
            raw = self._thermal_raw.copy()

        if self.cal is None:
            return

        try:
            temps = raw_to_celsius(raw, self.cal)
        except Exception as e:
            self.get_logger().warn(f'Error conversión térmica: {e}')
            return

        # Filtra píxeles con temperaturas físicamente imposibles
        temps = np.where((temps < -40) | (temps > 300), np.nan, temps)
        if np.all(np.isnan(temps)):
            return
        mean_val = float(np.nanmean(temps))
        temps = np.where(np.isnan(temps), mean_val, temps)

        img_bgr = temps_to_image(temps)

        msg = Image()
        msg.header.stamp    = self.get_clock().now().to_msg()
        msg.header.frame_id = 'thermal'
        msg.height          = OUT_H
        msg.width           = OUT_W
        msg.encoding        = 'bgr8'
        msg.is_bigendian    = False
        msg.step            = OUT_W * 3
        msg.data            = img_bgr.tobytes()
        self.pub_thermal.publish(msg)

        self.get_logger().info(
            f'Thermal Min={np.nanmin(temps):.1f} Max={np.nanmax(temps):.1f} Mean={mean_val:.1f}C',
            throttle_duration_sec=2.0
        )

    def destroy_node(self):
        self._running = False
        if self.ser and self.ser.is_open:
            self.ser.close()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = ArduinoNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()