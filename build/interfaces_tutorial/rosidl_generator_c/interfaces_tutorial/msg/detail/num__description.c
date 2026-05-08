// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from interfaces_tutorial:msg/Num.idl
// generated code does not contain a copyright notice

#include "interfaces_tutorial/msg/detail/num__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_interfaces_tutorial
const rosidl_type_hash_t *
interfaces_tutorial__msg__Num__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd9, 0x37, 0x79, 0x71, 0x89, 0x63, 0xc7, 0x52,
      0x8f, 0x2e, 0x22, 0x93, 0x39, 0x0b, 0xc2, 0x62,
      0xb3, 0x03, 0x38, 0x90, 0x7c, 0x3b, 0xf5, 0xce,
      0xb9, 0x5e, 0xd8, 0x1e, 0xc6, 0x2b, 0xf5, 0xc9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char interfaces_tutorial__msg__Num__TYPE_NAME[] = "interfaces_tutorial/msg/Num";

// Define type names, field names, and default values
static char interfaces_tutorial__msg__Num__FIELD_NAME__num[] = "num";

static rosidl_runtime_c__type_description__Field interfaces_tutorial__msg__Num__FIELDS[] = {
  {
    {interfaces_tutorial__msg__Num__FIELD_NAME__num, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
interfaces_tutorial__msg__Num__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {interfaces_tutorial__msg__Num__TYPE_NAME, 27, 27},
      {interfaces_tutorial__msg__Num__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int64 num";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
interfaces_tutorial__msg__Num__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {interfaces_tutorial__msg__Num__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 9, 9},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
interfaces_tutorial__msg__Num__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *interfaces_tutorial__msg__Num__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
