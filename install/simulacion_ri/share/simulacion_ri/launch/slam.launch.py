import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():

    pkg = get_package_share_directory('simulacion_ri')
    slam_params = os.path.join(pkg, 'config', 'mapper_params_online_async.yaml')
    gazebo_launch = os.path.join(pkg, 'launch', 'gazebo.launch.py')
    slam_launch = os.path.join(
        get_package_share_directory('slam_toolbox'),
        'launch', 'online_async_launch.py'
    )

    return LaunchDescription([

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(gazebo_launch)
        ),

        TimerAction(period=15.0, actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(slam_launch),
                launch_arguments={
                    'params_file': slam_params,
                    'use_sim_time': 'true'
                }.items()
            ),
        ]),
    ])