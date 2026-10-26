// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_ros2_interfaces:msg/RobotActionEnum.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_ENUM__STRUCT_H_
#define ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_ENUM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'EXIT'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__EXIT = 0l
};

/// Constant 'STAND_UP'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__STAND_UP = 1l
};

/// Constant 'LIE_DOWN'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__LIE_DOWN = 2l
};

/// Constant 'GO_FORWARD'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__GO_FORWARD = 3l
};

/// Constant 'GO_BACKWARD'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__GO_BACKWARD = 4l
};

/// Constant 'GO_LEFT'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__GO_LEFT = 5l
};

/// Constant 'GO_RIGHT'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__GO_RIGHT = 6l
};

/// Constant 'TURN_LEFT'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__TURN_LEFT = 7l
};

/// Constant 'TURN_RIGHT'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__TURN_RIGHT = 8l
};

/// Constant 'JUMP'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__JUMP = 9l
};

/// Constant 'FRONT_JUMP'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__FRONT_JUMP = 10l
};

/// Constant 'BACK_FLIP'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__BACK_FLIP = 11l
};

/// Constant 'SHAKE_HAND'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__SHAKE_HAND = 12l
};

/// Constant 'ATTITUDE_CONTROL'.
/**
  * attitudeControl姿态控制
 */
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__ATTITUDE_CONTROL = 13l
};

/// Constant 'RESET'.
/**
  * 复位
 */
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__RESET = 14l
};

/// Constant 'TWO_LEG_STAND'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__TWO_LEG_STAND = 15l
};

/// Constant 'TWO_LEG_STAND_C'.
enum
{
  robot_ros2_interfaces__msg__RobotActionEnum__TWO_LEG_STAND_C = 16l
};

/// Struct defined in msg/RobotActionEnum in the package robot_ros2_interfaces.
typedef struct robot_ros2_interfaces__msg__RobotActionEnum
{
  int32_t value;
} robot_ros2_interfaces__msg__RobotActionEnum;

// Struct for a sequence of robot_ros2_interfaces__msg__RobotActionEnum.
typedef struct robot_ros2_interfaces__msg__RobotActionEnum__Sequence
{
  robot_ros2_interfaces__msg__RobotActionEnum * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_ros2_interfaces__msg__RobotActionEnum__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_ENUM__STRUCT_H_
