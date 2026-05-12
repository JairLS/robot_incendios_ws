from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():

    return LaunchDescription([

        # ── RPLidar A1M8 ──────────────────────────────────────────────
        Node(
            package='rplidar_ros',
            executable='rplidar_composition',
            name='rplidar',
            output='screen',
            parameters=[{
                'serial_port': '/dev/ttyUSB0',
                'serial_baudrate': 115200,
                'frame_id': 'laser',
                'angle_compensate': True,
                'scan_mode': 'Standard',
                'use_sim_time': False,
            }],
        ),

        # ── Static TF: base_link → laser ───────────────────────────────
        # Ajusta xyz/rpy según la posición física del lidar en el chasis
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_to_laser_tf',
            arguments=['0.0', '0.0', '0.10',   # x y z  (lidar 10 cm arriba del centro)
                       '0',   '0',   '0',       # roll pitch yaw
                       'base_link', 'laser'],
            parameters=[{'use_sim_time': False}],
        ),

    ])