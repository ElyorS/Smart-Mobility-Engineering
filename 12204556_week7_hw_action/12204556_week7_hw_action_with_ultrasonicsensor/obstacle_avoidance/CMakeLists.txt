cmake_minimum_required(VERSION 3.5)
project(obstacle_avoidance)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(action_msgs REQUIRED)

ament_export_dependencies(rclcpp rclcpp_action action_msgs)

ament_package()

