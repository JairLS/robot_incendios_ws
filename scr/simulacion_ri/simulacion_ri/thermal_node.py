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
        self.bus = smbus2.SMBus(1)
        self.get_logger().info("Thermal MLX90640 iniciada")
        self.timer = self.create_timer(0.5, self.timer_callback)

    def _read_register(self, reg, length):
        msg_w = smbus2.i2c_msg.write(MLX_ADDR, [(reg >> 8) & 0xFF, reg & 0xFF])
        msg_r = smbus2.i2c_msg.read(MLX_ADDR, length * 2)
        self.bus.i2c_rdwr(msg_w, msg_r)
        data = list(msg_r)
        words = []
        for i in range(0, len(data), 2):
            word = (data[i] << 8) | data[i+1]
            if word > 32767:
                word -= 65536
            words.append(word)
        return words

    def _get_frame(self):
        for _ in range(20):
            status = self._read_register(0x8000, 1)[0]
            if status & 0x0008:
                break
            time.sleep(0.01)
        self._read_register(0x8000, 1)
        return self._read_register(0x0400, 832)

    def timer_callback(self):
        try:
            raw = self._get_frame()
            frame_data = np.array(raw[:768], dtype=np.float32).reshape(24, 32)
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