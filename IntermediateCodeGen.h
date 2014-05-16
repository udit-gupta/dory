#ifndef INTERMEDIATE_CODE_H
#define INTERMEDIATE_CODE_H

#include <cassert>
#include <string>
#include "Reg.h"
#include "Instruction.h"
#include <list>

using namespace std;

class IntermediateCode {
  public:

    IntermediateCode() {};

    ~IntermediateCode() {};

    std::list<Instruction *> instructionList(void);

    void addInstruction(Instruction * instr);

    void printInstructionList(void);

  private:
    std::list<Instruction *> instrList_;
};

#endif // INTERMEDIATE_CODE_H
