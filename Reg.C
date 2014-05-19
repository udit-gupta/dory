#include "Reg.h"
#include "log.h"

using namespace std;

enum {
        GLOBAL_DATA = 0,
        SP,
        BP,
        TEMP_STACK,
        VREG_COUNT
};

static int reg_int_i = VREG_COUNT;
static int reg_float_i = 0;

int get_vreg_int() {
	if (reg_int_i >= MAX_REGISTERS)
		LOG("Warning: Out of Integer Machine Registers.");
	return reg_int_i ++;
}

int get_vreg_float() {
	if (reg_float_i >= MAX_REGISTERS)
		LOG("Warning: Out of Float Registers.");
	return reg_float_i ++;
}

int get_vreg_global() {
        return GLOBAL_DATA;
}

int get_vreg_sp() {
        return SP;
}

int get_vreg_bp() {
        return BP;
}

int get_vreg_temp_stack() {
        return TEMP_STACK;
}
