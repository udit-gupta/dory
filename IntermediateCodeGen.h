#ifndef INTERMEDIATE_CODE_H
#define INTERMEDIATE_CODE_H

#include <cassert>
#include <string>
#include "Reg.h"
#include "Instruction.h"
#include <list>

using namespace std;

class IntermediateCodeGen {
  public:

    IntermediateCodeGen() {};

    ~IntermediateCodeGen() {};

    std::list<Instruction *> instructionList(void);

    void addInstruction(Instruction * instr);

    void printInstructionList(const char *outFile);

    Instruction * getLastInstruction(void);

  private:
    string escapeChars(string old);

    std::list<Instruction *> instrList_;
};

#endif // INTERMEDIATE_CODE_H
