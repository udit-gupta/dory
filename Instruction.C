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
    "MOVIF", "MOVFI",
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

void Instruction::funLabel(string label_name)
{
    label_function_ = 1;
    funLabel_ = label_name;
}

string Instruction::funLabel(void)
{
    return funLabel_;
}

int Instruction::isFunLabel(void)
{
    return label_function_;
}

static Mnemonic Instruction::typedMnemonic(bool isInt, Mnemonic intOpcode) const {
    switch(intOpcode) {
    case Mnemonic::ADD: return isInt ? Mnemonic::ADD : Mnemonic::FADD;
    case Mnemonic::SUB: return isInt ? Mnemonic::SUB : Mnemonic::FSUB;
    case Mnemonic::DIV: return isInt ? Mnemonic::DIV : Mnemonic::FDIV;
    case Mnemonic::MUL: return isInt ? Mnemonic::MUL : Mnemonic::FMUL;
    case Mnemonic::MOD: return Mnemonic::MOD;
    case Mnemonic::AND: return Mnemonic::AND;
    case Mnemonic::OR: return Mnemonic::OR;
    case Mnemonic::XOR: return Mnemonic::XOR;
    case Mnemonic::NEG: return isInt ? Mnemonic::NEG : Mnemonic::FNEG;
    case Mnemonic::UGT: return Mnemonic::UGT;
    case Mnemonic::UGE: return Mnemonic::UGE;
    case Mnemonic::GT: return isInt ? Mnemonic::GT : Mnemonic::FGT;
    case Mnemonic::GE: return isInt ? Mnemonic::GE : Mnemonic::FGE;
    case Mnemonic::EQ: return isInt ? Mnemonic::EQ : Mnemonic::FEQ;
    case Mnemonic::NE: return isInt ? Mnemonic::NE : Mnemonic::FNE;
    case Mnemonic::PRTS: return Mnemonic::PRTS;
    case Mnemonic::PRTI: return isInt ? Mnemonic::PRTI : Mnemonic::PRTF;
    case Mnemonic::JMP: return Mnemonic::JMP;
    case Mnemonic::JMPC: return Mnemonic::JMPC;
    case Mnemonic::JMPI: return Mnemonic::JMPI;
    case Mnemonic::JMPCI: return Mnemonic::JMPCI;
    case Mnemonic::MOVL: return Mnemonic::MOVL;
    case Mnemonic::MOVS: return Mnemonic::MOVS;
    case Mnemonic::MOVIF: return isInt ? Mnemonic::MOVIF : Mnemonic::MOVFI;
    case Mnemonic::STI: return isInt ? Mnemonic::STI : Mnemonic::STF;
    case Mnemonic::LDI: return isInt ? Mnemonic::LDI : Mnemonic::LDF;
    case Mnemonic::INI: return isInt ? Mnemonic::INI : Mnemonic::INF;
    case Mnemonic::IN: return Mnemonic::IN;
    case Mnemonic::MOVI: return isInt ? Mnemonic::MOVI : Mnemonic::MOVF;
    case Mnemonic::LABEL: return Mnemonic::LABEL;
    default: return Mnemonic::ERROR;
    }
}

/*****************************************************************************
 *				LABEL FUNCTIONS				     *
 *****************************************************************************/

int Instruction::Label::label_num_ = 0;

int Instruction::Label::get_label(void)
{
    return Label::label_num_++;
}
