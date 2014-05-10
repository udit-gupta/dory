#ifndef CODE_GEN_H
#define CODE_GEN_H

#include "list.h"
#include "Reg.h"

enum Mnemonic {
	ADD, SUB, DIV, MUL, MOD, AND, OR, XOR,
	FADD, FSUB, FDIV, FMUL,
	NEG, FNEG,
	UGT, UGE, GT, GE, EQ, NE,
	FGT, FGE, FEQ, FNE,
	PRTS, PRTI, PRTF,
	JMP, JMPC, JMPI, JMPCI,
	MOVL, MOVS, MOVI, MOVF,
	MOVIF, MIVFI, // MIV?
	STI, STF,
	LDI, LDF,
	IN, INI, INF
};

enum OpType {IMM = REG_TYPE_COUNT,
	NIL,
	OP_TYPE_COUNT};

struct Operand {
	int reg;
	int imm;
	int type; // can be one of OpType or RegType enums
};

struct Instr {
	Mnemonic opcode;
	Operand dest;
	Operand src1;
	Operand src2;
};

struct InstrList {
	Instr instr;
	list_head instrList;
};

#endif

