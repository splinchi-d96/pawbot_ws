// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_ros2_interfaces:msg/RobotActionEnum.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_ENUM__TRAITS_HPP_
#define ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_ENUM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_ros2_interfaces/msg/detail/robot_action_enum__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_ros2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotActionEnum & msg,
  std::ostream & out)
{
  out << "{";
  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotActionEnum & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotActionEnum & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace robot_ros2_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_ros2_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_ros2_interfaces::msg::RobotActionEnum & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_ros2_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_ros2_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_ros2_interfaces::msg::RobotActionEnum & msg)
{
  return robot_ros2_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_ros2_interfaces::msg::RobotActionEnum>()
{
  return "robot_ros2_interfaces::msg::RobotActionEnum";
}

template<>
inline const char * name<robot_ros2_interfaces::msg::RobotActionEnum>()
{
  return "robot_ros2_interfaces/msg/RobotActionEnum";
}

template<>
struct has_fixed_size<robot_ros2_interfaces::msg::RobotActionEnum>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_ros2_interfaces::msg::RobotActionEnum>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_ros2_interfaces::msg::RobotActionEnum>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_ENUM__TRAITS_HPP_
