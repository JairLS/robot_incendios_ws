// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from interfaces_tutorial:msg/Sphere.idl
// generated code does not contain a copyright notice
#ifndef INTERFACES_TUTORIAL__MSG__DETAIL__SPHERE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define INTERFACES_TUTORIAL__MSG__DETAIL__SPHERE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "interfaces_tutorial/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "interfaces_tutorial/msg/detail/sphere__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces_tutorial
bool cdr_serialize_interfaces_tutorial__msg__Sphere(
  const interfaces_tutorial__msg__Sphere * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces_tutorial
bool cdr_deserialize_interfaces_tutorial__msg__Sphere(
  eprosima::fastcdr::Cdr &,
  interfaces_tutorial__msg__Sphere * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces_tutorial
size_t get_serialized_size_interfaces_tutorial__msg__Sphere(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces_tutorial
size_t max_serialized_size_interfaces_tutorial__msg__Sphere(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces_tutorial
bool cdr_serialize_key_interfaces_tutorial__msg__Sphere(
  const interfaces_tutorial__msg__Sphere * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces_tutorial
size_t get_serialized_size_key_interfaces_tutorial__msg__Sphere(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces_tutorial
size_t max_serialized_size_key_interfaces_tutorial__msg__Sphere(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces_tutorial
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, msg, Sphere)();

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES_TUTORIAL__MSG__DETAIL__SPHERE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
