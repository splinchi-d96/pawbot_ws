// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_ros2_interfaces:msg/RobotActionParams.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_PARAMS__STRUCT_H_
#define ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_PARAMS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'action_name'
// Member 'param_string'
#include "rosidl_runtime_c/string.h"
// Member 'param_int'
// Member 'param_float'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RobotActionParams in the package robot_ros2_interfaces.
/**
  * 动作名字
 */
typedef struct robot_ros2_interfaces__msg__RobotActionParams
{
  rosidl_runtime_c__String action_name;
  /// 动作参数
  rosidl_runtime_c__int32__Sequence param_int;
  rosidl_runtime_c__float__Sequence param_float;
  rosidl_runtime_c__String__Sequence param_string;
} robot_ros2_interfaces__msg__RobotActionParams;

// Struct for a sequence of robot_ros2_interfaces__msg__RobotActionParams.
typedef struct robot_ros2_interfaces__msg__RobotActionParams__Sequence
{
  robot_ros2_interfaces__msg__RobotActionParams * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_ros2_interfaces__msg__RobotActionParams__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_PARAMS__STRUCT_H_
