// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_ros2_interfaces:msg/RobotActionEnum.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_ENUM__BUILDER_HPP_
#define ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_ENUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_ros2_interfaces/msg/detail/robot_action_enum__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_ros2_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotActionEnum_value
{
public:
  Init_RobotActionEnum_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_ros2_interfaces::msg::RobotActionEnum value(::robot_ros2_interfaces::msg::RobotActionEnum::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_ros2_interfaces::msg::RobotActionEnum msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_ros2_interfaces::msg::RobotActionEnum>()
{
  return robot_ros2_interfaces::msg::builder::Init_RobotActionEnum_value();
}

}  // namespace robot_ros2_interfaces

#endif  // ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_ENUM__BUILDER_HPP_
