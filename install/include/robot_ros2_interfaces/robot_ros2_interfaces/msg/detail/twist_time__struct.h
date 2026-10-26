// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_ros2_interfaces:msg/TwistTime.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__MSG__DETAIL__TWIST_TIME__STRUCT_H_
#define ROBOT_ROS2_INTERFACES__MSG__DETAIL__TWIST_TIME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in msg/TwistTime in the package robot_ros2_interfaces.
/**
  * Twist消息与持续时间
  * Twist
 */
typedef struct robot_ros2_interfaces__msg__TwistTime
{
  geometry_msgs__msg__Twist twist;
  /// 持续时间
  float time;
} robot_ros2_interfaces__msg__TwistTime;

// Struct for a sequence of robot_ros2_interfaces__msg__TwistTime.
typedef struct robot_ros2_interfaces__msg__TwistTime__Sequence
{
  robot_ros2_interfaces__msg__TwistTime * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_ros2_interfaces__msg__TwistTime__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_ROS2_INTERFACES__MSG__DETAIL__TWIST_TIME__STRUCT_H_
