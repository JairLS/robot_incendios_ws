// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces_tutorial:msg/Sphere.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces_tutorial/msg/sphere.h"


#ifndef INTERFACES_TUTORIAL__MSG__DETAIL__SPHERE__STRUCT_H_
#define INTERFACES_TUTORIAL__MSG__DETAIL__SPHERE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Sphere in the package interfaces_tutorial.
typedef struct interfaces_tutorial__msg__Sphere
{
  geometry_msgs__msg__Point center;
  double radius;
} interfaces_tutorial__msg__Sphere;

// Struct for a sequence of interfaces_tutorial__msg__Sphere.
typedef struct interfaces_tutorial__msg__Sphere__Sequence
{
  interfaces_tutorial__msg__Sphere * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces_tutorial__msg__Sphere__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES_TUTORIAL__MSG__DETAIL__SPHERE__STRUCT_H_
