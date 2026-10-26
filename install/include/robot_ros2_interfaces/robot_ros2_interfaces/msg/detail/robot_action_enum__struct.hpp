// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_ros2_interfaces:msg/RobotActionEnum.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_ENUM__STRUCT_HPP_
#define ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_ENUM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_ros2_interfaces__msg__RobotActionEnum __attribute__((deprecated))
#else
# define DEPRECATED__robot_ros2_interfaces__msg__RobotActionEnum __declspec(deprecated)
#endif

namespace robot_ros2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotActionEnum_
{
  using Type = RobotActionEnum_<ContainerAllocator>;

  explicit RobotActionEnum_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0l;
    }
  }

  explicit RobotActionEnum_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0l;
    }
  }

  // field types and members
  using _value_type =
    int32_t;
  _value_type value;

  // setters for named parameter idiom
  Type & set__value(
    const int32_t & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int32_t EXIT =
    0;
  static constexpr int32_t STAND_UP =
    1;
  static constexpr int32_t LIE_DOWN =
    2;
  static constexpr int32_t GO_FORWARD =
    3;
  static constexpr int32_t GO_BACKWARD =
    4;
  static constexpr int32_t GO_LEFT =
    5;
  static constexpr int32_t GO_RIGHT =
    6;
  static constexpr int32_t TURN_LEFT =
    7;
  static constexpr int32_t TURN_RIGHT =
    8;
  static constexpr int32_t JUMP =
    9;
  static constexpr int32_t FRONT_JUMP =
    10;
  static constexpr int32_t BACK_FLIP =
    11;
  static constexpr int32_t SHAKE_HAND =
    12;
  static constexpr int32_t ATTITUDE_CONTROL =
    13;
  static constexpr int32_t RESET =
    14;
  static constexpr int32_t TWO_LEG_STAND =
    15;
  static constexpr int32_t TWO_LEG_STAND_C =
    16;

  // pointer types
  using RawPtr =
    robot_ros2_interfaces::msg::RobotActionEnum_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_ros2_interfaces::msg::RobotActionEnum_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_ros2_interfaces::msg::RobotActionEnum_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_ros2_interfaces::msg::RobotActionEnum_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_ros2_interfaces::msg::RobotActionEnum_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_ros2_interfaces::msg::RobotActionEnum_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_ros2_interfaces::msg::RobotActionEnum_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_ros2_interfaces::msg::RobotActionEnum_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_ros2_interfaces::msg::RobotActionEnum_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_ros2_interfaces::msg::RobotActionEnum_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_ros2_interfaces__msg__RobotActionEnum
    std::shared_ptr<robot_ros2_interfaces::msg::RobotActionEnum_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_ros2_interfaces__msg__RobotActionEnum
    std::shared_ptr<robot_ros2_interfaces::msg::RobotActionEnum_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotActionEnum_ & other) const
  {
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotActionEnum_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotActionEnum_

// alias to use template instance with default allocator
using RobotActionEnum =
  robot_ros2_interfaces::msg::RobotActionEnum_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::EXIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::STAND_UP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::LIE_DOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::GO_FORWARD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::GO_BACKWARD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::GO_LEFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::GO_RIGHT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::TURN_LEFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::TURN_RIGHT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::JUMP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::FRONT_JUMP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::BACK_FLIP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::SHAKE_HAND;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::ATTITUDE_CONTROL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::RESET;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::TWO_LEG_STAND;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t RobotActionEnum_<ContainerAllocator>::TWO_LEG_STAND_C;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace robot_ros2_interfaces

#endif  // ROBOT_ROS2_INTERFACES__MSG__DETAIL__ROBOT_ACTION_ENUM__STRUCT_HPP_
