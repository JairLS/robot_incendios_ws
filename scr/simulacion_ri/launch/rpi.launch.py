import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():

    urdf_path = os.path.join(
        get_package_share_directory('simulacion_ri'),
        'urdf', 'Ensamblaje_URDF_Final.urdf'
    )
    with open(urdf_path, 'r') as f:
        robot_description = f.read()

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

        # ── Cámara NoIR (picamera2) ───────────────────────────────────
        Node(
            package='simulacion_ri',
            executable='camera_node',
            name='camera_node',
            output='screen',
            parameters=[{'use_sim_time': False}],
        ),

        # ── Robot State Publisher ─────────────────────────────────────
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': robot_description,
                'use_sim_time': False,
            }],
        ),

        # ── Foxglove Bridge ───────────────────────────────────────────
        Node(
            package='foxglove_bridge',
            executable='foxglove_bridge',
            name='foxglove_bridge',
            output='screen',
            parameters=[{'use_sim_time': False}],
        ),

    ])