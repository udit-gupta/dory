/* vim: tabstop=4:softtabstop=4:shiftwidth=4:expandtab
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <string>
#include "Reg.h"

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
        MOVIF, MIVFI, // MIV?
        STI, STF,
        LDI, LDF,
        IN, INI, INF,
        ERROR, LABEL
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
        int reg;
        int imm;
        int type; // can be one of OpType or RegType enums
    };

    class Label {
      public:
	static int label_num_;

	Label() {};
	~Label() {};

	int get_label(void);
    };

    Instruction() {
	label_function_ = 0;
    };

    Instruction(Mnemonic opcode) {
        opcode_ = opcode;
	label_function_ = 0;
    };

    ~Instruction() {};

    void operand_src1(int reg, int imm, int type);
    Operand * operand_src1(void);

    void operand_src2(int reg, int imm, int type);
    Operand * operand_src2(void);

    void operand_dest(int reg, int imm, int type);
    Operand * operand_dest(void);

    void opcode(Mnemonic opcode);
    Mnemonic opcode(void);

    void label(int label);
    int label(void);

    void funLabel(string * label_name);
    string * funLabel(void);

    int isFunLabel(void);

    const string name(Mnemonic opcode);

  private:
    Mnemonic opcode_;
    Operand src1_;
    Operand src2_;
    Operand dest_;
    int label_;
    int label_function_;    //Use funLabel_ instead of default label_
    string * funLabel_;
};

#endif // INSTRUCTION_H
