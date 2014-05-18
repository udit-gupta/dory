#ifndef __MEMALLOCUTIL__H__
#define __MEMALLOCUTIL__H__

#include <string>
#include <iostream>
#include "Type.h"

using namespace std;

class Type;

//#define RETURN_VALUE_SIZE 4
//#define RETURN_ADDR_SIZE 4
#define RETURN_VALUE_SIZE 1
#define RETURN_ADDR_SIZE 1
#define RBP_SIZE 1
#define INT_FLOAT_ALIGN_BOUNDARY 4

/*
 * GLOBAL: Variables of this type are to be allocated in the static area.  We
 * will identify the starting offset based on the variable type (for example,
 * currently I assume that integers and floating point numbers require 4 byte
 * boundary alignment), and set the offset_from_data to the new offset after
 * adding the current size + padding to previous value.
 *
 * FUNCTION_PARAMETER: Variables of this type are to be allocated at a negative
 * offset from the base pointer for the current call.
 *
 * LOCAL: Variables of this type are to be allocated at a positive offset from
 * the base pointer for the current call.
 *
 */
enum EntryKind {
	GLOBAL,
	FUNCTION_PARAMETER,
	LOCAL
};

int memAllocUtil(Type *var_type, enum EntryKind entry_kind, int reset_AR);

#endif /*  __MEMALLOCUTIL__H__ */
