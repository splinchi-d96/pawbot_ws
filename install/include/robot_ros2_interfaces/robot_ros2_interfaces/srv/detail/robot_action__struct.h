// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_ros2_interfaces:srv/RobotAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__SRV__DETAIL__ROBOT_ACTION__STRUCT_H_
#define ROBOT_ROS2_INTERFACES__SRV__DETAIL__ROBOT_ACTION__STRUCT_H_

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

/// Struct defined in srv/RobotAction in the package robot_ros2_interfaces.
typedef struct robot_ros2_interfaces__srv__RobotAction_Request
{
  rosidl_runtime_c__String action_name;
  /// 动作参数
  rosidl_runtime_c__int32__Sequence param_int;
  rosidl_runtime_c__float__Sequence param_float;
  rosidl_runtime_c__String__Sequence param_string;
} robot_ros2_interfaces__srv__RobotAction_Request;

// Struct for a sequence of robot_ros2_interfaces__srv__RobotAction_Request.
typedef struct robot_ros2_interfaces__srv__RobotAction_Request__Sequence
{
  robot_ros2_interfaces__srv__RobotAction_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_ros2_interfaces__srv__RobotAction_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RobotAction in the package robot_ros2_interfaces.
typedef struct robot_ros2_interfaces__srv__RobotAction_Response
{
  rosidl_runtime_c__String result;
} robot_ros2_interfaces__srv__RobotAction_Response;

// Struct for a sequence of robot_ros2_interfaces__srv__RobotAction_Response.
typedef struct robot_ros2_interfaces__srv__RobotAction_Response__Sequence
{
  robot_ros2_interfaces__srv__RobotAction_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_ros2_interfaces__srv__RobotAction_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_ROS2_INTERFACES__SRV__DETAIL__ROBOT_ACTION__STRUCT_H_
