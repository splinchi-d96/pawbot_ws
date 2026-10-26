// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_ros2_interfaces:srv/RobotAction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__SRV__DETAIL__ROBOT_ACTION__TRAITS_HPP_
#define ROBOT_ROS2_INTERFACES__SRV__DETAIL__ROBOT_ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_ros2_interfaces/srv/detail/robot_action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_ros2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotAction_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: action_name
  {
    out << "action_name: ";
    rosidl_generator_traits::value_to_yaml(msg.action_name, out);
    out << ", ";
  }

  // member: param_int
  {
    if (msg.param_int.size() == 0) {
      out << "param_int: []";
    } else {
      out << "param_int: [";
      size_t pending_items = msg.param_int.size();
      for (auto item : msg.param_int) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: param_float
  {
    if (msg.param_float.size() == 0) {
      out << "param_float: []";
    } else {
      out << "param_float: [";
      size_t pending_items = msg.param_float.size();
      for (auto item : msg.param_float) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: param_string
  {
    if (msg.param_string.size() == 0) {
      out << "param_string: []";
    } else {
      out << "param_string: [";
      size_t pending_items = msg.param_string.size();
      for (auto item : msg.param_string) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotAction_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: action_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action_name: ";
    rosidl_generator_traits::value_to_yaml(msg.action_name, out);
    out << "\n";
  }

  // member: param_int
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.param_int.size() == 0) {
      out << "param_int: []\n";
    } else {
      out << "param_int:\n";
      for (auto item : msg.param_int) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: param_float
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.param_float.size() == 0) {
      out << "param_float: []\n";
    } else {
      out << "param_float:\n";
      for (auto item : msg.param_float) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: param_string
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.param_string.size() == 0) {
      out << "param_string: []\n";
    } else {
      out << "param_string:\n";
      for (auto item : msg.param_string) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotAction_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_ros2_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_ros2_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_ros2_interfaces::srv::RobotAction_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_ros2_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_ros2_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_ros2_interfaces::srv::RobotAction_Request & msg)
{
  return robot_ros2_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_ros2_interfaces::srv::RobotAction_Request>()
{
  return "robot_ros2_interfaces::srv::RobotAction_Request";
}

template<>
inline const char * name<robot_ros2_interfaces::srv::RobotAction_Request>()
{
  return "robot_ros2_interfaces/srv/RobotAction_Request";
}

template<>
struct has_fixed_size<robot_ros2_interfaces::srv::RobotAction_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_ros2_interfaces::srv::RobotAction_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_ros2_interfaces::srv::RobotAction_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_ros2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotAction_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotAction_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotAction_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_ros2_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_ros2_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_ros2_interfaces::srv::RobotAction_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_ros2_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_ros2_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_ros2_interfaces::srv::RobotAction_Response & msg)
{
  return robot_ros2_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_ros2_interfaces::srv::RobotAction_Response>()
{
  return "robot_ros2_interfaces::srv::RobotAction_Response";
}

template<>
inline const char * name<robot_ros2_interfaces::srv::RobotAction_Response>()
{
  return "robot_ros2_interfaces/srv/RobotAction_Response";
}

template<>
struct has_fixed_size<robot_ros2_interfaces::srv::RobotAction_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_ros2_interfaces::srv::RobotAction_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_ros2_interfaces::srv::RobotAction_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_ros2_interfaces::srv::RobotAction>()
{
  return "robot_ros2_interfaces::srv::RobotAction";
}

template<>
inline const char * name<robot_ros2_interfaces::srv::RobotAction>()
{
  return "robot_ros2_interfaces/srv/RobotAction";
}

template<>
struct has_fixed_size<robot_ros2_interfaces::srv::RobotAction>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_ros2_interfaces::srv::RobotAction_Request>::value &&
    has_fixed_size<robot_ros2_interfaces::srv::RobotAction_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_ros2_interfaces::srv::RobotAction>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_ros2_interfaces::srv::RobotAction_Request>::value &&
    has_bounded_size<robot_ros2_interfaces::srv::RobotAction_Response>::value
  >
{
};

template<>
struct is_service<robot_ros2_interfaces::srv::RobotAction>
  : std::true_type
{
};

template<>
struct is_service_request<robot_ros2_interfaces::srv::RobotAction_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_ros2_interfaces::srv::RobotAction_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_ROS2_INTERFACES__SRV__DETAIL__ROBOT_ACTION__TRAITS_HPP_
