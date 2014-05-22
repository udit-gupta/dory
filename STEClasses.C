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

    int regInput = get_vreg_int();
    int regTemp;
    Instruction *initial_jmp = NULL;
    Instruction *initial_prt = NULL;
    Instruction *initial_label = NULL;
    Instruction *initial_in = NULL;
    Instruction *movsName = NULL;
    Instruction *jmpcInstr = NULL;
    Instruction *initSP = NULL;
    Instruction *initBP = NULL;
    Value *immediateName = NULL;
    Value *immediateAddr = NULL;

    const vector<RuleNode*> pr = GlobalEntry::rules();
    vector<SymTabEntry*> * eventList = getEventEntry();
    vector<SymTabEntry*>::const_iterator sit;
    vector<int> regList;

    /* Code to create first "JMP L_MAIN:" label */
    initial_jmp = new Instruction(Instruction::Mnemonic::JMP);
    initial_jmp->funLabel("begin");

    instrList->addInstruction(initial_jmp);

    codeGenST(0, 0, instrList);

    initial_label = new Instruction(Instruction::Mnemonic::LABEL);
    initial_label->funLabel("begin");

    instrList->addInstruction(initial_label);

    initial_in = new Instruction(Instruction::Mnemonic::IN);
    initial_in->operand_src1(regInput, NULL, VREG_INT);

    instrList->addInstruction(initial_in);

    initial_prt = new Instruction(Instruction::Mnemonic::PRTI);
    initial_prt->operand_src1(regInput, NULL, VREG_INT);

    instrList->addInstruction(initial_prt);

    immediateAddr = new Value(10000, Type::TypeTag::INT);
    initSP = new Instruction(Instruction::Mnemonic::MOVI);
    initSP->operand_src1(-1, immediateAddr, Instruction::OpType::IMM);
    initSP->operand_src2(get_vreg_sp(), NULL, VREG_INT);

    instrList->addInstruction(initSP);

    initBP = new Instruction(Instruction::Mnemonic::MOVI);
    initBP->operand_src1(-1, immediateAddr, Instruction::OpType::IMM);
    initBP->operand_src2(get_vreg_bp(), NULL, VREG_INT);

    instrList->addInstruction(initBP);

    for (sit = eventList->begin(); sit != eventList->end(); ++sit) {
	/* Not generating label and JMPC code for "any" event */
	if ((*sit)->name().compare("any") == 0)
	    continue;

	regTemp = get_vreg_int();
	immediateName = new Value((*sit)->name()[0], Type::TypeTag::INT);
	movsName = new Instruction(Instruction::Mnemonic::MOVI);
	movsName->operand_src1(-1, immediateName, Instruction::OpType::IMM);
	movsName->operand_dest(regTemp, NULL, VREG_INT);
	
	instrList->addInstruction(movsName);

	jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);
	jmpcInstr->relational_op(Instruction::Mnemonic::EQ);
	jmpcInstr->operand_src1(regTemp, NULL, VREG_INT);
	jmpcInstr->operand_src2(regInput, NULL, VREG_INT);
	jmpcInstr->funLabel((*sit)->name());

	instrList->addInstruction(jmpcInstr);
    }

    /* Iterate through the eventList and move their names into registers one by one. 
     * Then compare one by one and JMP to appropriate target. Target named same as event name.
     * Target event will be created at EventEntry, where it will get the required inputs. */
    instrList->addInstruction(initial_jmp);
    
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

    vector<Type*> * args = type()->argTypes();
    vector<Type*>::const_iterator it;

    if (args != NULL && args->size() > 0) {
   	 for (it = args->begin(); it != args->end(); ++it) {
   	     if (Type::isIntegral((*it)->tag()))
   	         inputRegisterList(get_vreg_int());
   	     else
   	         inputRegisterList(get_vreg_float());
   	 }
    }

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

    int isInt, regPtr = -1;
    Instruction *instr = NULL;
    Instruction *getParam = NULL;
    Instruction *instrAddOffset = NULL;
    Value *immediate = NULL;
    Value *immediate1 = NULL;

    if (type()->isIntegral(type()->tag()) || type()->isBool(type()->tag())) {
	setReg(get_vreg_int(), VREG_INT);
	isInt = 1;
    } else {
	setReg(get_vreg_float(), VREG_FLOAT);
	isInt = 0;
    }

    if (varKind() == VariableEntry::VarKind::PARAM_VAR) {
        immediate1 = new Value(1, Type::TypeTag::INT);
        instr = new Instruction(Instruction::Mnemonic::ADD);
        instr->operand_src1(get_vreg_sp(), NULL, VREG_INT);
        instr->operand_src2(-1, immediate1, Instruction::OpType::IMM);
        instr->operand_dest(get_vreg_temp_stack(), NULL, VREG_INT);

        list->addInstruction(instr);

	getParam = new Instruction(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::LDI));
	getParam->operand_src1(get_vreg_temp_stack(), NULL, VREG_INT);
	getParam->operand_dest(getReg(), NULL, reg_type());

	list->addInstruction(getParam);
    } else if (varKind() == VariableEntry::VarKind::LOCAL_VAR) {
	if (initVal()) {
	    initVal()->codeGen(list);
	    getParam = new Instruction(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::STI));
	    getParam->operand_src1(initVal()->getReg(), NULL, initVal()->reg_type());
	    getParam->operand_dest(get_vreg_sp(), NULL, VREG_INT);
	    list->addInstruction(getParam);
	}

        immediate1 = new Value(1, Type::TypeTag::INT);
        instr = new Instruction(Instruction::Mnemonic::SUB);
        instr->operand_src1(get_vreg_sp(), NULL, VREG_INT);
        instr->operand_src2(-1, immediate1, Instruction::OpType::IMM);
        instr->operand_dest(get_vreg_sp(), NULL, VREG_INT);

        list->addInstruction(instr);
    } else if (varKind() == VariableEntry::VarKind::GLOBAL_VAR) {
	instrAddOffset = new Instruction();
        instrAddOffset->opcode(Instruction::Mnemonic::ADD);
        instrAddOffset->operand_src1(get_vreg_global(), NULL, VREG_INT);
	immediate = new Value(offSet(), Type::TypeTag::INT);
	instrAddOffset->operand_src2(-1, immediate, Instruction::OpType::IMM);
	regPtr = get_vreg_int();
	instrAddOffset->operand_dest(regPtr, NULL, VREG_INT);
	list->addInstruction(instrAddOffset);

	if (initVal()) {
	    initVal()->codeGen(list);
	    instr = new Instruction(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::STI));
	    instr->operand_dest(regPtr, NULL, VREG_INT);
	    instr->operand_src1(initVal()->getReg(), NULL, initVal()->reg_type());
	    list->addInstruction(instr);
	}
    }

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

//    int i, tempReg;
    std::vector<int> regParamList;
    std::vector<int> regLocalList;
    int regBP = get_vreg_int();
    int regRetAddr = get_vreg_int();
    int newFuncRetLabel = -1;
    //int regRetValue = get_vreg_int();
    Value *immediate1 = new Value(1, Type::TypeTag::INT);
    Value *popImm = NULL;
    Value *getParamImm = NULL;
    Instruction * functionLabel = NULL;
    Instruction * funcRetLabel = NULL;
    Instruction * getParam = NULL;
    Instruction * getRetAddr = NULL;
//    Instruction * getRetValue = NULL;
    Instruction * getBP = NULL;
    Instruction * incrSP = NULL;
    Instruction * popAllSP = NULL;
    Instruction * jmpRetAddr = NULL;
    Instruction * sp2bp = NULL;

    /* Function Label */
    functionLabel = new Instruction(Instruction::Mnemonic::LABEL);
    functionLabel->funLabel(name());

    list->addInstruction(functionLabel);

    /* BP = SP */
    sp2bp = new Instruction(Instruction::Mnemonic::MOVI);
    sp2bp->operand_src1(get_vreg_sp(), NULL, VREG_INT);
    sp2bp->operand_dest(get_vreg_bp(), NULL, VREG_INT);
    list->addInstruction(sp2bp);

    /* TODO: Get BP Properly */
    incrSP = new Instruction(Instruction::Mnemonic::ADD);
    incrSP->operand_src1(get_vreg_sp(), NULL, VREG_INT);
    incrSP->operand_src2(-1, immediate1, Instruction::OpType::IMM);
    incrSP->operand_dest(get_vreg_temp_stack(), NULL, VREG_INT);

    list->addInstruction(incrSP);

    getBP = new Instruction(Instruction::Mnemonic::LDI);
    getBP->operand_src1(get_vreg_temp_stack(), NULL, VREG_INT);
    getBP->operand_dest(regBP, NULL, VREG_INT);

    list->addInstruction(getBP);

    /* Get Return Address */
    list->addInstruction(incrSP);

    getRetAddr = new Instruction(Instruction::Mnemonic::LDI);
    getRetAddr->operand_src1(get_vreg_temp_stack(), NULL, VREG_INT);
    getRetAddr->operand_dest(regRetAddr, NULL, VREG_INT);

    list->addInstruction(getRetAddr);

    /* Get Return Value */
    list->addInstruction(incrSP);

//    getRetValue = new Instruction(Instruction::Mnemonic::LDI);
//    getRetValue->operand_src1(get_vreg_temp_stack(), NULL, VREG_INT);
//    getRetValue->operand_dest(regRetValue, NULL, VREG_INT);
//
//    list->addInstruction(getRetValue);
//
//    setReturnValueRegister(regRetValue);	// To be used by return statement node

    /* Get all Parameters */
    if (this->type()->arity())
        this->codeGenST(0, this->type()->arity(), list);

    int num_local_var = this->codeGenST(this->type()->arity(), 100000, list);

    getParamImm = new Value(num_local_var, Type::TypeTag::INT);
    getParam = new Instruction(Instruction::Mnemonic::ADD);
    getParam->operand_src1(get_vreg_sp(), NULL, VREG_INT);
    getParam->operand_src2(-1, getParamImm, Instruction::OpType::IMM);
    getParam->operand_dest(get_vreg_sp(), NULL, VREG_INT);
//    for (i = 0; i < type()->arity(); i++) {
//	list->addInstruction(incrSP);
//
//	tempReg = get_vreg_int();
//	regParamList.push_back(tempReg);
//	getParam = new Instruction(Instruction::Mnemonic::LDI);
//	getParam->operand_src1(get_vreg_temp_stack(), NULL, VREG_INT);
//	getParam->operand_dest(tempReg, NULL, VREG_INT);
//
//	list->addInstruction(getParam);
//    }

    /* XXX TODO: Code to add local variables to STACK */

    newFuncRetLabel = Instruction::Label::get_label();
    setReturnLabel(newFuncRetLabel);

    /* Call Function Body's CodeGen */
    if (body()) {
	body()->codeGen(list);
    }

    funcRetLabel = new Instruction(Instruction::Mnemonic::LABEL);
    funcRetLabel->label(newFuncRetLabel);

    list->addInstruction(funcRetLabel);
    /* Pop stuff off stack by Adding num_local + num_params + 3
     * XXX TODO: Add code for adding local variables to stack
     * For now Only adding num_params + 3
     */

    popImm = new Value(num_local_var + /*type()->arity() + 1*/ + 2, Type::TypeTag::INT);
    popAllSP = new Instruction(Instruction::Mnemonic::ADD);
    popAllSP->operand_src1(get_vreg_sp(), NULL, VREG_INT);
    popAllSP->operand_src2(-1, popImm, Instruction::OpType::IMM);
    popAllSP->operand_dest(get_vreg_sp(), NULL, VREG_INT);

    list->addInstruction(popAllSP);

    /* JMPI to return address */
    jmpRetAddr = new Instruction(Instruction::Mnemonic::JMPI);
    jmpRetAddr->operand_dest(regRetAddr, NULL, VREG_INT);

    list->addInstruction(jmpRetAddr);

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
