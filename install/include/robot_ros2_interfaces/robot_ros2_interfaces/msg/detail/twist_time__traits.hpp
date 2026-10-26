// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_ros2_interfaces:msg/TwistTime.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__MSG__DETAIL__TWIST_TIME__TRAITS_HPP_
#define ROBOT_ROS2_INTERFACES__MSG__DETAIL__TWIST_TIME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_ros2_interfaces/msg/detail/twist_time__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace robot_ros2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TwistTime & msg,
  std::ostream & out)
{
  out << "{";
  // member: twist
  {
    out << "twist: ";
    to_flow_style_yaml(msg.twist, out);
    out << ", ";
  }

  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TwistTime & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: twist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist:\n";
    to_block_style_yaml(msg.twist, out, indentation + 2);
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TwistTime & msg, bool use_flow_style = false)
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
  const robot_ros2_interfaces::msg::TwistTime & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_ros2_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_ros2_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_ros2_interfaces::msg::TwistTime & msg)
{
  return robot_ros2_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_ros2_interfaces::msg::TwistTime>()
{
  return "robot_ros2_interfaces::msg::TwistTime";
}

template<>
inline const char * name<robot_ros2_interfaces::msg::TwistTime>()
{
  return "robot_ros2_interfaces/msg/TwistTime";
}

template<>
struct has_fixed_size<robot_ros2_interfaces::msg::TwistTime>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Twist>::value> {};

template<>
struct has_bounded_size<robot_ros2_interfaces::msg::TwistTime>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Twist>::value> {};

template<>
struct is_message<robot_ros2_interfaces::msg::TwistTime>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_ROS2_INTERFACES__MSG__DETAIL__TWIST_TIME__TRAITS_HPP_
