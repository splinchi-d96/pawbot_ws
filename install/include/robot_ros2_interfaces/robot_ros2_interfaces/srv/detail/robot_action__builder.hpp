// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_ros2_interfaces:srv/RobotAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__SRV__DETAIL__ROBOT_ACTION__BUILDER_HPP_
#define ROBOT_ROS2_INTERFACES__SRV__DETAIL__ROBOT_ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_ros2_interfaces/srv/detail/robot_action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_RobotAction_Request_param_string
{
public:
  explicit Init_RobotAction_Request_param_string(::robot_ros2_interfaces::srv::RobotAction_Request & msg)
  : msg_(msg)
  {}
  ::robot_ros2_interfaces::srv::RobotAction_Request param_string(::robot_ros2_interfaces::srv::RobotAction_Request::_param_string_type arg)
  {
    msg_.param_string = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_ros2_interfaces::srv::RobotAction_Request msg_;
};

class Init_RobotAction_Request_param_float
{
public:
  explicit Init_RobotAction_Request_param_float(::robot_ros2_interfaces::srv::RobotAction_Request & msg)
  : msg_(msg)
  {}
  Init_RobotAction_Request_param_string param_float(::robot_ros2_interfaces::srv::RobotAction_Request::_param_float_type arg)
  {
    msg_.param_float = std::move(arg);
    return Init_RobotAction_Request_param_string(msg_);
  }

private:
  ::robot_ros2_interfaces::srv::RobotAction_Request msg_;
};

class Init_RobotAction_Request_param_int
{
public:
  explicit Init_RobotAction_Request_param_int(::robot_ros2_interfaces::srv::RobotAction_Request & msg)
  : msg_(msg)
  {}
  Init_RobotAction_Request_param_float param_int(::robot_ros2_interfaces::srv::RobotAction_Request::_param_int_type arg)
  {
    msg_.param_int = std::move(arg);
    return Init_RobotAction_Request_param_float(msg_);
  }

private:
  ::robot_ros2_interfaces::srv::RobotAction_Request msg_;
};

class Init_RobotAction_Request_action_name
{
public:
  Init_RobotAction_Request_action_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotAction_Request_param_int action_name(::robot_ros2_interfaces::srv::RobotAction_Request::_action_name_type arg)
  {
    msg_.action_name = std::move(arg);
    return Init_RobotAction_Request_param_int(msg_);
  }

private:
  ::robot_ros2_interfaces::srv::RobotAction_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_ros2_interfaces::srv::RobotAction_Request>()
{
  return robot_ros2_interfaces::srv::builder::Init_RobotAction_Request_action_name();
}

}  // namespace robot_ros2_interfaces


namespace robot_ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_RobotAction_Response_result
{
public:
  Init_RobotAction_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_ros2_interfaces::srv::RobotAction_Response result(::robot_ros2_interfaces::srv::RobotAction_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_ros2_interfaces::srv::RobotAction_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_ros2_interfaces::srv::RobotAction_Response>()
{
  return robot_ros2_interfaces::srv::builder::Init_RobotAction_Response_result();
}

}  // namespace robot_ros2_interfaces

#endif  // ROBOT_ROS2_INTERFACES__SRV__DETAIL__ROBOT_ACTION__BUILDER_HPP_
