// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces_tutorial:action/Counter.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "interfaces_tutorial/action/counter.hpp"


#ifndef INTERFACES_TUTORIAL__ACTION__DETAIL__COUNTER__BUILDER_HPP_
#define INTERFACES_TUTORIAL__ACTION__DETAIL__COUNTER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces_tutorial/action/detail/counter__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces_tutorial
{

namespace action
{

namespace builder
{

class Init_Counter_Goal_range
{
public:
  Init_Counter_Goal_range()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces_tutorial::action::Counter_Goal range(::interfaces_tutorial::action::Counter_Goal::_range_type arg)
  {
    msg_.range = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces_tutorial::action::Counter_Goal>()
{
  return interfaces_tutorial::action::builder::Init_Counter_Goal_range();
}

}  // namespace interfaces_tutorial


namespace interfaces_tutorial
{

namespace action
{

namespace builder
{

class Init_Counter_Result_sequence
{
public:
  Init_Counter_Result_sequence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces_tutorial::action::Counter_Result sequence(::interfaces_tutorial::action::Counter_Result::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces_tutorial::action::Counter_Result>()
{
  return interfaces_tutorial::action::builder::Init_Counter_Result_sequence();
}

}  // namespace interfaces_tutorial


namespace interfaces_tutorial
{

namespace action
{

namespace builder
{

class Init_Counter_Feedback_partial_sequence
{
public:
  Init_Counter_Feedback_partial_sequence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces_tutorial::action::Counter_Feedback partial_sequence(::interfaces_tutorial::action::Counter_Feedback::_partial_sequence_type arg)
  {
    msg_.partial_sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces_tutorial::action::Counter_Feedback>()
{
  return interfaces_tutorial::action::builder::Init_Counter_Feedback_partial_sequence();
}

}  // namespace interfaces_tutorial


namespace interfaces_tutorial
{

namespace action
{

namespace builder
{

class Init_Counter_SendGoal_Request_goal
{
public:
  explicit Init_Counter_SendGoal_Request_goal(::interfaces_tutorial::action::Counter_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::interfaces_tutorial::action::Counter_SendGoal_Request goal(::interfaces_tutorial::action::Counter_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_SendGoal_Request msg_;
};

class Init_Counter_SendGoal_Request_goal_id
{
public:
  Init_Counter_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Counter_SendGoal_Request_goal goal_id(::interfaces_tutorial::action::Counter_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Counter_SendGoal_Request_goal(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces_tutorial::action::Counter_SendGoal_Request>()
{
  return interfaces_tutorial::action::builder::Init_Counter_SendGoal_Request_goal_id();
}

}  // namespace interfaces_tutorial


namespace interfaces_tutorial
{

namespace action
{

namespace builder
{

class Init_Counter_SendGoal_Response_stamp
{
public:
  explicit Init_Counter_SendGoal_Response_stamp(::interfaces_tutorial::action::Counter_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::interfaces_tutorial::action::Counter_SendGoal_Response stamp(::interfaces_tutorial::action::Counter_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_SendGoal_Response msg_;
};

class Init_Counter_SendGoal_Response_accepted
{
public:
  Init_Counter_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Counter_SendGoal_Response_stamp accepted(::interfaces_tutorial::action::Counter_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Counter_SendGoal_Response_stamp(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces_tutorial::action::Counter_SendGoal_Response>()
{
  return interfaces_tutorial::action::builder::Init_Counter_SendGoal_Response_accepted();
}

}  // namespace interfaces_tutorial


namespace interfaces_tutorial
{

namespace action
{

namespace builder
{

class Init_Counter_SendGoal_Event_response
{
public:
  explicit Init_Counter_SendGoal_Event_response(::interfaces_tutorial::action::Counter_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::interfaces_tutorial::action::Counter_SendGoal_Event response(::interfaces_tutorial::action::Counter_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_SendGoal_Event msg_;
};

class Init_Counter_SendGoal_Event_request
{
public:
  explicit Init_Counter_SendGoal_Event_request(::interfaces_tutorial::action::Counter_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_Counter_SendGoal_Event_response request(::interfaces_tutorial::action::Counter_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Counter_SendGoal_Event_response(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_SendGoal_Event msg_;
};

class Init_Counter_SendGoal_Event_info
{
public:
  Init_Counter_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Counter_SendGoal_Event_request info(::interfaces_tutorial::action::Counter_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Counter_SendGoal_Event_request(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces_tutorial::action::Counter_SendGoal_Event>()
{
  return interfaces_tutorial::action::builder::Init_Counter_SendGoal_Event_info();
}

}  // namespace interfaces_tutorial


namespace interfaces_tutorial
{

namespace action
{

namespace builder
{

class Init_Counter_GetResult_Request_goal_id
{
public:
  Init_Counter_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces_tutorial::action::Counter_GetResult_Request goal_id(::interfaces_tutorial::action::Counter_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces_tutorial::action::Counter_GetResult_Request>()
{
  return interfaces_tutorial::action::builder::Init_Counter_GetResult_Request_goal_id();
}

}  // namespace interfaces_tutorial


namespace interfaces_tutorial
{

namespace action
{

namespace builder
{

class Init_Counter_GetResult_Response_result
{
public:
  explicit Init_Counter_GetResult_Response_result(::interfaces_tutorial::action::Counter_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::interfaces_tutorial::action::Counter_GetResult_Response result(::interfaces_tutorial::action::Counter_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_GetResult_Response msg_;
};

class Init_Counter_GetResult_Response_status
{
public:
  Init_Counter_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Counter_GetResult_Response_result status(::interfaces_tutorial::action::Counter_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Counter_GetResult_Response_result(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces_tutorial::action::Counter_GetResult_Response>()
{
  return interfaces_tutorial::action::builder::Init_Counter_GetResult_Response_status();
}

}  // namespace interfaces_tutorial


namespace interfaces_tutorial
{

namespace action
{

namespace builder
{

class Init_Counter_GetResult_Event_response
{
public:
  explicit Init_Counter_GetResult_Event_response(::interfaces_tutorial::action::Counter_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::interfaces_tutorial::action::Counter_GetResult_Event response(::interfaces_tutorial::action::Counter_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_GetResult_Event msg_;
};

class Init_Counter_GetResult_Event_request
{
public:
  explicit Init_Counter_GetResult_Event_request(::interfaces_tutorial::action::Counter_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_Counter_GetResult_Event_response request(::interfaces_tutorial::action::Counter_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Counter_GetResult_Event_response(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_GetResult_Event msg_;
};

class Init_Counter_GetResult_Event_info
{
public:
  Init_Counter_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Counter_GetResult_Event_request info(::interfaces_tutorial::action::Counter_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Counter_GetResult_Event_request(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces_tutorial::action::Counter_GetResult_Event>()
{
  return interfaces_tutorial::action::builder::Init_Counter_GetResult_Event_info();
}

}  // namespace interfaces_tutorial


namespace interfaces_tutorial
{

namespace action
{

namespace builder
{

class Init_Counter_FeedbackMessage_feedback
{
public:
  explicit Init_Counter_FeedbackMessage_feedback(::interfaces_tutorial::action::Counter_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::interfaces_tutorial::action::Counter_FeedbackMessage feedback(::interfaces_tutorial::action::Counter_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_FeedbackMessage msg_;
};

class Init_Counter_FeedbackMessage_goal_id
{
public:
  Init_Counter_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Counter_FeedbackMessage_feedback goal_id(::interfaces_tutorial::action::Counter_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Counter_FeedbackMessage_feedback(msg_);
  }

private:
  ::interfaces_tutorial::action::Counter_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces_tutorial::action::Counter_FeedbackMessage>()
{
  return interfaces_tutorial::action::builder::Init_Counter_FeedbackMessage_goal_id();
}

}  // namespace interfaces_tutorial

#endif  // INTERFACES_TUTORIAL__ACTION__DETAIL__COUNTER__BUILDER_HPP_
