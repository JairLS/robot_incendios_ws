from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    return LaunchDescription([

        # ── RPLidar A1M8 ──────────────────────────────────────────────
        Node(
            package='rplidar_ros',
            executable='rplidar_composition',
            name='rplidar',
            output='screen',
            parameters=[{
                'serial_port': '/dev/lidar',
                'serial_baudrate': 115200,
                'frame_id': 'laser',
                'angle_compensate': True,
                'scan_mode': 'Standard',
                'use_sim_time': False,
            }],
        ),

        # ── Static TF: base_link → laser ───────────────────────────────
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_to_laser_tf',
            arguments=['0.0', '0.0', '0.10',
                       '0',   '0',   '0',
                       'base_link', 'laser'],
            parameters=[{'use_sim_time': False}],
        ),

        # ── Cámara NoIR ───────────────────────────────────────────────
        Node(
            package='simulacion_ri',
            executable='camera_node',
            name='camera_node',
            output='screen',
            parameters=[{'use_sim_time': False}],
        ),

    ])