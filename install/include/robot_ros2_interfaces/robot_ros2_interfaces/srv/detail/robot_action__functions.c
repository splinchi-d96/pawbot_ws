// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robot_ros2_interfaces:srv/RobotAction.idl
// generated code does not contain a copyright notice
#include "robot_ros2_interfaces/srv/detail/robot_action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `action_name`
// Member `param_string`
#include "rosidl_runtime_c/string_functions.h"
// Member `param_int`
// Member `param_float`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
robot_ros2_interfaces__srv__RobotAction_Request__init(robot_ros2_interfaces__srv__RobotAction_Request * msg)
{
  if (!msg) {
    return false;
  }
  // action_name
  if (!rosidl_runtime_c__String__init(&msg->action_name)) {
    robot_ros2_interfaces__srv__RobotAction_Request__fini(msg);
    return false;
  }
  // param_int
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->param_int, 0)) {
    robot_ros2_interfaces__srv__RobotAction_Request__fini(msg);
    return false;
  }
  // param_float
  if (!rosidl_runtime_c__float__Sequence__init(&msg->param_float, 0)) {
    robot_ros2_interfaces__srv__RobotAction_Request__fini(msg);
    return false;
  }
  // param_string
  if (!rosidl_runtime_c__String__Sequence__init(&msg->param_string, 0)) {
    robot_ros2_interfaces__srv__RobotAction_Request__fini(msg);
    return false;
  }
  return true;
}

void
robot_ros2_interfaces__srv__RobotAction_Request__fini(robot_ros2_interfaces__srv__RobotAction_Request * msg)
{
  if (!msg) {
    return;
  }
  // action_name
  rosidl_runtime_c__String__fini(&msg->action_name);
  // param_int
  rosidl_runtime_c__int32__Sequence__fini(&msg->param_int);
  // param_float
  rosidl_runtime_c__float__Sequence__fini(&msg->param_float);
  // param_string
  rosidl_runtime_c__String__Sequence__fini(&msg->param_string);
}

bool
robot_ros2_interfaces__srv__RobotAction_Request__are_equal(const robot_ros2_interfaces__srv__RobotAction_Request * lhs, const robot_ros2_interfaces__srv__RobotAction_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // action_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->action_name), &(rhs->action_name)))
  {
    return false;
  }
  // param_int
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->param_int), &(rhs->param_int)))
  {
    return false;
  }
  // param_float
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->param_float), &(rhs->param_float)))
  {
    return false;
  }
  // param_string
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->param_string), &(rhs->param_string)))
  {
    return false;
  }
  return true;
}

bool
robot_ros2_interfaces__srv__RobotAction_Request__copy(
  const robot_ros2_interfaces__srv__RobotAction_Request * input,
  robot_ros2_interfaces__srv__RobotAction_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // action_name
  if (!rosidl_runtime_c__String__copy(
      &(input->action_name), &(output->action_name)))
  {
    return false;
  }
  // param_int
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->param_int), &(output->param_int)))
  {
    return false;
  }
  // param_float
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->param_float), &(output->param_float)))
  {
    return false;
  }
  // param_string
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->param_string), &(output->param_string)))
  {
    return false;
  }
  return true;
}

robot_ros2_interfaces__srv__RobotAction_Request *
robot_ros2_interfaces__srv__RobotAction_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_ros2_interfaces__srv__RobotAction_Request * msg = (robot_ros2_interfaces__srv__RobotAction_Request *)allocator.allocate(sizeof(robot_ros2_interfaces__srv__RobotAction_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_ros2_interfaces__srv__RobotAction_Request));
  bool success = robot_ros2_interfaces__srv__RobotAction_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_ros2_interfaces__srv__RobotAction_Request__destroy(robot_ros2_interfaces__srv__RobotAction_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_ros2_interfaces__srv__RobotAction_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_ros2_interfaces__srv__RobotAction_Request__Sequence__init(robot_ros2_interfaces__srv__RobotAction_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_ros2_interfaces__srv__RobotAction_Request * data = NULL;

  if (size) {
    data = (robot_ros2_interfaces__srv__RobotAction_Request *)allocator.zero_allocate(size, sizeof(robot_ros2_interfaces__srv__RobotAction_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_ros2_interfaces__srv__RobotAction_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_ros2_interfaces__srv__RobotAction_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robot_ros2_interfaces__srv__RobotAction_Request__Sequence__fini(robot_ros2_interfaces__srv__RobotAction_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robot_ros2_interfaces__srv__RobotAction_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robot_ros2_interfaces__srv__RobotAction_Request__Sequence *
robot_ros2_interfaces__srv__RobotAction_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_ros2_interfaces__srv__RobotAction_Request__Sequence * array = (robot_ros2_interfaces__srv__RobotAction_Request__Sequence *)allocator.allocate(sizeof(robot_ros2_interfaces__srv__RobotAction_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_ros2_interfaces__srv__RobotAction_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_ros2_interfaces__srv__RobotAction_Request__Sequence__destroy(robot_ros2_interfaces__srv__RobotAction_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_ros2_interfaces__srv__RobotAction_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_ros2_interfaces__srv__RobotAction_Request__Sequence__are_equal(const robot_ros2_interfaces__srv__RobotAction_Request__Sequence * lhs, const robot_ros2_interfaces__srv__RobotAction_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_ros2_interfaces__srv__RobotAction_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_ros2_interfaces__srv__RobotAction_Request__Sequence__copy(
  const robot_ros2_interfaces__srv__RobotAction_Request__Sequence * input,
  robot_ros2_interfaces__srv__RobotAction_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_ros2_interfaces__srv__RobotAction_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_ros2_interfaces__srv__RobotAction_Request * data =
      (robot_ros2_interfaces__srv__RobotAction_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_ros2_interfaces__srv__RobotAction_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_ros2_interfaces__srv__RobotAction_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_ros2_interfaces__srv__RobotAction_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
robot_ros2_interfaces__srv__RobotAction_Response__init(robot_ros2_interfaces__srv__RobotAction_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__init(&msg->result)) {
    robot_ros2_interfaces__srv__RobotAction_Response__fini(msg);
    return false;
  }
  return true;
}

void
robot_ros2_interfaces__srv__RobotAction_Response__fini(robot_ros2_interfaces__srv__RobotAction_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  rosidl_runtime_c__String__fini(&msg->result);
}

bool
robot_ros2_interfaces__srv__RobotAction_Response__are_equal(const robot_ros2_interfaces__srv__RobotAction_Response * lhs, const robot_ros2_interfaces__srv__RobotAction_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
robot_ros2_interfaces__srv__RobotAction_Response__copy(
  const robot_ros2_interfaces__srv__RobotAction_Response * input,
  robot_ros2_interfaces__srv__RobotAction_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

robot_ros2_interfaces__srv__RobotAction_Response *
robot_ros2_interfaces__srv__RobotAction_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_ros2_interfaces__srv__RobotAction_Response * msg = (robot_ros2_interfaces__srv__RobotAction_Response *)allocator.allocate(sizeof(robot_ros2_interfaces__srv__RobotAction_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_ros2_interfaces__srv__RobotAction_Response));
  bool success = robot_ros2_interfaces__srv__RobotAction_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_ros2_interfaces__srv__RobotAction_Response__destroy(robot_ros2_interfaces__srv__RobotAction_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_ros2_interfaces__srv__RobotAction_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_ros2_interfaces__srv__RobotAction_Response__Sequence__init(robot_ros2_interfaces__srv__RobotAction_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_ros2_interfaces__srv__RobotAction_Response * data = NULL;

  if (size) {
    data = (robot_ros2_interfaces__srv__RobotAction_Response *)allocator.zero_allocate(size, sizeof(robot_ros2_interfaces__srv__RobotAction_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_ros2_interfaces__srv__RobotAction_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_ros2_interfaces__srv__RobotAction_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robot_ros2_interfaces__srv__RobotAction_Response__Sequence__fini(robot_ros2_interfaces__srv__RobotAction_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robot_ros2_interfaces__srv__RobotAction_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robot_ros2_interfaces__srv__RobotAction_Response__Sequence *
robot_ros2_interfaces__srv__RobotAction_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_ros2_interfaces__srv__RobotAction_Response__Sequence * array = (robot_ros2_interfaces__srv__RobotAction_Response__Sequence *)allocator.allocate(sizeof(robot_ros2_interfaces__srv__RobotAction_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_ros2_interfaces__srv__RobotAction_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_ros2_interfaces__srv__RobotAction_Response__Sequence__destroy(robot_ros2_interfaces__srv__RobotAction_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_ros2_interfaces__srv__RobotAction_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_ros2_interfaces__srv__RobotAction_Response__Sequence__are_equal(const robot_ros2_interfaces__srv__RobotAction_Response__Sequence * lhs, const robot_ros2_interfaces__srv__RobotAction_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_ros2_interfaces__srv__RobotAction_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_ros2_interfaces__srv__RobotAction_Response__Sequence__copy(
  const robot_ros2_interfaces__srv__RobotAction_Response__Sequence * input,
  robot_ros2_interfaces__srv__RobotAction_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_ros2_interfaces__srv__RobotAction_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_ros2_interfaces__srv__RobotAction_Response * data =
      (robot_ros2_interfaces__srv__RobotAction_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_ros2_interfaces__srv__RobotAction_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_ros2_interfaces__srv__RobotAction_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_ros2_interfaces__srv__RobotAction_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
