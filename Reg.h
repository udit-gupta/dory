#ifndef REG_H
#define REG_H

#define MAX_REGISTERS	1000

enum RegType {VREG_INT = 0,
	VREG_FLOAT,
	REG_INT,
	REG_FLOAT,
	REG_TYPE_COUNT};

int get_vreg_int();
int get_vreg_float();

#endif
