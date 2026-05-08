// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from interfaces_tutorial:action/Counter.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "interfaces_tutorial/action/detail/counter__functions.h"
#include "interfaces_tutorial/action/detail/counter__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Counter_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_Goal_type_support_ids_t;

static const _Counter_Goal_type_support_ids_t _Counter_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces_tutorial, action, Counter_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces_tutorial, action, Counter_Goal)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_Goal__get_type_hash,
  &interfaces_tutorial__action__Counter_Goal__get_type_description,
  &interfaces_tutorial__action__Counter_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces_tutorial::action::Counter_Goal>()
{
  return &::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter_Goal)() {
  return get_message_type_support_handle<interfaces_tutorial::action::Counter_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Counter_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_Result_type_support_ids_t;

static const _Counter_Result_type_support_ids_t _Counter_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces_tutorial, action, Counter_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces_tutorial, action, Counter_Result)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_Result__get_type_hash,
  &interfaces_tutorial__action__Counter_Result__get_type_description,
  &interfaces_tutorial__action__Counter_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces_tutorial::action::Counter_Result>()
{
  return &::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter_Result)() {
  return get_message_type_support_handle<interfaces_tutorial::action::Counter_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Counter_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_Feedback_type_support_ids_t;

static const _Counter_Feedback_type_support_ids_t _Counter_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces_tutorial, action, Counter_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces_tutorial, action, Counter_Feedback)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_Feedback__get_type_hash,
  &interfaces_tutorial__action__Counter_Feedback__get_type_description,
  &interfaces_tutorial__action__Counter_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces_tutorial::action::Counter_Feedback>()
{
  return &::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter_Feedback)() {
  return get_message_type_support_handle<interfaces_tutorial::action::Counter_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Counter_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_SendGoal_Request_type_support_ids_t;

static const _Counter_SendGoal_Request_type_support_ids_t _Counter_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces_tutorial, action, Counter_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces_tutorial, action, Counter_SendGoal_Request)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_SendGoal_Request__get_type_hash,
  &interfaces_tutorial__action__Counter_SendGoal_Request__get_type_description,
  &interfaces_tutorial__action__Counter_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces_tutorial::action::Counter_SendGoal_Request>()
{
  return &::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter_SendGoal_Request)() {
  return get_message_type_support_handle<interfaces_tutorial::action::Counter_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Counter_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_SendGoal_Response_type_support_ids_t;

static const _Counter_SendGoal_Response_type_support_ids_t _Counter_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces_tutorial, action, Counter_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces_tutorial, action, Counter_SendGoal_Response)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_SendGoal_Response__get_type_hash,
  &interfaces_tutorial__action__Counter_SendGoal_Response__get_type_description,
  &interfaces_tutorial__action__Counter_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces_tutorial::action::Counter_SendGoal_Response>()
{
  return &::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter_SendGoal_Response)() {
  return get_message_type_support_handle<interfaces_tutorial::action::Counter_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Counter_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_SendGoal_Event_type_support_ids_t;

static const _Counter_SendGoal_Event_type_support_ids_t _Counter_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces_tutorial, action, Counter_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces_tutorial, action, Counter_SendGoal_Event)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_SendGoal_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_SendGoal_Event__get_type_hash,
  &interfaces_tutorial__action__Counter_SendGoal_Event__get_type_description,
  &interfaces_tutorial__action__Counter_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces_tutorial::action::Counter_SendGoal_Event>()
{
  return &::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter_SendGoal_Event)() {
  return get_message_type_support_handle<interfaces_tutorial::action::Counter_SendGoal_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Counter_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_SendGoal_type_support_ids_t;

static const _Counter_SendGoal_type_support_ids_t _Counter_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces_tutorial, action, Counter_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces_tutorial, action, Counter_SendGoal)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<interfaces_tutorial::action::Counter_SendGoal_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<interfaces_tutorial::action::Counter_SendGoal_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<interfaces_tutorial::action::Counter_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<interfaces_tutorial::action::Counter_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<interfaces_tutorial::action::Counter_SendGoal>,
  &interfaces_tutorial__action__Counter_SendGoal__get_type_hash,
  &interfaces_tutorial__action__Counter_SendGoal__get_type_description,
  &interfaces_tutorial__action__Counter_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<interfaces_tutorial::action::Counter_SendGoal>()
{
  return &::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<interfaces_tutorial::action::Counter_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Counter_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_GetResult_Request_type_support_ids_t;

static const _Counter_GetResult_Request_type_support_ids_t _Counter_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces_tutorial, action, Counter_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces_tutorial, action, Counter_GetResult_Request)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_GetResult_Request__get_type_hash,
  &interfaces_tutorial__action__Counter_GetResult_Request__get_type_description,
  &interfaces_tutorial__action__Counter_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces_tutorial::action::Counter_GetResult_Request>()
{
  return &::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter_GetResult_Request)() {
  return get_message_type_support_handle<interfaces_tutorial::action::Counter_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Counter_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_GetResult_Response_type_support_ids_t;

static const _Counter_GetResult_Response_type_support_ids_t _Counter_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces_tutorial, action, Counter_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces_tutorial, action, Counter_GetResult_Response)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_GetResult_Response__get_type_hash,
  &interfaces_tutorial__action__Counter_GetResult_Response__get_type_description,
  &interfaces_tutorial__action__Counter_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces_tutorial::action::Counter_GetResult_Response>()
{
  return &::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter_GetResult_Response)() {
  return get_message_type_support_handle<interfaces_tutorial::action::Counter_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Counter_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_GetResult_Event_type_support_ids_t;

static const _Counter_GetResult_Event_type_support_ids_t _Counter_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces_tutorial, action, Counter_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces_tutorial, action, Counter_GetResult_Event)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_GetResult_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_GetResult_Event__get_type_hash,
  &interfaces_tutorial__action__Counter_GetResult_Event__get_type_description,
  &interfaces_tutorial__action__Counter_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces_tutorial::action::Counter_GetResult_Event>()
{
  return &::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter_GetResult_Event)() {
  return get_message_type_support_handle<interfaces_tutorial::action::Counter_GetResult_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Counter_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_GetResult_type_support_ids_t;

static const _Counter_GetResult_type_support_ids_t _Counter_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces_tutorial, action, Counter_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces_tutorial, action, Counter_GetResult)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<interfaces_tutorial::action::Counter_GetResult_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<interfaces_tutorial::action::Counter_GetResult_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<interfaces_tutorial::action::Counter_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<interfaces_tutorial::action::Counter_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<interfaces_tutorial::action::Counter_GetResult>,
  &interfaces_tutorial__action__Counter_GetResult__get_type_hash,
  &interfaces_tutorial__action__Counter_GetResult__get_type_description,
  &interfaces_tutorial__action__Counter_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<interfaces_tutorial::action::Counter_GetResult>()
{
  return &::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<interfaces_tutorial::action::Counter_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__functions.h"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Counter_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Counter_FeedbackMessage_type_support_ids_t;

static const _Counter_FeedbackMessage_type_support_ids_t _Counter_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces_tutorial, action, Counter_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, interfaces_tutorial, action, Counter_FeedbackMessage)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Counter_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &interfaces_tutorial__action__Counter_FeedbackMessage__get_type_hash,
  &interfaces_tutorial__action__Counter_FeedbackMessage__get_type_description,
  &interfaces_tutorial__action__Counter_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces_tutorial::action::Counter_FeedbackMessage>()
{
  return &::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter_FeedbackMessage)() {
  return get_message_type_support_handle<interfaces_tutorial::action::Counter_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "interfaces_tutorial/action/detail/counter__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace interfaces_tutorial
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t Counter_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL,
  &interfaces_tutorial__action__Counter__get_type_hash,
  &interfaces_tutorial__action__Counter__get_type_description,
  &interfaces_tutorial__action__Counter__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace interfaces_tutorial

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<interfaces_tutorial::action::Counter>()
{
  using ::interfaces_tutorial::action::rosidl_typesupport_cpp::Counter_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  Counter_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::interfaces_tutorial::action::Counter::Impl::SendGoalService>();
  Counter_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::interfaces_tutorial::action::Counter::Impl::GetResultService>();
  Counter_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::interfaces_tutorial::action::Counter::Impl::CancelGoalService>();
  Counter_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::interfaces_tutorial::action::Counter::Impl::FeedbackMessage>();
  Counter_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::interfaces_tutorial::action::Counter::Impl::GoalStatusMessage>();
  return &Counter_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, interfaces_tutorial, action, Counter)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<interfaces_tutorial::action::Counter>();
}

#ifdef __cplusplus
}
#endif
