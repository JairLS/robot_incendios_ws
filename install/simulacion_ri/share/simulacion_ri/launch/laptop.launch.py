from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():

    pkg = get_package_share_directory('simulacion_ri')
    rviz_config = os.path.join(pkg, 'config', 'robot_real.rviz')

    return LaunchDescription([

        # ── RViz2 ──────────────────────────────────────────────────────
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            # Si existe el archivo de config lo usa; si no, abre vacío
            arguments=['-d', rviz_config] if os.path.exists(rviz_config) else [],
            parameters=[{'use_sim_time': False}],
        ),

    ])