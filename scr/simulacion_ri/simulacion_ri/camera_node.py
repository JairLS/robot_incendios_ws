#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
import time
import cv2
from picamera2 import Picamera2

class CameraNode(Node):

    def __init__(self):
        super().__init__("camera_node")
        self.publisher = self.create_publisher(CompressedImage, "/image_raw/compressed", 10)
        self.cam = Picamera2()
        config = self.cam.create_video_configuration(
            main={"size": (640, 480), "format": "RGB888"},
            buffer_count=2
        )
        self.cam.configure(config)
        self.cam.start()
        time.sleep(2)
        self.get_logger().info("Camara NoIR iniciada")
        self.timer = self.create_timer(0.1, self.timer_callback)

    def timer_callback(self):
        try:
            frame = self.cam.capture_array("main")
            _, jpeg = cv2.imencode('.jpg', frame, [cv2.IMWRITE_JPEG_QUALITY, 80])
            msg = CompressedImage()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = "camera"
            msg.format = "jpeg"
            msg.data = jpeg.tobytes()
            self.publisher.publish(msg)
        except Exception as e:
            self.get_logger().error(f"Error: {e}")

    def destroy_node(self):
        self.cam.stop()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = CameraNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()