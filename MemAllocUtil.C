#include "MemAllocUtil.h"
#include "log.h"

using namespace std;

/*
 * offset_from_data:  Offset of global variables from the DATA section.
 *
 * neg_offset_from_bp:  Offset of function parameters from current base
 * pointer.  Must reset this every time there is a new base pointer (reset_AR
 * parameter in memAllocUtil()).  The offset is negative.
 *
 * pos_offset_from_bp:  Offset of local variables in function body from current
 * base pointer.  Must reset this every time there is a new base pointer
 * (reset_AR parameter in memAllocUtil()).  The offset is positive.
 *
 */
static int offset_from_data = 0;
static int neg_offset_from_bp = 0;
static int pos_offset_from_bp = 0;


static int alignment_required(Type *var_type, int current_offset)
{
    int offset = 0;

    /* Identify alignment requirements. */
    if (var_type->isInt(var_type->tag()) ||
	    var_type->isFloat(var_type->tag()) ||
	    var_type->isString(var_type->tag())) {
	/* Align integers and floats on 4 byte boundary */
	/* TODO: Does string need alignment? What is size? */

	if (current_offset % INT_FLOAT_ALIGN_BOUNDARY)
	    offset = current_offset % INT_FLOAT_ALIGN_BOUNDARY;
    }

    return offset;
}

static int size_of_type(Type *var_type)
{
    int type_size = 0;

    if (var_type->isInt(var_type->tag()) ||
	    var_type->isFloat(var_type->tag()) ||
	    var_type->isString(var_type->tag())) {
	/* TODO: Can we assume strings are pointers and allocate 4 bytes for
	 * them too?
	 */
	type_size = 4;
    } else if (var_type->isIntegral(var_type->tag()) ||
	    var_type->isBool(var_type->tag())) {
	type_size = 1;
    }

    return type_size;
}


/*
 * var_type: The type of the variable we need to allocate.  Used to find the
 * alignment requirements and size.
 *
 * entry_kind: Type of entry to find out where to allocate.
 *
 * rest_AR: reset activation record (new base pointer). 1 to reset it to start,
 * 0 to keep where it is.
 *
 */
int memAllocUtil(Type *var_type, enum EntryKind entry_kind, int reset_AR)
{
    int return_offset = 0;
    int type_size = 0;

    if (!var_type) {
	LOG("Type is NULL!");
	return return_offset;
    }

    type_size = size_of_type(var_type);

    switch(entry_kind) {
	case GLOBAL:
	    offset_from_data += alignment_required(var_type, offset_from_data);

	    return_offset = offset_from_data;
	    offset_from_data += type_size;
		
	    break;
	case FUNCTION_PARAMETER:
	    /* These should be at a negative offset from the base pointer. */

	    /* First check if base pointer reset is required */
	    if (reset_AR)
		neg_offset_from_bp = -(RETURN_VALUE_SIZE + RETURN_ADDR_SIZE);

	    neg_offset_from_bp += -(alignment_required(var_type,
			neg_offset_from_bp));

	    return_offset = neg_offset_from_bp;
	    neg_offset_from_bp += -(type_size);

	    break;
	case LOCAL:
	    /* These should be at a positive offset from the base pointer. */

	    /* First check if base pointer reset is required */
	    if (reset_AR)
		pos_offset_from_bp = 0;

	    pos_offset_from_bp += alignment_required(var_type,
			pos_offset_from_bp);

	    return_offset = pos_offset_from_bp;
	    pos_offset_from_bp += type_size;

	    break;
	default:
	    LOG("Incorrect Entry Kind!");
	    break;
    }

    return return_offset;
}
