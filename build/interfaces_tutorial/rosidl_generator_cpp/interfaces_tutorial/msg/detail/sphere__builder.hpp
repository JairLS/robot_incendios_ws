// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces_tutorial:msg/Sphere.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces_tutorial/msg/sphere.hpp"


#ifndef INTERFACES_TUTORIAL__MSG__DETAIL__SPHERE__BUILDER_HPP_
#define INTERFACES_TUTORIAL__MSG__DETAIL__SPHERE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces_tutorial/msg/detail/sphere__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces_tutorial
{

namespace msg
{

namespace builder
{

class Init_Sphere_radius
{
public:
  explicit Init_Sphere_radius(::interfaces_tutorial::msg::Sphere & msg)
  : msg_(msg)
  {}
  ::interfaces_tutorial::msg::Sphere radius(::interfaces_tutorial::msg::Sphere::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces_tutorial::msg::Sphere msg_;
};

class Init_Sphere_center
{
public:
  Init_Sphere_center()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sphere_radius center(::interfaces_tutorial::msg::Sphere::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_Sphere_radius(msg_);
  }

private:
  ::interfaces_tutorial::msg::Sphere msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces_tutorial::msg::Sphere>()
{
  return interfaces_tutorial::msg::builder::Init_Sphere_center();
}

}  // namespace interfaces_tutorial

#endif  // INTERFACES_TUTORIAL__MSG__DETAIL__SPHERE__BUILDER_HPP_
