cmake_minimum_required(VERSION 3.5)
project(obstacle_avoidance_server)

# Find dependencies
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(obstacle_avoidance_msgs REQUIRED)

include_directories(include)

add_executable(obstacle_avoidance_server src/obstacle_avoidance_server.cpp)
ament_target_dependencies(obstacle_avoidance_server
  rclcpp
  rclcpp_action
  obstacle_avoidance_msgs
)

install(TARGETS
  obstacle_avoidance_server
  DESTINATION lib/${PROJECT_NAME}
)

ament_export_dependencies(rclcpp rclcpp_action obstacle_avoidance_msgs)
ament_package()

