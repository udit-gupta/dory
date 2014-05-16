/* vim: tabstop=4:softtabstop=4:shiftwidth=4:expandtab
 */

#include "Instruction.h"
#include "log.h"

const char * instructionName[] = {
    "ADD", "SUB", "DIV", "MUL", "MOD", "AND", "OR", "XOR",
    "FADD", "FSUB", "FDIV", "FMUL",
    "NEG", "FNEG",
    "UGT", "UGE", "GT", "GE", "EQ", "NE",
    "FGT", "FGE", "FEQ", "FNE",
    "PRTS", "PRTI", "PRTF",
    "JMP", "JMPC", "JMPI", "JMPCI",
    "MOVL", "MOVS", "MOVI", "MOVF",
    "MOVIF", "MIVFI", // "MIV"?
    "STI", "STF",
    "LDI", "LDF",
    "IN", "INI", "INF",
    "ERROR"
};

const string Instruction::name(Mnemonic opcode)
{
    if ((opcode >= ADD) && (opcode <= ERROR))
        return string(instructionName[opcode]);
    else
        return string();
}

void Instruction::operand_src1(int reg, int imm, int type)
{
    src1_.reg = reg;
    src1_.imm = imm;
    src1_.type = type;
}

Instruction::Operand * Instruction::operand_src1(void)
{
    return &src1_;
}

void Instruction::operand_src2(int reg, int imm, int type)
{
    src2_.reg = reg;
    src2_.imm = imm;
    src2_.type = type;
}

Instruction::Operand * Instruction::operand_src2(void)
{
    return &src2_;
}

void Instruction::operand_dest(int reg, int imm, int type)
{
    dest_.reg = reg;
    dest_.imm = imm;
    dest_.type = type;
}

Instruction::Operand * Instruction::operand_dest(void)
{
    return &dest_;
}

void Instruction::opcode(Mnemonic opcode)
{
    opcode_ = opcode;
}

Instruction::Mnemonic Instruction::opcode(void)
{
    return opcode_;
}

void Instruction::label(int label)
{
    label_ = label;
}

int Instruction::label(void)
{
    return label_;
}

void Instruction::funLabel(string * label_name)
{
    label_function_ = 1;
    funLabel_ = new string(label_name->c_str());
}

string * Instruction::funLabel(void)
{
    return funLabel_;
}

int Instruction::Label::label_num_ = 0;

int Instruction::Label::get_label(void)
{
    return Label::label_num_++;
}
