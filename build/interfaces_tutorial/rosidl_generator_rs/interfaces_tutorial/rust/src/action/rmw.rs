
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "interfaces_tutorial__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_Goal() -> *const std::ffi::c_void;
}

#[link(name = "interfaces_tutorial__rosidl_generator_c")]
extern "C" {
    fn interfaces_tutorial__action__Counter_Goal__init(msg: *mut Counter_Goal) -> bool;
    fn interfaces_tutorial__action__Counter_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Counter_Goal>, size: usize) -> bool;
    fn interfaces_tutorial__action__Counter_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Counter_Goal>);
    fn interfaces_tutorial__action__Counter_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Counter_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Counter_Goal>) -> bool;
}

// Corresponds to interfaces_tutorial__action__Counter_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Counter_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub range: i32,

}



impl Default for Counter_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces_tutorial__action__Counter_Goal__init(&mut msg as *mut _) {
        panic!("Call to interfaces_tutorial__action__Counter_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Counter_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Counter_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Counter_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces_tutorial/action/Counter_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_Goal() }
  }
}


#[link(name = "interfaces_tutorial__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_Result() -> *const std::ffi::c_void;
}

#[link(name = "interfaces_tutorial__rosidl_generator_c")]
extern "C" {
    fn interfaces_tutorial__action__Counter_Result__init(msg: *mut Counter_Result) -> bool;
    fn interfaces_tutorial__action__Counter_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Counter_Result>, size: usize) -> bool;
    fn interfaces_tutorial__action__Counter_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Counter_Result>);
    fn interfaces_tutorial__action__Counter_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Counter_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Counter_Result>) -> bool;
}

// Corresponds to interfaces_tutorial__action__Counter_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Counter_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sequence: rosidl_runtime_rs::Sequence<i32>,

}



impl Default for Counter_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces_tutorial__action__Counter_Result__init(&mut msg as *mut _) {
        panic!("Call to interfaces_tutorial__action__Counter_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Counter_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Counter_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Counter_Result where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces_tutorial/action/Counter_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_Result() }
  }
}


#[link(name = "interfaces_tutorial__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "interfaces_tutorial__rosidl_generator_c")]
extern "C" {
    fn interfaces_tutorial__action__Counter_Feedback__init(msg: *mut Counter_Feedback) -> bool;
    fn interfaces_tutorial__action__Counter_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Counter_Feedback>, size: usize) -> bool;
    fn interfaces_tutorial__action__Counter_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Counter_Feedback>);
    fn interfaces_tutorial__action__Counter_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Counter_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Counter_Feedback>) -> bool;
}

// Corresponds to interfaces_tutorial__action__Counter_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Counter_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub partial_sequence: rosidl_runtime_rs::Sequence<i32>,

}



impl Default for Counter_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces_tutorial__action__Counter_Feedback__init(&mut msg as *mut _) {
        panic!("Call to interfaces_tutorial__action__Counter_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Counter_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Counter_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Counter_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces_tutorial/action/Counter_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_Feedback() }
  }
}


#[link(name = "interfaces_tutorial__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "interfaces_tutorial__rosidl_generator_c")]
extern "C" {
    fn interfaces_tutorial__action__Counter_FeedbackMessage__init(msg: *mut Counter_FeedbackMessage) -> bool;
    fn interfaces_tutorial__action__Counter_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Counter_FeedbackMessage>, size: usize) -> bool;
    fn interfaces_tutorial__action__Counter_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Counter_FeedbackMessage>);
    fn interfaces_tutorial__action__Counter_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Counter_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Counter_FeedbackMessage>) -> bool;
}

// Corresponds to interfaces_tutorial__action__Counter_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Counter_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Counter_Feedback,

}



impl Default for Counter_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces_tutorial__action__Counter_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to interfaces_tutorial__action__Counter_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Counter_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Counter_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Counter_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces_tutorial/action/Counter_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_FeedbackMessage() }
  }
}




#[link(name = "interfaces_tutorial__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "interfaces_tutorial__rosidl_generator_c")]
extern "C" {
    fn interfaces_tutorial__action__Counter_SendGoal_Request__init(msg: *mut Counter_SendGoal_Request) -> bool;
    fn interfaces_tutorial__action__Counter_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Counter_SendGoal_Request>, size: usize) -> bool;
    fn interfaces_tutorial__action__Counter_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Counter_SendGoal_Request>);
    fn interfaces_tutorial__action__Counter_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Counter_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Counter_SendGoal_Request>) -> bool;
}

// Corresponds to interfaces_tutorial__action__Counter_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Counter_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Counter_Goal,

}



impl Default for Counter_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces_tutorial__action__Counter_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to interfaces_tutorial__action__Counter_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Counter_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Counter_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Counter_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces_tutorial/action/Counter_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_SendGoal_Request() }
  }
}


#[link(name = "interfaces_tutorial__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "interfaces_tutorial__rosidl_generator_c")]
extern "C" {
    fn interfaces_tutorial__action__Counter_SendGoal_Response__init(msg: *mut Counter_SendGoal_Response) -> bool;
    fn interfaces_tutorial__action__Counter_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Counter_SendGoal_Response>, size: usize) -> bool;
    fn interfaces_tutorial__action__Counter_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Counter_SendGoal_Response>);
    fn interfaces_tutorial__action__Counter_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Counter_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Counter_SendGoal_Response>) -> bool;
}

// Corresponds to interfaces_tutorial__action__Counter_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Counter_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Counter_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces_tutorial__action__Counter_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to interfaces_tutorial__action__Counter_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Counter_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Counter_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Counter_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces_tutorial/action/Counter_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_SendGoal_Response() }
  }
}


#[link(name = "interfaces_tutorial__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "interfaces_tutorial__rosidl_generator_c")]
extern "C" {
    fn interfaces_tutorial__action__Counter_GetResult_Request__init(msg: *mut Counter_GetResult_Request) -> bool;
    fn interfaces_tutorial__action__Counter_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Counter_GetResult_Request>, size: usize) -> bool;
    fn interfaces_tutorial__action__Counter_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Counter_GetResult_Request>);
    fn interfaces_tutorial__action__Counter_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Counter_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Counter_GetResult_Request>) -> bool;
}

// Corresponds to interfaces_tutorial__action__Counter_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Counter_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Counter_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces_tutorial__action__Counter_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to interfaces_tutorial__action__Counter_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Counter_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Counter_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Counter_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces_tutorial/action/Counter_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_GetResult_Request() }
  }
}


#[link(name = "interfaces_tutorial__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "interfaces_tutorial__rosidl_generator_c")]
extern "C" {
    fn interfaces_tutorial__action__Counter_GetResult_Response__init(msg: *mut Counter_GetResult_Response) -> bool;
    fn interfaces_tutorial__action__Counter_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Counter_GetResult_Response>, size: usize) -> bool;
    fn interfaces_tutorial__action__Counter_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Counter_GetResult_Response>);
    fn interfaces_tutorial__action__Counter_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Counter_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Counter_GetResult_Response>) -> bool;
}

// Corresponds to interfaces_tutorial__action__Counter_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Counter_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Counter_Result,

}



impl Default for Counter_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !interfaces_tutorial__action__Counter_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to interfaces_tutorial__action__Counter_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Counter_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { interfaces_tutorial__action__Counter_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Counter_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Counter_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "interfaces_tutorial/action/Counter_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__interfaces_tutorial__action__Counter_GetResult_Response() }
  }
}






#[link(name = "interfaces_tutorial__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__interfaces_tutorial__action__Counter_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to interfaces_tutorial__action__Counter_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Counter_SendGoal;

impl rosidl_runtime_rs::Service for Counter_SendGoal {
    type Request = Counter_SendGoal_Request;
    type Response = Counter_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__interfaces_tutorial__action__Counter_SendGoal() }
    }
}




#[link(name = "interfaces_tutorial__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__interfaces_tutorial__action__Counter_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to interfaces_tutorial__action__Counter_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Counter_GetResult;

impl rosidl_runtime_rs::Service for Counter_GetResult {
    type Request = Counter_GetResult_Request;
    type Response = Counter_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__interfaces_tutorial__action__Counter_GetResult() }
    }
}


