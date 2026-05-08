// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces_tutorial:action/Counter.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces_tutorial/action/counter.h"


#ifndef INTERFACES_TUTORIAL__ACTION__DETAIL__COUNTER__STRUCT_H_
#define INTERFACES_TUTORIAL__ACTION__DETAIL__COUNTER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Counter in the package interfaces_tutorial.
typedef struct interfaces_tutorial__action__Counter_Goal
{
  int32_t range;
} interfaces_tutorial__action__Counter_Goal;

// Struct for a sequence of interfaces_tutorial__action__Counter_Goal.
typedef struct interfaces_tutorial__action__Counter_Goal__Sequence
{
  interfaces_tutorial__action__Counter_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces_tutorial__action__Counter_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'sequence'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/Counter in the package interfaces_tutorial.
typedef struct interfaces_tutorial__action__Counter_Result
{
  rosidl_runtime_c__int32__Sequence sequence;
} interfaces_tutorial__action__Counter_Result;

// Struct for a sequence of interfaces_tutorial__action__Counter_Result.
typedef struct interfaces_tutorial__action__Counter_Result__Sequence
{
  interfaces_tutorial__action__Counter_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces_tutorial__action__Counter_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'partial_sequence'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/Counter in the package interfaces_tutorial.
typedef struct interfaces_tutorial__action__Counter_Feedback
{
  rosidl_runtime_c__int32__Sequence partial_sequence;
} interfaces_tutorial__action__Counter_Feedback;

// Struct for a sequence of interfaces_tutorial__action__Counter_Feedback.
typedef struct interfaces_tutorial__action__Counter_Feedback__Sequence
{
  interfaces_tutorial__action__Counter_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces_tutorial__action__Counter_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "interfaces_tutorial/action/detail/counter__struct.h"

/// Struct defined in action/Counter in the package interfaces_tutorial.
typedef struct interfaces_tutorial__action__Counter_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  interfaces_tutorial__action__Counter_Goal goal;
} interfaces_tutorial__action__Counter_SendGoal_Request;

// Struct for a sequence of interfaces_tutorial__action__Counter_SendGoal_Request.
typedef struct interfaces_tutorial__action__Counter_SendGoal_Request__Sequence
{
  interfaces_tutorial__action__Counter_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces_tutorial__action__Counter_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Counter in the package interfaces_tutorial.
typedef struct interfaces_tutorial__action__Counter_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} interfaces_tutorial__action__Counter_SendGoal_Response;

// Struct for a sequence of interfaces_tutorial__action__Counter_SendGoal_Response.
typedef struct interfaces_tutorial__action__Counter_SendGoal_Response__Sequence
{
  interfaces_tutorial__action__Counter_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces_tutorial__action__Counter_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  interfaces_tutorial__action__Counter_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  interfaces_tutorial__action__Counter_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Counter in the package interfaces_tutorial.
typedef struct interfaces_tutorial__action__Counter_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  interfaces_tutorial__action__Counter_SendGoal_Request__Sequence request;
  interfaces_tutorial__action__Counter_SendGoal_Response__Sequence response;
} interfaces_tutorial__action__Counter_SendGoal_Event;

// Struct for a sequence of interfaces_tutorial__action__Counter_SendGoal_Event.
typedef struct interfaces_tutorial__action__Counter_SendGoal_Event__Sequence
{
  interfaces_tutorial__action__Counter_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces_tutorial__action__Counter_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Counter in the package interfaces_tutorial.
typedef struct interfaces_tutorial__action__Counter_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} interfaces_tutorial__action__Counter_GetResult_Request;

// Struct for a sequence of interfaces_tutorial__action__Counter_GetResult_Request.
typedef struct interfaces_tutorial__action__Counter_GetResult_Request__Sequence
{
  interfaces_tutorial__action__Counter_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces_tutorial__action__Counter_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.h"

/// Struct defined in action/Counter in the package interfaces_tutorial.
typedef struct interfaces_tutorial__action__Counter_GetResult_Response
{
  int8_t status;
  interfaces_tutorial__action__Counter_Result result;
} interfaces_tutorial__action__Counter_GetResult_Response;

// Struct for a sequence of interfaces_tutorial__action__Counter_GetResult_Response.
typedef struct interfaces_tutorial__action__Counter_GetResult_Response__Sequence
{
  interfaces_tutorial__action__Counter_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces_tutorial__action__Counter_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  interfaces_tutorial__action__Counter_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  interfaces_tutorial__action__Counter_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Counter in the package interfaces_tutorial.
typedef struct interfaces_tutorial__action__Counter_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  interfaces_tutorial__action__Counter_GetResult_Request__Sequence request;
  interfaces_tutorial__action__Counter_GetResult_Response__Sequence response;
} interfaces_tutorial__action__Counter_GetResult_Event;

// Struct for a sequence of interfaces_tutorial__action__Counter_GetResult_Event.
typedef struct interfaces_tutorial__action__Counter_GetResult_Event__Sequence
{
  interfaces_tutorial__action__Counter_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces_tutorial__action__Counter_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.h"

/// Struct defined in action/Counter in the package interfaces_tutorial.
typedef struct interfaces_tutorial__action__Counter_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  interfaces_tutorial__action__Counter_Feedback feedback;
} interfaces_tutorial__action__Counter_FeedbackMessage;

// Struct for a sequence of interfaces_tutorial__action__Counter_FeedbackMessage.
typedef struct interfaces_tutorial__action__Counter_FeedbackMessage__Sequence
{
  interfaces_tutorial__action__Counter_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces_tutorial__action__Counter_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES_TUTORIAL__ACTION__DETAIL__COUNTER__STRUCT_H_
