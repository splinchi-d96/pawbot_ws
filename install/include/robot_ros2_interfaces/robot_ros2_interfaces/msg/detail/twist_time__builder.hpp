// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_ros2_interfaces:msg/TwistTime.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__MSG__DETAIL__TWIST_TIME__BUILDER_HPP_
#define ROBOT_ROS2_INTERFACES__MSG__DETAIL__TWIST_TIME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_ros2_interfaces/msg/detail/twist_time__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_ros2_interfaces
{

namespace msg
{

namespace builder
{

class Init_TwistTime_time
{
public:
  explicit Init_TwistTime_time(::robot_ros2_interfaces::msg::TwistTime & msg)
  : msg_(msg)
  {}
  ::robot_ros2_interfaces::msg::TwistTime time(::robot_ros2_interfaces::msg::TwistTime::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_ros2_interfaces::msg::TwistTime msg_;
};

class Init_TwistTime_twist
{
public:
  Init_TwistTime_twist()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TwistTime_time twist(::robot_ros2_interfaces::msg::TwistTime::_twist_type arg)
  {
    msg_.twist = std::move(arg);
    return Init_TwistTime_time(msg_);
  }

private:
  ::robot_ros2_interfaces::msg::TwistTime msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_ros2_interfaces::msg::TwistTime>()
{
  return robot_ros2_interfaces::msg::builder::Init_TwistTime_twist();
}

}  // namespace robot_ros2_interfaces

#endif  // ROBOT_ROS2_INTERFACES__MSG__DETAIL__TWIST_TIME__BUILDER_HPP_
