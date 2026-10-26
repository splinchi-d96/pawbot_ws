// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_ros2_interfaces:msg/RobotActionParams.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_PARAMS__BUILDER_HPP_
#define ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_PARAMS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_ros2_interfaces/msg/detail/robot_action_params__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_ros2_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotActionParams_param_string
{
public:
  explicit Init_RobotActionParams_param_string(::robot_ros2_interfaces::msg::RobotActionParams & msg)
  : msg_(msg)
  {}
  ::robot_ros2_interfaces::msg::RobotActionParams param_string(::robot_ros2_interfaces::msg::RobotActionParams::_param_string_type arg)
  {
    msg_.param_string = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_ros2_interfaces::msg::RobotActionParams msg_;
};

class Init_RobotActionParams_param_float
{
public:
  explicit Init_RobotActionParams_param_float(::robot_ros2_interfaces::msg::RobotActionParams & msg)
  : msg_(msg)
  {}
  Init_RobotActionParams_param_string param_float(::robot_ros2_interfaces::msg::RobotActionParams::_param_float_type arg)
  {
    msg_.param_float = std::move(arg);
    return Init_RobotActionParams_param_string(msg_);
  }

private:
  ::robot_ros2_interfaces::msg::RobotActionParams msg_;
};

class Init_RobotActionParams_param_int
{
public:
  explicit Init_RobotActionParams_param_int(::robot_ros2_interfaces::msg::RobotActionParams & msg)
  : msg_(msg)
  {}
  Init_RobotActionParams_param_float param_int(::robot_ros2_interfaces::msg::RobotActionParams::_param_int_type arg)
  {
    msg_.param_int = std::move(arg);
    return Init_RobotActionParams_param_float(msg_);
  }

private:
  ::robot_ros2_interfaces::msg::RobotActionParams msg_;
};

class Init_RobotActionParams_action_name
{
public:
  Init_RobotActionParams_action_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotActionParams_param_int action_name(::robot_ros2_interfaces::msg::RobotActionParams::_action_name_type arg)
  {
    msg_.action_name = std::move(arg);
    return Init_RobotActionParams_param_int(msg_);
  }

private:
  ::robot_ros2_interfaces::msg::RobotActionParams msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_ros2_interfaces::msg::RobotActionParams>()
{
  return robot_ros2_interfaces::msg::builder::Init_RobotActionParams_action_name();
}

}  // namespace robot_ros2_interfaces

#endif  // ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_PARAMS__BUILDER_HPP_
