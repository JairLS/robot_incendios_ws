import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess, TimerAction, DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    pkg = get_package_share_directory('simulacion_ri')
    os.environ['GZ_SIM_RESOURCE_PATH'] = os.path.dirname(pkg)
    urdf_file = os.path.join(pkg, 'urdf', 'Ensamblaje_URDF_Final.urdf')

    with open(urdf_file, 'r') as f:
        robot_description = f.read()

    robot_description = robot_description.replace(
        'package://Ensamblaje_V1',
        pkg
    )

    world = 'cuarto'
    world_file = os.path.join(pkg, 'worlds', world + '.sdf')
    joint_state_topic = f'/world/{world}/model/simulacion_ri/joint_state'

    return LaunchDescription([
        ExecuteProcess(
            cmd=['gz', 'sim', '-v4', world_file],
            output='screen'
        ),

        TimerAction(period=5.0, actions=[
            Node(
                package='robot_state_publisher',
                executable='robot_state_publisher',
                name='robot_state_publisher',
                output='screen',
                parameters=[{
                    'robot_description': robot_description,
                    'use_sim_time': True,
                }]
            ),
        ]),

        TimerAction(period=8.0, actions=[
            Node(
                package='ros_gz_sim',
                executable='create',
                name='spawn_entity',
                output='screen',
                arguments=[
                    '-topic', 'robot_description',
                    '-name', 'simulacion_ri',
                    '-x', '0', '-y', '0', '-z', '0.05',
                    '-R', '0', '-P', '0', '-Y', '0'
                ]
            ),
        ]),

        TimerAction(period=9.0, actions=[
            Node(
                package='ros_gz_bridge',
                executable='parameter_bridge',
                name='bridge',
                output='screen',
                arguments=[
                    '/cmd_vel@geometry_msgs/msg/Twist@gz.msgs.Twist',
                    '/odom@nav_msgs/msg/Odometry@gz.msgs.Odometry',
                    '/tf@tf2_msgs/msg/TFMessage@gz.msgs.Pose_V',
                    f'{joint_state_topic}@sensor_msgs/msg/JointState@gz.msgs.Model',
                    '/scan@sensor_msgs/msg/LaserScan@gz.msgs.LaserScan',
                    '/clock@rosgraph_msgs/msg/Clock@gz.msgs.Clock',
                ],
                remappings=[
                    (joint_state_topic, '/joint_states'),
                ]
            ),
        ]),

        TimerAction(period=9.5, actions=[
            Node(
                package='simulacion_ri',
                executable='odom_tf',
                name='odom_tf_publisher',
                output='screen',
                parameters=[{'use_sim_time': True}]
            ),
        ]),

        TimerAction(period=11.0, actions=[
            Node(
                package='simulacion_ri',
                executable='lidar_tf',
                name='lidar_tf_publisher',
                output='screen',
                parameters=[{'use_sim_time': True}]
            ),
        ]),
    ])
