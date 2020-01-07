#ifndef SPVM_CSOURCE_BUILDER_PRECOMPILE_H
#define SPVM_CSOURCE_BUILDER_PRECOMPILE_H
#include <spvm_native.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <complex.h>
#define SPVM_RUNTIME_API_GET_OBJECT_NO_WEAKEN_ADDRESS(object) ((void*)((intptr_t)object & ~(intptr_t)1))
#define SPVM_RUNTIME_API_GET_REF_COUNT(object) ((*(int32_t*)((intptr_t)object + (intptr_t)env->object_ref_count_offset)))
#define SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object) ((*(int32_t*)((intptr_t)object + (intptr_t)env->object_ref_count_offset))++)
#define SPVM_RUNTIME_API_INC_REF_COUNT(object)\
do {\
  if (object != NULL) {\
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object);\
  }\
} while (0)\

#define SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(object) ((*(int32_t*)((intptr_t)object + (intptr_t)env->object_ref_count_offset))--)
#define SPVM_RUNTIME_API_DEC_REF_COUNT(object)\
do {\
  if (object != NULL) {\
    if (SPVM_RUNTIME_API_GET_REF_COUNT(object) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(object); }\
    else { env->dec_ref_count(env, object); }\
  }\
} while (0)\

#define SPVM_RUNTIME_API_ISWEAK(dist_address) (((intptr_t)*(void**)dist_address) & 1)

#define SPVM_RUNTIME_API_OBJECT_ASSIGN(dist_address, src_object) \
do {\
  void* tmp_object = SPVM_RUNTIME_API_GET_OBJECT_NO_WEAKEN_ADDRESS(src_object);\
  if (tmp_object != NULL) {\
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(tmp_object);\
  }\
  if (*(void**)(dist_address) != NULL) {\
    if (__builtin_expect(SPVM_RUNTIME_API_ISWEAK(dist_address), 0)) { env->unweaken(env, dist_address); }\
    if (SPVM_RUNTIME_API_GET_REF_COUNT(*(void**)(dist_address)) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*(void**)(dist_address)); }\
    else { env->dec_ref_count(env, *(void**)(dist_address)); }\
  }\
  *(void**)(dist_address) = tmp_object;\
} while (0)\

#endif
// Package variable id declarations
static int32_t VAR_PACKAGE_VAR_ID_SPVM__Webkit__JSON__Bool__FALSE = -1;
static int32_t VAR_PACKAGE_VAR_ID_SPVM__Webkit__JSON__Bool__TRUE = -1;
// Field id and index declarations
static int32_t FIELD_ID_SPVM__Webkit__JSON__canonical = -1;
static int32_t FIELD_BYTE_OFFSET_SPVM__Webkit__JSON__canonical = -1;
static int32_t FIELD_ID_SPVM__ObjectList__length = -1;
static int32_t FIELD_BYTE_OFFSET_SPVM__ObjectList__length = -1;
static int32_t FIELD_ID_SPVM__Byte__val = -1;
static int32_t FIELD_BYTE_OFFSET_SPVM__Byte__val = -1;
static int32_t FIELD_ID_SPVM__Short__val = -1;
static int32_t FIELD_BYTE_OFFSET_SPVM__Short__val = -1;
static int32_t FIELD_ID_SPVM__Int__val = -1;
static int32_t FIELD_BYTE_OFFSET_SPVM__Int__val = -1;
static int32_t FIELD_ID_SPVM__Long__val = -1;
static int32_t FIELD_BYTE_OFFSET_SPVM__Long__val = -1;
static int32_t FIELD_ID_SPVM__Float__val = -1;
static int32_t FIELD_BYTE_OFFSET_SPVM__Float__val = -1;
static int32_t FIELD_ID_SPVM__Double__val = -1;
static int32_t FIELD_BYTE_OFFSET_SPVM__Double__val = -1;
static int32_t FIELD_ID_SPVM__Webkit__JSON__Bool__val = -1;
static int32_t FIELD_BYTE_OFFSET_SPVM__Webkit__JSON__Bool__val = -1;
// Sub id declarations
static int32_t SUB_ID_SPVM__Util__substr = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___expect_token = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON__Bool__FALSE = - 1;
static int32_t SUB_ID_SPVM__Hash__new = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___expect_char = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___skip_spaces = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___decode_error = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___decode_string = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___decode_recursive = - 1;
static int32_t SUB_ID_SPVM__Hash__set = - 1;
static int32_t SUB_ID_SPVM__ObjectList__new = - 1;
static int32_t SUB_ID_SPVM__ObjectList__push = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON__DECODE_NUM_BEGIN = - 1;
static int32_t SUB_ID_SPVM__Util__isdigit = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON__DECODE_NUM_LEADING_DIGIT = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON__DECODE_NUM_END = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON__DECODE_NUM_DOT = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON__DECODE_NUM_EXP = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON__DECODE_NUM_EXP_SIGN = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON__DECODE_NUM_EXP_DIGIT = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON__DECODE_NUM_FRAC = - 1;
static int32_t SUB_ID_SPVM__Util__strtod = - 1;
static int32_t SUB_ID_SPVM__Double__new = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___decode_hash = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___decode_list = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___decode_num = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___decode_true = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___decode_false = - 1;
static int32_t SUB_ID_SPVM__StringBuffer__new = - 1;
static int32_t SUB_ID_SPVM__StringBuffer__push_char = - 1;
static int32_t SUB_ID_SPVM__StringBuffer__to_string = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON__Bool__TRUE = - 1;
static int32_t SUB_ID_SPVM__Hash__keys = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON__canonical = - 1;
static int32_t SUB_ID_SPVM__Sort__sortstr = - 1;
static int32_t SUB_ID_SPVM__StringBuffer__push = - 1;
static int32_t SUB_ID_SPVM__Hash__get = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___encode_recursive = - 1;
static int32_t SUB_ID_SPVM__ObjectList__length = - 1;
static int32_t SUB_ID_SPVM__ObjectList__get = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON___escape_string = - 1;
static int32_t SUB_ID_SPVM__Byte__val = - 1;
static int32_t SUB_ID_SPVM__Short__val = - 1;
static int32_t SUB_ID_SPVM__Int__val = - 1;
static int32_t SUB_ID_SPVM__Long__val = - 1;
static int32_t SUB_ID_SPVM__Float__val = - 1;
static int32_t SUB_ID_SPVM__Double__val = - 1;
static int32_t SUB_ID_SPVM__Webkit__JSON__Bool__val = - 1;
// Basic type id declarations
static int32_t BASIC_TYPE_ID_byte = -1;
static int32_t BASIC_TYPE_ID_SPVM__Hash = -1;
static int32_t BASIC_TYPE_ID_SPVM__ObjectList = -1;
static int32_t BASIC_TYPE_ID_SPVM__Byte = -1;
static int32_t BASIC_TYPE_ID_SPVM__Short = -1;
static int32_t BASIC_TYPE_ID_SPVM__Int = -1;
static int32_t BASIC_TYPE_ID_SPVM__Long = -1;
static int32_t BASIC_TYPE_ID_SPVM__Float = -1;
static int32_t BASIC_TYPE_ID_SPVM__Double = -1;
static int32_t BASIC_TYPE_ID_SPVM__Webkit__JSON__Bool = -1;
static int32_t BASIC_TYPE_ID_SPVM__Webkit__JSON = -1;
// Function Declarations
// [SIG]void(string,string,int)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]SPVM::Webkit::JSON::Bool(self,string,&int)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_false(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]SPVM::Hash(self,string,&int)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_hash(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]SPVM::ObjectList(self,string,&int)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_list(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]object(self,string,&int)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_num(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]object(self,string,&int)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_recursive(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]string(self,string,&int)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_string(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]SPVM::Webkit::JSON::Bool(self,string,&int)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_true(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]string(self,object,int)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___encode_recursive(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]string(string)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___escape_string(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]void(string,&int,byte)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___expect_char(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]void(string,&int,string)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___expect_token(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]void(self,string,&int)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___skip_spaces(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]object(self,string)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON__decode(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]string(self,object)
int32_t SPPRECOMPILE__SPVM__Webkit__JSON__encode(SPVM_ENV* env, SPVM_VALUE* stack);

// [SIG]SPVM::Webkit::JSON()
int32_t SPPRECOMPILE__SPVM__Webkit__JSON__new(SPVM_ENV* env, SPVM_VALUE* stack);


// Function Implementations
int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[8] = {0};
  int32_t int_vars[7];
  int32_t exception_flag = 0;
  int32_t mortal_stack[13];
  int32_t mortal_stack_top = 0;
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  object_vars[1] = *(void**)&stack[1];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }
  int_vars[1] = *(int32_t*)&stack[2];

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // ARRAY_LENGTH
  if (object_vars[1] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[2] = *(int32_t*)((intptr_t)object_vars[1] + (intptr_t)env->object_length_offset);
  }
L4: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_error";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 16;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L5: // MOVE_CONSTANT_INT
  int_vars[4] = 10;
L6: // SUBTRACT_INT
  int_vars[5] = int_vars[2] - int_vars[1];
L7: // GT_INT
  int_vars[0] = (int_vars[4] > int_vars[5]);
L8: // BOOL_INT
  int_vars[0] = int_vars[0];
L9: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L12; }
L10: // SUBTRACT_INT
  int_vars[4] = int_vars[2] - int_vars[1];
L11: // GOTO
  goto L12;
L12: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L13: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "", 0));
L14: // MOVE_CONSTANT_INT
  int_vars[5] = 0;
L15: // GT_INT
  int_vars[0] = (int_vars[4] > int_vars[5]);
L16: // BOOL_INT
  int_vars[0] = int_vars[0];
L17: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L39; }
L18: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L19: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], env->new_string_len_raw(env, "\x6E\x65\x61\x72\x20\x27", 6));
L20: // SUBTRACT_INT
  int_vars[5] = int_vars[2] - int_vars[1];
L21: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 4;
  mortal_stack_top++;
L22: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L23: // PUSH_ARG_INT
  *(int32_t*)&stack[1] = int_vars[1];
L24: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[5];
L25: // CALL_SUB_OBJECT
  // SPVM::Util->substr
  {
    if (SUB_ID_SPVM__Util__substr < 0) {
      SUB_ID_SPVM__Util__substr = env->get_sub_id(env, "SPVM::Util", "substr", "string(string,int,int)");
      if (SUB_ID_SPVM__Util__substr < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Util substr");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Util__substr;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], stack[0].oval);
    }
  }
L26: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_error";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 23;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L27: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 5;
  mortal_stack_top++;
L28: // CONCAT
  {
    void* string1 = object_vars[3];
    void* string2 = object_vars[4];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], string3);
    }
  }
L29: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_error";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 23;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L30: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 6;
  mortal_stack_top++;
L31: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], env->new_string_len_raw(env, "\x27", 1));
L32: // CONCAT
  {
    void* string1 = object_vars[5];
    void* string2 = object_vars[6];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], string3);
    }
  }
L33: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_error";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 23;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L34: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], NULL);
L35: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], NULL);
L36: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], NULL);
L37: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L38: // GOTO
  goto L41;
L39: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L40: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x65\x6E\x64\x20\x6F\x66\x20\x73\x74\x72\x69\x6E\x67", 13));
L41: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L42: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L43: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], env->new_string_len_raw(env, "\x20\x2E\x2E\x2E\x20", 5));
L44: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 4;
  mortal_stack_top++;
L45: // CONCAT
  {
    void* string1 = object_vars[0];
    void* string2 = object_vars[3];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], string3);
    }
  }
L46: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_error";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 28;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L47: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 5;
  mortal_stack_top++;
L48: // CONCAT
  {
    void* string1 = object_vars[4];
    void* string2 = object_vars[2];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], string3);
    }
  }
L49: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_error";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 28;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L50: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 6;
  mortal_stack_top++;
L51: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], env->new_string_len_raw(env, "", 0));
L52: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 7;
  mortal_stack_top++;
L53: // CONCAT
  {
    void* string1 = object_vars[5];
    void* string2 = object_vars[6];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[7], string3);
    }
  }
L54: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_error";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 28;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L55: // SET_EXCEPTION_VAR
  env->set_exception(env, object_vars[7]);
L56: // SET_CROAK_FLAG_TRUE
  exception_flag = 1;
L57: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_error";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 28;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L58: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[7], NULL);
L59: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], NULL);
L60: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], NULL);
L61: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], NULL);
L62: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L63: // RETURN_VOID
  goto L64;
L64: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L65: // END_SUB
  if (!exception_flag) {
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_false(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[4] = {0};
  void* ref_vars[1] = {0};
  int32_t int_vars[4];
  int32_t exception_flag = 0;
  int32_t mortal_stack[6];
  int32_t mortal_stack_top = 0;
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  object_vars[1] = *(void**)&stack[1];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }
  ref_vars[0] = *(void**)&stack[2];

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L4: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x66\x61\x6C\x73\x65", 5));
L5: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L6: // PUSH_ARG_REF
  *(void**)&stack[1] = ref_vars[0];
L7: // PUSH_ARG_OBJECT
  *(void**)&stack[2] = object_vars[2];
L8: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_expect_token
  {
    if (SUB_ID_SPVM__Webkit__JSON___expect_token < 0) {
      SUB_ID_SPVM__Webkit__JSON___expect_token = env->get_sub_id(env, "SPVM::Webkit::JSON", "_expect_token", "void(string,&int,string)");
      if (SUB_ID_SPVM__Webkit__JSON___expect_token < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _expect_token");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___expect_token;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___expect_token(env, stack);
    if (!exception_flag) {
    }
  }
L9: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_false";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 260;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L17;
  }
L10: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L11: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L12: // GET_PACKAGE_VAR_OBJECT
  {
    if (VAR_PACKAGE_VAR_ID_SPVM__Webkit__JSON__Bool__FALSE < 0) {
      VAR_PACKAGE_VAR_ID_SPVM__Webkit__JSON__Bool__FALSE = env->get_package_var_id(env, "SPVM::Webkit::JSON::Bool", "$FALSE", "SPVM::Webkit::JSON::Bool");
      if (VAR_PACKAGE_VAR_ID_SPVM__Webkit__JSON__Bool__FALSE < 0) {
        void* exception = env->new_string_raw(env, "Package variable not found SPVM::Webkit::JSON::Bool $FALSE");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], *(void**)&(*(SPVM_VALUE**)(env->runtime + (intptr_t)env->runtime_package_vars_heap_offset))[VAR_PACKAGE_VAR_ID_SPVM__Webkit__JSON__Bool__FALSE]);
  }
L13: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[2];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L17;
L14: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L15: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L16: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[3];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L17;
L17: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L18: // END_SUB
  if (!exception_flag) {
    if (stack[0].oval != NULL) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(stack[0].oval); }
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_hash(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[5] = {0};
  void* ref_vars[1] = {0};
  int32_t int_vars[8];
  int32_t exception_flag = 0;
  int32_t mortal_stack[8];
  int32_t mortal_stack_top = 0;
  int8_t byte_vars[2];
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  object_vars[1] = *(void**)&stack[1];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }
  ref_vars[0] = *(void**)&stack[2];

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // ARRAY_LENGTH
  if (object_vars[1] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[1] = *(int32_t*)((intptr_t)object_vars[1] + (intptr_t)env->object_length_offset);
  }
L4: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 265;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L5: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L6: // CALL_SUB_OBJECT
  // SPVM::Hash->new
  {
    if (SUB_ID_SPVM__Hash__new < 0) {
      SUB_ID_SPVM__Hash__new = env->get_sub_id(env, "SPVM::Hash", "new", "SPVM::Hash()");
      if (SUB_ID_SPVM__Hash__new < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Hash new");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Hash__new;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], stack[0].oval);
    }
  }
L7: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 266;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L8: // MOVE_CONSTANT_INT
  int_vars[3] = 0;
L9: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x7B';
L10: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L11: // PUSH_ARG_REF
  *(void**)&stack[1] = ref_vars[0];
L12: // PUSH_ARG_BYTE
  *(int8_t*)&stack[2] = byte_vars[0];
L13: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_expect_char
  {
    if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
      SUB_ID_SPVM__Webkit__JSON___expect_char = env->get_sub_id(env, "SPVM::Webkit::JSON", "_expect_char", "void(string,&int,byte)");
      if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _expect_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___expect_char;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___expect_char(env, stack);
    if (!exception_flag) {
    }
  }
L14: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 269;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L15: // GOTO
  goto L92;
L16: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L17: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L18: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L19: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_skip_spaces
  {
    if (SUB_ID_SPVM__Webkit__JSON___skip_spaces < 0) {
      SUB_ID_SPVM__Webkit__JSON___skip_spaces = env->get_sub_id(env, "SPVM::Webkit::JSON", "_skip_spaces", "void(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___skip_spaces < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _skip_spaces");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___skip_spaces;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___skip_spaces(env, stack);
    if (!exception_flag) {
    }
  }
L20: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 272;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L21: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L22: // EQ_INT
  int_vars[0] = (int_vars[4] == int_vars[1]);
L23: // BOOL_INT
  int_vars[0] = int_vars[0];
L24: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L35; }
L25: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L26: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], env->new_string_len_raw(env, "\x49\x6E\x63\x6F\x6D\x70\x6C\x65\x74\x65\x20\x6F\x62\x6A\x65\x63\x74\x20\x69\x6E\x20\x4A\x53\x4F\x4E\x3A\x20\x65\x6E\x64\x20\x6F\x66\x20\x73\x74\x72\x69\x6E\x67", 40));
L27: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L28: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L29: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L30: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[4];
L31: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L32: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 274;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L33: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L34: // GOTO
  goto L36;
L35: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L36: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L37: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L38: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[4];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L39: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 278;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L40: // CONVERT_BYTE_TO_INT
  int_vars[5] = (int32_t)byte_vars[0];
L41: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x7D';
L42: // CONVERT_BYTE_TO_INT
  int_vars[6] = (int32_t)byte_vars[1];
L43: // EQ_INT
  int_vars[0] = (int_vars[5] == int_vars[6]);
L44: // BOOL_INT
  int_vars[0] = int_vars[0];
L45: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L48; }
L46: // GOTO
  goto L95;
L47: // GOTO
  goto L48;
L48: // BOOL_INT
  int_vars[0] = int_vars[3];
L49: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L62; }
L50: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x2C';
L51: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L52: // PUSH_ARG_REF
  *(void**)&stack[1] = ref_vars[0];
L53: // PUSH_ARG_BYTE
  *(int8_t*)&stack[2] = byte_vars[0];
L54: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_expect_char
  {
    if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
      SUB_ID_SPVM__Webkit__JSON___expect_char = env->get_sub_id(env, "SPVM::Webkit::JSON", "_expect_char", "void(string,&int,byte)");
      if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _expect_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___expect_char;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___expect_char(env, stack);
    if (!exception_flag) {
    }
  }
L55: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 284;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L56: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L57: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L58: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L59: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_skip_spaces
  {
    if (SUB_ID_SPVM__Webkit__JSON___skip_spaces < 0) {
      SUB_ID_SPVM__Webkit__JSON___skip_spaces = env->get_sub_id(env, "SPVM::Webkit::JSON", "_skip_spaces", "void(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___skip_spaces < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _skip_spaces");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___skip_spaces;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___skip_spaces(env, stack);
    if (!exception_flag) {
    }
  }
L60: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 285;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L61: // GOTO
  goto L63;
L62: // MOVE_CONSTANT_INT
  int_vars[3] = 1;
L63: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L64: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L65: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L66: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L67: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_decode_string
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_string < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_string = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_string", "string(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_string < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_string");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_string;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_string(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], stack[0].oval);
    }
  }
L68: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 292;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L69: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L70: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L71: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L72: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_skip_spaces
  {
    if (SUB_ID_SPVM__Webkit__JSON___skip_spaces < 0) {
      SUB_ID_SPVM__Webkit__JSON___skip_spaces = env->get_sub_id(env, "SPVM::Webkit::JSON", "_skip_spaces", "void(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___skip_spaces < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _skip_spaces");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___skip_spaces;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___skip_spaces(env, stack);
    if (!exception_flag) {
    }
  }
L73: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 295;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L74: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x3A';
L75: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L76: // PUSH_ARG_REF
  *(void**)&stack[1] = ref_vars[0];
L77: // PUSH_ARG_BYTE
  *(int8_t*)&stack[2] = byte_vars[0];
L78: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_expect_char
  {
    if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
      SUB_ID_SPVM__Webkit__JSON___expect_char = env->get_sub_id(env, "SPVM::Webkit::JSON", "_expect_char", "void(string,&int,byte)");
      if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _expect_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___expect_char;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___expect_char(env, stack);
    if (!exception_flag) {
    }
  }
L79: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 296;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L80: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 4;
  mortal_stack_top++;
L81: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L82: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L83: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L84: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_decode_recursive
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_recursive < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_recursive = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_recursive", "object(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_recursive < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_recursive");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_recursive;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_recursive(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], stack[0].oval);
    }
  }
L85: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 299;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L86: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L87: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[3];
L88: // PUSH_ARG_OBJECT
  *(void**)&stack[2] = object_vars[4];
L89: // CALL_SUB_VOID
  // SPVM::Hash->set
  {
    if (SUB_ID_SPVM__Hash__set < 0) {
      SUB_ID_SPVM__Hash__set = env->get_sub_id(env, "SPVM::Hash", "set", "void(self,string,object)");
      if (SUB_ID_SPVM__Hash__set < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Hash set");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Hash__set;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L90: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 300;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L91: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L92: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L93: // BOOL_INT
  int_vars[0] = int_vars[4];
L94: // IF_NE_ZERO
  if (int_vars[0]) { goto L16; }
L95: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L96: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x7D';
L97: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L98: // PUSH_ARG_REF
  *(void**)&stack[1] = ref_vars[0];
L99: // PUSH_ARG_BYTE
  *(int8_t*)&stack[2] = byte_vars[0];
L100: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_expect_char
  {
    if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
      SUB_ID_SPVM__Webkit__JSON___expect_char = env->get_sub_id(env, "SPVM::Webkit::JSON", "_expect_char", "void(string,&int,byte)");
      if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _expect_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___expect_char;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___expect_char(env, stack);
    if (!exception_flag) {
    }
  }
L101: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_hash";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 303;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L106;
  }
L102: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[2];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L106;
L103: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L104: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L105: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[3];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L106;
L106: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L107: // END_SUB
  if (!exception_flag) {
    if (stack[0].oval != NULL) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(stack[0].oval); }
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_list(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[4] = {0};
  void* ref_vars[1] = {0};
  int32_t int_vars[8];
  int32_t exception_flag = 0;
  int32_t mortal_stack[7];
  int32_t mortal_stack_top = 0;
  int8_t byte_vars[2];
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  object_vars[1] = *(void**)&stack[1];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }
  ref_vars[0] = *(void**)&stack[2];

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // ARRAY_LENGTH
  if (object_vars[1] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[1] = *(int32_t*)((intptr_t)object_vars[1] + (intptr_t)env->object_length_offset);
  }
L4: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_list";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 309;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L84;
  }
L5: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L6: // CALL_SUB_OBJECT
  // SPVM::ObjectList->new
  {
    if (SUB_ID_SPVM__ObjectList__new < 0) {
      SUB_ID_SPVM__ObjectList__new = env->get_sub_id(env, "SPVM::ObjectList", "new", "SPVM::ObjectList()");
      if (SUB_ID_SPVM__ObjectList__new < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::ObjectList new");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__ObjectList__new;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], stack[0].oval);
    }
  }
L7: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_list";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 310;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L84;
  }
L8: // MOVE_CONSTANT_INT
  int_vars[3] = 0;
L9: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x5B';
L10: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L11: // PUSH_ARG_REF
  *(void**)&stack[1] = ref_vars[0];
L12: // PUSH_ARG_BYTE
  *(int8_t*)&stack[2] = byte_vars[0];
L13: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_expect_char
  {
    if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
      SUB_ID_SPVM__Webkit__JSON___expect_char = env->get_sub_id(env, "SPVM::Webkit::JSON", "_expect_char", "void(string,&int,byte)");
      if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _expect_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___expect_char;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___expect_char(env, stack);
    if (!exception_flag) {
    }
  }
L14: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_list";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 313;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L84;
  }
L15: // GOTO
  goto L70;
L16: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L17: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L18: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L19: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_skip_spaces
  {
    if (SUB_ID_SPVM__Webkit__JSON___skip_spaces < 0) {
      SUB_ID_SPVM__Webkit__JSON___skip_spaces = env->get_sub_id(env, "SPVM::Webkit::JSON", "_skip_spaces", "void(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___skip_spaces < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _skip_spaces");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___skip_spaces;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___skip_spaces(env, stack);
    if (!exception_flag) {
    }
  }
L20: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_list";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 316;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L84;
  }
L21: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L22: // EQ_INT
  int_vars[0] = (int_vars[4] == int_vars[1]);
L23: // BOOL_INT
  int_vars[0] = int_vars[0];
L24: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L35; }
L25: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L26: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], env->new_string_len_raw(env, "\x49\x6E\x63\x6F\x6D\x70\x6C\x65\x74\x65\x20\x61\x72\x72\x61\x79\x20\x69\x6E\x20\x4A\x53\x4F\x4E\x3A\x20\x65\x6E\x64\x20\x6F\x66\x20\x73\x74\x72\x69\x6E\x67", 39));
L27: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L28: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L29: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L30: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[4];
L31: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L32: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_list";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 318;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L84;
  }
L33: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L34: // GOTO
  goto L36;
L35: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L36: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L37: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L38: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[4];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L39: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_list";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 322;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L84;
  }
L40: // CONVERT_BYTE_TO_INT
  int_vars[5] = (int32_t)byte_vars[0];
L41: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x5D';
L42: // CONVERT_BYTE_TO_INT
  int_vars[6] = (int32_t)byte_vars[1];
L43: // EQ_INT
  int_vars[0] = (int_vars[5] == int_vars[6]);
L44: // BOOL_INT
  int_vars[0] = int_vars[0];
L45: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L48; }
L46: // GOTO
  goto L73;
L47: // GOTO
  goto L48;
L48: // BOOL_INT
  int_vars[0] = int_vars[3];
L49: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L57; }
L50: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x2C';
L51: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L52: // PUSH_ARG_REF
  *(void**)&stack[1] = ref_vars[0];
L53: // PUSH_ARG_BYTE
  *(int8_t*)&stack[2] = byte_vars[0];
L54: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_expect_char
  {
    if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
      SUB_ID_SPVM__Webkit__JSON___expect_char = env->get_sub_id(env, "SPVM::Webkit::JSON", "_expect_char", "void(string,&int,byte)");
      if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _expect_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___expect_char;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___expect_char(env, stack);
    if (!exception_flag) {
    }
  }
L55: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_list";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 328;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L84;
  }
L56: // GOTO
  goto L58;
L57: // MOVE_CONSTANT_INT
  int_vars[3] = 1;
L58: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L59: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L60: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L61: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L62: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_decode_recursive
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_recursive < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_recursive = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_recursive", "object(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_recursive < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_recursive");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_recursive;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_recursive(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], stack[0].oval);
    }
  }
L63: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_list";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 333;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L84;
  }
L64: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L65: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[3];
L66: // CALL_SUB_VOID
  // SPVM::ObjectList->push
  {
    if (SUB_ID_SPVM__ObjectList__push < 0) {
      SUB_ID_SPVM__ObjectList__push = env->get_sub_id(env, "SPVM::ObjectList", "push", "void(self,object)");
      if (SUB_ID_SPVM__ObjectList__push < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::ObjectList push");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__ObjectList__push;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L67: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_list";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 333;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L84;
  }
L68: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L69: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L70: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L71: // BOOL_INT
  int_vars[0] = int_vars[4];
L72: // IF_NE_ZERO
  if (int_vars[0]) { goto L16; }
L73: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L74: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x5D';
L75: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L76: // PUSH_ARG_REF
  *(void**)&stack[1] = ref_vars[0];
L77: // PUSH_ARG_BYTE
  *(int8_t*)&stack[2] = byte_vars[0];
L78: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_expect_char
  {
    if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
      SUB_ID_SPVM__Webkit__JSON___expect_char = env->get_sub_id(env, "SPVM::Webkit::JSON", "_expect_char", "void(string,&int,byte)");
      if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _expect_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___expect_char;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___expect_char(env, stack);
    if (!exception_flag) {
    }
  }
L79: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_list";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 336;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L84;
  }
L80: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[2];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L84;
L81: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L82: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L83: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[3];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L84;
L84: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L85: // END_SUB
  if (!exception_flag) {
    if (stack[0].oval != NULL) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(stack[0].oval); }
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_num(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[5] = {0};
  void* ref_vars[1] = {0};
  double double_vars[1];
  int32_t int_vars[14];
  int32_t exception_flag = 0;
  int32_t mortal_stack[14];
  int32_t mortal_stack_top = 0;
  int8_t byte_vars[2];
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  object_vars[1] = *(void**)&stack[1];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }
  ref_vars[0] = *(void**)&stack[2];

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // ARRAY_LENGTH
  if (object_vars[1] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[1] = *(int32_t*)((intptr_t)object_vars[1] + (intptr_t)env->object_length_offset);
  }
L4: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 144;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L5: // GET_DEREF_INT
  int_vars[3] = *(int32_t*)*(void**)&ref_vars[0];
L6: // MOVE_CONSTANT_INT
  int_vars[4] = 0;
L7: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L8: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[5];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L9: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 151;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L10: // CONVERT_BYTE_TO_INT
  int_vars[6] = (int32_t)byte_vars[0];
L11: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x2D';
L12: // CONVERT_BYTE_TO_INT
  int_vars[7] = (int32_t)byte_vars[1];
L13: // EQ_INT
  int_vars[0] = (int_vars[6] == int_vars[7]);
L14: // BOOL_INT
  int_vars[0] = int_vars[0];
L15: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L60; }
L16: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L17: // MOVE_CONSTANT_INT
  int_vars[6] = 1;
L18: // ADD_INT
  int_vars[7] = int_vars[5] + int_vars[6];
L19: // LT_INT
  int_vars[0] = (int_vars[7] < int_vars[1]);
L20: // BOOL_INT
  int_vars[0] = int_vars[0];
L21: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L39; }
L22: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L23: // MOVE_CONSTANT_INT
  int_vars[6] = 1;
L24: // ADD_INT
  int_vars[7] = int_vars[5] + int_vars[6];
L25: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[7];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L26: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 152;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L27: // CONVERT_BYTE_TO_INT
  int_vars[8] = (int32_t)byte_vars[0];
L28: // PUSH_ARG_INT
  *(int32_t*)&stack[0] = int_vars[8];
L29: // CALL_SUB_INT
  // SPVM::Util->isdigit
  {
    if (SUB_ID_SPVM__Util__isdigit < 0) {
      SUB_ID_SPVM__Util__isdigit = env->get_sub_id(env, "SPVM::Util", "isdigit", "int(int)");
      if (SUB_ID_SPVM__Util__isdigit < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Util isdigit");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Util__isdigit;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      int_vars[9] = *(int32_t*)&stack[0];
    }
  }
L30: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 152;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L31: // BOOL_INT
  int_vars[0] = int_vars[9];
L32: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L36; }
L33: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L34: // BOOL_INT
  int_vars[0] = int_vars[5];
L35: // GOTO
  goto L38;
L36: // MOVE_CONSTANT_INT
  int_vars[6] = 0;
L37: // BOOL_INT
  int_vars[0] = int_vars[6];
L38: // GOTO
  goto L41;
L39: // MOVE_CONSTANT_INT
  int_vars[7] = 0;
L40: // BOOL_INT
  int_vars[0] = int_vars[7];
L41: // BOOL_INT
  int_vars[0] = int_vars[0];
L42: // IF_NE_ZERO
  if (int_vars[0]) { goto L53; }
L43: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L44: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x6D\x61\x6C\x66\x6F\x72\x6D\x65\x64\x20\x6E\x75\x6D\x62\x65\x72\x20\x28\x6E\x6F\x20\x64\x69\x67\x69\x74\x20\x61\x66\x74\x65\x72\x20\x27\x2D\x27\x29", 37));
L45: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L46: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L47: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L48: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[5];
L49: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L50: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 153;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L51: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L52: // GOTO
  goto L54;
L53: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L54: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L55: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L56: // MOVE_CONSTANT_INT
  int_vars[6] = 2;
L57: // ADD_INT
  int_vars[7] = int_vars[5] + int_vars[6];
L58: // SET_DEREF_INT
  *(int32_t*)*(void**)&ref_vars[0] = int_vars[7];
L59: // GOTO
  goto L85;
L60: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L61: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L62: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[5];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L63: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 157;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L64: // CONVERT_BYTE_TO_INT
  int_vars[6] = (int32_t)byte_vars[0];
L65: // PUSH_ARG_INT
  *(int32_t*)&stack[0] = int_vars[6];
L66: // CALL_SUB_INT
  // SPVM::Util->isdigit
  {
    if (SUB_ID_SPVM__Util__isdigit < 0) {
      SUB_ID_SPVM__Util__isdigit = env->get_sub_id(env, "SPVM::Util", "isdigit", "int(int)");
      if (SUB_ID_SPVM__Util__isdigit < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Util isdigit");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Util__isdigit;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      int_vars[7] = *(int32_t*)&stack[0];
    }
  }
L67: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 157;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L68: // BOOL_INT
  int_vars[0] = int_vars[7];
L69: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L73; }
L70: // MOVE_CONSTANT_INT
  int_vars[5] = 0;
L71: // BOOL_INT
  int_vars[0] = int_vars[5];
L72: // GOTO
  goto L75;
L73: // MOVE_CONSTANT_INT
  int_vars[6] = 1;
L74: // BOOL_INT
  int_vars[0] = int_vars[6];
L75: // BOOL_INT
  int_vars[0] = int_vars[0];
L76: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L84; }
L77: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L78: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x5B\x42\x55\x47\x5D\x20\x66\x69\x72\x73\x74\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x20\x6D\x75\x73\x74\x20\x62\x65\x20\x64\x69\x67\x69\x74\x20\x6F\x72\x20\x27\x2D\x27", 42));
L79: // SET_EXCEPTION_VAR
  env->set_exception(env, object_vars[2]);
L80: // SET_CROAK_FLAG_TRUE
  exception_flag = 1;
L81: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 158;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L82: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L83: // GOTO
  goto L85;
L84: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L85: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L86: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L87: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L88: // GOTO
  goto L288;
L89: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L90: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[5];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L91: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 164;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L92: // CONVERT_BYTE_TO_INT
  int_vars[6] = (int32_t)byte_vars[0];
L93: // LOOKUP_SWITCH
  switch(int_vars[6]) {
    case 46: goto L94;
    case 101: goto L113;
    default: goto L129;
  }
L94: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L95: // EQ_INT
  int_vars[0] = (int_vars[4] == int_vars[5]);
L96: // BOOL_INT
  int_vars[0] = int_vars[0];
L97: // IF_NE_ZERO
  if (int_vars[0]) { goto L108; }
L98: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L99: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x6D\x61\x6C\x66\x6F\x72\x6D\x65\x64\x20\x6E\x75\x6D\x62\x65\x72\x20\x28\x69\x6D\x70\x72\x6F\x70\x65\x72\x20\x70\x6F\x73\x69\x74\x69\x6F\x6E\x20\x6F\x66\x20\x27\x2E\x27\x29", 43));
L100: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L101: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L102: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L103: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[5];
L104: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L105: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 169;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L106: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L107: // GOTO
  goto L109;
L108: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L109: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L110: // MOVE_CONSTANT_INT
  int_vars[4] = 2;
L111: // GOTO
  goto L224;
L112: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L113: // TABLE_SWITCH
  switch(int_vars[4]) {
    case 2: goto L114;
    case 3: goto L125;
    case 4: goto L114;
    case 5: goto L114;
    case 6: goto L114;
    default: goto L125;
  }
L114: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L115: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x6D\x61\x6C\x66\x6F\x72\x6D\x65\x64\x20\x6E\x75\x6D\x62\x65\x72\x20\x28\x69\x6D\x70\x72\x6F\x70\x65\x72\x20\x70\x6F\x73\x69\x74\x69\x6F\x6E\x20\x6F\x66\x20\x27\x65\x27\x29", 43));
L116: // GET_DEREF_INT
  int_vars[9] = *(int32_t*)*(void**)&ref_vars[0];
L117: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L118: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L119: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[9];
L120: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L121: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 180;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L122: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L123: // GOTO
  goto L126;
L124: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L125: // MOVE_CONSTANT_INT
  int_vars[4] = 4;
L126: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L127: // GOTO
  goto L224;
L128: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L129: // TABLE_SWITCH
  switch(int_vars[4]) {
    case 2: goto L130;
    case 3: goto L213;
    case 4: goto L150;
    case 5: goto L193;
    default: goto L213;
  }
L130: // PUSH_ARG_INT
  *(int32_t*)&stack[0] = int_vars[6];
L131: // CALL_SUB_INT
  // SPVM::Util->isdigit
  {
    if (SUB_ID_SPVM__Util__isdigit < 0) {
      SUB_ID_SPVM__Util__isdigit = env->get_sub_id(env, "SPVM::Util", "isdigit", "int(int)");
      if (SUB_ID_SPVM__Util__isdigit < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Util isdigit");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Util__isdigit;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      int_vars[5] = *(int32_t*)&stack[0];
    }
  }
L132: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 192;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L133: // BOOL_INT
  int_vars[0] = int_vars[5];
L134: // IF_NE_ZERO
  if (int_vars[0]) { goto L145; }
L135: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L136: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x6D\x61\x6C\x66\x6F\x72\x6D\x65\x64\x20\x6E\x75\x6D\x62\x65\x72\x20\x28\x6E\x6F\x20\x64\x69\x67\x69\x74\x20\x61\x66\x74\x65\x72\x20\x27\x2E\x27\x29", 37));
L137: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L138: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L139: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L140: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[5];
L141: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L142: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 193;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L143: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L144: // GOTO
  goto L146;
L145: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L146: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L147: // MOVE_CONSTANT_INT
  int_vars[4] = 3;
L148: // GOTO
  goto L221;
L149: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L150: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x2B';
L151: // CONVERT_BYTE_TO_INT
  int_vars[8] = (int32_t)byte_vars[0];
L152: // EQ_INT
  int_vars[0] = (int_vars[6] == int_vars[8]);
L153: // BOOL_INT
  int_vars[0] = int_vars[0];
L154: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L158; }
L155: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L156: // BOOL_INT
  int_vars[0] = int_vars[5];
L157: // GOTO
  goto L168;
L158: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x2D';
L159: // CONVERT_BYTE_TO_INT
  int_vars[7] = (int32_t)byte_vars[0];
L160: // EQ_INT
  int_vars[0] = (int_vars[6] == int_vars[7]);
L161: // BOOL_INT
  int_vars[0] = int_vars[0];
L162: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L166; }
L163: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L164: // BOOL_INT
  int_vars[0] = int_vars[5];
L165: // GOTO
  goto L168;
L166: // MOVE_CONSTANT_INT
  int_vars[7] = 0;
L167: // BOOL_INT
  int_vars[0] = int_vars[7];
L168: // BOOL_INT
  int_vars[0] = int_vars[0];
L169: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L172; }
L170: // MOVE_CONSTANT_INT
  int_vars[4] = 5;
L171: // GOTO
  goto L189;
L172: // PUSH_ARG_INT
  *(int32_t*)&stack[0] = int_vars[6];
L173: // CALL_SUB_INT
  // SPVM::Util->isdigit
  {
    if (SUB_ID_SPVM__Util__isdigit < 0) {
      SUB_ID_SPVM__Util__isdigit = env->get_sub_id(env, "SPVM::Util", "isdigit", "int(int)");
      if (SUB_ID_SPVM__Util__isdigit < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Util isdigit");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Util__isdigit;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      int_vars[5] = *(int32_t*)&stack[0];
    }
  }
L174: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 202;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L175: // BOOL_INT
  int_vars[0] = int_vars[5];
L176: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L179; }
L177: // MOVE_CONSTANT_INT
  int_vars[4] = 6;
L178: // GOTO
  goto L188;
L179: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L180: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x6D\x61\x6C\x66\x6F\x72\x6D\x65\x64\x20\x6E\x75\x6D\x62\x65\x72\x20\x28\x6E\x6F\x20\x64\x69\x67\x69\x74\x20\x61\x66\x74\x65\x72\x20\x27\x65\x27\x29", 37));
L181: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L182: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L183: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L184: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[5];
L185: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L186: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 206;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L187: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L188: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L189: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L190: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L191: // GOTO
  goto L221;
L192: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L193: // PUSH_ARG_INT
  *(int32_t*)&stack[0] = int_vars[6];
L194: // CALL_SUB_INT
  // SPVM::Util->isdigit
  {
    if (SUB_ID_SPVM__Util__isdigit < 0) {
      SUB_ID_SPVM__Util__isdigit = env->get_sub_id(env, "SPVM::Util", "isdigit", "int(int)");
      if (SUB_ID_SPVM__Util__isdigit < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Util isdigit");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Util__isdigit;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      int_vars[8] = *(int32_t*)&stack[0];
    }
  }
L195: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 211;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L196: // BOOL_INT
  int_vars[0] = int_vars[8];
L197: // IF_NE_ZERO
  if (int_vars[0]) { goto L208; }
L198: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L199: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x6D\x61\x6C\x66\x6F\x72\x6D\x65\x64\x20\x6E\x75\x6D\x62\x65\x72\x20\x28\x6E\x6F\x20\x64\x69\x67\x69\x74\x20\x61\x66\x74\x65\x72\x20\x65\x78\x70\x6F\x6E\x65\x6E\x74\x69\x61\x6C\x20\x73\x69\x67\x6E\x29", 50));
L200: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L201: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L202: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L203: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[5];
L204: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L205: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 212;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L206: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L207: // GOTO
  goto L209;
L208: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L209: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L210: // MOVE_CONSTANT_INT
  int_vars[4] = 6;
L211: // GOTO
  goto L221;
L212: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L213: // PUSH_ARG_INT
  *(int32_t*)&stack[0] = int_vars[6];
L214: // CALL_SUB_INT
  // SPVM::Util->isdigit
  {
    if (SUB_ID_SPVM__Util__isdigit < 0) {
      SUB_ID_SPVM__Util__isdigit = env->get_sub_id(env, "SPVM::Util", "isdigit", "int(int)");
      if (SUB_ID_SPVM__Util__isdigit < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Util isdigit");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Util__isdigit;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      int_vars[8] = *(int32_t*)&stack[0];
    }
  }
L215: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 218;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L216: // BOOL_INT
  int_vars[0] = int_vars[8];
L217: // IF_NE_ZERO
  if (int_vars[0]) { goto L220; }
L218: // MOVE_CONSTANT_INT
  int_vars[4] = 7;
L219: // GOTO
  goto L220;
L220: // GOTO
  goto L221;
L221: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L222: // GOTO
  goto L224;
L223: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L224: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L225: // MOVE_CONSTANT_INT
  int_vars[12] = 7;
L226: // EQ_INT
  int_vars[0] = (int_vars[4] == int_vars[12]);
L227: // BOOL_INT
  int_vars[0] = int_vars[0];
L228: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L231; }
L229: // GOTO
  goto L292;
L230: // GOTO
  goto L231;
L231: // GET_DEREF_INT
  int_vars[7] = *(int32_t*)*(void**)&ref_vars[0];
L232: // MOVE_CONSTANT_INT
  int_vars[8] = 1;
L233: // ADD_INT
  int_vars[9] = int_vars[7] + int_vars[8];
L234: // SET_DEREF_INT
  *(int32_t*)*(void**)&ref_vars[0] = int_vars[9];
L235: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L236: // LE_INT
  int_vars[0] = (int_vars[1] <= int_vars[5]);
L237: // BOOL_INT
  int_vars[0] = int_vars[0];
L238: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L285; }
L239: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L240: // EQ_INT
  int_vars[0] = (int_vars[4] == int_vars[5]);
L241: // BOOL_INT
  int_vars[0] = int_vars[0];
L242: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L246; }
L243: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L244: // BOOL_INT
  int_vars[0] = int_vars[5];
L245: // GOTO
  goto L255;
L246: // MOVE_CONSTANT_INT
  int_vars[7] = 3;
L247: // EQ_INT
  int_vars[0] = (int_vars[4] == int_vars[7]);
L248: // BOOL_INT
  int_vars[0] = int_vars[0];
L249: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L253; }
L250: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L251: // BOOL_INT
  int_vars[0] = int_vars[5];
L252: // GOTO
  goto L255;
L253: // MOVE_CONSTANT_INT
  int_vars[7] = 0;
L254: // BOOL_INT
  int_vars[0] = int_vars[7];
L255: // BOOL_INT
  int_vars[0] = int_vars[0];
L256: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L260; }
L257: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L258: // BOOL_INT
  int_vars[0] = int_vars[5];
L259: // GOTO
  goto L269;
L260: // MOVE_CONSTANT_INT
  int_vars[7] = 6;
L261: // EQ_INT
  int_vars[0] = (int_vars[4] == int_vars[7]);
L262: // BOOL_INT
  int_vars[0] = int_vars[0];
L263: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L267; }
L264: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L265: // BOOL_INT
  int_vars[0] = int_vars[5];
L266: // GOTO
  goto L269;
L267: // MOVE_CONSTANT_INT
  int_vars[7] = 0;
L268: // BOOL_INT
  int_vars[0] = int_vars[7];
L269: // BOOL_INT
  int_vars[0] = int_vars[0];
L270: // IF_NE_ZERO
  if (int_vars[0]) { goto L281; }
L271: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L272: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x6D\x61\x6C\x66\x6F\x72\x6D\x65\x64\x20\x6E\x75\x6D\x62\x65\x72\x20\x28\x65\x6E\x64\x20\x6F\x66\x20\x73\x74\x72\x69\x6E\x67\x29", 32));
L273: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L274: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L275: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L276: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[5];
L277: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L278: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 238;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L279: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L280: // GOTO
  goto L282;
L281: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L282: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L283: // MOVE_CONSTANT_INT
  int_vars[4] = 7;
L284: // GOTO
  goto L286;
L285: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L286: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L287: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L288: // MOVE_CONSTANT_INT
  int_vars[5] = 7;
L289: // NE_INT
  int_vars[0] = (int_vars[4] != int_vars[5]);
L290: // BOOL_INT
  int_vars[0] = int_vars[0];
L291: // IF_NE_ZERO
  if (int_vars[0]) { goto L89; }
L292: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L293: // GET_DEREF_INT
  int_vars[6] = *(int32_t*)*(void**)&ref_vars[0];
L294: // SUBTRACT_INT
  int_vars[5] = int_vars[6] - int_vars[3];
L295: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L296: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L297: // PUSH_ARG_INT
  *(int32_t*)&stack[1] = int_vars[3];
L298: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[5];
L299: // CALL_SUB_OBJECT
  // SPVM::Util->substr
  {
    if (SUB_ID_SPVM__Util__substr < 0) {
      SUB_ID_SPVM__Util__substr = env->get_sub_id(env, "SPVM::Util", "substr", "string(string,int,int)");
      if (SUB_ID_SPVM__Util__substr < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Util substr");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Util__substr;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], stack[0].oval);
    }
  }
L300: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 248;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L301: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L302: // CALL_SUB_DOUBLE
  // SPVM::Util->strtod
  {
    if (SUB_ID_SPVM__Util__strtod < 0) {
      SUB_ID_SPVM__Util__strtod = env->get_sub_id(env, "SPVM::Util", "strtod", "double(string)");
      if (SUB_ID_SPVM__Util__strtod < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Util strtod");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Util__strtod;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      double_vars[0] = *(double*)&stack[0];
    }
  }
L303: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 249;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L304: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L305: // PUSH_ARG_DOUBLE
  *(double*)&stack[0] = double_vars[0];
L306: // CALL_SUB_OBJECT
  // SPVM::Double->new
  {
    if (SUB_ID_SPVM__Double__new < 0) {
      SUB_ID_SPVM__Double__new = env->get_sub_id(env, "SPVM::Double", "new", "SPVM::Double(double)");
      if (SUB_ID_SPVM__Double__new < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Double new");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Double__new;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], stack[0].oval);
    }
  }
L307: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_num";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 251;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L312;
  }
L308: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[3];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L312;
L309: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 4;
  mortal_stack_top++;
L310: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], NULL);
L311: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[4];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L312;
L312: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L313: // END_SUB
  if (!exception_flag) {
    if (stack[0].oval != NULL) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(stack[0].oval); }
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_recursive(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[9] = {0};
  void* ref_vars[1] = {0};
  int32_t int_vars[26];
  int32_t exception_flag = 0;
  int32_t mortal_stack[13];
  int32_t mortal_stack_top = 0;
  int8_t byte_vars[1];
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  object_vars[1] = *(void**)&stack[1];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }
  ref_vars[0] = *(void**)&stack[2];

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // ARRAY_LENGTH
  if (object_vars[1] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[1] = *(int32_t*)((intptr_t)object_vars[1] + (intptr_t)env->object_length_offset);
  }
L4: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 342;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L109;
  }
L5: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L6: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L7: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L8: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_skip_spaces
  {
    if (SUB_ID_SPVM__Webkit__JSON___skip_spaces < 0) {
      SUB_ID_SPVM__Webkit__JSON___skip_spaces = env->get_sub_id(env, "SPVM::Webkit::JSON", "_skip_spaces", "void(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___skip_spaces < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _skip_spaces");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___skip_spaces;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___skip_spaces(env, stack);
    if (!exception_flag) {
    }
  }
L9: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 344;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L109;
  }
L10: // GET_DEREF_INT
  int_vars[3] = *(int32_t*)*(void**)&ref_vars[0];
L11: // EQ_INT
  int_vars[0] = (int_vars[3] == int_vars[1]);
L12: // BOOL_INT
  int_vars[0] = int_vars[0];
L13: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L24; }
L14: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L15: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x49\x6E\x63\x6F\x6D\x70\x6C\x65\x74\x65\x20\x4A\x53\x4F\x4E", 15));
L16: // GET_DEREF_INT
  int_vars[3] = *(int32_t*)*(void**)&ref_vars[0];
L17: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L18: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L19: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[3];
L20: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L21: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 346;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L109;
  }
L22: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L23: // GOTO
  goto L25;
L24: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L25: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L26: // GET_DEREF_INT
  int_vars[3] = *(int32_t*)*(void**)&ref_vars[0];
L27: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[3];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L28: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 349;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L109;
  }
L29: // CONVERT_BYTE_TO_INT
  int_vars[4] = (int32_t)byte_vars[0];
L30: // LOOKUP_SWITCH
  switch(int_vars[4]) {
    case 34: goto L47;
    case 45: goto L55;
    case 48: goto L55;
    case 49: goto L55;
    case 50: goto L55;
    case 51: goto L55;
    case 52: goto L55;
    case 53: goto L55;
    case 54: goto L55;
    case 55: goto L55;
    case 56: goto L55;
    case 57: goto L55;
    case 91: goto L39;
    case 102: goto L71;
    case 110: goto L79;
    case 116: goto L63;
    case 123: goto L31;
    default: goto L95;
  }
L31: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L32: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L33: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L34: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L35: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_decode_hash
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_hash < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_hash = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_hash", "SPVM::Hash(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_hash < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_hash");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_hash;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_hash(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], stack[0].oval);
    }
  }
L36: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 353;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L109;
  }
L37: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[2];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L109;
L38: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L39: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L40: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L41: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L42: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L43: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_decode_list
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_list < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_list = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_list", "SPVM::ObjectList(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_list < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_list");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_list;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_list(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], stack[0].oval);
    }
  }
L44: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 356;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L109;
  }
L45: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[3];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L109;
L46: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L47: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 4;
  mortal_stack_top++;
L48: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L49: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L50: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L51: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_decode_string
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_string < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_string = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_string", "string(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_string < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_string");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_string;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_string(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], stack[0].oval);
    }
  }
L52: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 359;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L109;
  }
L53: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[4];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L109;
L54: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L55: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 5;
  mortal_stack_top++;
L56: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L57: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L58: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L59: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_decode_num
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_num < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_num = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_num", "object(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_num < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_num");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_num;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_num(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], stack[0].oval);
    }
  }
L60: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 364;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L109;
  }
L61: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[5];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L109;
L62: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L63: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 6;
  mortal_stack_top++;
L64: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L65: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L66: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L67: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_decode_true
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_true < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_true = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_true", "SPVM::Webkit::JSON::Bool(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_true < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_true");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_true;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_true(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], stack[0].oval);
    }
  }
L68: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 367;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L109;
  }
L69: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[6];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L109;
L70: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L71: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 7;
  mortal_stack_top++;
L72: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L73: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L74: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L75: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_decode_false
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_false < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_false = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_false", "SPVM::Webkit::JSON::Bool(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_false < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_false");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_false;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_false(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[7], stack[0].oval);
    }
  }
L76: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 370;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L109;
  }
L77: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[7];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L109;
L78: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L79: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 8;
  mortal_stack_top++;
L80: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[8], env->new_string_len_raw(env, "\x6E\x75\x6C\x6C", 4));
L81: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L82: // PUSH_ARG_REF
  *(void**)&stack[1] = ref_vars[0];
L83: // PUSH_ARG_OBJECT
  *(void**)&stack[2] = object_vars[8];
L84: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_expect_token
  {
    if (SUB_ID_SPVM__Webkit__JSON___expect_token < 0) {
      SUB_ID_SPVM__Webkit__JSON___expect_token = env->get_sub_id(env, "SPVM::Webkit::JSON", "_expect_token", "void(string,&int,string)");
      if (SUB_ID_SPVM__Webkit__JSON___expect_token < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _expect_token");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___expect_token;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___expect_token(env, stack);
    if (!exception_flag) {
    }
  }
L85: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 373;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L109;
  }
L86: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[8], NULL);
L87: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[7], NULL);
L88: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], NULL);
L89: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], NULL);
L90: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], NULL);
L91: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L92: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L93: // RETURN_UNDEF
  *(void**)&stack[0] = NULL;
  goto L109;
L94: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L95: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L96: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x55\x6E\x65\x78\x70\x65\x63\x74\x65\x64\x20\x74\x6F\x6B\x65\x6E\x2E", 17));
L97: // GET_DEREF_INT
  int_vars[6] = *(int32_t*)*(void**)&ref_vars[0];
L98: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L99: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L100: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[6];
L101: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L102: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 377;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L109;
  }
L103: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L104: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L105: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L106: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L107: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L108: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[2];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L109;
L109: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L110: // END_SUB
  if (!exception_flag) {
    if (stack[0].oval != NULL) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(stack[0].oval); }
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_string(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[6] = {0};
  void* ref_vars[1] = {0};
  int32_t int_vars[8];
  int32_t exception_flag = 0;
  int32_t mortal_stack[10];
  int32_t mortal_stack_top = 0;
  int8_t byte_vars[2];
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  object_vars[1] = *(void**)&stack[1];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }
  ref_vars[0] = *(void**)&stack[2];

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // ARRAY_LENGTH
  if (object_vars[1] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[1] = *(int32_t*)((intptr_t)object_vars[1] + (intptr_t)env->object_length_offset);
  }
L4: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 67;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L5: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L6: // CALL_SUB_OBJECT
  // SPVM::StringBuffer->new
  {
    if (SUB_ID_SPVM__StringBuffer__new < 0) {
      SUB_ID_SPVM__StringBuffer__new = env->get_sub_id(env, "SPVM::StringBuffer", "new", "SPVM::StringBuffer()");
      if (SUB_ID_SPVM__StringBuffer__new < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer new");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__new;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], stack[0].oval);
    }
  }
L7: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 68;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L8: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x22';
L9: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L10: // PUSH_ARG_REF
  *(void**)&stack[1] = ref_vars[0];
L11: // PUSH_ARG_BYTE
  *(int8_t*)&stack[2] = byte_vars[0];
L12: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_expect_char
  {
    if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
      SUB_ID_SPVM__Webkit__JSON___expect_char = env->get_sub_id(env, "SPVM::Webkit::JSON", "_expect_char", "void(string,&int,byte)");
      if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _expect_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___expect_char;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___expect_char(env, stack);
    if (!exception_flag) {
    }
  }
L13: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 70;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L14: // MOVE_CONSTANT_INT
  int_vars[3] = 0;
L15: // GOTO
  goto L168;
L16: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L17: // GE_INT
  int_vars[0] = (int_vars[4] >= int_vars[1]);
L18: // BOOL_INT
  int_vars[0] = int_vars[0];
L19: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L23; }
L20: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L21: // BOOL_INT
  int_vars[0] = int_vars[4];
L22: // GOTO
  goto L56;
L23: // BOOL_INT
  int_vars[0] = int_vars[3];
L24: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L28; }
L25: // MOVE_CONSTANT_INT
  int_vars[4] = 0;
L26: // BOOL_INT
  int_vars[0] = int_vars[4];
L27: // GOTO
  goto L30;
L28: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L29: // BOOL_INT
  int_vars[0] = int_vars[5];
L30: // BOOL_INT
  int_vars[0] = int_vars[0];
L31: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L47; }
L32: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L33: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[4];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L34: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 74;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L35: // CONVERT_BYTE_TO_INT
  int_vars[5] = (int32_t)byte_vars[0];
L36: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x22';
L37: // CONVERT_BYTE_TO_INT
  int_vars[6] = (int32_t)byte_vars[1];
L38: // EQ_INT
  int_vars[0] = (int_vars[5] == int_vars[6]);
L39: // BOOL_INT
  int_vars[0] = int_vars[0];
L40: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L44; }
L41: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L42: // BOOL_INT
  int_vars[0] = int_vars[4];
L43: // GOTO
  goto L46;
L44: // MOVE_CONSTANT_INT
  int_vars[5] = 0;
L45: // BOOL_INT
  int_vars[0] = int_vars[5];
L46: // GOTO
  goto L49;
L47: // MOVE_CONSTANT_INT
  int_vars[6] = 0;
L48: // BOOL_INT
  int_vars[0] = int_vars[6];
L49: // BOOL_INT
  int_vars[0] = int_vars[0];
L50: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L54; }
L51: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L52: // BOOL_INT
  int_vars[0] = int_vars[4];
L53: // GOTO
  goto L56;
L54: // MOVE_CONSTANT_INT
  int_vars[5] = 0;
L55: // BOOL_INT
  int_vars[0] = int_vars[5];
L56: // BOOL_INT
  int_vars[0] = int_vars[0];
L57: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L60; }
L58: // GOTO
  goto L171;
L59: // GOTO
  goto L60;
L60: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L61: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[5];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L62: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 77;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L63: // BOOL_INT
  int_vars[0] = int_vars[3];
L64: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L115; }
L65: // CONVERT_BYTE_TO_INT
  int_vars[4] = (int32_t)byte_vars[0];
L66: // LOOKUP_SWITCH
  switch(int_vars[4]) {
    case 34: goto L67;
    case 47: goto L67;
    case 92: goto L67;
    case 98: goto L72;
    case 102: goto L78;
    case 110: goto L84;
    case 114: goto L90;
    case 116: goto L96;
    default: goto L102;
  }
L67: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L68: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[0];
L69: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L70: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 83;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L71: // GOTO
  goto L112;
L72: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x08';
L73: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L74: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[1];
L75: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L76: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 87;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L77: // GOTO
  goto L112;
L78: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x0C';
L79: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L80: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[1];
L81: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L82: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 91;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L83: // GOTO
  goto L112;
L84: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x0A';
L85: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L86: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[1];
L87: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L88: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 95;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L89: // GOTO
  goto L112;
L90: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x0D';
L91: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L92: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[1];
L93: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L94: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 99;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L95: // GOTO
  goto L112;
L96: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x09';
L97: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L98: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[1];
L99: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L100: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 103;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L101: // GOTO
  goto L112;
L102: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L103: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], env->new_string_len_raw(env, "\x55\x6E\x64\x65\x66\x69\x6E\x65\x64\x20\x73\x70\x65\x63\x69\x61\x6C\x20\x63\x68\x61\x72", 22));
L104: // GET_DEREF_INT
  int_vars[6] = *(int32_t*)*(void**)&ref_vars[0];
L105: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L106: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L107: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[6];
L108: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L109: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 107;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L110: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L111: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L112: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L113: // MOVE_CONSTANT_INT
  int_vars[3] = 0;
L114: // GOTO
  goto L161;
L115: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L116: // CONVERT_BYTE_TO_INT
  int_vars[4] = (int32_t)byte_vars[0];
L117: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x5C';
L118: // CONVERT_BYTE_TO_INT
  int_vars[5] = (int32_t)byte_vars[1];
L119: // EQ_INT
  int_vars[0] = (int_vars[4] == int_vars[5]);
L120: // BOOL_INT
  int_vars[0] = int_vars[0];
L121: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L124; }
L122: // MOVE_CONSTANT_INT
  int_vars[3] = 1;
L123: // GOTO
  goto L160;
L124: // CONVERT_BYTE_TO_INT
  int_vars[4] = (int32_t)byte_vars[0];
L125: // MOVE_CONSTANT_INT
  int_vars[5] = 31;
L126: // LE_INT
  int_vars[0] = (int_vars[4] <= int_vars[5]);
L127: // BOOL_INT
  int_vars[0] = int_vars[0];
L128: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L132; }
L129: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L130: // BOOL_INT
  int_vars[0] = int_vars[4];
L131: // GOTO
  goto L142;
L132: // CONVERT_BYTE_TO_INT
  int_vars[5] = (int32_t)byte_vars[0];
L133: // MOVE_CONSTANT_INT
  int_vars[6] = 127;
L134: // EQ_INT
  int_vars[0] = (int_vars[5] == int_vars[6]);
L135: // BOOL_INT
  int_vars[0] = int_vars[0];
L136: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L140; }
L137: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L138: // BOOL_INT
  int_vars[0] = int_vars[4];
L139: // GOTO
  goto L142;
L140: // MOVE_CONSTANT_INT
  int_vars[5] = 0;
L141: // BOOL_INT
  int_vars[0] = int_vars[5];
L142: // BOOL_INT
  int_vars[0] = int_vars[0];
L143: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L154; }
L144: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L145: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], env->new_string_len_raw(env, "\x43\x6F\x6E\x74\x72\x6F\x6C\x20\x41\x53\x43\x49\x49\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x73\x20\x61\x72\x65\x20\x6E\x6F\x74\x20\x61\x6C\x6C\x6F\x77\x65\x64\x20\x69\x6E\x20\x73\x74\x72\x69\x6E\x67", 50));
L146: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L147: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L148: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L149: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[4];
L150: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L151: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 117;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L152: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L153: // GOTO
  goto L155;
L154: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L155: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L156: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L157: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[0];
L158: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L159: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 119;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L160: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L161: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L162: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L163: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L164: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L165: // ADD_INT
  int_vars[6] = int_vars[4] + int_vars[5];
L166: // SET_DEREF_INT
  *(int32_t*)*(void**)&ref_vars[0] = int_vars[6];
L167: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L168: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L169: // BOOL_INT
  int_vars[0] = int_vars[4];
L170: // IF_NE_ZERO
  if (int_vars[0]) { goto L16; }
L171: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L172: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L173: // EQ_INT
  int_vars[0] = (int_vars[5] == int_vars[1]);
L174: // BOOL_INT
  int_vars[0] = int_vars[0];
L175: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L186; }
L176: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L177: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], env->new_string_len_raw(env, "\x49\x6E\x76\x61\x6C\x69\x64\x20\x73\x74\x72\x69\x6E\x67\x2E\x20\x65\x6E\x64\x2D\x71\x75\x6F\x74\x65\x20\x64\x6F\x65\x73\x6E\x27\x74\x20\x65\x78\x69\x73\x74", 39));
L178: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L179: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L180: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L181: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[4];
L182: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L183: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 124;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L184: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L185: // GOTO
  goto L187;
L186: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L187: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L188: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x22';
L189: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L190: // PUSH_ARG_REF
  *(void**)&stack[1] = ref_vars[0];
L191: // PUSH_ARG_BYTE
  *(int8_t*)&stack[2] = byte_vars[0];
L192: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_expect_char
  {
    if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
      SUB_ID_SPVM__Webkit__JSON___expect_char = env->get_sub_id(env, "SPVM::Webkit::JSON", "_expect_char", "void(string,&int,byte)");
      if (SUB_ID_SPVM__Webkit__JSON___expect_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _expect_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___expect_char;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___expect_char(env, stack);
    if (!exception_flag) {
    }
  }
L193: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 127;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L194: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L195: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[2];
L196: // CALL_SUB_OBJECT
  // SPVM::StringBuffer->to_string
  {
    if (SUB_ID_SPVM__StringBuffer__to_string < 0) {
      SUB_ID_SPVM__StringBuffer__to_string = env->get_sub_id(env, "SPVM::StringBuffer", "to_string", "string(self)");
      if (SUB_ID_SPVM__StringBuffer__to_string < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer to_string");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__to_string;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], stack[0].oval);
    }
  }
L197: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 129;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L204;
  }
L198: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 4;
  mortal_stack_top++;
L199: // MOVE_OBJECT
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], object_vars[3]);
L200: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[4];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L204;
L201: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 5;
  mortal_stack_top++;
L202: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], NULL);
L203: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[5];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L204;
L204: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L205: // END_SUB
  if (!exception_flag) {
    if (stack[0].oval != NULL) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(stack[0].oval); }
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON___decode_true(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[4] = {0};
  void* ref_vars[1] = {0};
  int32_t int_vars[4];
  int32_t exception_flag = 0;
  int32_t mortal_stack[6];
  int32_t mortal_stack_top = 0;
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  object_vars[1] = *(void**)&stack[1];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }
  ref_vars[0] = *(void**)&stack[2];

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L4: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x74\x72\x75\x65", 4));
L5: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L6: // PUSH_ARG_REF
  *(void**)&stack[1] = ref_vars[0];
L7: // PUSH_ARG_OBJECT
  *(void**)&stack[2] = object_vars[2];
L8: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_expect_token
  {
    if (SUB_ID_SPVM__Webkit__JSON___expect_token < 0) {
      SUB_ID_SPVM__Webkit__JSON___expect_token = env->get_sub_id(env, "SPVM::Webkit::JSON", "_expect_token", "void(string,&int,string)");
      if (SUB_ID_SPVM__Webkit__JSON___expect_token < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _expect_token");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___expect_token;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___expect_token(env, stack);
    if (!exception_flag) {
    }
  }
L9: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_decode_true";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 255;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L17;
  }
L10: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L11: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L12: // GET_PACKAGE_VAR_OBJECT
  {
    if (VAR_PACKAGE_VAR_ID_SPVM__Webkit__JSON__Bool__TRUE < 0) {
      VAR_PACKAGE_VAR_ID_SPVM__Webkit__JSON__Bool__TRUE = env->get_package_var_id(env, "SPVM::Webkit::JSON::Bool", "$TRUE", "SPVM::Webkit::JSON::Bool");
      if (VAR_PACKAGE_VAR_ID_SPVM__Webkit__JSON__Bool__TRUE < 0) {
        void* exception = env->new_string_raw(env, "Package variable not found SPVM::Webkit::JSON::Bool $TRUE");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], *(void**)&(*(SPVM_VALUE**)(env->runtime + (intptr_t)env->runtime_package_vars_heap_offset))[VAR_PACKAGE_VAR_ID_SPVM__Webkit__JSON__Bool__TRUE]);
  }
L13: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[2];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L17;
L14: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L15: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L16: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[3];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L17;
L17: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L18: // END_SUB
  if (!exception_flag) {
    if (stack[0].oval != NULL) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(stack[0].oval); }
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON___encode_recursive(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[9] = {0};
  double double_vars[1];
  float float_vars[1];
  int64_t long_vars[1];
  int32_t int_vars[7];
  int32_t exception_flag = 0;
  int32_t mortal_stack[29];
  int32_t mortal_stack_top = 0;
  int16_t short_vars[1];
  int8_t byte_vars[1];
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  object_vars[1] = *(void**)&stack[1];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }
  int_vars[1] = *(int32_t*)&stack[2];

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L4: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L5: // IS_UNDEF
  int_vars[0] = object_vars[1] == NULL;
L6: // BOOL_INT
  int_vars[0] = int_vars[0];
L7: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L10; }
L8: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x6E\x75\x6C\x6C", 4));
L9: // GOTO
  goto L311;
L10: // IS_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Hash < 0) {
      BASIC_TYPE_ID_SPVM__Hash = env->get_basic_type_id(env, "SPVM::Hash");
      if (BASIC_TYPE_ID_SPVM__Hash < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Hash");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Hash;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
int_vars[0]      = env->is_type(env, object, check_basic_type_id, check_type_dimension);
    }
    else {
int_vars[0]      = 0;
    }
  }
L11: // BOOL_INT
  int_vars[0] = int_vars[0];
L12: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L112; }
L13: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L14: // CALL_SUB_OBJECT
  // SPVM::StringBuffer->new
  {
    if (SUB_ID_SPVM__StringBuffer__new < 0) {
      SUB_ID_SPVM__StringBuffer__new = env->get_sub_id(env, "SPVM::StringBuffer", "new", "SPVM::StringBuffer()");
      if (SUB_ID_SPVM__StringBuffer__new < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer new");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__new;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], stack[0].oval);
    }
  }
L15: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 444;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L16: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x7B';
L17: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L18: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[0];
L19: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L20: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 445;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L21: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 4;
  mortal_stack_top++;
L22: // CHECK_OBJECT_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Hash < 0) {
      BASIC_TYPE_ID_SPVM__Hash = env->get_basic_type_id(env, "SPVM::Hash");
      if (BASIC_TYPE_ID_SPVM__Hash < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Hash");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Hash;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object != NULL) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension_id = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
      if (object_basic_type_id == check_basic_type_id && object_type_dimension_id == check_type_dimension) {
        SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], object_vars[1]);
      }
      else {
        void* exception = env->new_string_raw(env, "Can't cast uncompatible type.");
        env->set_exception(env, exception);
        exception_flag = 1;
      }
    }
  }
L23: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 446;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L24: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 5;
  mortal_stack_top++;
L25: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[4];
L26: // CALL_SUB_OBJECT
  // SPVM::Hash->keys
  {
    if (SUB_ID_SPVM__Hash__keys < 0) {
      SUB_ID_SPVM__Hash__keys = env->get_sub_id(env, "SPVM::Hash", "keys", "string[](self)");
      if (SUB_ID_SPVM__Hash__keys < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Hash keys");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Hash__keys;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], stack[0].oval);
    }
  }
L27: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 447;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L28: // GET_FIELD_BYTE
  {
    if (__builtin_expect(FIELD_ID_SPVM__Webkit__JSON__canonical < 0, 0)) {
      FIELD_ID_SPVM__Webkit__JSON__canonical = env->get_field_id(env, "SPVM::Webkit::JSON", "canonical", "byte");
      if (FIELD_ID_SPVM__Webkit__JSON__canonical < 0) {
        void* exception = env->new_string_raw(env, "Field not found SPVM::Webkit::JSON canonical");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
      FIELD_BYTE_OFFSET_SPVM__Webkit__JSON__canonical = env->get_field_offset(env, FIELD_ID_SPVM__Webkit__JSON__canonical);
    };
    void* object = object_vars[0];
    if (__builtin_expect(object == NULL, 0)) {
      env->set_exception(env, env->new_string_raw(env, "Object must be not undef."));
      exception_flag = 1;
    }
    else {
      byte_vars[0] = *(int8_t*)((intptr_t)object + object_header_byte_size + FIELD_BYTE_OFFSET_SPVM__Webkit__JSON__canonical);
    }
  }
L29: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 448;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L30: // CONVERT_BYTE_TO_INT
  int_vars[3] = (int32_t)byte_vars[0];
L31: // BOOL_INT
  int_vars[0] = int_vars[3];
L32: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L37; }
L33: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[5];
L34: // CALL_SUB_VOID
  // SPVM::Sort->sortstr
  {
    if (SUB_ID_SPVM__Sort__sortstr < 0) {
      SUB_ID_SPVM__Sort__sortstr = env->get_sub_id(env, "SPVM::Sort", "sortstr", "void(string[])");
      if (SUB_ID_SPVM__Sort__sortstr < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Sort sortstr");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Sort__sortstr;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L35: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 449;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L36: // GOTO
  goto L37;
L37: // MOVE_CONSTANT_INT
  int_vars[3] = 0;
L38: // GOTO
  goto L97;
L39: // MOVE_CONSTANT_INT
  int_vars[4] = 0;
L40: // GT_INT
  int_vars[0] = (int_vars[3] > int_vars[4]);
L41: // BOOL_INT
  int_vars[0] = int_vars[0];
L42: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L49; }
L43: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x2C';
L44: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L45: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[0];
L46: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L47: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 453;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L48: // GOTO
  goto L49;
L49: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x22';
L50: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L51: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[0];
L52: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L53: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 455;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L54: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 6;
  mortal_stack_top++;
L55: // ARRAY_FETCH_OBJECT
  {
    void* array = object_vars[5];
    int32_t index = int_vars[3];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        void* object = ((SPVM_VALUE_object*)((intptr_t)array + object_header_byte_size))[index];
        SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], object); 
      } 
    } 
  } 
L56: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 456;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L57: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L58: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[6];
L59: // CALL_SUB_VOID
  // SPVM::StringBuffer->push
  {
    if (SUB_ID_SPVM__StringBuffer__push < 0) {
      SUB_ID_SPVM__StringBuffer__push = env->get_sub_id(env, "SPVM::StringBuffer", "push", "void(self,string)");
      if (SUB_ID_SPVM__StringBuffer__push < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L60: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 456;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L61: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], NULL);
L62: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x22';
L63: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L64: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[0];
L65: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L66: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 457;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L67: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x3A';
L68: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L69: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[0];
L70: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L71: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 458;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L72: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 6;
  mortal_stack_top++;
L73: // ARRAY_FETCH_OBJECT
  {
    void* array = object_vars[5];
    int32_t index = int_vars[3];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        void* object = ((SPVM_VALUE_object*)((intptr_t)array + object_header_byte_size))[index];
        SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], object); 
      } 
    } 
  } 
L74: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 459;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L75: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 7;
  mortal_stack_top++;
L76: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[4];
L77: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[6];
L78: // CALL_SUB_OBJECT
  // SPVM::Hash->get
  {
    if (SUB_ID_SPVM__Hash__get < 0) {
      SUB_ID_SPVM__Hash__get = env->get_sub_id(env, "SPVM::Hash", "get", "object(self,string)");
      if (SUB_ID_SPVM__Hash__get < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Hash get");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Hash__get;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[7], stack[0].oval);
    }
  }
L79: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 459;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L80: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L81: // ADD_INT
  int_vars[5] = int_vars[1] + int_vars[4];
L82: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 8;
  mortal_stack_top++;
L83: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L84: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[7];
L85: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[5];
L86: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_encode_recursive
  {
    if (SUB_ID_SPVM__Webkit__JSON___encode_recursive < 0) {
      SUB_ID_SPVM__Webkit__JSON___encode_recursive = env->get_sub_id(env, "SPVM::Webkit::JSON", "_encode_recursive", "string(self,object,int)");
      if (SUB_ID_SPVM__Webkit__JSON___encode_recursive < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _encode_recursive");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___encode_recursive;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___encode_recursive(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[8], stack[0].oval);
    }
  }
L87: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 459;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L88: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[7], NULL);
L89: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], NULL);
L90: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L91: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[8];
L92: // CALL_SUB_VOID
  // SPVM::StringBuffer->push
  {
    if (SUB_ID_SPVM__StringBuffer__push < 0) {
      SUB_ID_SPVM__StringBuffer__push = env->get_sub_id(env, "SPVM::StringBuffer", "push", "void(self,string)");
      if (SUB_ID_SPVM__StringBuffer__push < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L93: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 460;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L94: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 6;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L95: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L96: // ADD_INT
  int_vars[3] = int_vars[3] + int_vars[4];
L97: // ARRAY_LENGTH
  if (object_vars[5] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[4] = *(int32_t*)((intptr_t)object_vars[5] + (intptr_t)env->object_length_offset);
  }
L98: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 451;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L99: // LT_INT
  int_vars[0] = (int_vars[3] < int_vars[4]);
L100: // BOOL_INT
  int_vars[0] = int_vars[0];
L101: // IF_NE_ZERO
  if (int_vars[0]) { goto L39; }
L102: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 6;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L103: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x7D';
L104: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L105: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[0];
L106: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L107: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 462;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L108: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L109: // CALL_SUB_OBJECT
  // SPVM::StringBuffer->to_string
  {
    if (SUB_ID_SPVM__StringBuffer__to_string < 0) {
      SUB_ID_SPVM__StringBuffer__to_string = env->get_sub_id(env, "SPVM::StringBuffer", "to_string", "string(self)");
      if (SUB_ID_SPVM__StringBuffer__to_string < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer to_string");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__to_string;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], stack[0].oval);
    }
  }
L110: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 464;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L111: // GOTO
  goto L310;
L112: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L113: // IS_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__ObjectList < 0) {
      BASIC_TYPE_ID_SPVM__ObjectList = env->get_basic_type_id(env, "SPVM::ObjectList");
      if (BASIC_TYPE_ID_SPVM__ObjectList < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::ObjectList");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__ObjectList;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
int_vars[0]      = env->is_type(env, object, check_basic_type_id, check_type_dimension);
    }
    else {
int_vars[0]      = 0;
    }
  }
L114: // BOOL_INT
  int_vars[0] = int_vars[0];
L115: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L175; }
L116: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L117: // CALL_SUB_OBJECT
  // SPVM::StringBuffer->new
  {
    if (SUB_ID_SPVM__StringBuffer__new < 0) {
      SUB_ID_SPVM__StringBuffer__new = env->get_sub_id(env, "SPVM::StringBuffer", "new", "SPVM::StringBuffer()");
      if (SUB_ID_SPVM__StringBuffer__new < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer new");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__new;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], stack[0].oval);
    }
  }
L118: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 468;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L119: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x5B';
L120: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L121: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[0];
L122: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L123: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 469;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L124: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 4;
  mortal_stack_top++;
L125: // CHECK_OBJECT_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__ObjectList < 0) {
      BASIC_TYPE_ID_SPVM__ObjectList = env->get_basic_type_id(env, "SPVM::ObjectList");
      if (BASIC_TYPE_ID_SPVM__ObjectList < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::ObjectList");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__ObjectList;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object != NULL) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension_id = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
      if (object_basic_type_id == check_basic_type_id && object_type_dimension_id == check_type_dimension) {
        SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], object_vars[1]);
      }
      else {
        void* exception = env->new_string_raw(env, "Can't cast uncompatible type.");
        env->set_exception(env, exception);
        exception_flag = 1;
      }
    }
  }
L126: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 471;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L127: // GET_FIELD_INT
  {
    if (__builtin_expect(FIELD_ID_SPVM__ObjectList__length < 0, 0)) {
      FIELD_ID_SPVM__ObjectList__length = env->get_field_id(env, "SPVM::ObjectList", "length", "int");
      if (FIELD_ID_SPVM__ObjectList__length < 0) {
        void* exception = env->new_string_raw(env, "Field not found SPVM::ObjectList length");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
      FIELD_BYTE_OFFSET_SPVM__ObjectList__length = env->get_field_offset(env, FIELD_ID_SPVM__ObjectList__length);
    };
    void* object = object_vars[4];
    if (__builtin_expect(object == NULL, 0)) {
      env->set_exception(env, env->new_string_raw(env, "Object must be not undef."));
      exception_flag = 1;
    }
    else {
      int_vars[3] = *(int32_t*)((intptr_t)object + object_header_byte_size + FIELD_BYTE_OFFSET_SPVM__ObjectList__length);
    }
  }
L128: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 472;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L129: // MOVE_CONSTANT_INT
  int_vars[4] = 0;
L130: // GOTO
  goto L162;
L131: // MOVE_CONSTANT_INT
  int_vars[5] = 0;
L132: // GT_INT
  int_vars[0] = (int_vars[4] > int_vars[5]);
L133: // BOOL_INT
  int_vars[0] = int_vars[0];
L134: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L141; }
L135: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x2C';
L136: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L137: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[0];
L138: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L139: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 475;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L140: // GOTO
  goto L141;
L141: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 5;
  mortal_stack_top++;
L142: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[4];
L143: // PUSH_ARG_INT
  *(int32_t*)&stack[1] = int_vars[4];
L144: // CALL_SUB_OBJECT
  // SPVM::ObjectList->get
  {
    if (SUB_ID_SPVM__ObjectList__get < 0) {
      SUB_ID_SPVM__ObjectList__get = env->get_sub_id(env, "SPVM::ObjectList", "get", "object(self,int)");
      if (SUB_ID_SPVM__ObjectList__get < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::ObjectList get");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__ObjectList__get;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], stack[0].oval);
    }
  }
L145: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 477;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L146: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L147: // ADD_INT
  int_vars[6] = int_vars[1] + int_vars[5];
L148: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 6;
  mortal_stack_top++;
L149: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L150: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[5];
L151: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[6];
L152: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_encode_recursive
  {
    if (SUB_ID_SPVM__Webkit__JSON___encode_recursive < 0) {
      SUB_ID_SPVM__Webkit__JSON___encode_recursive = env->get_sub_id(env, "SPVM::Webkit::JSON", "_encode_recursive", "string(self,object,int)");
      if (SUB_ID_SPVM__Webkit__JSON___encode_recursive < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _encode_recursive");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___encode_recursive;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___encode_recursive(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], stack[0].oval);
    }
  }
L153: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 477;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L154: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], NULL);
L155: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L156: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[6];
L157: // CALL_SUB_VOID
  // SPVM::StringBuffer->push
  {
    if (SUB_ID_SPVM__StringBuffer__push < 0) {
      SUB_ID_SPVM__StringBuffer__push = env->get_sub_id(env, "SPVM::StringBuffer", "push", "void(self,string)");
      if (SUB_ID_SPVM__StringBuffer__push < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L158: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 478;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L159: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 5;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L160: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L161: // ADD_INT
  int_vars[4] = int_vars[4] + int_vars[5];
L162: // LT_INT
  int_vars[0] = (int_vars[4] < int_vars[3]);
L163: // BOOL_INT
  int_vars[0] = int_vars[0];
L164: // IF_NE_ZERO
  if (int_vars[0]) { goto L131; }
L165: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 5;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L166: // MOVE_CONSTANT_BYTE
  byte_vars[0] = '\x5D';
L167: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L168: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[0];
L169: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L170: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 480;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L171: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L172: // CALL_SUB_OBJECT
  // SPVM::StringBuffer->to_string
  {
    if (SUB_ID_SPVM__StringBuffer__to_string < 0) {
      SUB_ID_SPVM__StringBuffer__to_string = env->get_sub_id(env, "SPVM::StringBuffer", "to_string", "string(self)");
      if (SUB_ID_SPVM__StringBuffer__to_string < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer to_string");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__to_string;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], stack[0].oval);
    }
  }
L173: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 482;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L174: // GOTO
  goto L309;
L175: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L176: // IS_TYPE
  {
    if (BASIC_TYPE_ID_byte < 0) {
      BASIC_TYPE_ID_byte = env->get_basic_type_id(env, "byte");
      if (BASIC_TYPE_ID_byte < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found byte");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_byte;
    int32_t check_type_dimension = 1;
    void* object = object_vars[1];
    if (object) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
int_vars[0]      = env->is_type(env, object, check_basic_type_id, check_type_dimension);
    }
    else {
int_vars[0]      = 0;
    }
  }
L177: // BOOL_INT
  int_vars[0] = int_vars[0];
L178: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L200; }
L179: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L180: // CHECK_OBJECT_TYPE
  {
    if (BASIC_TYPE_ID_byte < 0) {
      BASIC_TYPE_ID_byte = env->get_basic_type_id(env, "byte");
      if (BASIC_TYPE_ID_byte < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found byte");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_byte;
    int32_t check_type_dimension = 1;
    void* object = object_vars[1];
    if (object != NULL) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension_id = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
      if (object_basic_type_id == check_basic_type_id && object_type_dimension_id == check_type_dimension) {
        SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], object_vars[1]);
      }
      else {
        void* exception = env->new_string_raw(env, "Can't cast uncompatible type.");
        env->set_exception(env, exception);
        exception_flag = 1;
      }
    }
  }
L181: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 486;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L182: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 4;
  mortal_stack_top++;
L183: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L184: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_escape_string
  {
    if (SUB_ID_SPVM__Webkit__JSON___escape_string < 0) {
      SUB_ID_SPVM__Webkit__JSON___escape_string = env->get_sub_id(env, "SPVM::Webkit::JSON", "_escape_string", "string(string)");
      if (SUB_ID_SPVM__Webkit__JSON___escape_string < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _escape_string");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___escape_string;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___escape_string(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], stack[0].oval);
    }
  }
L185: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 486;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L186: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L187: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L188: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], env->new_string_len_raw(env, "\x22", 1));
L189: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 5;
  mortal_stack_top++;
L190: // CONCAT
  {
    void* string1 = object_vars[3];
    void* string2 = object_vars[4];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], string3);
    }
  }
L191: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 487;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L192: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 6;
  mortal_stack_top++;
L193: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], env->new_string_len_raw(env, "\x22", 1));
L194: // CONCAT
  {
    void* string1 = object_vars[5];
    void* string2 = object_vars[6];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], string3);
    }
  }
L195: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 487;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L196: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], NULL);
L197: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], NULL);
L198: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L199: // GOTO
  goto L308;
L200: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L201: // IS_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Byte < 0) {
      BASIC_TYPE_ID_SPVM__Byte = env->get_basic_type_id(env, "SPVM::Byte");
      if (BASIC_TYPE_ID_SPVM__Byte < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Byte");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Byte;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
int_vars[0]      = env->is_type(env, object, check_basic_type_id, check_type_dimension);
    }
    else {
int_vars[0]      = 0;
    }
  }
L202: // BOOL_INT
  int_vars[0] = int_vars[0];
L203: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L213; }
L204: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L205: // CHECK_OBJECT_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Byte < 0) {
      BASIC_TYPE_ID_SPVM__Byte = env->get_basic_type_id(env, "SPVM::Byte");
      if (BASIC_TYPE_ID_SPVM__Byte < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Byte");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Byte;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object != NULL) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension_id = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
      if (object_basic_type_id == check_basic_type_id && object_type_dimension_id == check_type_dimension) {
        SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], object_vars[1]);
      }
      else {
        void* exception = env->new_string_raw(env, "Can't cast uncompatible type.");
        env->set_exception(env, exception);
        exception_flag = 1;
      }
    }
  }
L206: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 491;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L207: // GET_FIELD_BYTE
  {
    if (__builtin_expect(FIELD_ID_SPVM__Byte__val < 0, 0)) {
      FIELD_ID_SPVM__Byte__val = env->get_field_id(env, "SPVM::Byte", "val", "byte");
      if (FIELD_ID_SPVM__Byte__val < 0) {
        void* exception = env->new_string_raw(env, "Field not found SPVM::Byte val");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
      FIELD_BYTE_OFFSET_SPVM__Byte__val = env->get_field_offset(env, FIELD_ID_SPVM__Byte__val);
    };
    void* object = object_vars[3];
    if (__builtin_expect(object == NULL, 0)) {
      env->set_exception(env, env->new_string_raw(env, "Object must be not undef."));
      exception_flag = 1;
    }
    else {
      byte_vars[0] = *(int8_t*)((intptr_t)object + object_header_byte_size + FIELD_BYTE_OFFSET_SPVM__Byte__val);
    }
  }
L208: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 491;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L209: // CONVERT_BYTE_TO_DOUBLE
  double_vars[0] = (double)byte_vars[0];
L210: // CONVERT_DOUBLE_TO_STRING
  {
    sprintf(convert_string_buffer, "%g", double_vars[0]);
    int32_t string_length = strlen(convert_string_buffer);
    void* string = env->new_string_len_raw(env, convert_string_buffer, string_length);
    SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], string);
  }
L211: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L212: // GOTO
  goto L307;
L213: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L214: // IS_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Short < 0) {
      BASIC_TYPE_ID_SPVM__Short = env->get_basic_type_id(env, "SPVM::Short");
      if (BASIC_TYPE_ID_SPVM__Short < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Short");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Short;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
int_vars[0]      = env->is_type(env, object, check_basic_type_id, check_type_dimension);
    }
    else {
int_vars[0]      = 0;
    }
  }
L215: // BOOL_INT
  int_vars[0] = int_vars[0];
L216: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L226; }
L217: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L218: // CHECK_OBJECT_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Short < 0) {
      BASIC_TYPE_ID_SPVM__Short = env->get_basic_type_id(env, "SPVM::Short");
      if (BASIC_TYPE_ID_SPVM__Short < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Short");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Short;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object != NULL) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension_id = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
      if (object_basic_type_id == check_basic_type_id && object_type_dimension_id == check_type_dimension) {
        SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], object_vars[1]);
      }
      else {
        void* exception = env->new_string_raw(env, "Can't cast uncompatible type.");
        env->set_exception(env, exception);
        exception_flag = 1;
      }
    }
  }
L219: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 495;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L220: // GET_FIELD_SHORT
  {
    if (__builtin_expect(FIELD_ID_SPVM__Short__val < 0, 0)) {
      FIELD_ID_SPVM__Short__val = env->get_field_id(env, "SPVM::Short", "val", "short");
      if (FIELD_ID_SPVM__Short__val < 0) {
        void* exception = env->new_string_raw(env, "Field not found SPVM::Short val");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
      FIELD_BYTE_OFFSET_SPVM__Short__val = env->get_field_offset(env, FIELD_ID_SPVM__Short__val);
    };
    void* object = object_vars[3];
    if (__builtin_expect(object == NULL, 0)) {
      env->set_exception(env, env->new_string_raw(env, "Object must be not undef."));
      exception_flag = 1;
    }
    else {
      short_vars[0] = *(int16_t*)((intptr_t)object + object_header_byte_size + FIELD_BYTE_OFFSET_SPVM__Short__val);
    }
  }
L221: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 495;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L222: // CONVERT_SHORT_TO_DOUBLE
  double_vars[0] = (double)short_vars[0];
L223: // CONVERT_DOUBLE_TO_STRING
  {
    sprintf(convert_string_buffer, "%g", double_vars[0]);
    int32_t string_length = strlen(convert_string_buffer);
    void* string = env->new_string_len_raw(env, convert_string_buffer, string_length);
    SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], string);
  }
L224: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L225: // GOTO
  goto L306;
L226: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L227: // IS_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Int < 0) {
      BASIC_TYPE_ID_SPVM__Int = env->get_basic_type_id(env, "SPVM::Int");
      if (BASIC_TYPE_ID_SPVM__Int < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Int");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Int;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
int_vars[0]      = env->is_type(env, object, check_basic_type_id, check_type_dimension);
    }
    else {
int_vars[0]      = 0;
    }
  }
L228: // BOOL_INT
  int_vars[0] = int_vars[0];
L229: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L239; }
L230: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L231: // CHECK_OBJECT_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Int < 0) {
      BASIC_TYPE_ID_SPVM__Int = env->get_basic_type_id(env, "SPVM::Int");
      if (BASIC_TYPE_ID_SPVM__Int < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Int");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Int;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object != NULL) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension_id = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
      if (object_basic_type_id == check_basic_type_id && object_type_dimension_id == check_type_dimension) {
        SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], object_vars[1]);
      }
      else {
        void* exception = env->new_string_raw(env, "Can't cast uncompatible type.");
        env->set_exception(env, exception);
        exception_flag = 1;
      }
    }
  }
L232: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 499;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L233: // GET_FIELD_INT
  {
    if (__builtin_expect(FIELD_ID_SPVM__Int__val < 0, 0)) {
      FIELD_ID_SPVM__Int__val = env->get_field_id(env, "SPVM::Int", "val", "int");
      if (FIELD_ID_SPVM__Int__val < 0) {
        void* exception = env->new_string_raw(env, "Field not found SPVM::Int val");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
      FIELD_BYTE_OFFSET_SPVM__Int__val = env->get_field_offset(env, FIELD_ID_SPVM__Int__val);
    };
    void* object = object_vars[3];
    if (__builtin_expect(object == NULL, 0)) {
      env->set_exception(env, env->new_string_raw(env, "Object must be not undef."));
      exception_flag = 1;
    }
    else {
      int_vars[3] = *(int32_t*)((intptr_t)object + object_header_byte_size + FIELD_BYTE_OFFSET_SPVM__Int__val);
    }
  }
L234: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 499;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L235: // CONVERT_INT_TO_DOUBLE
  double_vars[0] = (double)int_vars[3];
L236: // CONVERT_DOUBLE_TO_STRING
  {
    sprintf(convert_string_buffer, "%g", double_vars[0]);
    int32_t string_length = strlen(convert_string_buffer);
    void* string = env->new_string_len_raw(env, convert_string_buffer, string_length);
    SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], string);
  }
L237: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L238: // GOTO
  goto L305;
L239: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L240: // IS_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Long < 0) {
      BASIC_TYPE_ID_SPVM__Long = env->get_basic_type_id(env, "SPVM::Long");
      if (BASIC_TYPE_ID_SPVM__Long < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Long");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Long;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
int_vars[0]      = env->is_type(env, object, check_basic_type_id, check_type_dimension);
    }
    else {
int_vars[0]      = 0;
    }
  }
L241: // BOOL_INT
  int_vars[0] = int_vars[0];
L242: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L252; }
L243: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L244: // CHECK_OBJECT_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Long < 0) {
      BASIC_TYPE_ID_SPVM__Long = env->get_basic_type_id(env, "SPVM::Long");
      if (BASIC_TYPE_ID_SPVM__Long < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Long");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Long;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object != NULL) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension_id = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
      if (object_basic_type_id == check_basic_type_id && object_type_dimension_id == check_type_dimension) {
        SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], object_vars[1]);
      }
      else {
        void* exception = env->new_string_raw(env, "Can't cast uncompatible type.");
        env->set_exception(env, exception);
        exception_flag = 1;
      }
    }
  }
L245: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 503;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L246: // GET_FIELD_LONG
  {
    if (__builtin_expect(FIELD_ID_SPVM__Long__val < 0, 0)) {
      FIELD_ID_SPVM__Long__val = env->get_field_id(env, "SPVM::Long", "val", "long");
      if (FIELD_ID_SPVM__Long__val < 0) {
        void* exception = env->new_string_raw(env, "Field not found SPVM::Long val");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
      FIELD_BYTE_OFFSET_SPVM__Long__val = env->get_field_offset(env, FIELD_ID_SPVM__Long__val);
    };
    void* object = object_vars[3];
    if (__builtin_expect(object == NULL, 0)) {
      env->set_exception(env, env->new_string_raw(env, "Object must be not undef."));
      exception_flag = 1;
    }
    else {
      long_vars[0] = *(int64_t*)((intptr_t)object + object_header_byte_size + FIELD_BYTE_OFFSET_SPVM__Long__val);
    }
  }
L247: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 503;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L248: // CONVERT_LONG_TO_DOUBLE
  double_vars[0] = (double)long_vars[0];
L249: // CONVERT_DOUBLE_TO_STRING
  {
    sprintf(convert_string_buffer, "%g", double_vars[0]);
    int32_t string_length = strlen(convert_string_buffer);
    void* string = env->new_string_len_raw(env, convert_string_buffer, string_length);
    SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], string);
  }
L250: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L251: // GOTO
  goto L304;
L252: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L253: // IS_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Float < 0) {
      BASIC_TYPE_ID_SPVM__Float = env->get_basic_type_id(env, "SPVM::Float");
      if (BASIC_TYPE_ID_SPVM__Float < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Float");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Float;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
int_vars[0]      = env->is_type(env, object, check_basic_type_id, check_type_dimension);
    }
    else {
int_vars[0]      = 0;
    }
  }
L254: // BOOL_INT
  int_vars[0] = int_vars[0];
L255: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L265; }
L256: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L257: // CHECK_OBJECT_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Float < 0) {
      BASIC_TYPE_ID_SPVM__Float = env->get_basic_type_id(env, "SPVM::Float");
      if (BASIC_TYPE_ID_SPVM__Float < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Float");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Float;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object != NULL) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension_id = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
      if (object_basic_type_id == check_basic_type_id && object_type_dimension_id == check_type_dimension) {
        SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], object_vars[1]);
      }
      else {
        void* exception = env->new_string_raw(env, "Can't cast uncompatible type.");
        env->set_exception(env, exception);
        exception_flag = 1;
      }
    }
  }
L258: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 507;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L259: // GET_FIELD_FLOAT
  {
    if (__builtin_expect(FIELD_ID_SPVM__Float__val < 0, 0)) {
      FIELD_ID_SPVM__Float__val = env->get_field_id(env, "SPVM::Float", "val", "float");
      if (FIELD_ID_SPVM__Float__val < 0) {
        void* exception = env->new_string_raw(env, "Field not found SPVM::Float val");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
      FIELD_BYTE_OFFSET_SPVM__Float__val = env->get_field_offset(env, FIELD_ID_SPVM__Float__val);
    };
    void* object = object_vars[3];
    if (__builtin_expect(object == NULL, 0)) {
      env->set_exception(env, env->new_string_raw(env, "Object must be not undef."));
      exception_flag = 1;
    }
    else {
      float_vars[0] = *(float*)((intptr_t)object + object_header_byte_size + FIELD_BYTE_OFFSET_SPVM__Float__val);
    }
  }
L260: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 507;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L261: // CONVERT_FLOAT_TO_DOUBLE
  double_vars[0] = (double)float_vars[0];
L262: // CONVERT_DOUBLE_TO_STRING
  {
    sprintf(convert_string_buffer, "%g", double_vars[0]);
    int32_t string_length = strlen(convert_string_buffer);
    void* string = env->new_string_len_raw(env, convert_string_buffer, string_length);
    SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], string);
  }
L263: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L264: // GOTO
  goto L303;
L265: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L266: // IS_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Double < 0) {
      BASIC_TYPE_ID_SPVM__Double = env->get_basic_type_id(env, "SPVM::Double");
      if (BASIC_TYPE_ID_SPVM__Double < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Double");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Double;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
int_vars[0]      = env->is_type(env, object, check_basic_type_id, check_type_dimension);
    }
    else {
int_vars[0]      = 0;
    }
  }
L267: // BOOL_INT
  int_vars[0] = int_vars[0];
L268: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L277; }
L269: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L270: // CHECK_OBJECT_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Double < 0) {
      BASIC_TYPE_ID_SPVM__Double = env->get_basic_type_id(env, "SPVM::Double");
      if (BASIC_TYPE_ID_SPVM__Double < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Double");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Double;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object != NULL) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension_id = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
      if (object_basic_type_id == check_basic_type_id && object_type_dimension_id == check_type_dimension) {
        SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], object_vars[1]);
      }
      else {
        void* exception = env->new_string_raw(env, "Can't cast uncompatible type.");
        env->set_exception(env, exception);
        exception_flag = 1;
      }
    }
  }
L271: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 511;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L272: // GET_FIELD_DOUBLE
  {
    if (__builtin_expect(FIELD_ID_SPVM__Double__val < 0, 0)) {
      FIELD_ID_SPVM__Double__val = env->get_field_id(env, "SPVM::Double", "val", "double");
      if (FIELD_ID_SPVM__Double__val < 0) {
        void* exception = env->new_string_raw(env, "Field not found SPVM::Double val");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
      FIELD_BYTE_OFFSET_SPVM__Double__val = env->get_field_offset(env, FIELD_ID_SPVM__Double__val);
    };
    void* object = object_vars[3];
    if (__builtin_expect(object == NULL, 0)) {
      env->set_exception(env, env->new_string_raw(env, "Object must be not undef."));
      exception_flag = 1;
    }
    else {
      double_vars[0] = *(double*)((intptr_t)object + object_header_byte_size + FIELD_BYTE_OFFSET_SPVM__Double__val);
    }
  }
L273: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 511;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L274: // CONVERT_DOUBLE_TO_STRING
  {
    sprintf(convert_string_buffer, "%g", double_vars[0]);
    int32_t string_length = strlen(convert_string_buffer);
    void* string = env->new_string_len_raw(env, convert_string_buffer, string_length);
    SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], string);
  }
L275: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L276: // GOTO
  goto L302;
L277: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L278: // IS_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Webkit__JSON__Bool < 0) {
      BASIC_TYPE_ID_SPVM__Webkit__JSON__Bool = env->get_basic_type_id(env, "SPVM::Webkit::JSON::Bool");
      if (BASIC_TYPE_ID_SPVM__Webkit__JSON__Bool < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Webkit::JSON::Bool");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Webkit__JSON__Bool;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
int_vars[0]      = env->is_type(env, object, check_basic_type_id, check_type_dimension);
    }
    else {
int_vars[0]      = 0;
    }
  }
L279: // BOOL_INT
  int_vars[0] = int_vars[0];
L280: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L294; }
L281: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L282: // CHECK_OBJECT_TYPE
  {
    if (BASIC_TYPE_ID_SPVM__Webkit__JSON__Bool < 0) {
      BASIC_TYPE_ID_SPVM__Webkit__JSON__Bool = env->get_basic_type_id(env, "SPVM::Webkit::JSON::Bool");
      if (BASIC_TYPE_ID_SPVM__Webkit__JSON__Bool < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Webkit::JSON::Bool");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t check_basic_type_id = BASIC_TYPE_ID_SPVM__Webkit__JSON__Bool;
    int32_t check_type_dimension = 0;
    void* object = object_vars[1];
    if (object != NULL) {
      int32_t object_basic_type_id = *(int32_t*)((intptr_t)object + (intptr_t)env->object_basic_type_id_offset);
      int32_t object_type_dimension_id = *(uint8_t*)((intptr_t)object + (intptr_t)env->object_type_dimension_offset);
      if (object_basic_type_id == check_basic_type_id && object_type_dimension_id == check_type_dimension) {
        SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], object_vars[1]);
      }
      else {
        void* exception = env->new_string_raw(env, "Can't cast uncompatible type.");
        env->set_exception(env, exception);
        exception_flag = 1;
      }
    }
  }
L283: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 515;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L284: // GET_FIELD_INT
  {
    if (__builtin_expect(FIELD_ID_SPVM__Webkit__JSON__Bool__val < 0, 0)) {
      FIELD_ID_SPVM__Webkit__JSON__Bool__val = env->get_field_id(env, "SPVM::Webkit::JSON::Bool", "val", "int");
      if (FIELD_ID_SPVM__Webkit__JSON__Bool__val < 0) {
        void* exception = env->new_string_raw(env, "Field not found SPVM::Webkit::JSON::Bool val");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
      FIELD_BYTE_OFFSET_SPVM__Webkit__JSON__Bool__val = env->get_field_offset(env, FIELD_ID_SPVM__Webkit__JSON__Bool__val);
    };
    void* object = object_vars[3];
    if (__builtin_expect(object == NULL, 0)) {
      env->set_exception(env, env->new_string_raw(env, "Object must be not undef."));
      exception_flag = 1;
    }
    else {
      int_vars[3] = *(int32_t*)((intptr_t)object + object_header_byte_size + FIELD_BYTE_OFFSET_SPVM__Webkit__JSON__Bool__val);
    }
  }
L285: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 515;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L286: // BOOL_INT
  int_vars[0] = int_vars[3];
L287: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L291; }
L288: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L289: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x74\x72\x75\x65", 4));
L290: // GOTO
  goto L292;
L291: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x66\x61\x6C\x73\x65", 5));
L292: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L293: // GOTO
  goto L301;
L294: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L295: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L296: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], env->new_string_len_raw(env, "\x49\x6E\x76\x61\x6C\x69\x64\x20\x64\x61\x74\x61\x20\x74\x79\x70\x65", 17));
L297: // SET_EXCEPTION_VAR
  env->set_exception(env, object_vars[3]);
L298: // SET_CROAK_FLAG_TRUE
  exception_flag = 1;
L299: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_encode_recursive";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 523;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L317;
  }
L300: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L301: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L302: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L303: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L304: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L305: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L306: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L307: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L308: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L309: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L310: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L311: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L312: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L313: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[2];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L317;
L314: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L315: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L316: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[3];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L317;
L317: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L318: // END_SUB
  if (!exception_flag) {
    if (stack[0].oval != NULL) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(stack[0].oval); }
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON___escape_string(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[4] = {0};
  int32_t int_vars[10];
  int32_t exception_flag = 0;
  int32_t mortal_stack[5];
  int32_t mortal_stack_top = 0;
  int8_t byte_vars[3];
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // ARRAY_LENGTH
  if (object_vars[0] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[1] = *(int32_t*)((intptr_t)object_vars[0] + (intptr_t)env->object_length_offset);
  }
L3: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_escape_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 383;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L63;
  }
L4: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L5: // CALL_SUB_OBJECT
  // SPVM::StringBuffer->new
  {
    if (SUB_ID_SPVM__StringBuffer__new < 0) {
      SUB_ID_SPVM__StringBuffer__new = env->get_sub_id(env, "SPVM::StringBuffer", "new", "SPVM::StringBuffer()");
      if (SUB_ID_SPVM__StringBuffer__new < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer new");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__new;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[1], stack[0].oval);
    }
  }
L6: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_escape_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 384;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L63;
  }
L7: // MOVE_CONSTANT_INT
  int_vars[3] = 0;
L8: // GOTO
  goto L52;
L9: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[0];
    int32_t index = int_vars[3];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L10: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_escape_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 386;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L63;
  }
L11: // MOVE_CONSTANT_INT
  int_vars[4] = -1;
L12: // CONVERT_INT_TO_BYTE
  byte_vars[1] = (int8_t)int_vars[4];
L13: // CONVERT_BYTE_TO_INT
  int_vars[4] = (int32_t)byte_vars[0];
L14: // LOOKUP_SWITCH
  switch(int_vars[4]) {
    case 8: goto L21;
    case 9: goto L29;
    case 10: goto L25;
    case 12: goto L23;
    case 13: goto L27;
    case 34: goto L15;
    case 47: goto L19;
    case 92: goto L17;
    default: goto L31;
  }
L15: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x22';
L16: // GOTO
  goto L31;
L17: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x5C';
L18: // GOTO
  goto L31;
L19: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x2F';
L20: // GOTO
  goto L31;
L21: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x62';
L22: // GOTO
  goto L31;
L23: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x66';
L24: // GOTO
  goto L31;
L25: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x6E';
L26: // GOTO
  goto L31;
L27: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x72';
L28: // GOTO
  goto L31;
L29: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x74';
L30: // GOTO
  goto L31;
L31: // CONVERT_BYTE_TO_INT
  int_vars[7] = (int32_t)byte_vars[1];
L32: // MOVE_CONSTANT_INT
  int_vars[8] = -1;
L33: // EQ_INT
  int_vars[0] = (int_vars[7] == int_vars[8]);
L34: // BOOL_INT
  int_vars[0] = int_vars[0];
L35: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L41; }
L36: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L37: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[0];
L38: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L39: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_escape_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 424;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L63;
  }
L40: // GOTO
  goto L50;
L41: // MOVE_CONSTANT_BYTE
  byte_vars[2] = '\x5C';
L42: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L43: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[2];
L44: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L45: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_escape_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 427;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L63;
  }
L46: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L47: // PUSH_ARG_BYTE
  *(int8_t*)&stack[1] = byte_vars[1];
L48: // CALL_SUB_VOID
  // SPVM::StringBuffer->push_char
  {
    if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
      SUB_ID_SPVM__StringBuffer__push_char = env->get_sub_id(env, "SPVM::StringBuffer", "push_char", "void(self,byte)");
      if (SUB_ID_SPVM__StringBuffer__push_char < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer push_char");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__push_char;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
    }
  }
L49: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_escape_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 428;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L63;
  }
L50: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L51: // ADD_INT
  int_vars[3] = int_vars[3] + int_vars[4];
L52: // LT_INT
  int_vars[0] = (int_vars[3] < int_vars[1]);
L53: // BOOL_INT
  int_vars[0] = int_vars[0];
L54: // IF_NE_ZERO
  if (int_vars[0]) { goto L9; }
L55: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L56: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[1];
L57: // CALL_SUB_OBJECT
  // SPVM::StringBuffer->to_string
  {
    if (SUB_ID_SPVM__StringBuffer__to_string < 0) {
      SUB_ID_SPVM__StringBuffer__to_string = env->get_sub_id(env, "SPVM::StringBuffer", "to_string", "string(self)");
      if (SUB_ID_SPVM__StringBuffer__to_string < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::StringBuffer to_string");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__StringBuffer__to_string;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], stack[0].oval);
    }
  }
L58: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_escape_string";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 431;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L63;
  }
L59: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[2];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L63;
L60: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L61: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L62: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[3];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L63;
L63: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L64: // END_SUB
  if (!exception_flag) {
    if (stack[0].oval != NULL) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(stack[0].oval); }
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON___expect_char(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[6] = {0};
  void* ref_vars[1] = {0};
  int32_t int_vars[7];
  int32_t exception_flag = 0;
  int32_t mortal_stack[7];
  int32_t mortal_stack_top = 0;
  int8_t byte_vars[2];
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  ref_vars[0] = *(void**)&stack[1];
  byte_vars[0] = *(int8_t*)&stack[2];

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // ARRAY_LENGTH
  if (object_vars[0] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[1] = *(int32_t*)((intptr_t)object_vars[0] + (intptr_t)env->object_length_offset);
  }
L3: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_char";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 44;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L4: // GET_DEREF_INT
  int_vars[3] = *(int32_t*)*(void**)&ref_vars[0];
L5: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L6: // ADD_INT
  int_vars[5] = int_vars[3] + int_vars[4];
L7: // LE_INT
  int_vars[0] = (int_vars[5] <= int_vars[1]);
L8: // BOOL_INT
  int_vars[0] = int_vars[0];
L9: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L24; }
L10: // GET_DEREF_INT
  int_vars[3] = *(int32_t*)*(void**)&ref_vars[0];
L11: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[0];
    int32_t index = int_vars[3];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[1] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L12: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_char";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 45;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L13: // CONVERT_BYTE_TO_INT
  int_vars[4] = (int32_t)byte_vars[1];
L14: // CONVERT_BYTE_TO_INT
  int_vars[5] = (int32_t)byte_vars[0];
L15: // EQ_INT
  int_vars[0] = (int_vars[4] == int_vars[5]);
L16: // BOOL_INT
  int_vars[0] = int_vars[0];
L17: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L21; }
L18: // MOVE_CONSTANT_INT
  int_vars[3] = 1;
L19: // BOOL_INT
  int_vars[0] = int_vars[3];
L20: // GOTO
  goto L23;
L21: // MOVE_CONSTANT_INT
  int_vars[4] = 0;
L22: // BOOL_INT
  int_vars[0] = int_vars[4];
L23: // GOTO
  goto L26;
L24: // MOVE_CONSTANT_INT
  int_vars[5] = 0;
L25: // BOOL_INT
  int_vars[0] = int_vars[5];
L26: // BOOL_INT
  int_vars[0] = int_vars[0];
L27: // IF_NE_ZERO
  if (int_vars[0]) { goto L57; }
L28: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L29: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[1], env->new_string_len_raw(env, "\x45\x78\x70\x65\x63\x74\x65\x64\x20\x63\x68\x61\x72\x3A\x20\x27", 16));
L30: // MOVE_CONSTANT_INT
  int_vars[3] = 1;
L31: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L32: // NEW_BYTE_ARRAY
  {
    int32_t length = *(SPVM_VALUE_int*)&int_vars[3];
    if (length >= 0) {
      void* object = env->new_byte_array_raw(env, length);
      SPVM_RUNTIME_API_OBJECT_ASSIGN((void**)&object_vars[2], object);
    }
    else {
      void* exception = env->new_string_raw(env, "Array length must be more than or equal to 0");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
  }
L33: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_char";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 46;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L34: // MOVE_CONSTANT_INT
  int_vars[4] = 0;
L35: // ARRAY_STORE_BYTE
  {
    void* array = object_vars[2];
    int32_t index = int_vars[4];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
((int8_t*)((intptr_t)array + object_header_byte_size))[index]
 = byte_vars[0];
      } 
    } 
  } 
L36: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_char";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 46;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L37: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L38: // CONCAT
  {
    void* string1 = object_vars[1];
    void* string2 = object_vars[2];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], string3);
    }
  }
L39: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_char";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 46;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L40: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 4;
  mortal_stack_top++;
L41: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], env->new_string_len_raw(env, "\x27\x20\x64\x6F\x65\x73\x6E\x27\x74\x20\x65\x78\x69\x73\x74", 15));
L42: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 5;
  mortal_stack_top++;
L43: // CONCAT
  {
    void* string1 = object_vars[3];
    void* string2 = object_vars[4];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], string3);
    }
  }
L44: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_char";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 46;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L45: // GET_DEREF_INT
  int_vars[5] = *(int32_t*)*(void**)&ref_vars[0];
L46: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[5];
L47: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[0];
L48: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[5];
L49: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L50: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_char";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 46;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L64;
  }
L51: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], NULL);
L52: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], NULL);
L53: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L54: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L55: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[1], NULL);
L56: // GOTO
  goto L58;
L57: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 1;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L58: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 1;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L59: // GET_DEREF_INT
  int_vars[3] = *(int32_t*)*(void**)&ref_vars[0];
L60: // MOVE_CONSTANT_INT
  int_vars[4] = 1;
L61: // ADD_INT
  int_vars[5] = int_vars[3] + int_vars[4];
L62: // SET_DEREF_INT
  *(int32_t*)*(void**)&ref_vars[0] = int_vars[5];
L63: // RETURN_VOID
  goto L64;
L64: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L65: // END_SUB
  if (!exception_flag) {
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON___expect_token(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[7] = {0};
  void* ref_vars[1] = {0};
  int32_t int_vars[7];
  int32_t exception_flag = 0;
  int32_t mortal_stack[12];
  int32_t mortal_stack_top = 0;
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  ref_vars[0] = *(void**)&stack[1];
  object_vars[1] = *(void**)&stack[2];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // ARRAY_LENGTH
  if (object_vars[0] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[1] = *(int32_t*)((intptr_t)object_vars[0] + (intptr_t)env->object_length_offset);
  }
L4: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_token";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 52;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L73;
  }
L5: // ARRAY_LENGTH
  if (object_vars[1] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[3] = *(int32_t*)((intptr_t)object_vars[1] + (intptr_t)env->object_length_offset);
  }
L6: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_token";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 53;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L73;
  }
L7: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L8: // ADD_INT
  int_vars[5] = int_vars[4] + int_vars[3];
L9: // LE_INT
  int_vars[0] = (int_vars[5] <= int_vars[1]);
L10: // BOOL_INT
  int_vars[0] = int_vars[0];
L11: // IF_NE_ZERO
  if (int_vars[0]) { goto L33; }
L12: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L13: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], env->new_string_len_raw(env, "\x45\x78\x70\x65\x63\x74\x65\x64\x20\x74\x6F\x6B\x65\x6E\x3A\x20", 16));
L14: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L15: // CONCAT
  {
    void* string1 = object_vars[2];
    void* string2 = object_vars[1];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], string3);
    }
  }
L16: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_token";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 55;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L73;
  }
L17: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 4;
  mortal_stack_top++;
L18: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], env->new_string_len_raw(env, "\x20\x64\x6F\x65\x73\x6E\x27\x74\x20\x65\x78\x69\x73\x74", 14));
L19: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 5;
  mortal_stack_top++;
L20: // CONCAT
  {
    void* string1 = object_vars[3];
    void* string2 = object_vars[4];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], string3);
    }
  }
L21: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_token";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 55;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L73;
  }
L22: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L23: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[5];
L24: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[0];
L25: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[4];
L26: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L27: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_token";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 55;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L73;
  }
L28: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], NULL);
L29: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], NULL);
L30: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L31: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], NULL);
L32: // GOTO
  goto L34;
L33: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L34: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 2;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L35: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L36: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L37: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L38: // PUSH_ARG_INT
  *(int32_t*)&stack[1] = int_vars[4];
L39: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[3];
L40: // CALL_SUB_OBJECT
  // SPVM::Util->substr
  {
    if (SUB_ID_SPVM__Util__substr < 0) {
      SUB_ID_SPVM__Util__substr = env->get_sub_id(env, "SPVM::Util", "substr", "string(string,int,int)");
      if (SUB_ID_SPVM__Util__substr < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Util substr");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Util__substr;
    exception_flag = env->call_sub(env, call_sub_id, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], stack[0].oval);
    }
  }
L41: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_token";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 57;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L73;
  }
L42: // STRING_EQ
  {
    void* object1 = object_vars[2];
    void* object2 = object_vars[1];
    if (__builtin_expect(object1 == NULL || object2 == NULL, 0)) {
int_vars[0] = 0;
      env->set_exception(env, env->new_string_raw(env, "Use of uninitialized value in string comparison operator")); 
      exception_flag = 1;
    }
    else {
      int32_t length1 = *(SPVM_VALUE_int*)((intptr_t)object1 + (intptr_t)env->object_length_offset);
      int32_t lenght2 = *(SPVM_VALUE_int*)((intptr_t)object2 + (intptr_t)env->object_length_offset);
      SPVM_VALUE_byte* bytes1 = env->get_elems_byte(env, object1);
      SPVM_VALUE_byte* bytes2 = env->get_elems_byte(env, object2);
      int32_t short_string_length = length1 < lenght2 ? length1 : lenght2;
      int32_t retval = memcmp(bytes1, bytes2, short_string_length);
      int32_t cmp;
      if (retval) {
        cmp = retval < 0 ? -1 : 1;
      } else if (length1 == lenght2) {
        cmp = 0;
      } else {
        cmp = length1 < lenght2 ? -1 : 1;
      }
  int_vars[0] = (cmp == 0);
    }
  }
L43: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_token";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 58;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L73;
  }
L44: // BOOL_INT
  int_vars[0] = int_vars[0];
L45: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L50; }
L46: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L47: // ADD_INT
  int_vars[5] = int_vars[4] + int_vars[3];
L48: // SET_DEREF_INT
  *(int32_t*)*(void**)&ref_vars[0] = int_vars[5];
L49: // GOTO
  goto L70;
L50: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L51: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], env->new_string_len_raw(env, "\x45\x78\x70\x65\x63\x74\x65\x64\x20\x74\x6F\x6B\x65\x6E\x3A\x20", 16));
L52: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 4;
  mortal_stack_top++;
L53: // CONCAT
  {
    void* string1 = object_vars[3];
    void* string2 = object_vars[1];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], string3);
    }
  }
L54: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_token";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 62;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L73;
  }
L55: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 5;
  mortal_stack_top++;
L56: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], env->new_string_len_raw(env, "\x20\x64\x6F\x65\x73\x6E\x27\x74\x20\x65\x78\x69\x73\x74", 14));
L57: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 6;
  mortal_stack_top++;
L58: // CONCAT
  {
    void* string1 = object_vars[4];
    void* string2 = object_vars[5];
    if (string1 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater left value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else if (string2 == NULL) {
      void* exception = env->new_string_raw(env, "\".\" operater right value must be defined");
      env->set_exception(env, exception);
      exception_flag = 1;
    }
    else {
      void* string3 = env->concat_raw(env, string1, string2);
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], string3);
    }
  }
L59: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_token";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 62;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L73;
  }
L60: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L61: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[6];
L62: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[0];
L63: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[4];
L64: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L65: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_expect_token";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 62;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L73;
  }
L66: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[6], NULL);
L67: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[5], NULL);
L68: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[4], NULL);
L69: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L70: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L71: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L72: // RETURN_VOID
  goto L73;
L73: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L74: // END_SUB
  if (!exception_flag) {
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON___skip_spaces(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[2] = {0};
  void* ref_vars[1] = {0};
  int32_t int_vars[8];
  int32_t exception_flag = 0;
  int32_t mortal_stack[3];
  int32_t mortal_stack_top = 0;
  int8_t byte_vars[2];
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  object_vars[1] = *(void**)&stack[1];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }
  ref_vars[0] = *(void**)&stack[2];

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // ARRAY_LENGTH
  if (object_vars[1] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[1] = *(int32_t*)((intptr_t)object_vars[1] + (intptr_t)env->object_length_offset);
  }
L4: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_skip_spaces";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 32;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L88;
  }
L5: // GOTO
  goto L84;
L6: // GET_DEREF_INT
  int_vars[3] = *(int32_t*)*(void**)&ref_vars[0];
L7: // EQ_INT
  int_vars[0] = (int_vars[3] == int_vars[1]);
L8: // BOOL_INT
  int_vars[0] = int_vars[0];
L9: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L12; }
L10: // RETURN_VOID
  goto L88;
L11: // GOTO
  goto L12;
L12: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L13: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[4];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L14: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_skip_spaces";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 37;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L88;
  }
L15: // CONVERT_BYTE_TO_INT
  int_vars[5] = (int32_t)byte_vars[0];
L16: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x20';
L17: // CONVERT_BYTE_TO_INT
  int_vars[6] = (int32_t)byte_vars[1];
L18: // EQ_INT
  int_vars[0] = (int_vars[5] == int_vars[6]);
L19: // BOOL_INT
  int_vars[0] = int_vars[0];
L20: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L24; }
L21: // MOVE_CONSTANT_INT
  int_vars[3] = 1;
L22: // BOOL_INT
  int_vars[0] = int_vars[3];
L23: // GOTO
  goto L38;
L24: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L25: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[4];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L26: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_skip_spaces";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 37;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L88;
  }
L27: // CONVERT_BYTE_TO_INT
  int_vars[5] = (int32_t)byte_vars[0];
L28: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x0A';
L29: // CONVERT_BYTE_TO_INT
  int_vars[6] = (int32_t)byte_vars[1];
L30: // EQ_INT
  int_vars[0] = (int_vars[5] == int_vars[6]);
L31: // BOOL_INT
  int_vars[0] = int_vars[0];
L32: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L36; }
L33: // MOVE_CONSTANT_INT
  int_vars[3] = 1;
L34: // BOOL_INT
  int_vars[0] = int_vars[3];
L35: // GOTO
  goto L38;
L36: // MOVE_CONSTANT_INT
  int_vars[4] = 0;
L37: // BOOL_INT
  int_vars[0] = int_vars[4];
L38: // BOOL_INT
  int_vars[0] = int_vars[0];
L39: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L43; }
L40: // MOVE_CONSTANT_INT
  int_vars[3] = 1;
L41: // BOOL_INT
  int_vars[0] = int_vars[3];
L42: // GOTO
  goto L57;
L43: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L44: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[4];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L45: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_skip_spaces";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 37;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L88;
  }
L46: // CONVERT_BYTE_TO_INT
  int_vars[5] = (int32_t)byte_vars[0];
L47: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x09';
L48: // CONVERT_BYTE_TO_INT
  int_vars[6] = (int32_t)byte_vars[1];
L49: // EQ_INT
  int_vars[0] = (int_vars[5] == int_vars[6]);
L50: // BOOL_INT
  int_vars[0] = int_vars[0];
L51: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L55; }
L52: // MOVE_CONSTANT_INT
  int_vars[3] = 1;
L53: // BOOL_INT
  int_vars[0] = int_vars[3];
L54: // GOTO
  goto L57;
L55: // MOVE_CONSTANT_INT
  int_vars[4] = 0;
L56: // BOOL_INT
  int_vars[0] = int_vars[4];
L57: // BOOL_INT
  int_vars[0] = int_vars[0];
L58: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L62; }
L59: // MOVE_CONSTANT_INT
  int_vars[3] = 1;
L60: // BOOL_INT
  int_vars[0] = int_vars[3];
L61: // GOTO
  goto L76;
L62: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L63: // ARRAY_FETCH_BYTE
  {
    void* array = object_vars[1];
    int32_t index = int_vars[4];
    if (__builtin_expect(array == NULL, 0)) { 
      env->set_exception(env, env->new_string_raw(env, "Array must not be undef")); 
      exception_flag = 1;
    } 
    else { 
      if (__builtin_expect(index < 0 || index >= *(int32_t*)((intptr_t)array + (intptr_t)env->object_length_offset), 0)) { 
        env->set_exception(env, env->new_string_raw(env, "Index is out of range")); 
        exception_flag = 1;
      } 
      else { 
        byte_vars[0] = ((int8_t*)((intptr_t)array + object_header_byte_size))[index];
      } 
    } 
  } 
L64: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "_skip_spaces";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 37;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L88;
  }
L65: // CONVERT_BYTE_TO_INT
  int_vars[5] = (int32_t)byte_vars[0];
L66: // MOVE_CONSTANT_BYTE
  byte_vars[1] = '\x0D';
L67: // CONVERT_BYTE_TO_INT
  int_vars[6] = (int32_t)byte_vars[1];
L68: // EQ_INT
  int_vars[0] = (int_vars[5] == int_vars[6]);
L69: // BOOL_INT
  int_vars[0] = int_vars[0];
L70: // IF_EQ_ZERO
  if (int_vars[0] == 0) { goto L74; }
L71: // MOVE_CONSTANT_INT
  int_vars[3] = 1;
L72: // BOOL_INT
  int_vars[0] = int_vars[3];
L73: // GOTO
  goto L76;
L74: // MOVE_CONSTANT_INT
  int_vars[4] = 0;
L75: // BOOL_INT
  int_vars[0] = int_vars[4];
L76: // BOOL_INT
  int_vars[0] = int_vars[0];
L77: // IF_NE_ZERO
  if (int_vars[0]) { goto L80; }
L78: // GOTO
  goto L87;
L79: // GOTO
  goto L80;
L80: // GET_DEREF_INT
  int_vars[4] = *(int32_t*)*(void**)&ref_vars[0];
L81: // MOVE_CONSTANT_INT
  int_vars[5] = 1;
L82: // ADD_INT
  int_vars[6] = int_vars[4] + int_vars[5];
L83: // SET_DEREF_INT
  *(int32_t*)*(void**)&ref_vars[0] = int_vars[6];
L84: // MOVE_CONSTANT_INT
  int_vars[3] = 1;
L85: // BOOL_INT
  int_vars[0] = int_vars[3];
L86: // IF_NE_ZERO
  if (int_vars[0]) { goto L6; }
L87: // RETURN_VOID
  goto L88;
L88: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L89: // END_SUB
  if (!exception_flag) {
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON__decode(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[4] = {0};
  void* ref_vars[1] = {0};
  int32_t int_vars[6];
  int32_t exception_flag = 0;
  int32_t mortal_stack[6];
  int32_t mortal_stack_top = 0;
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  object_vars[1] = *(void**)&stack[1];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // MOVE_CONSTANT_INT
  int_vars[1] = 0;
L4: // REF_INT
  *(void**)&ref_vars[0] = &int_vars[1];
L5: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L6: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L7: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L8: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L9: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_decode_recursive
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_recursive < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_recursive = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_recursive", "object(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_recursive < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_recursive");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_recursive;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_recursive(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], stack[0].oval);
    }
  }
L10: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "decode";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 540;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L37;
  }
L11: // REF_INT
  *(void**)&ref_vars[0] = &int_vars[1];
L12: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L13: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L14: // PUSH_ARG_REF
  *(void**)&stack[2] = ref_vars[0];
L15: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_skip_spaces
  {
    if (SUB_ID_SPVM__Webkit__JSON___skip_spaces < 0) {
      SUB_ID_SPVM__Webkit__JSON___skip_spaces = env->get_sub_id(env, "SPVM::Webkit::JSON", "_skip_spaces", "void(self,string,&int)");
      if (SUB_ID_SPVM__Webkit__JSON___skip_spaces < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _skip_spaces");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___skip_spaces;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___skip_spaces(env, stack);
    if (!exception_flag) {
    }
  }
L16: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "decode";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 543;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L37;
  }
L17: // ARRAY_LENGTH
  if (object_vars[1] == NULL) {
    env->set_exception(env, env->new_string_raw(env, "Can't get array length of undef value."));
    exception_flag = 1;
  }
  else {
    int_vars[3] = *(int32_t*)((intptr_t)object_vars[1] + (intptr_t)env->object_length_offset);
  }
L18: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "decode";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 547;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L37;
  }
L19: // EQ_INT
  int_vars[0] = (int_vars[1] == int_vars[3]);
L20: // BOOL_INT
  int_vars[0] = int_vars[0];
L21: // IF_NE_ZERO
  if (int_vars[0]) { goto L31; }
L22: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L23: // NEW_STRING
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], env->new_string_len_raw(env, "\x67\x61\x72\x62\x61\x67\x65\x20\x61\x66\x74\x65\x72\x20\x4A\x53\x4F\x4E\x20\x6F\x62\x6A\x65\x63\x74", 25));
L24: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[3];
L25: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L26: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[1];
L27: // CALL_SUB_VOID
  // SPVM::Webkit::JSON->_decode_error
  {
    if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
      SUB_ID_SPVM__Webkit__JSON___decode_error = env->get_sub_id(env, "SPVM::Webkit::JSON", "_decode_error", "void(string,string,int)");
      if (SUB_ID_SPVM__Webkit__JSON___decode_error < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _decode_error");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___decode_error;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___decode_error(env, stack);
    if (!exception_flag) {
    }
  }
L28: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "decode";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 549;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L37;
  }
L29: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L30: // GOTO
  goto L32;
L31: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L32: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 3;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L33: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[2];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L37;
L34: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L35: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L36: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[3];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L37;
L37: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L38: // END_SUB
  if (!exception_flag) {
    if (stack[0].oval != NULL) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(stack[0].oval); }
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON__encode(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[4] = {0};
  int32_t int_vars[4];
  int32_t exception_flag = 0;
  int32_t mortal_stack[5];
  int32_t mortal_stack_top = 0;
  char convert_string_buffer[21];
  // Copy arguments to variables
  object_vars[0] = *(void**)&stack[0];
  if (object_vars[0] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[0]); }
  object_vars[1] = *(void**)&stack[1];
  if (object_vars[1] != NULL) { SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(object_vars[1]); }

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L3: // MOVE_CONSTANT_INT
  int_vars[1] = 0;
L4: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 2;
  mortal_stack_top++;
L5: // PUSH_ARG_OBJECT
  *(void**)&stack[0] = object_vars[0];
L6: // PUSH_ARG_OBJECT
  *(void**)&stack[1] = object_vars[1];
L7: // PUSH_ARG_INT
  *(int32_t*)&stack[2] = int_vars[1];
L8: // CALL_SUB_OBJECT
  // SPVM::Webkit::JSON->_encode_recursive
  {
    if (SUB_ID_SPVM__Webkit__JSON___encode_recursive < 0) {
      SUB_ID_SPVM__Webkit__JSON___encode_recursive = env->get_sub_id(env, "SPVM::Webkit::JSON", "_encode_recursive", "string(self,object,int)");
      if (SUB_ID_SPVM__Webkit__JSON___encode_recursive < 0) {
        void* exception = env->new_string_raw(env, "Subroutine not found SPVM::Webkit::JSON _encode_recursive");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t call_sub_id = SUB_ID_SPVM__Webkit__JSON___encode_recursive;
    exception_flag = SPPRECOMPILE__SPVM__Webkit__JSON___encode_recursive(env, stack);
    if (!exception_flag) {
      SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[2], stack[0].oval);
    }
  }
L9: // IF_EXCEPTION_RETURN
  if (exception_flag) {
    const char* sub_package_name = "SPVM::Webkit::JSON";
    const char* sub_name = "encode";
    const char* file = "SPVM/Webkit/JSON.spvm";
    int32_t line = 535;
    env->set_exception(env, env->new_stack_trace_raw(env, env->get_exception(env), sub_package_name, sub_name, file, line));
    goto L14;
  }
L10: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[2];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L14;
L11: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 3;
  mortal_stack_top++;
L12: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[3], NULL);
L13: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[3];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L14;
L14: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L15: // END_SUB
  if (!exception_flag) {
    if (stack[0].oval != NULL) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(stack[0].oval); }
  }
  return exception_flag;
}

int32_t SPPRECOMPILE__SPVM__Webkit__JSON__new(SPVM_ENV* env, SPVM_VALUE* stack) {
  int32_t object_header_byte_size = (intptr_t)env->object_header_byte_size;
  void* object_vars[2] = {0};
  int32_t int_vars[4];
  int32_t exception_flag = 0;
  int32_t mortal_stack[3];
  int32_t mortal_stack_top = 0;
  char convert_string_buffer[21];

L0: // INIT_INT
  int_vars[0] = 0;
L1: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 0;
  mortal_stack_top++;
L2: // NEW_OBJECT
  {
    if (BASIC_TYPE_ID_SPVM__Webkit__JSON < 0) {
      BASIC_TYPE_ID_SPVM__Webkit__JSON = env->get_basic_type_id(env, "SPVM::Webkit::JSON");
      if (BASIC_TYPE_ID_SPVM__Webkit__JSON < 0) {
        void* exception = env->new_string_raw(env, "Basic type not found SPVM::Webkit::JSON");
        env->set_exception(env, exception);
        return SPVM_EXCEPTION;
      }
    }
    int32_t basic_type_id = BASIC_TYPE_ID_SPVM__Webkit__JSON;
    void* object = env->new_object_raw(env, basic_type_id);
    SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[0], object);
  }
L3: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[0];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L7;
L4: // PUSH_MORTAL
  mortal_stack[mortal_stack_top] = 1;
  mortal_stack_top++;
L5: // INIT_UNDEF
  SPVM_RUNTIME_API_OBJECT_ASSIGN(&object_vars[1], NULL);
L6: // RETURN_OBJECT
  *(void**)&stack[0] = object_vars[1];
  if (*(void**)&stack[0] != NULL) {
    SPVM_RUNTIME_API_INC_REF_COUNT_ONLY(*(void**)&stack[0]);
  }
  goto L7;
L7: // LEAVE_SCOPE
  {
    int32_t original_mortal_stack_top = 0;
    {
      int32_t mortal_stack_index;
      for (mortal_stack_index = original_mortal_stack_top; mortal_stack_index < mortal_stack_top; mortal_stack_index++) {
        int32_t var_index = mortal_stack[mortal_stack_index];
        void** object_address = (void**)&object_vars[var_index];
        if (*object_address != NULL) {
          if (SPVM_RUNTIME_API_GET_REF_COUNT(*object_address) > 1) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(*object_address); }
          else { env->dec_ref_count(env, *object_address); }
          *object_address = NULL;
        }
      }
    }
    mortal_stack_top = original_mortal_stack_top;
  }
L8: // END_SUB
  if (!exception_flag) {
    if (stack[0].oval != NULL) { SPVM_RUNTIME_API_DEC_REF_COUNT_ONLY(stack[0].oval); }
  }
  return exception_flag;
}


