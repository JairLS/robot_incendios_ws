cmake_minimum_required(VERSION 3.5)
project(simulacion_ri)
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
ament_python_install_package(${PROJECT_NAME})
install(PROGRAMS
  simulacion_ri/lidar_tf_publisher.py
  DESTINATION lib/${PROJECT_NAME}
  RENAME lidar_tf
)
install(PROGRAMS
  simulacion_ri/odom_tf_publisher.py
  DESTINATION lib/${PROJECT_NAME}
  RENAME odom_tf
)
install(PROGRAMS
  simulacion_ri/camera_node.py
  DESTINATION lib/${PROJECT_NAME}
  RENAME camera_node
)
install(PROGRAMS
  simulacion_ri/thermal_node.py
  DESTINATION lib/${PROJECT_NAME}
  RENAME thermal_node
)

install(PROGRAMS
  simulacion_ri/arduino_node.py
  DESTINATION lib/${PROJECT_NAME}
  RENAME arduino_node
)

install(PROGRAMS
  simulacion_ri/diagnostics_node.py
  DESTINATION lib/${PROJECT_NAME}
  RENAME diagnostics_node
)

install(PROGRAMS
  simulacion_ri/fire_detector_node.py
  DESTINATION lib/${PROJECT_NAME}
  RENAME fire_detector_node
)

install(DIRECTORY
  config launch meshes urdf  worlds
  DESTINATION share/${PROJECT_NAME}
)
ament_package()
