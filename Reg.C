#include "Reg.h"

static int reg_int_i = 0;
static int reg_float_i = 0;

int get_vreg_int() {
	return reg_int_i ++;
}

int get_vreg_float() {
	return reg_float_i ++;
}

