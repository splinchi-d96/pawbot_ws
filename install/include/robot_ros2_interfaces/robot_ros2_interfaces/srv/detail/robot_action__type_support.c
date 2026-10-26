// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_ros2_interfaces:srv/RobotAction.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_ros2_interfaces/srv/detail/robot_action__rosidl_typesupport_introspection_c.h"
#include "robot_ros2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_ros2_interfaces/srv/detail/robot_action__functions.h"
#include "robot_ros2_interfaces/srv/detail/robot_action__struct.h"


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

void robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__RobotAction_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_ros2_interfaces__srv__RobotAction_Request__init(message_memory);
}

void robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__RobotAction_Request_fini_function(void * message_memory)
{
  robot_ros2_interfaces__srv__RobotAction_Request__fini(message_memory);
}

size_t robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__size_function__RobotAction_Request__param_int(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_const_function__RobotAction_Request__param_int(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_function__RobotAction_Request__param_int(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__fetch_function__RobotAction_Request__param_int(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_const_function__RobotAction_Request__param_int(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__assign_function__RobotAction_Request__param_int(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_function__RobotAction_Request__param_int(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__resize_function__RobotAction_Request__param_int(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__size_function__RobotAction_Request__param_float(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_const_function__RobotAction_Request__param_float(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_function__RobotAction_Request__param_float(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__fetch_function__RobotAction_Request__param_float(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_const_function__RobotAction_Request__param_float(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__assign_function__RobotAction_Request__param_float(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_function__RobotAction_Request__param_float(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__resize_function__RobotAction_Request__param_float(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__size_function__RobotAction_Request__param_string(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_const_function__RobotAction_Request__param_string(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_function__RobotAction_Request__param_string(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__fetch_function__RobotAction_Request__param_string(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_const_function__RobotAction_Request__param_string(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__assign_function__RobotAction_Request__param_string(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_function__RobotAction_Request__param_string(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__resize_function__RobotAction_Request__param_string(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__RobotAction_Request_message_member_array[4] = {
  {
    "action_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces__srv__RobotAction_Request, action_name),  // bytes offset in struct
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
    offsetof(robot_ros2_interfaces__srv__RobotAction_Request, param_int),  // bytes offset in struct
    NULL,  // default value
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__size_function__RobotAction_Request__param_int,  // size() function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_const_function__RobotAction_Request__param_int,  // get_const(index) function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_function__RobotAction_Request__param_int,  // get(index) function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__fetch_function__RobotAction_Request__param_int,  // fetch(index, &value) function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__assign_function__RobotAction_Request__param_int,  // assign(index, value) function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__resize_function__RobotAction_Request__param_int  // resize(index) function pointer
  },
  {
    "param_float",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces__srv__RobotAction_Request, param_float),  // bytes offset in struct
    NULL,  // default value
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__size_function__RobotAction_Request__param_float,  // size() function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_const_function__RobotAction_Request__param_float,  // get_const(index) function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_function__RobotAction_Request__param_float,  // get(index) function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__fetch_function__RobotAction_Request__param_float,  // fetch(index, &value) function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__assign_function__RobotAction_Request__param_float,  // assign(index, value) function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__resize_function__RobotAction_Request__param_float  // resize(index) function pointer
  },
  {
    "param_string",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces__srv__RobotAction_Request, param_string),  // bytes offset in struct
    NULL,  // default value
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__size_function__RobotAction_Request__param_string,  // size() function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_const_function__RobotAction_Request__param_string,  // get_const(index) function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__get_function__RobotAction_Request__param_string,  // get(index) function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__fetch_function__RobotAction_Request__param_string,  // fetch(index, &value) function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__assign_function__RobotAction_Request__param_string,  // assign(index, value) function pointer
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__resize_function__RobotAction_Request__param_string  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__RobotAction_Request_message_members = {
  "robot_ros2_interfaces__srv",  // message namespace
  "RobotAction_Request",  // message name
  4,  // number of fields
  sizeof(robot_ros2_interfaces__srv__RobotAction_Request),
  robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__RobotAction_Request_message_member_array,  // message members
  robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__RobotAction_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__RobotAction_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__RobotAction_Request_message_type_support_handle = {
  0,
  &robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__RobotAction_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_ros2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_ros2_interfaces, srv, RobotAction_Request)() {
  if (!robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__RobotAction_Request_message_type_support_handle.typesupport_identifier) {
    robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__RobotAction_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_ros2_interfaces__srv__RobotAction_Request__rosidl_typesupport_introspection_c__RobotAction_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "robot_ros2_interfaces/srv/detail/robot_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robot_ros2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robot_ros2_interfaces/srv/detail/robot_action__functions.h"
// already included above
// #include "robot_ros2_interfaces/srv/detail/robot_action__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_ros2_interfaces__srv__RobotAction_Response__rosidl_typesupport_introspection_c__RobotAction_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_ros2_interfaces__srv__RobotAction_Response__init(message_memory);
}

void robot_ros2_interfaces__srv__RobotAction_Response__rosidl_typesupport_introspection_c__RobotAction_Response_fini_function(void * message_memory)
{
  robot_ros2_interfaces__srv__RobotAction_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robot_ros2_interfaces__srv__RobotAction_Response__rosidl_typesupport_introspection_c__RobotAction_Response_message_member_array[1] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_ros2_interfaces__srv__RobotAction_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_ros2_interfaces__srv__RobotAction_Response__rosidl_typesupport_introspection_c__RobotAction_Response_message_members = {
  "robot_ros2_interfaces__srv",  // message namespace
  "RobotAction_Response",  // message name
  1,  // number of fields
  sizeof(robot_ros2_interfaces__srv__RobotAction_Response),
  robot_ros2_interfaces__srv__RobotAction_Response__rosidl_typesupport_introspection_c__RobotAction_Response_message_member_array,  // message members
  robot_ros2_interfaces__srv__RobotAction_Response__rosidl_typesupport_introspection_c__RobotAction_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_ros2_interfaces__srv__RobotAction_Response__rosidl_typesupport_introspection_c__RobotAction_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_ros2_interfaces__srv__RobotAction_Response__rosidl_typesupport_introspection_c__RobotAction_Response_message_type_support_handle = {
  0,
  &robot_ros2_interfaces__srv__RobotAction_Response__rosidl_typesupport_introspection_c__RobotAction_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_ros2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_ros2_interfaces, srv, RobotAction_Response)() {
  if (!robot_ros2_interfaces__srv__RobotAction_Response__rosidl_typesupport_introspection_c__RobotAction_Response_message_type_support_handle.typesupport_identifier) {
    robot_ros2_interfaces__srv__RobotAction_Response__rosidl_typesupport_introspection_c__RobotAction_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_ros2_interfaces__srv__RobotAction_Response__rosidl_typesupport_introspection_c__RobotAction_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robot_ros2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "robot_ros2_interfaces/srv/detail/robot_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers robot_ros2_interfaces__srv__detail__robot_action__rosidl_typesupport_introspection_c__RobotAction_service_members = {
  "robot_ros2_interfaces__srv",  // service namespace
  "RobotAction",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // robot_ros2_interfaces__srv__detail__robot_action__rosidl_typesupport_introspection_c__RobotAction_Request_message_type_support_handle,
  NULL  // response message
  // robot_ros2_interfaces__srv__detail__robot_action__rosidl_typesupport_introspection_c__RobotAction_Response_message_type_support_handle
};

static rosidl_service_type_support_t robot_ros2_interfaces__srv__detail__robot_action__rosidl_typesupport_introspection_c__RobotAction_service_type_support_handle = {
  0,
  &robot_ros2_interfaces__srv__detail__robot_action__rosidl_typesupport_introspection_c__RobotAction_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_ros2_interfaces, srv, RobotAction_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_ros2_interfaces, srv, RobotAction_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_ros2_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_ros2_interfaces, srv, RobotAction)() {
  if (!robot_ros2_interfaces__srv__detail__robot_action__rosidl_typesupport_introspection_c__RobotAction_service_type_support_handle.typesupport_identifier) {
    robot_ros2_interfaces__srv__detail__robot_action__rosidl_typesupport_introspection_c__RobotAction_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)robot_ros2_interfaces__srv__detail__robot_action__rosidl_typesupport_introspection_c__RobotAction_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_ros2_interfaces, srv, RobotAction_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_ros2_interfaces, srv, RobotAction_Response)()->data;
  }

  return &robot_ros2_interfaces__srv__detail__robot_action__rosidl_typesupport_introspection_c__RobotAction_service_type_support_handle;
}
