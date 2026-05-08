#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped

class LidarTFPublisher(Node):
    def __init__(self):
        super().__init__('lidar_tf_publisher')
        self.br = TransformBroadcaster(self)
        self.create_subscription(LaserScan, '/scan', self.callback, 10)

    def callback(self, msg):
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'base_link'
        t.child_frame_id = msg.header.frame_id
        t.transform.rotation.w = 1.0
        self.br.sendTransform(t)

def main():
    rclpy.init()
    rclpy.spin(LidarTFPublisher())

if __name__ == '__main__':
    main()