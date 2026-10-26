// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_ros2_interfaces:msg/RobotActionParams.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_ros2_interfaces/msg/detail/robot_action_params__rosidl_typesupport_introspection_c.h"
#include "robot_ros2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_ros2_interfaces/msg/detail/robot_action_params__functions.h"
#include "robot_ros2_interfaces/msg/detail/robot_action_params__struct.h"


// Include directives for member types
// Member `action_name`
// Member `param_string`
#include "rosidl_runtime_c/string_functions.h"
// Member `param_int`
// Member `param_float`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__RobotActionParams_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_ros2_interfaces__msg__RobotActionParams__init(message_memory);
}

void robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__RobotActionParams_fini_function(void * message_memory)
{
  robot_ros2_interfaces__msg__RobotActionParams__fini(message_memory);
}

size_t robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__size_function__RobotActionParams__param_int(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_const_function__RobotActionParams__param_int(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_function__RobotActionParams__param_int(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__fetch_function__RobotActionParams__param_int(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_const_function__RobotActionParams__param_int(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__assign_function__RobotActionParams__param_int(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_function__RobotActionParams__param_int(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__resize_function__RobotActionParams__param_int(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__size_function__RobotActionParams__param_float(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_const_function__RobotActionParams__param_float(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_function__RobotActionParams__param_float(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__fetch_function__RobotActionParams__param_float(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_const_function__RobotActionParams__param_float(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__assign_function__RobotActionParams__param_float(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_function__RobotActionParams__param_float(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__resize_function__RobotActionParams__param_float(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__size_function__RobotActionParams__param_string(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_const_function__RobotActionParams__param_string(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_function__RobotActionParams__param_string(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__fetch_function__RobotActionParams__param_string(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_const_function__RobotActionParams__param_string(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__assign_function__RobotActionParams__param_string(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_function__RobotActionParams__param_string(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__resize_function__RobotActionParams__param_string(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__RobotActionParams_message_member_array[4] = {
  {
    "action_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces__msg__RobotActionParams, action_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "param_int",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces__msg__RobotActionParams, param_int),  // bytes offset in struct
    NULL,  // default value
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__size_function__RobotActionParams__param_int,  // size() function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_const_function__RobotActionParams__param_int,  // get_const(index) function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_function__RobotActionParams__param_int,  // get(index) function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__fetch_function__RobotActionParams__param_int,  // fetch(index, &value) function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__assign_function__RobotActionParams__param_int,  // assign(index, value) function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__resize_function__RobotActionParams__param_int  // resize(index) function pointer
  },
  {
    "param_float",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces__msg__RobotActionParams, param_float),  // bytes offset in struct
    NULL,  // default value
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__size_function__RobotActionParams__param_float,  // size() function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_const_function__RobotActionParams__param_float,  // get_const(index) function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_function__RobotActionParams__param_float,  // get(index) function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__fetch_function__RobotActionParams__param_float,  // fetch(index, &value) function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__assign_function__RobotActionParams__param_float,  // assign(index, value) function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__resize_function__RobotActionParams__param_float  // resize(index) function pointer
  },
  {
    "param_string",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces__msg__RobotActionParams, param_string),  // bytes offset in struct
    NULL,  // default value
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__size_function__RobotActionParams__param_string,  // size() function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_const_function__RobotActionParams__param_string,  // get_const(index) function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__get_function__RobotActionParams__param_string,  // get(index) function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__fetch_function__RobotActionParams__param_string,  // fetch(index, &value) function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__assign_function__RobotActionParams__param_string,  // assign(index, value) function pointer
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__resize_function__RobotActionParams__param_string  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__RobotActionParams_message_members = {
  "robot_ros2_interfaces__msg",  // message namespace
  "RobotActionParams",  // message name
  4,  // number of fields
  sizeof(robot_ros2_interfaces__msg__RobotActionParams),
  robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__RobotActionParams_message_member_array,  // message members
  robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__RobotActionParams_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__RobotActionParams_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__RobotActionParams_message_type_support_handle = {
  0,
  &robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__RobotActionParams_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_ros2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_ros2_interfaces, msg, RobotActionParams)() {
  if (!robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__RobotActionParams_message_type_support_handle.typesupport_identifier) {
    robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__RobotActionParams_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_ros2_interfaces__msg__RobotActionParams__rosidl_typesupport_introspection_c__RobotActionParams_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
