#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
import numpy as np
import cv2
import smbus2
import time

MLX_ADDR = 0x33
TCA_ADDR = 0x70

class ThermalNode(Node):

    def __init__(self):
        super().__init__("thermal_node")
        qos = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1
        )
        self.publisher = self.create_publisher(Image, "/thermal/image_raw", qos)
        self.bus = smbus2.SMBus(1)
        self.bus.write_byte(TCA_ADDR, 0x01)  # Activa canal 0 del TCA9548A
        time.sleep(5.0)
        self.get_logger().info("Thermal MLX90640 iniciada")
        self.timer = self.create_timer(0.5, self.timer_callback)

    def _get_frame(self):
        self.bus.write_byte(TCA_ADDR, 0x01)  # Mantiene canal 0 activo

        for _ in range(50):
            msg_w = smbus2.i2c_msg.write(MLX_ADDR, [0x80, 0x00])
            msg_r = smbus2.i2c_msg.read(MLX_ADDR, 2)
            self.bus.i2c_rdwr(msg_w, msg_r)
            status = (list(msg_r)[0] << 8) | list(msg_r)[1]
            if status & 0x0008:
                break
            time.sleep(0.05)

        msg_w = smbus2.i2c_msg.write(MLX_ADDR, [0x04, 0x00])
        msg_r = smbus2.i2c_msg.read(MLX_ADDR, 1536)
        self.bus.i2c_rdwr(msg_w, msg_r)
        data = list(msg_r)
        raw = []
        for i in range(0, 1536, 2):
            word = (data[i] << 8) | data[i+1]
            if word > 32767:
                word -= 65536
            raw.append(word)

        msg_w = smbus2.i2c_msg.write(MLX_ADDR, [0x80, 0x00, 0x00, 0x30])
        self.bus.i2c_rdwr(msg_w)

        return raw

    def timer_callback(self):
        try:
            raw = self._get_frame()
            frame_data = np.array(raw, dtype=np.float32).reshape(24, 32)
            temp_min, temp_max = 15.0, 45.0
            normalized = np.clip((frame_data - temp_min) / (temp_max - temp_min), 0, 1)
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