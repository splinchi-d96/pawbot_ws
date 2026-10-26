// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robot_ros2_interfaces:msg/RobotActionEnum.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robot_ros2_interfaces/msg/detail/robot_action_enum__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace robot_ros2_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RobotActionEnum_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robot_ros2_interfaces::msg::RobotActionEnum(_init);
}

void RobotActionEnum_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robot_ros2_interfaces::msg::RobotActionEnum *>(message_memory);
  typed_message->~RobotActionEnum();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RobotActionEnum_message_member_array[1] = {
  {
    "value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces::msg::RobotActionEnum, value),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RobotActionEnum_message_members = {
  "robot_ros2_interfaces::msg",  // message namespace
  "RobotActionEnum",  // message name
  1,  // number of fields
  sizeof(robot_ros2_interfaces::msg::RobotActionEnum),
  RobotActionEnum_message_member_array,  // message members
  RobotActionEnum_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotActionEnum_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RobotActionEnum_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotActionEnum_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace robot_ros2_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_ros2_interfaces::msg::RobotActionEnum>()
{
  return &::robot_ros2_interfaces::msg::rosidl_typesupport_introspection_cpp::RobotActionEnum_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_ros2_interfaces, msg, RobotActionEnum)() {
  return &::robot_ros2_interfaces::msg::rosidl_typesupport_introspection_cpp::RobotActionEnum_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
