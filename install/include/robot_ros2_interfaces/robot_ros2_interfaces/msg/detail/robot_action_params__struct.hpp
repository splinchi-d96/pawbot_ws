// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_ros2_interfaces:msg/RobotActionParams.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_PARAMS__STRUCT_HPP_
#define ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_PARAMS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_ros2_interfaces__msg__RobotActionParams __attribute__((deprecated))
#else
# define DEPRECATED__robot_ros2_interfaces__msg__RobotActionParams __declspec(deprecated)
#endif

namespace robot_ros2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotActionParams_
{
  using Type = RobotActionParams_<ContainerAllocator>;

  explicit RobotActionParams_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_name = "";
    }
  }

  explicit RobotActionParams_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : action_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_name = "";
    }
  }

  // field types and members
  using _action_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _action_name_type action_name;
  using _param_int_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _param_int_type param_int;
  using _param_float_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _param_float_type param_float;
  using _param_string_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _param_string_type param_string;

  // setters for named parameter idiom
  Type & set__action_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->action_name = _arg;
    return *this;
  }
  Type & set__param_int(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->param_int = _arg;
    return *this;
  }
  Type & set__param_float(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->param_float = _arg;
    return *this;
  }
  Type & set__param_string(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->param_string = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_ros2_interfaces::msg::RobotActionParams_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_ros2_interfaces::msg::RobotActionParams_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_ros2_interfaces::msg::RobotActionParams_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_ros2_interfaces::msg::RobotActionParams_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_ros2_interfaces::msg::RobotActionParams_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_ros2_interfaces::msg::RobotActionParams_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_ros2_interfaces::msg::RobotActionParams_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_ros2_interfaces::msg::RobotActionParams_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_ros2_interfaces::msg::RobotActionParams_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_ros2_interfaces::msg::RobotActionParams_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_ros2_interfaces__msg__RobotActionParams
    std::shared_ptr<robot_ros2_interfaces::msg::RobotActionParams_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_ros2_interfaces__msg__RobotActionParams
    std::shared_ptr<robot_ros2_interfaces::msg::RobotActionParams_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotActionParams_ & other) const
  {
    if (this->action_name != other.action_name) {
      return false;
    }
    if (this->param_int != other.param_int) {
      return false;
    }
    if (this->param_float != other.param_float) {
      return false;
    }
    if (this->param_string != other.param_string) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotActionParams_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotActionParams_

// alias to use template instance with default allocator
using RobotActionParams =
  robot_ros2_interfaces::msg::RobotActionParams_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_ros2_interfaces

#endif  // ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_PARAMS__STRUCT_HPP_
