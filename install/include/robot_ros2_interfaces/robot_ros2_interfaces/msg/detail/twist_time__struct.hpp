// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_ros2_interfaces:msg/TwistTime.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__MSG__DETAIL__TWIST_TIME__STRUCT_HPP_
#define ROBOT_ROS2_INTERFACES__MSG__DETAIL__TWIST_TIME__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_ros2_interfaces__msg__TwistTime __attribute__((deprecated))
#else
# define DEPRECATED__robot_ros2_interfaces__msg__TwistTime __declspec(deprecated)
#endif

namespace robot_ros2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TwistTime_
{
  using Type = TwistTime_<ContainerAllocator>;

  explicit TwistTime_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : twist(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time = 0.0f;
    }
  }

  explicit TwistTime_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : twist(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time = 0.0f;
    }
  }

  // field types and members
  using _twist_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _twist_type twist;
  using _time_type =
    float;
  _time_type time;

  // setters for named parameter idiom
  Type & set__twist(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->twist = _arg;
    return *this;
  }
  Type & set__time(
    const float & _arg)
  {
    this->time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_ros2_interfaces::msg::TwistTime_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_ros2_interfaces::msg::TwistTime_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_ros2_interfaces::msg::TwistTime_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_ros2_interfaces::msg::TwistTime_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_ros2_interfaces::msg::TwistTime_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_ros2_interfaces::msg::TwistTime_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_ros2_interfaces::msg::TwistTime_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_ros2_interfaces::msg::TwistTime_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_ros2_interfaces::msg::TwistTime_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_ros2_interfaces::msg::TwistTime_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_ros2_interfaces__msg__TwistTime
    std::shared_ptr<robot_ros2_interfaces::msg::TwistTime_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_ros2_interfaces__msg__TwistTime
    std::shared_ptr<robot_ros2_interfaces::msg::TwistTime_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TwistTime_ & other) const
  {
    if (this->twist != other.twist) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    return true;
  }
  bool operator!=(const TwistTime_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TwistTime_

// alias to use template instance with default allocator
using TwistTime =
  robot_ros2_interfaces::msg::TwistTime_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_ros2_interfaces

#endif  // ROBOT_ROS2_INTERFACES__MSG__DETAIL__TWIST_TIME__STRUCT_HPP_
