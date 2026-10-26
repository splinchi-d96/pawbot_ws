// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robot_ros2_interfaces:msg/RobotActionParams.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robot_ros2_interfaces/msg/detail/robot_action_params__struct.hpp"
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

void RobotActionParams_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robot_ros2_interfaces::msg::RobotActionParams(_init);
}

void RobotActionParams_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robot_ros2_interfaces::msg::RobotActionParams *>(message_memory);
  typed_message->~RobotActionParams();
}

size_t size_function__RobotActionParams__param_int(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RobotActionParams__param_int(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotActionParams__param_int(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__RobotActionParams__param_int(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__RobotActionParams__param_int(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__RobotActionParams__param_int(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__RobotActionParams__param_int(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__RobotActionParams__param_int(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__RobotActionParams__param_float(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RobotActionParams__param_float(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotActionParams__param_float(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__RobotActionParams__param_float(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__RobotActionParams__param_float(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__RobotActionParams__param_float(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__RobotActionParams__param_float(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__RobotActionParams__param_float(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__RobotActionParams__param_string(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RobotActionParams__param_string(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotActionParams__param_string(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__RobotActionParams__param_string(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__RobotActionParams__param_string(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__RobotActionParams__param_string(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__RobotActionParams__param_string(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__RobotActionParams__param_string(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RobotActionParams_message_member_array[4] = {
  {
    "action_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces::msg::RobotActionParams, action_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "param_int",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces::msg::RobotActionParams, param_int),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotActionParams__param_int,  // size() function pointer
    get_const_function__RobotActionParams__param_int,  // get_const(index) function pointer
    get_function__RobotActionParams__param_int,  // get(index) function pointer
    fetch_function__RobotActionParams__param_int,  // fetch(index, &value) function pointer
    assign_function__RobotActionParams__param_int,  // assign(index, value) function pointer
    resize_function__RobotActionParams__param_int  // resize(index) function pointer
  },
  {
    "param_float",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces::msg::RobotActionParams, param_float),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotActionParams__param_float,  // size() function pointer
    get_const_function__RobotActionParams__param_float,  // get_const(index) function pointer
    get_function__RobotActionParams__param_float,  // get(index) function pointer
    fetch_function__RobotActionParams__param_float,  // fetch(index, &value) function pointer
    assign_function__RobotActionParams__param_float,  // assign(index, value) function pointer
    resize_function__RobotActionParams__param_float  // resize(index) function pointer
  },
  {
    "param_string",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces::msg::RobotActionParams, param_string),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotActionParams__param_string,  // size() function pointer
    get_const_function__RobotActionParams__param_string,  // get_const(index) function pointer
    get_function__RobotActionParams__param_string,  // get(index) function pointer
    fetch_function__RobotActionParams__param_string,  // fetch(index, &value) function pointer
    assign_function__RobotActionParams__param_string,  // assign(index, value) function pointer
    resize_function__RobotActionParams__param_string  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RobotActionParams_message_members = {
  "robot_ros2_interfaces::msg",  // message namespace
  "RobotActionParams",  // message name
  4,  // number of fields
  sizeof(robot_ros2_interfaces::msg::RobotActionParams),
  RobotActionParams_message_member_array,  // message members
  RobotActionParams_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotActionParams_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RobotActionParams_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotActionParams_message_members,
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
get_message_type_support_handle<robot_ros2_interfaces::msg::RobotActionParams>()
{
  return &::robot_ros2_interfaces::msg::rosidl_typesupport_introspection_cpp::RobotActionParams_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_ros2_interfaces, msg, RobotActionParams)() {
  return &::robot_ros2_interfaces::msg::rosidl_typesupport_introspection_cpp::RobotActionParams_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
