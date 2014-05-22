#include "IntermediateCodeGen.h"
#include "log.h"
#include <fstream>

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

/* This function is taken from: http://stackoverflow.com/questions/4377320/converting-special-characters-like-n-to-their-escaped-versions */
string IntermediateCodeGen::escapeChars(string input)
{
    string output;

    for(std::string::const_iterator it = input.begin(); it != input.end(); ++it)
    {
	char currentValue = *it;
	switch (currentValue)
	{
	    case L'\t':
		output.append("\\t");
		break;
	    case L'\\':
		output.append("\\\\");
		break;
	    case L'\n':
		output.append("\\n");
		break;
	    default:
		output.push_back(currentValue);
	}
    }

    return output;
}

void IntermediateCodeGen::printInstructionList(const char *outputFile)
{
    list<Instruction *>::const_iterator it;

    ofstream outFile;

    if (instrList_.size() <= 0) {
	LOG("Instruction List is Empty!");
	return;
    }

    cout << endl;

    /* Open outputFile and use it to print. */
    outFile.open(outputFile, ios::out | ios::app);

    for (it = instrList_.begin(); it != instrList_.end(); it++) {
	if (!(*it))
		continue;
	/* Printing the LABEL */
	if (((*it)->name((*it)->opcode()).empty() &&
		((*it)->opcode() == Instruction::Mnemonic::LABEL))) {
	    if (!(*it)->isFunLabel())
		outFile << DEFAULT_LABEL_PREFIX << (*it)->label() << ": ";
	    else
		outFile << DEFAULT_LABEL_PREFIX << "_" << (*it)->funLabel() << ": ";
	    continue;
	}

	outFile << (*it)->name((*it)->opcode());

	if ((*it)->opcode() == Instruction::Mnemonic::JMP) {
	    if (!(*it)->isFunLabel())
		outFile << " " << DEFAULT_LABEL_PREFIX << (*it)->label() << endl;
	    else
		outFile << " " << DEFAULT_LABEL_PREFIX << "_" << (*it)->funLabel() << endl;
	}

	if ((*it)->opcode() == Instruction::Mnemonic::MOVL) {
	    if (!(*it)->isFunLabel())
		outFile << " " << DEFAULT_LABEL_PREFIX << (*it)->label();
	    else
		outFile << " " << DEFAULT_LABEL_PREFIX << "_" << (*it)->funLabel();
	}

	if ((*it)->opcode() == Instruction::Mnemonic::JMPC ||
		(*it)->opcode() == Instruction::Mnemonic::JMPCI)
	    outFile << " " << (*it)->name((*it)->relational_op());

	if ((*it)->operand_src1() && !((*it)->operand_src1()->type == Instruction::OpType::NIL)) {
	    assert((*it)->operand_src1()->type < Instruction::OpType::OP_TYPE_COUNT);

	    if ((*it)->operand_src1()->type == Instruction::OpType::IMM) {
		if ((*it)->operand_src1()->immediate()->type()->tag() == Type::TypeTag::STRING) {
		    if ((*it)->opcode() != Instruction::Mnemonic::MOVS)
		    	outFile << " " << (*it)->operand_src1()->immediate()->sval();
		    else
		    	outFile << " \"" << escapeChars((*it)->operand_src1()->immediate()->sval()) << "\"";
		} else if ((*it)->operand_src1()->immediate()->type()->tag() == Type::TypeTag::BOOL)
		    outFile << " " << (*it)->operand_src1()->immediate()->bval();
		else if ((*it)->operand_src1()->immediate()->type()->tag() == Type::TypeTag::DOUBLE)
		    outFile << " " << (*it)->operand_src1()->immediate()->dval();
		else
		    outFile << " " << (*it)->operand_src1()->immediate()->ival();
	    } else if ((*it)->operand_src1()->type == VREG_INT ||
		    (*it)->operand_src1()->type == REG_INT) {
		if ((*it)->operand_src1()->reg > 99)
			outFile << " " << INT_REGISTER_PREFIX << (*it)->operand_src1()->reg;
		else if ((*it)->operand_src1()->reg > 9)
			outFile << " " << INT_REGISTER_PREFIX << "0" << (*it)->operand_src1()->reg;
		else
			outFile << " " << INT_REGISTER_PREFIX << "00" << (*it)->operand_src1()->reg;
	    } else {
		if ((*it)->operand_src1()->reg > 99)
			outFile << " " << FLOAT_REGISTER_PREFIX << (*it)->operand_src1()->reg;
		else if ((*it)->operand_src1()->reg > 9)
			outFile << " " << FLOAT_REGISTER_PREFIX << "0" << (*it)->operand_src1()->reg;
		else
			outFile << " " << FLOAT_REGISTER_PREFIX << "00" << (*it)->operand_src1()->reg;
	    }
	}

	if ((*it)->operand_src2() && !((*it)->operand_src2()->type == Instruction::OpType::NIL)) {
	    assert((*it)->operand_src2()->type < Instruction::OpType::OP_TYPE_COUNT);

	    if ((*it)->operand_src2()->type == Instruction::OpType::IMM) {
		if ((*it)->operand_src2()->immediate()->type()->tag() == Type::TypeTag::STRING)
		    outFile << " " << (*it)->operand_src2()->immediate()->sval();
		else if ((*it)->operand_src2()->immediate()->type()->tag() == Type::TypeTag::BOOL)
		    outFile << " " << (*it)->operand_src2()->immediate()->bval();
		else if ((*it)->operand_src2()->immediate()->type()->tag() == Type::TypeTag::DOUBLE)
		    outFile << " " << (*it)->operand_src2()->immediate()->dval();
		else
		    outFile << " " << (*it)->operand_src2()->immediate()->ival();
	    } else if ((*it)->operand_src2()->type == VREG_INT ||
		    (*it)->operand_src2()->type == REG_INT) {
		if ((*it)->operand_src2()->reg > 99)
			outFile << " " << INT_REGISTER_PREFIX << (*it)->operand_src2()->reg;
		else if ((*it)->operand_src2()->reg > 9)
			outFile << " " << INT_REGISTER_PREFIX << "0" <<  (*it)->operand_src2()->reg;
		else
			outFile << " " << INT_REGISTER_PREFIX << "00" << (*it)->operand_src2()->reg;
	    } else {
		if ((*it)->operand_src2()->reg > 99)
			outFile << " " << FLOAT_REGISTER_PREFIX << (*it)->operand_src2()->reg;
		else if ((*it)->operand_src2()->reg > 9)
			outFile << " " << FLOAT_REGISTER_PREFIX << "0" <<  (*it)->operand_src2()->reg;
		else
			outFile << " " << FLOAT_REGISTER_PREFIX << "00" << (*it)->operand_src2()->reg;
	    }
	}

	if ((*it)->opcode() == Instruction::Mnemonic::JMPC) {
	    if (!(*it)->isFunLabel())
		outFile << " " << DEFAULT_LABEL_PREFIX << (*it)->label() << endl;
	    else
		outFile << " " << DEFAULT_LABEL_PREFIX << "_" << (*it)->funLabel() << endl;
	    continue;
	}

	if ((*it)->operand_dest() && !((*it)->operand_dest()->type == Instruction::OpType::NIL)) {
	    assert((*it)->operand_dest()->type < REG_TYPE_COUNT);

	    if ((*it)->operand_dest()->type == VREG_INT ||
		    (*it)->operand_dest()->type == REG_INT) {
		if ((*it)->operand_dest()->reg > 99)
			outFile << " " << INT_REGISTER_PREFIX << (*it)->operand_dest()->reg;
		else if ((*it)->operand_dest()->reg > 9)
			outFile << " " << INT_REGISTER_PREFIX << "0" <<  (*it)->operand_dest()->reg;
		else
			outFile << " " << INT_REGISTER_PREFIX << "00" << (*it)->operand_dest()->reg;
	    } else {
		if ((*it)->operand_dest()->reg > 99)
			outFile << " " << FLOAT_REGISTER_PREFIX << (*it)->operand_dest()->reg;
		else if ((*it)->operand_dest()->reg > 9)
			outFile << " " << FLOAT_REGISTER_PREFIX << "0" <<  (*it)->operand_dest()->reg;
		else
			outFile << " " << FLOAT_REGISTER_PREFIX << "00" << (*it)->operand_dest()->reg;
	    }
	}

	outFile << endl;
    }

    outFile.close();

    return;
}
