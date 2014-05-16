#include "IntermediateCodeGen.h"
#include "log.h"

std::list<Instruction *> IntermediateCode::instructionList(void)
{
    return instrList_;
}

void IntermediateCode::addInstruction(Instruction * instr)
{
    instrList_.push_back(instr);
}

void IntermediateCode::printInstructionList(void)
{
    list<Instruction *>::const_iterator it;

    if (instrList_.size() <= 0) {
	LOG("Instruction List is Empty!");
	return;
    }

    for (it = instrList_.begin(); it != instrList_.end(); it++) {
	if (!(*it)->name((*it)->opcode()).empty())
	    cout << (*it)->name((*it)->opcode());

	/* TODO:
	 * 1. Check if destination register exists, if so, print it.
	 * 2. Check if source 1 register exists, if so print it.
	 * 3. Check if source 2 register exists, if so print it.
	 * 4. For Jumps, print the label.
	 * 5. For LABEL opcode instructions, only print the label (name() is NULL for LABEL).
	 */
    }

    return;
}
