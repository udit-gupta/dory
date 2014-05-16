/* vim: tabstop=4:softtabstop=4:shiftwidth=4:expandtab
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <string>
#include "Reg.h"

using namespace std;

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
        int reg;
        int imm;
        int type; // can be one of OpType or RegType enums
    };

    Instruction() {};

    Instruction(Mnemonic opcode) {
        opcode_ = opcode;
    };

    ~Instruction() {};

    void operand_src1(int reg, int imm, int type);
    struct Operand * operand_src1(void);

    void operand_src2(int reg, int imm, int type);
    struct Operand * operand_src2(void);

    void operand_dest(int reg, int imm, int type);
    struct Operand * operand_dest(void);

    void opcode(Mnemonic opcode);
    Mnemonic opcode(void);

    void label(int label);
    int label(void);

    const string name(Mnemonic opcode);

  private:
    Mnemonic opcode_;
    struct Operand src1_;
    struct Operand src2_;
    struct Operand dest_;
    int label_;
};

#endif // INSTRUCTION_H
