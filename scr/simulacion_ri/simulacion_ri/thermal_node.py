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

class ThermalNode(Node):

    def __init__(self):
        super().__init__("thermal_node")
        qos = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1
        )
        self.publisher = self.create_publisher(Image, "/thermal/image_raw", qos)
        self.bus = smbus2.SMBus(0)
        self.get_logger().info("Thermal MLX90640 iniciada")
        self.timer = self.create_timer(0.5, self.timer_callback)

    def _read_word(self, reg):
        self.bus.write_i2c_block_data(MLX_ADDR, reg >> 8, [reg & 0xFF])
        time.sleep(0.005)
        data = self.bus.read_i2c_block_data(MLX_ADDR, 0, 2)
        word = (data[0] << 8) | data[1]
        if word > 32767:
            word -= 65536
        return word

    def _get_frame(self):
        # Espera datos listos
        for _ in range(50):
            self.bus.write_i2c_block_data(MLX_ADDR, 0x80, [0x00])
            time.sleep(0.02)
            data = self.bus.read_i2c_block_data(MLX_ADDR, 0, 2)
            status = (data[0] << 8) | data[1]
            if status & 0x0008:
                break
            time.sleep(0.05)

        # Lee frame
        raw = []
        for i in range(768):
            reg = 0x0400 + i
            self.bus.write_i2c_block_data(MLX_ADDR, reg >> 8, [reg & 0xFF])
            time.sleep(0.005)
            data = self.bus.read_i2c_block_data(MLX_ADDR, 0, 2)
            word = (data[0] << 8) | data[1]
            if word > 32767:
                word -= 65536
            raw.append(word)

        # Limpia el flag de datos listos
        self.bus.write_i2c_block_data(MLX_ADDR, 0x80, [0x30])
        time.sleep(0.01)

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