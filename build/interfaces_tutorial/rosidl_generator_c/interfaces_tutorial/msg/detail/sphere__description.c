// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from interfaces_tutorial:msg/Sphere.idl
// generated code does not contain a copyright notice

#include "interfaces_tutorial/msg/detail/sphere__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_interfaces_tutorial
const rosidl_type_hash_t *
interfaces_tutorial__msg__Sphere__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x30, 0x0b, 0x0e, 0xef, 0x43, 0xd5, 0x01, 0xa5,
      0x47, 0x6f, 0x0d, 0x55, 0x61, 0xbe, 0x43, 0x8a,
      0x7e, 0x25, 0x6c, 0x24, 0x32, 0x54, 0xbc, 0xff,
      0x4c, 0x8d, 0x1f, 0x3e, 0xbe, 0xe8, 0x45, 0x64,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
#endif

static char interfaces_tutorial__msg__Sphere__TYPE_NAME[] = "interfaces_tutorial/msg/Sphere";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";

// Define type names, field names, and default values
static char interfaces_tutorial__msg__Sphere__FIELD_NAME__center[] = "center";
static char interfaces_tutorial__msg__Sphere__FIELD_NAME__radius[] = "radius";

static rosidl_runtime_c__type_description__Field interfaces_tutorial__msg__Sphere__FIELDS[] = {
  {
    {interfaces_tutorial__msg__Sphere__FIELD_NAME__center, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
  {
    {interfaces_tutorial__msg__Sphere__FIELD_NAME__radius, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription interfaces_tutorial__msg__Sphere__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
interfaces_tutorial__msg__Sphere__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {interfaces_tutorial__msg__Sphere__TYPE_NAME, 30, 30},
      {interfaces_tutorial__msg__Sphere__FIELDS, 2, 2},
    },
    {interfaces_tutorial__msg__Sphere__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "geometry_msgs/Point center\n"
  "float64 radius";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
interfaces_tutorial__msg__Sphere__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {interfaces_tutorial__msg__Sphere__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 41, 41},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
interfaces_tutorial__msg__Sphere__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *interfaces_tutorial__msg__Sphere__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
