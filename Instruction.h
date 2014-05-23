/* vim: tabstop=4:softtabstop=4:shiftwidth=4:expandtab
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <cassert>
#include "Reg.h"
#include "Value.h"

using namespace std;

class Instruction;

class Instruction {
  public:
    enum Mnemonic {
        ADD, SUB, DIV, MUL, MOD, AND, OR, XOR,
        FADD, FSUB, FDIV, FMUL,
        NEG, FNEG,
        UGT, UGE, GT, GE, EQ, NE,
        FGT, FGE, FEQ, FNE,
        PRTS, PRTI, PRTF,
        JMP, JMPC, JMPI, JMPCI,
        MOVL, MOVS, MOVI, MOVF,
        MOVIF, MOVFI,
        STI, STF,
        LDI, LDF,
        IN, INI, INF,
        ERROR, LABEL, INVALID
    };

    enum OpType {
        IMM = REG_TYPE_COUNT,
        NIL,
        OP_TYPE_COUNT
    };

    class Operand {
      public:
        Operand() {
            type = NIL;
        }

	const Value * immediate(void) {
	    return imm;
	};

        int reg;
        const Value * imm;
        int type; // can be one of OpType or RegType enums
    };

    class Label {
      public:
	static int label_num_;

	Label() {};
	~Label() {};

	static int get_label(void);
    };

    Instruction() {
	opcode_ = Mnemonic::INVALID;
	label_function_ = 0;
	rel_ = Mnemonic::ERROR;
    };

    Instruction(Mnemonic opcode) {
        opcode_ = opcode;
	label_function_ = 0;
	rel_ = Mnemonic::ERROR;
    };

    ~Instruction() {};

    void operand_src1(int reg, const Value * imm, int type);
    Operand * operand_src1(void);

    void operand_src2(int reg, const Value * imm, int type);
    Operand * operand_src2(void);

    void operand_dest(int reg, const Value * imm, int type);
    Operand * operand_dest(void);

    void opcode(Mnemonic opcode);
    Mnemonic opcode(void);

    void label(int label);
    int label(void);

    void funLabel(string label_name);
    string funLabel(void);

    int isFunLabel(void);

    void relational_op(Mnemonic rel);
    Mnemonic relational_op(void);

    const string name(Mnemonic opcode);

    static Mnemonic typedMnemonic(bool isInt, Mnemonic intOpcode);

    static int isFloating(Mnemonic intOpcode);

  private:
    Mnemonic opcode_;
    Operand src1_;
    Operand src2_;
    Operand dest_;
    int label_;
    int label_function_;    //Use funLabel_ instead of default label_
    string funLabel_;
    Mnemonic rel_;	    //Only for Conditional JMPs
};

#endif // INSTRUCTION_H
