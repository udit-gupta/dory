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

void Instruction::operand_src1(int reg, const Value * imm, int type)
{
    src1_.reg = reg;
    src1_.imm = imm;
    src1_.type = type;
}

Instruction::Operand * Instruction::operand_src1(void)
{
    return &src1_;
}

void Instruction::operand_src2(int reg, const Value * imm, int type)
{
    src2_.reg = reg;
    src2_.imm = imm;
    src2_.type = type;
}

Instruction::Operand * Instruction::operand_src2(void)
{
    return &src2_;
}

void Instruction::operand_dest(int reg, const Value * imm, int type)
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
    label_function_ = 0;
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

void Instruction::relational_op(Mnemonic rel)
{
    assert(rel == Mnemonic::GE || rel == Mnemonic::GT || rel == Mnemonic::EQ || rel == Mnemonic::NE ||
		    rel == Mnemonic::FGE || rel == Mnemonic::FGT || rel == Mnemonic::FEQ || rel == Mnemonic::FNE ||
		    rel == Mnemonic::UGE || rel == Mnemonic::UGT);

    if (opcode_ == Mnemonic::JMPC || opcode_ == Mnemonic::JMPCI)
	rel_ = rel;
}

Instruction::Mnemonic Instruction::relational_op(void)
{
    return rel_;
}

Instruction::Mnemonic Instruction::typedMnemonic(bool isInt, Mnemonic intOpcode) {
    switch(intOpcode) {
    case Instruction::Mnemonic::ADD: return isInt ? Instruction::Mnemonic::ADD : Instruction::Mnemonic::FADD;
    case Instruction::Mnemonic::SUB: return isInt ? Instruction::Mnemonic::SUB : Instruction::Mnemonic::FSUB;
    case Instruction::Mnemonic::DIV: return isInt ? Instruction::Mnemonic::DIV : Instruction::Mnemonic::FDIV;
    case Instruction::Mnemonic::MUL: return isInt ? Instruction::Mnemonic::MUL : Instruction::Mnemonic::FMUL;
    case Instruction::Mnemonic::MOD: return Instruction::Mnemonic::MOD;
    case Instruction::Mnemonic::AND: return Instruction::Mnemonic::AND;
    case Instruction::Mnemonic::OR: return Instruction::Mnemonic::OR;
    case Instruction::Mnemonic::XOR: return Instruction::Mnemonic::XOR;
    case Instruction::Mnemonic::NEG: return isInt ? Instruction::Mnemonic::NEG : Instruction::Mnemonic::FNEG;
    case Instruction::Mnemonic::UGT: return Instruction::Mnemonic::UGT;
    case Instruction::Mnemonic::UGE: return Instruction::Mnemonic::UGE;
    case Instruction::Mnemonic::GT: return isInt ? Instruction::Mnemonic::GT : Instruction::Mnemonic::FGT;
    case Instruction::Mnemonic::GE: return isInt ? Instruction::Mnemonic::GE : Instruction::Mnemonic::FGE;
    case Instruction::Mnemonic::EQ: return isInt ? Instruction::Mnemonic::EQ : Instruction::Mnemonic::FEQ;
    case Instruction::Mnemonic::NE: return isInt ? Instruction::Mnemonic::NE : Instruction::Mnemonic::FNE;
    case Instruction::Mnemonic::PRTS: return Instruction::Mnemonic::PRTS;
    case Instruction::Mnemonic::PRTI: return isInt ? Instruction::Mnemonic::PRTI : Instruction::Mnemonic::PRTF;
    case Instruction::Mnemonic::JMP: return Instruction::Mnemonic::JMP;
    case Instruction::Mnemonic::JMPC: return Instruction::Mnemonic::JMPC;
    case Instruction::Mnemonic::JMPI: return Instruction::Mnemonic::JMPI;
    case Instruction::Mnemonic::JMPCI: return Instruction::Mnemonic::JMPCI;
    case Instruction::Mnemonic::MOVL: return Instruction::Mnemonic::MOVL;
    case Instruction::Mnemonic::MOVS: return Instruction::Mnemonic::MOVS;
    case Instruction::Mnemonic::MOVIF: return isInt ? Instruction::Mnemonic::MOVIF : Instruction::Mnemonic::MOVFI;
    case Instruction::Mnemonic::STI: return isInt ? Instruction::Mnemonic::STI : Instruction::Mnemonic::STF;
    case Instruction::Mnemonic::LDI: return isInt ? Instruction::Mnemonic::LDI : Instruction::Mnemonic::LDF;
    case Instruction::Mnemonic::INI: return isInt ? Instruction::Mnemonic::INI : Instruction::Mnemonic::INF;
    case Instruction::Mnemonic::IN: return Instruction::Mnemonic::IN;
    case Instruction::Mnemonic::MOVI: return isInt ? Instruction::Mnemonic::MOVI : Instruction::Mnemonic::MOVF;
    case Instruction::Mnemonic::LABEL: return Instruction::Mnemonic::LABEL;
    default: return Instruction::Mnemonic::ERROR;
    }
}

int Instruction::isFloating(Mnemonic intOpcode)
{
    int ret = 0;

    if (intOpcode == Instruction::Mnemonic::FADD ||
	    intOpcode == Instruction::Mnemonic::FSUB ||
	    intOpcode == Instruction::Mnemonic::FDIV ||
	    intOpcode == Instruction::Mnemonic::FMUL ||
	    intOpcode == Instruction::Mnemonic::FNEG ||
	    intOpcode == Instruction::Mnemonic::LDF ||
	    intOpcode == Instruction::Mnemonic::MOVF)
	ret = 1;

    return ret;
}

/*****************************************************************************
 *				LABEL FUNCTIONS				     *
 *****************************************************************************/

int Instruction::Label::label_num_ = 0;

int Instruction::Label::get_label(void)
{
    return Label::label_num_++;
}
