#include "STEClasses.h"
#include "Value.h"
#include "ParserUtil.h"
#include "log.h"
#include "MemAllocUtil.h"
#include "IntermediateCodeGen.h"
#include "Instruction.h"

/*************

Need to add functions for following entries, add more as needed.

GlobalEntry
EventEntry
ClassEntry
VariableEntry
FunctionEntry
BlockEntry

*************/


void GlobalEntry::print(ostream& out, int indent) const
{   
    prtSpace(out, indent);
    printST(out, indent, '\0', ';', true);
    prtln(out, indent);
    const vector<RuleNode*> pr = GlobalEntry::rules();
    if(pr.size() == 0 ) 
        prtln(out, indent);
    for(vector<RuleNode*>::const_iterator it = pr.begin(); it != pr.end(); it++) {
        (*it)->print(out, indent + STEP_INDENT);
        endln(out, indent);
    }
    prtSpace(out, indent + STEP_INDENT);
}

void GlobalEntry::typePrint(ostream& out, int indent) const
{   
    prtSpace(out, indent);
    typePrintST(out, indent, '\0', ';', true);
    prtln(out, indent);
    const vector<RuleNode*> pr = GlobalEntry::rules();
    if(pr.size() == 0 ) 
        prtln(out, indent);
    for(vector<RuleNode*>::const_iterator it = pr.begin(); it != pr.end(); it++) {
        (*it)->typePrint(out, indent + STEP_INDENT);
        endln(out, indent);
    }
    prtSpace(out, indent + STEP_INDENT);
}

const Type* GlobalEntry::typeCheck()
{
    LOG("");
    const vector<RuleNode*> pr = GlobalEntry::rules();

    typeST(0, 0);

    for(vector<RuleNode*>::const_iterator it = pr.begin(); it != pr.end(); it++) {
      (*it)->typeCheck();
    }

    return NULL;
}

void GlobalEntry::memAlloc(int reset_AR)
{
    memAllocST(0, 0, reset_AR);

    return;
}

void GlobalEntry::codeGen(IntermediateCodeGen * instrList)
{
    LOG("");

    assert(instrList);

    Instruction *initial_jmp = NULL;
    const vector<RuleNode*> pr = GlobalEntry::rules();

    /* Code to create first "JMP L_MAIN:" label */
    initial_jmp = new Instruction(Instruction::Mnemonic::JMP);
    initial_jmp->funLabel("begin");

    instrList->addInstruction(initial_jmp);

    codeGenST(0, 0, instrList);

    for(vector<RuleNode*>::const_iterator it = pr.begin(); it != pr.end(); it++) {
	(*it)->codeGen(instrList);
    }

    return;
}

void EventEntry::print(ostream& out, int indent) const
{
    out << "event " << name();
    printST(out, indent, '(', ')', false);
}

void EventEntry::typePrint(ostream& out, int indent) const
{
    out << "event " << name();
    typePrintST(out, indent, '(', ')', false);
}

const Type* EventEntry::typeCheck()
{
    LOG("");
    return NULL;
}

void EventEntry::memAlloc(int reset_AT)
{
    this->memAllocST(0, this->type()->arity(), 1);

    return;
}

void EventEntry::codeGen(IntermediateCodeGen * list)
{
    LOG("");

    return;
}

void ClassEntry::print(ostream& out, int indent) const 
{
    out << "class " << name();
} 

void ClassEntry::typePrint(ostream& out, int indent) const 
{
    out << "class " << name();
} 

const Type* ClassEntry::typeCheck()
{
    LOG("");
    return NULL;
}

void ClassEntry::codeGen(IntermediateCodeGen * list)
{
    LOG("");

    return;
}

void VariableEntry::print(ostream& out, int indent) const
{
    out << type()->fullName() << " " << name();
    if(initVal() != NULL) {
        out << " = ";
        initVal()->print(out, indent);
    }
}

void VariableEntry::typePrint(ostream& out, int indent) const
{
    out << type()->fullName() << " " << name();
    if(initVal() != NULL) {
        out << " = ";
        initVal()->typePrint(out, indent);
    }
}

const Type* VariableEntry::typeCheck()
{
    LOG("");
    Type *init_type = NULL;
    const Type *return_type = NULL;

    if (initVal()) {
        init_type = (Type *)initVal()->typeCheck();

        if (type()->isSubType(init_type)) {
            if (!init_type->isSubType(type()))
                initVal()->coercedType(type());
            return_type = type();
        } else {
            return_type = new Type(Type::TypeTag::ERROR);
            errMsg("Assignment between incompatible types", initVal());
        }
    }

    return return_type;
}

void VariableEntry::memAlloc(int reset_AR)
{
    if (varKind() == VariableEntry::GLOBAL_VAR) {
	offSet(memAllocUtil(type(), EntryKind::GLOBAL, 0));
	LOG("Allocation of GLOBAL name: " << name() << ", offSet: " << offSet());
    } else if (varKind() == VariableEntry::LOCAL_VAR) {
	offSet(memAllocUtil(type(), EntryKind::LOCAL, reset_AR));
	LOG("Allocation of LOCAL, name: " << name() << ", offSet:" << offSet());
    } else if (varKind() == VariableEntry::PARAM_VAR) {
	offSet(memAllocUtil(type(), EntryKind::FUNCTION_PARAMETER, reset_AR));
	LOG("Allocation of PARAM, name: " << name() << ", offSet: " << offSet());
    } else {
	LOG("Allocation failed for, name: " << name() << ", VarKind not set! Cannot know where to allocate this.");
    }

    return;
}

void VariableEntry::codeGen(IntermediateCodeGen * list)
{
    LOG("");

    if (type()->isIntegral(type()->tag()))
	setReg(get_vreg_int(), VREG_INT);
    else
	setReg(get_vreg_float(), VREG_FLOAT);

    return;
}

void FunctionEntry::print(ostream& out, int indent) const 
{
    out << type()->retType()->fullName() << " " << name();

    if (this->type()->arity())
        this->printST(out, indent, '(', ')', false, 0, this->type()->arity());
    else
        out << "()";


    if (this->body()) {
        out << " {";
        this->printST(out, indent, '\0', ';', true, this->type()->arity(), 10000);
        this->body()->printWithoutBraces(out, indent);
        out << "}";
    }
}

void FunctionEntry::typePrint(ostream& out, int indent) const 
{
    out << type()->retType()->fullName() << " " << name();

    if (this->type()->arity())
        this->typePrintST(out, indent, '(', ')', false, 0, this->type()->arity());
    else
        out << "()";

    if (this->body()) {
        out << " {";
        this->typePrintST(out, indent, '\0', ';', true, this->type()->arity(), 10000);
        this->body()->typePrintWithoutBraces(out, indent);
        out << "}";
    }
}

const Type* FunctionEntry::typeCheck()
{
    /* TODO: Call typeST() for this scope.
     * VariableEntry contains type information for variable declarations.
     * Need to validate that they are correct.
     */
    LOG("");
    typeST(0, 0);
    if (body())
	    body()->typeCheck();
    return NULL;
}

void FunctionEntry::memAlloc(int reset_AR)
{
    if (this->type()->arity())
	this->memAllocST(0, this->type()->arity(), 1);

    this->memAllocST(this->type()->arity(), 100000, 1);

    return;
}

void FunctionEntry::codeGen(IntermediateCodeGen * list)
{
    LOG("");

    return;
}

void BlockEntry::print(ostream& out, int indent) const
{
    printST(out, indent, '{', '}', true);
}

void BlockEntry::typePrint(ostream& out, int indent) const
{
    typePrintST(out, indent, '{', '}', true);
}

const Type* BlockEntry::typeCheck()
{
    LOG("");
    typeST(0, 0);
    return NULL;
}

void BlockEntry::codeGen(IntermediateCodeGen * list)
{
    LOG("");

    return;
}

const Type* RuleBlockEntry::typeCheck() {
	LOG("");
	typeST(0, 0);
	return NULL;
}

void RuleBlockEntry::codeGen(IntermediateCodeGen * list)
{
    LOG("");

    return;
}
