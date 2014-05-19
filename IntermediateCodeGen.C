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

    cout << endl;

    for (it = instrList_.begin(); it != instrList_.end(); it++) {
	/* Printing the LABEL */
	if ((*it)->name((*it)->opcode()).empty() &&
		((*it)->opcode() == Instruction::Mnemonic::LABEL)) {
	    if (!(*it)->isFunLabel())
		cout << DEFAULT_LABEL_PREFIX << (*it)->label() << ": ";
	    else
		cout << DEFAULT_LABEL_PREFIX << "_" << (*it)->funLabel() << ": ";
	    continue;
	}

	cout << (*it)->name((*it)->opcode());

	if ((*it)->opcode() == Instruction::Mnemonic::JMP) {
	    if (!(*it)->isFunLabel())
		cout << " " << DEFAULT_LABEL_PREFIX << (*it)->label() << endl;
	    else
		cout << " " << DEFAULT_LABEL_PREFIX << "_" << (*it)->funLabel() << endl;
	    continue;
	}

	if ((*it)->opcode() == Instruction::Mnemonic::JMPC ||
		(*it)->opcode() == Instruction::Mnemonic::JMPCI)
	    cout << (*it)->name((*it)->relational_op());

	if ((*it)->operand_src1() && !((*it)->operand_src1()->type == Instruction::OpType::NIL)) {
	    assert((*it)->operand_src1()->type < Instruction::OpType::OP_TYPE_COUNT);

	    if ((*it)->operand_src1()->type == Instruction::OpType::IMM) {
		if ((*it)->operand_src1()->immediate()->type()->tag() == Type::TypeTag::STRING)
		    cout << " " << (*it)->operand_src1()->immediate()->sval();
		else if ((*it)->operand_src1()->immediate()->type()->tag() == Type::TypeTag::BOOL)
		    cout << " " << (*it)->operand_src1()->immediate()->bval();
		else if ((*it)->operand_src1()->immediate()->type()->tag() == Type::TypeTag::DOUBLE)
		    cout << " " << (*it)->operand_src1()->immediate()->dval();
		else
		    cout << " " << (*it)->operand_src1()->immediate()->ival();
	    } else if ((*it)->operand_src1()->type == VREG_INT ||
		    (*it)->operand_src1()->type == REG_INT)
		cout << " " << INT_REGISTER_PREFIX << (*it)->operand_src1()->reg;
	    else
		cout << " " << FLOAT_REGISTER_PREFIX << (*it)->operand_src1()->reg;
	}

	if ((*it)->operand_src2() && !((*it)->operand_src2()->type == Instruction::OpType::NIL)) {
	    assert((*it)->operand_src2()->type < Instruction::OpType::OP_TYPE_COUNT);

	    if ((*it)->operand_src2()->type == Instruction::OpType::IMM) {
		if ((*it)->operand_src2()->immediate()->type()->tag() == Type::TypeTag::STRING)
		    cout << " " << (*it)->operand_src2()->immediate()->sval();
		else if ((*it)->operand_src2()->immediate()->type()->tag() == Type::TypeTag::BOOL)
		    cout << " " << (*it)->operand_src2()->immediate()->bval();
		else if ((*it)->operand_src2()->immediate()->type()->tag() == Type::TypeTag::DOUBLE)
		    cout << " " << (*it)->operand_src2()->immediate()->dval();
		else
		    cout << " " << (*it)->operand_src2()->immediate()->ival();
	    } else if ((*it)->operand_src2()->type == VREG_INT ||
		    (*it)->operand_src2()->type == REG_INT)
		cout << " " << INT_REGISTER_PREFIX << (*it)->operand_src2()->reg;
	    else
		cout << " " << FLOAT_REGISTER_PREFIX << (*it)->operand_src2()->reg;
	}

	if ((*it)->opcode() == Instruction::Mnemonic::JMPC) {
	    if (!(*it)->isFunLabel())
		cout << " " << DEFAULT_LABEL_PREFIX << (*it)->label() << endl;
	    else
		cout << " " << DEFAULT_LABEL_PREFIX << "_" << (*it)->funLabel() << endl;
	    continue;
	}

	if ((*it)->operand_dest() && !((*it)->operand_dest()->type == Instruction::OpType::NIL)) {
	    assert((*it)->operand_dest()->type < REG_TYPE_COUNT);

	    if ((*it)->operand_dest()->type == VREG_INT ||
		    (*it)->operand_dest()->type == REG_INT)
		cout << " " << INT_REGISTER_PREFIX << (*it)->operand_dest()->reg;
	    else
		cout << " " << FLOAT_REGISTER_PREFIX << (*it)->operand_dest()->reg;
	}

	cout << endl;
    }

    return;
}
