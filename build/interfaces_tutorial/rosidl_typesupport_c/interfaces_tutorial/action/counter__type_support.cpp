// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from interfaces_tutorial:action/Counter.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "interfaces_tutorial/action/detail/counter__struct.h"
#include "interfaces_tutorial/action/detail/counter__type_support.h"
#include "interfaces_tutorial/action/detail/counter__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Counter_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_Goal_type_support_ids_t;

static const _Counter_Goal_type_support_ids_t _Counter_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Counter_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Counter_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Counter_Goal_type_support_symbol_names_t _Counter_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, action, Counter_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces_tutorial, action, Counter_Goal)),
  }
};

typedef struct _Counter_Goal_type_support_data_t
{
  void * data[2];
} _Counter_Goal_type_support_data_t;

static _Counter_Goal_type_support_data_t _Counter_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Counter_Goal_message_typesupport_map = {
  2,
  "interfaces_tutorial",
  &_Counter_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Counter_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Counter_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Counter_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_Goal__get_type_hash,
  &interfaces_tutorial__action__Counter_Goal__get_type_description,
  &interfaces_tutorial__action__Counter_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces_tutorial

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces_tutorial, action, Counter_Goal)() {
  return &::interfaces_tutorial::action::rosidl_typesupport_c::Counter_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__type_support.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Counter_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_Result_type_support_ids_t;

static const _Counter_Result_type_support_ids_t _Counter_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Counter_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Counter_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Counter_Result_type_support_symbol_names_t _Counter_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, action, Counter_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces_tutorial, action, Counter_Result)),
  }
};

typedef struct _Counter_Result_type_support_data_t
{
  void * data[2];
} _Counter_Result_type_support_data_t;

static _Counter_Result_type_support_data_t _Counter_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Counter_Result_message_typesupport_map = {
  2,
  "interfaces_tutorial",
  &_Counter_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Counter_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Counter_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Counter_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_Result__get_type_hash,
  &interfaces_tutorial__action__Counter_Result__get_type_description,
  &interfaces_tutorial__action__Counter_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces_tutorial

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces_tutorial, action, Counter_Result)() {
  return &::interfaces_tutorial::action::rosidl_typesupport_c::Counter_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__type_support.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Counter_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_Feedback_type_support_ids_t;

static const _Counter_Feedback_type_support_ids_t _Counter_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Counter_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Counter_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Counter_Feedback_type_support_symbol_names_t _Counter_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, action, Counter_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces_tutorial, action, Counter_Feedback)),
  }
};

typedef struct _Counter_Feedback_type_support_data_t
{
  void * data[2];
} _Counter_Feedback_type_support_data_t;

static _Counter_Feedback_type_support_data_t _Counter_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Counter_Feedback_message_typesupport_map = {
  2,
  "interfaces_tutorial",
  &_Counter_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Counter_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Counter_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Counter_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_Feedback__get_type_hash,
  &interfaces_tutorial__action__Counter_Feedback__get_type_description,
  &interfaces_tutorial__action__Counter_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces_tutorial

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces_tutorial, action, Counter_Feedback)() {
  return &::interfaces_tutorial::action::rosidl_typesupport_c::Counter_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__type_support.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Counter_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_SendGoal_Request_type_support_ids_t;

static const _Counter_SendGoal_Request_type_support_ids_t _Counter_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Counter_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Counter_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Counter_SendGoal_Request_type_support_symbol_names_t _Counter_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, action, Counter_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces_tutorial, action, Counter_SendGoal_Request)),
  }
};

typedef struct _Counter_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Counter_SendGoal_Request_type_support_data_t;

static _Counter_SendGoal_Request_type_support_data_t _Counter_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Counter_SendGoal_Request_message_typesupport_map = {
  2,
  "interfaces_tutorial",
  &_Counter_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Counter_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Counter_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Counter_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_SendGoal_Request__get_type_hash,
  &interfaces_tutorial__action__Counter_SendGoal_Request__get_type_description,
  &interfaces_tutorial__action__Counter_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces_tutorial

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces_tutorial, action, Counter_SendGoal_Request)() {
  return &::interfaces_tutorial::action::rosidl_typesupport_c::Counter_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__type_support.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Counter_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_SendGoal_Response_type_support_ids_t;

static const _Counter_SendGoal_Response_type_support_ids_t _Counter_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Counter_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Counter_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Counter_SendGoal_Response_type_support_symbol_names_t _Counter_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, action, Counter_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces_tutorial, action, Counter_SendGoal_Response)),
  }
};

typedef struct _Counter_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Counter_SendGoal_Response_type_support_data_t;

static _Counter_SendGoal_Response_type_support_data_t _Counter_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Counter_SendGoal_Response_message_typesupport_map = {
  2,
  "interfaces_tutorial",
  &_Counter_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Counter_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Counter_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Counter_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_SendGoal_Response__get_type_hash,
  &interfaces_tutorial__action__Counter_SendGoal_Response__get_type_description,
  &interfaces_tutorial__action__Counter_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces_tutorial

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces_tutorial, action, Counter_SendGoal_Response)() {
  return &::interfaces_tutorial::action::rosidl_typesupport_c::Counter_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__type_support.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Counter_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_SendGoal_Event_type_support_ids_t;

static const _Counter_SendGoal_Event_type_support_ids_t _Counter_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Counter_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Counter_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Counter_SendGoal_Event_type_support_symbol_names_t _Counter_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, action, Counter_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces_tutorial, action, Counter_SendGoal_Event)),
  }
};

typedef struct _Counter_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _Counter_SendGoal_Event_type_support_data_t;

static _Counter_SendGoal_Event_type_support_data_t _Counter_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Counter_SendGoal_Event_message_typesupport_map = {
  2,
  "interfaces_tutorial",
  &_Counter_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Counter_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Counter_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Counter_SendGoal_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_SendGoal_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_SendGoal_Event__get_type_hash,
  &interfaces_tutorial__action__Counter_SendGoal_Event__get_type_description,
  &interfaces_tutorial__action__Counter_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces_tutorial

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces_tutorial, action, Counter_SendGoal_Event)() {
  return &::interfaces_tutorial::action::rosidl_typesupport_c::Counter_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_c
{
typedef struct _Counter_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_SendGoal_type_support_ids_t;

static const _Counter_SendGoal_type_support_ids_t _Counter_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Counter_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Counter_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Counter_SendGoal_type_support_symbol_names_t _Counter_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, action, Counter_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces_tutorial, action, Counter_SendGoal)),
  }
};

typedef struct _Counter_SendGoal_type_support_data_t
{
  void * data[2];
} _Counter_SendGoal_type_support_data_t;

static _Counter_SendGoal_type_support_data_t _Counter_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Counter_SendGoal_service_typesupport_map = {
  2,
  "interfaces_tutorial",
  &_Counter_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Counter_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Counter_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Counter_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &Counter_SendGoal_Request_message_type_support_handle,
  &Counter_SendGoal_Response_message_type_support_handle,
  &Counter_SendGoal_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    interfaces_tutorial,
    action,
    Counter_SendGoal
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    interfaces_tutorial,
    action,
    Counter_SendGoal
  ),
  &interfaces_tutorial__action__Counter_SendGoal__get_type_hash,
  &interfaces_tutorial__action__Counter_SendGoal__get_type_description,
  &interfaces_tutorial__action__Counter_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces_tutorial

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, interfaces_tutorial, action, Counter_SendGoal)() {
  return &::interfaces_tutorial::action::rosidl_typesupport_c::Counter_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__type_support.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Counter_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_GetResult_Request_type_support_ids_t;

static const _Counter_GetResult_Request_type_support_ids_t _Counter_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Counter_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Counter_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Counter_GetResult_Request_type_support_symbol_names_t _Counter_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, action, Counter_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces_tutorial, action, Counter_GetResult_Request)),
  }
};

typedef struct _Counter_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Counter_GetResult_Request_type_support_data_t;

static _Counter_GetResult_Request_type_support_data_t _Counter_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Counter_GetResult_Request_message_typesupport_map = {
  2,
  "interfaces_tutorial",
  &_Counter_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Counter_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Counter_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Counter_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_GetResult_Request__get_type_hash,
  &interfaces_tutorial__action__Counter_GetResult_Request__get_type_description,
  &interfaces_tutorial__action__Counter_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces_tutorial

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces_tutorial, action, Counter_GetResult_Request)() {
  return &::interfaces_tutorial::action::rosidl_typesupport_c::Counter_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__type_support.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Counter_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_GetResult_Response_type_support_ids_t;

static const _Counter_GetResult_Response_type_support_ids_t _Counter_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Counter_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Counter_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Counter_GetResult_Response_type_support_symbol_names_t _Counter_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, action, Counter_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces_tutorial, action, Counter_GetResult_Response)),
  }
};

typedef struct _Counter_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Counter_GetResult_Response_type_support_data_t;

static _Counter_GetResult_Response_type_support_data_t _Counter_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Counter_GetResult_Response_message_typesupport_map = {
  2,
  "interfaces_tutorial",
  &_Counter_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Counter_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Counter_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Counter_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_GetResult_Response__get_type_hash,
  &interfaces_tutorial__action__Counter_GetResult_Response__get_type_description,
  &interfaces_tutorial__action__Counter_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces_tutorial

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces_tutorial, action, Counter_GetResult_Response)() {
  return &::interfaces_tutorial::action::rosidl_typesupport_c::Counter_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__type_support.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Counter_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_GetResult_Event_type_support_ids_t;

static const _Counter_GetResult_Event_type_support_ids_t _Counter_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Counter_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Counter_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Counter_GetResult_Event_type_support_symbol_names_t _Counter_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, action, Counter_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces_tutorial, action, Counter_GetResult_Event)),
  }
};

typedef struct _Counter_GetResult_Event_type_support_data_t
{
  void * data[2];
} _Counter_GetResult_Event_type_support_data_t;

static _Counter_GetResult_Event_type_support_data_t _Counter_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Counter_GetResult_Event_message_typesupport_map = {
  2,
  "interfaces_tutorial",
  &_Counter_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Counter_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Counter_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Counter_GetResult_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_GetResult_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_GetResult_Event__get_type_hash,
  &interfaces_tutorial__action__Counter_GetResult_Event__get_type_description,
  &interfaces_tutorial__action__Counter_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces_tutorial

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces_tutorial, action, Counter_GetResult_Event)() {
  return &::interfaces_tutorial::action::rosidl_typesupport_c::Counter_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "service_msgs/msg/service_event_info.h"
// already included above
// #include "builtin_interfaces/msg/time.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_c
{
typedef struct _Counter_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_GetResult_type_support_ids_t;

static const _Counter_GetResult_type_support_ids_t _Counter_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Counter_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Counter_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Counter_GetResult_type_support_symbol_names_t _Counter_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, action, Counter_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces_tutorial, action, Counter_GetResult)),
  }
};

typedef struct _Counter_GetResult_type_support_data_t
{
  void * data[2];
} _Counter_GetResult_type_support_data_t;

static _Counter_GetResult_type_support_data_t _Counter_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Counter_GetResult_service_typesupport_map = {
  2,
  "interfaces_tutorial",
  &_Counter_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Counter_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Counter_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Counter_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &Counter_GetResult_Request_message_type_support_handle,
  &Counter_GetResult_Response_message_type_support_handle,
  &Counter_GetResult_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    interfaces_tutorial,
    action,
    Counter_GetResult
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    interfaces_tutorial,
    action,
    Counter_GetResult
  ),
  &interfaces_tutorial__action__Counter_GetResult__get_type_hash,
  &interfaces_tutorial__action__Counter_GetResult__get_type_description,
  &interfaces_tutorial__action__Counter_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces_tutorial

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, interfaces_tutorial, action, Counter_GetResult)() {
  return &::interfaces_tutorial::action::rosidl_typesupport_c::Counter_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__type_support.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Counter_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_FeedbackMessage_type_support_ids_t;

static const _Counter_FeedbackMessage_type_support_ids_t _Counter_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Counter_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Counter_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Counter_FeedbackMessage_type_support_symbol_names_t _Counter_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces_tutorial, action, Counter_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces_tutorial, action, Counter_FeedbackMessage)),
  }
};

typedef struct _Counter_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Counter_FeedbackMessage_type_support_data_t;

static _Counter_FeedbackMessage_type_support_data_t _Counter_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Counter_FeedbackMessage_message_typesupport_map = {
  2,
  "interfaces_tutorial",
  &_Counter_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Counter_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Counter_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Counter_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_FeedbackMessage__get_type_hash,
  &interfaces_tutorial__action__Counter_FeedbackMessage__get_type_description,
  &interfaces_tutorial__action__Counter_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces_tutorial

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces_tutorial, action, Counter_FeedbackMessage)() {
  return &::interfaces_tutorial::action::rosidl_typesupport_c::Counter_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "interfaces_tutorial/action/counter.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__type_support.h"

static rosidl_action_type_support_t _interfaces_tutorial__action__Counter__typesupport_c = {
  NULL, NULL, NULL, NULL, NULL,
  &interfaces_tutorial__action__Counter__get_type_hash,
  &interfaces_tutorial__action__Counter__get_type_description,
  &interfaces_tutorial__action__Counter__get_type_description_sources,
};

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, interfaces_tutorial, action, Counter)()
{
  // Thread-safe by always writing the same values to the static struct
  _interfaces_tutorial__action__Counter__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, interfaces_tutorial, action, Counter_SendGoal)();
  _interfaces_tutorial__action__Counter__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, interfaces_tutorial, action, Counter_GetResult)();
  _interfaces_tutorial__action__Counter__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _interfaces_tutorial__action__Counter__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, interfaces_tutorial, action, Counter_FeedbackMessage)();
  _interfaces_tutorial__action__Counter__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_interfaces_tutorial__action__Counter__typesupport_c;
}

#ifdef __cplusplus
}
#endif
