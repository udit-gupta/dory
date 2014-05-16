#include "IntermediateCodeGen.h"
#include "log.h"

#define DEFAULT_LABEL_PREFIX	"L"
#define INT_REGISTER_PREFIX	"R"
#define FLOAT_REGISTER_PREFIX	"F"

std::list<Instruction *> IntermediateCodeGen::instructionList(void)
{
    return instrList_;
}

void IntermediateCodeGen::addInstruction(Instruction * instr)
{
    instrList_.push_back(instr);
}

void IntermediateCodeGen::printInstructionList(void)
{
    list<Instruction *>::const_iterator it;

    if (instrList_.size() <= 0) {
	LOG("Instruction List is Empty!");
	return;
    }

    for (it = instrList_.begin(); it != instrList_.end(); it++) {
	/* Printing the LABEL */
	if ((*it)->name((*it)->opcode()).empty() &&
		((*it)->opcode() == Instruction::Mnemonic::LABEL)) {
	    cout << DEFAULT_LABEL_PREFIX << (*it)->label() << ":" << endl;
	    continue;
	}

	cout << (*it)->name((*it)->opcode());

	/* TODO: Add special handling for JMPC, JMPI, JMPCI. */
	if ((*it)->opcode() == Instruction::Mnemonic::JMP) {
	    cout << " " << DEFAULT_LABEL_PREFIX << (*it)->label() << endl;
	    continue;
	}

	if (!((*it)->operand_dest()->type == Instruction::OpType::NIL)) {
	    assert((*it)->operand_dest()->type < REG_TYPE_COUNT);

	    if ((*it)->operand_dest()->type == VREG_INT ||
		    (*it)->operand_dest()->type == REG_INT)
		cout << " " << INT_REGISTER_PREFIX << (*it)->operand_dest()->reg;
	    else
		cout << " " << FLOAT_REGISTER_PREFIX << (*it)->operand_dest()->reg;
	}

	if (!((*it)->operand_src1()->type == Instruction::OpType::NIL)) {
	    assert((*it)->operand_src1()->type < Instruction::OpType::OP_TYPE_COUNT);

	    if ((*it)->operand_src1()->type == Instruction::OpType::IMM)
		cout << " " << (*it)->operand_src1()->imm;
	    else if ((*it)->operand_src1()->type == VREG_INT ||
		    (*it)->operand_src1()->type == REG_INT)
		cout << " " << INT_REGISTER_PREFIX << (*it)->operand_src1()->reg;
	    else
		cout << " " << FLOAT_REGISTER_PREFIX << (*it)->operand_src1()->reg;
	}

	if (!((*it)->operand_src2()->type == Instruction::OpType::NIL)) {
	    assert((*it)->operand_src2()->type < Instruction::OpType::OP_TYPE_COUNT);

	    if ((*it)->operand_src2()->type == Instruction::OpType::IMM)
		cout << " " << (*it)->operand_src2()->imm;
	    else if ((*it)->operand_src2()->type == VREG_INT ||
		    (*it)->operand_src2()->type == REG_INT)
		cout << " " << INT_REGISTER_PREFIX << (*it)->operand_src2()->reg;
	    else
		cout << " " << FLOAT_REGISTER_PREFIX << (*it)->operand_src2()->reg;
	}

	cout << endl;
    }

    return;
}
