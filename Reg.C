#include "Reg.h"
#include "log.h"

using namespace std;

static int reg_int_i = 0;
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

