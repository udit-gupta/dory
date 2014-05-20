#include "Ast.h"                    
#include "ParserUtil.h"                 
#include "log.h"

AstNode::AstNode(NodeType nt, int line, int column, string file):
  ProgramElem(NULL, line, column, file) {
    AstNode::nodeType_ = nt;
}

AstNode::AstNode(const AstNode& ast): ProgramElem(ast) {
    AstNode::nodeType_ = ast.nodeType();
}

/****************************************************************/

ExprNode::ExprNode(ExprNodeType et, const Value* val, int line, int column, 
                   string file):
    AstNode(AstNode::NodeType::EXPR_NODE, line, column, file)
{
    ExprNode::exprType_ = et;
    ExprNode::val_ = val;
}


ExprNode::ExprNode(const ExprNode& e) : AstNode(e)
{
    ExprNode::exprType_ = e.exprNodeType();
    ExprNode::val_ = new Value(*e.value());
    ExprNode::coercedType_ = new Type(*e.coercedType());
}

void ExprNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

    return;
}

/****************************************************************/
extern const OpNode::OpInfo opInfo[] = {
  // print name, arity, paren_flag, fixity, arg types, out type, constraints
  //
  // Paren_flag -- opnode->print() outputs is surrounded by parenthesis if 
  // this flag is set. As set below, the expression may not print correctly
  // in some rare cases, e.g., ~(b * c) will get printed as ~b * c,
  // which actually corresponds to (~b)*c. To ensure that things get printed
  // correctly all the time, more paren_flags should be set to 1, but this
  // will lead to more clutter in printed output. Basically, what we have done
  // here is to look are expressions by type -- arithmetic, relational, 
  // boolean, bit operations, etc. Within each type, the highest priority 
  // operator is printed without paren. This will work correctly, as long
  // as the language doesn't permit mixing of different types of expressions.
  // But this assumption doesn't always hold, as in the example above. Also,
  // there is an exception to this general approach in the case of unary minus
  // and * -- since (-a)*b and -(a*b) have the same meaning, we can exclude
  // paren for * without an error.
  //
  // Codes for constraints:
  // first character:
  //    N: No additional constraint over what is given by argTypes
  //    I: all arguments must have identical type
  //    S: one of the arguments must have a type that is a supertype of
  //        of all other arguments. All other arguments require a coercion 
  //        operation to be introduced so as to convert their type to S.
  //    s: one of the arguments must have a type that is a subtype of
  //        of all other arguments. 
  //    L: all list arguments (and list output) must have same type. In 
  //        addition, all non-list arguments (and output) must have same 
  //        type as that of elements in these lists
  //    T: all tuple arguments to the function must have same type.
  //    A: (assignment). Type of second argument must be a subtype of
  //       the first argument
  //
  // second character:
  //    O: output type is the same as out type. (In the following cases,
  //        the output type need not be equal to out type, but a subtype
  //        of it.) Since a TypeTag provides complete type information only
  //        for primitive types, `O' is applicable only in this case.
  //    digit: output type is the same as that of the digit'th argument
  //       In this case, a third character may be used, the code for
  //       which is as follows:
  //         'e' denotes that the output is of type alpha, where
  //             the type of digit'th argument is list(alpha)
  //         'l' denotes that the output is of type list(alpha), where
  //             alpha is the type of the digit'th argument.
  //    S: The output type is the same as that of the argument with the
  //        most general type. (Typically used with first character 'S')
  //    s: The output type is the same as that of the argument with the
  //        least general type. (Typically used with first character 'S')
  //    P: The output type is the product of the types of all arguments
  //    p: The output type is a component of the input tuple type. The
  //        following character specifies the component. A digit k specifies
  //        that the component number as k. The character 'a' indicates that
  //        the component number is given by an integer argument to the
  //        operator. The argument number is given by the following digit.
  //        'p' can be used only in conjunction with first character 'P'.
  //    L: Output type is the same as type of list arguments. Can be used
  //        only in conjunction with first character L.
  //    e: Output type is the same as type of element of list arguments. 
  //        Can be used only in conjunction with first character L.
  //
  {OpNode::OpCode::UMINUS, "-",  1, 0, OpNode::OpPrintType::PREFIX, {Type::SIGNED}, Type::SIGNED, "N1"},
  {OpNode::OpCode::PLUS, "+",  2, 1, OpNode::OpPrintType::INFIX, {Type::NUMERIC, Type::NUMERIC}, Type::NUMERIC, "SS"},
  {OpNode::OpCode::MINUS, "-",  2, 1, OpNode::OpPrintType::INFIX, {Type::NUMERIC, Type::NUMERIC}, Type::NUMERIC, "SS"},
  {OpNode::OpCode::MULT, "*",  2, 0, OpNode::OpPrintType::INFIX, {Type::NUMERIC, Type::NUMERIC}, Type::NUMERIC, "SS"},
  {OpNode::OpCode::DIV, "/",  2, 1, OpNode::OpPrintType::INFIX, {Type::NUMERIC, Type::NUMERIC}, Type::NUMERIC, "SS"},
  {OpNode::OpCode::MOD, "%",  2, 1, OpNode::OpPrintType::INFIX, {Type::INTEGRAL, Type::INTEGRAL}, Type::INTEGRAL, "S2"},
  {OpNode::OpCode::EQ, "==", 2, 0, OpNode::OpPrintType::INFIX, {Type::PRIMITIVE, Type::PRIMITIVE}, Type::BOOL, "SO"},
  {OpNode::OpCode::NE, "!=", 2, 0, OpNode::OpPrintType::INFIX, {Type::PRIMITIVE, Type::PRIMITIVE}, Type::BOOL, "SO"},
  {OpNode::OpCode::GT, ">",  2, 0, OpNode::OpPrintType::INFIX, {Type::SCALAR, Type::SCALAR}, Type::BOOL, "SO"},
  {OpNode::OpCode::LT, "<",  2, 0, OpNode::OpPrintType::INFIX, {Type::SCALAR, Type::SCALAR}, Type::BOOL, "SO"},
  {OpNode::OpCode::GE, ">=", 2, 0, OpNode::OpPrintType::INFIX, {Type::SCALAR, Type::SCALAR}, Type::BOOL, "SO"},
  {OpNode::OpCode::LE, "<=", 2, 0, OpNode::OpPrintType::INFIX, {Type::SCALAR, Type::SCALAR}, Type::BOOL, "SO"},
  {OpNode::OpCode::AND, "&&",  2, 1, OpNode::OpPrintType::INFIX, {Type::BOOL, Type::BOOL}, Type::BOOL, "NO"},
  {OpNode::OpCode::OR, "||",  2, 1, OpNode::OpPrintType::INFIX, {Type::BOOL, Type::BOOL}, Type::BOOL, "NO"},
  {OpNode::OpCode::NOT, "!",  1, 0, OpNode::OpPrintType::PREFIX, {Type::BOOL}, Type::BOOL, "NO"}, 
  {OpNode::OpCode::BITNOT, "~",  1, 0, OpNode::OpPrintType::PREFIX, {Type::INTEGRAL}, Type::INTEGRAL, "N1"},
  {OpNode::OpCode::BITAND, "&",  2, 1, OpNode::OpPrintType::INFIX, {Type::INTEGRAL, Type::INTEGRAL}, Type::INTEGRAL, "Ss"},
  {OpNode::OpCode::BITOR, "|",  2, 1, OpNode::OpPrintType::INFIX, {Type::INTEGRAL, Type::INTEGRAL}, Type::INTEGRAL, "SS"},
  {OpNode::OpCode::BITXOR, "^",  2, 0, OpNode::OpPrintType::INFIX, {Type::INTEGRAL, Type::INTEGRAL}, Type::INTEGRAL, "SS"},
  {OpNode::OpCode::SHL, "<<", 2, 1, OpNode::OpPrintType::INFIX, {Type::INTEGRAL, Type::INTEGRAL}, Type::INTEGRAL, "N1"},
  {OpNode::OpCode::SHR, ">>", 2, 1, OpNode::OpPrintType::INFIX, {Type::INTEGRAL, Type::INTEGRAL}, Type::INTEGRAL, "N1"},
  {OpNode::OpCode::ASSIGN, "=",  2, 0, OpNode::OpPrintType::INFIX, {Type::NATIVE, Type::NATIVE}, Type::VOID, "AO"},
  {OpNode::OpCode::PRINT, "print", OpNode::VARIABLE, 1, OpNode::OpPrintType::PREFIX, {Type::NATIVE}, Type::VOID, "NO"},
  {OpNode::OpCode::INVALID, "invalid",            0, 0, OpNode::OpPrintType::PREFIX, {}, Type::ERROR, "NO"}
};

OpNode::OpNode(OpCode op, ExprNode* a1, ExprNode* a2, 
               int ln, int col, string file):
  ExprNode(ExprNode::ExprNodeType::OP_NODE, NULL, ln,col,file) {
  opCode_ = op;
  if (a1 != NULL) {
    arity_ = 1;
    arg_.push_back(a1);
    if (a2 != NULL) {
      arity_++;
      arg_.push_back(a2);
    }
  }
}

OpNode::OpNode(const OpNode &other):
  ExprNode(other) {
  arity_ = other.arity();
  opCode_ = other.opCode();
  for (unsigned int i=0; (i < other.arity()); i++) {
    if (other.arg_[i]) {
      arg_.push_back((other.arg_[i])->clone());
    } 
    else {
      arg_.push_back(NULL);
    }
  }
}

void 
OpNode::print(ostream& os, int indent) const {
    int iopcode = static_cast<int>(opCode_);
  if (opInfo[iopcode].prtType_ == OpNode::OpPrintType::PREFIX) {
    os << opInfo[iopcode].name_;
    if (arity_ > 0) {
      if (opInfo[iopcode].needParen_) 
        os << '(';
      for (unsigned i=0; i < arity_-1; i++) {
        if (arg_[i])
          arg_[i]->print(os, indent);
        else os << "NULL";
        os << ", ";
      }
      if (arg_[arity_-1])
        arg_[arity_-1]->print(os, indent);
      else os << "NULL";
      if (opInfo[iopcode].needParen_) 
        os << ") ";
    }
  }
  else if ((opInfo[iopcode].prtType_ == OpNode::OpPrintType::INFIX) && (arity_ == 2)) {
    if (opInfo[iopcode].needParen_) 
      os << "(";
    if(arg_[0])
      arg_[0]->print(os, indent);
    else os << "NULL";
    os << opInfo[iopcode].name_; 
    if(arg_[1])
      arg_[1]->print(os, indent);
    else os << "NULL";
    if (opInfo[iopcode].needParen_) 
      os << ")";
  }
  else internalErr("Unhandled case in OpNode::print");
}

void 
OpNode::typePrint(ostream& os, int indent) const {
    int iopcode = static_cast<int>(opCode_);
  if (opInfo[iopcode].prtType_ == OpNode::OpPrintType::PREFIX) {
    os << opInfo[iopcode].name_;
    if (arity_ > 0) {
      if (opInfo[iopcode].needParen_) 
        os << '(';
      for (unsigned i=0; i < arity_-1; i++) {
        if (arg_[i]) {
	  if (arg_[i]->coercedType()) {
            os << "(";
            arg_[i]->coercedType()->print(os, indent);
	    os << ")";
	  }
          arg_[i]->typePrint(os, indent);
	} else os << "NULL";
        os << ", ";
      }
      if (arg_[arity_-1]) {
	if (arg_[arity_-1]->coercedType()) {
	  os << "(";
	  arg_[arity_-1]->coercedType()->print(os, indent);
	  os << ")";
	}
        arg_[arity_-1]->typePrint(os, indent);
      } else os << "NULL";
      if (opInfo[iopcode].needParen_) 
        os << ") ";
    }
  }
  else if ((opInfo[iopcode].prtType_ == OpNode::OpPrintType::INFIX) && (arity_ == 2)) {
    if (opInfo[iopcode].needParen_) 
      os << "(";
    if(arg_[0]) {
      if (arg_[0]->coercedType()) {
	os << "(";
	arg_[0]->coercedType()->print(os, indent);
	os << ")";
      }
      arg_[0]->typePrint(os, indent);
    } else os << "NULL";
    os << opInfo[iopcode].name_; 
    if(arg_[1]) {
      if (arg_[1]->coercedType()) {
        os << "(";
        arg_[1]->coercedType()->print(os, indent);
        os << ")";
      }
      arg_[1]->typePrint(os, indent);
    } else os << "NULL";
    if (opInfo[iopcode].needParen_) 
      os << ")";
  }
  else internalErr("Unhandled case in OpNode::typePrint");
}

const Type *
OpNode::typeCheck()
{
  LOG("");

  LOG("_arity = " << arity_);
  assert(arity_ <= MAX_OP_ARITY);

  for (unsigned int i = 0; i < arity_; i++) {
    if (arg(i))
      arg(i)->typeCheck();
  }

  if (opCode_ == OpNode::OpCode::MOD) {
    /* MOD accepts two integer arguments and output is integer type */
    if (arg(0)->type()->isInt(arg(0)->type()->tag()) && arg(1)->type()->isInt(arg(1)->type()->tag())) {
      if (arg(0)->type()->isUnsigned(arg(0)->type()->tag()) && arg(1)->type()->isUnsigned(arg(1)->type()->tag()))
        type(new Type(Type::TypeTag::UINT));
      else
        type(new Type(Type::TypeTag::INT));

      if (!arg(0)->type()->isSubType(arg(1)->type()) && arg(1)->type()->isSubType(arg(0)->type()))
	      arg(0)->coercedType(arg(1)->type());
      else if (arg(0)->type()->isSubType(arg(1)->type()) && !arg(1)->type()->isSubType(arg(0)->type()))
	      arg(1)->coercedType(arg(0)->type());
    } else {

      type(new Type(Type::TypeTag::ERROR));
    }

    return type();
  }

  if (opCode_ == OpNode::OpCode::PLUS ||
      opCode_ == OpNode::OpCode::MINUS ||
      opCode_ == OpNode::OpCode::MULT ||
      opCode_ == OpNode::OpCode::DIV ||
      opCode_ == OpNode::OpCode::BITAND ||
      opCode_ == OpNode::OpCode::BITOR ||
      opCode_ == OpNode::OpCode::BITXOR ||
      opCode_ == OpNode::OpCode::SHL ||
      opCode_ == OpNode::OpCode::SHR) {
    if (arg(0) && arg(1) && arg(0)->type() && arg(1)->type() &&
		    arg(0)->type()->isNumeric(arg(0)->type()->tag()) &&
		    arg(1)->type()->isNumeric(arg(1)->type()->tag())) {
      if (arg(0)->type()->isSubType(arg(1)->type()) && !arg(1)->type()->isSubType(arg(0)->type())) {
        arg(1)->coercedType(arg(0)->type());
	type(arg(0)->type());
      } else if (!arg(0)->type()->isSubType(arg(1)->type()) && arg(1)->type()->isSubType(arg(0)->type())) {
        arg(0)->coercedType(arg(1)->type());
	type(arg(1)->type());
      } else if (arg(0)->type()->isSubType(arg(1)->type()) && arg(1)->type()->isSubType(arg(0)->type())) {
        /* They must be of same type. */
        type(arg(0)->type());
      } else {
        LOG("TypeTag::ERROR");
        /* This should not happen. Return error. */
        type(new Type(Type::TypeTag::ERROR));
      }
    } else {
      LOG("TypeTag::ERROR");
      type(new Type(Type::TypeTag::ERROR));
    }

    return type();
  }

  if (opCode_ == OpNode::OpCode::BITNOT) {
    assert(arity_ == 1);

    if (arg(0)->type()->isNumeric(arg(0)->type()->tag()))
      type(arg(0)->type());
    else {
      LOG("TypeTag::ERROR");
      type(new Type(Type::TypeTag::ERROR));
    }

    return type();
  }

  if (opCode_ == OpNode::OpCode::EQ ||
      opCode_ == OpNode::OpCode::NE ||
      opCode_ == OpNode::OpCode::GT ||
      opCode_ == OpNode::OpCode::LT ||
      opCode_ == OpNode::OpCode::GE ||
      opCode_ == OpNode::OpCode::LE) {
    if (arg(0)->type()->isNumeric(arg(0)->type()->tag()) && arg(1)->type()->isNumeric(arg(1)->type()->tag())) {
      if (arg(0)->type()->isSubType(arg(1)->type()) && !arg(1)->type()->isSubType(arg(0)->type())) {
        arg(1)->coercedType(arg(0)->type());
	type(new Type(Type::TypeTag::BOOL));
      } else if (!arg(0)->type()->isSubType(arg(1)->type()) && arg(1)->type()->isSubType(arg(0)->type())) {
        arg(0)->coercedType(arg(1)->type());
	type(new Type(Type::TypeTag::BOOL));
      } else if (arg(0)->type()->isSubType(arg(1)->type()) && arg(1)->type()->isSubType(arg(0)->type())) {
        /* They must be of same type. */
        type(new Type(Type::TypeTag::BOOL));
      } else {
        /* This should not happen. Return error. */
        type(new Type(Type::TypeTag::ERROR));
      }
    } else
      type(new Type(Type::TypeTag::ERROR));

    return type();
  }

  if (opCode_ == OpNode::OpCode::AND ||
      opCode_ == OpNode::OpCode::OR) {
    if (arg(0)->type()->isBool(arg(0)->type()->tag()) && arg(1)->type()->isBool(arg(1)->type()->tag()))
      type(new Type(Type::TypeTag::BOOL));
    else
      type(new Type(Type::TypeTag::ERROR));

    return type();
  }

  if (opCode_ == OpNode::OpCode::NOT) {
    assert(arity_ == 1);

    if (arg(0)->type()->isBool(arg(0)->type()->tag()))
      type(new Type(Type::TypeTag::BOOL));
    else
      type(new Type(Type::TypeTag::ERROR));

    return type();
  }

  if (opCode_ == OpNode::OpCode::UMINUS) {
    assert(arity_ == 1);

    if (arg(0)->type()->isNumeric(arg(0)->type()->tag())) {
      type(arg(0)->type());

      if (!arg(0)->type()->isSigned(arg(0)->type()->tag()))
        arg(0)->coercedType(new Type(Type::TypeTag::INT)); 
    } else
      type(new Type(Type::TypeTag::ERROR));

    return type();
  }

  if (opCode_ == OpNode::OpCode::ASSIGN) {
    if (arg(0)->type()->isSubType(arg(1)->type())) {
      if (!arg(1)->type()->isSubType(arg(0)->type()))
        arg(1)->coercedType(arg(0)->type());
      
      type(new Type(Type::TypeTag::BOOL));
    } else {
      type(new Type(Type::TypeTag::ERROR));
      errMsg("Assigned expression must be a subtype of target", arg(1));
    }

    return type();
  }

  type(new Type(Type::TypeTag::ERROR));
  return type();
}

void OpNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

    bool isInt;
    bool isSigned;
    Instruction *instr = new Instruction();
    Value *immediate = NULL;
    Value *immediate0 = NULL;
    Value *immediate1 = NULL;
    int tempReg = -1;
    int tempRegMain = -1;
    int tempRegImm = -1;
    int newLabel = -1;
    int newBeginLabel = -1;
    Instruction *movInstr = NULL;
    Instruction *movImmInstr = NULL;
    Instruction *movFinalInstr = NULL;
    Instruction *jmpcInstr = NULL;
    Instruction *jmpInstr = NULL;
    Instruction *mov1Instr = NULL;
    Instruction *newLabelInstr = NULL;
    Instruction *newLabelInstr2 = NULL;
    Instruction *mulordivInstr = NULL;
    Instruction *subInstr = NULL;

    for (unsigned int i = 0; i < arity_; i++) {
        if (arg(i))
            arg(i)->codeGen(instrList);
    }

    if ((coercedType() && (Type::isIntegral(coercedType()->tag()) || Type::isBool(coercedType()->tag()))) ||
                    ((Type::isIntegral(type()->tag()) || Type::isBool(type()->tag()))))
                isInt = true;
    else
                isInt = false;

    if ((isInt && coercedType() && Type::isSigned(coercedType()->tag())) ||
                    (isInt && (Type::isSigned(type()->tag()))))
                isSigned = true;
    else
                isSigned = false;

    if (isInt)
	    setReg(get_vreg_int(), VREG_INT);
    else
	    setReg(get_vreg_float(), VREG_FLOAT);

    switch(static_cast<int>(opCode())) {
    case static_cast<int>(OpNode::OpCode::PLUS):
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::ADD));
	    instr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    break;
    case static_cast<int>(OpNode::OpCode::MINUS):
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::SUB));
	    instr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    break;
    case static_cast<int>(OpNode::OpCode::MULT):
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::MUL));
	    instr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    break;
    case static_cast<int>(OpNode::OpCode::DIV):
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::DIV));
	    instr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    break;
    case static_cast<int>(OpNode::OpCode::MOD):
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::MOD));
	    instr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    break;
    case static_cast<int>(OpNode::OpCode::UMINUS):
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::NEG));
	    break;
    case static_cast<int>(OpNode::OpCode::BITAND):
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::AND));
	    instr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    break;
    case static_cast<int>(OpNode::OpCode::BITOR):
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::OR));
	    instr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    break;
    case static_cast<int>(OpNode::OpCode::BITXOR):
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::XOR));
	    instr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    break;
    case static_cast<int>(OpNode::OpCode::BITNOT):
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::XOR));
	    immediate = new Value(-1, Type::TypeTag::INT);
	    instr->operand_src2(-1, immediate, Instruction::OpType::IMM);
	    break;
    case static_cast<int>(OpNode::OpCode::SHL):
	    tempReg = get_vreg_int();
	    tempRegMain = get_vreg_int();
	    tempRegImm = get_vreg_int();

	    /* Move the RHS to a temporary register */
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::MOVI));
	    instr->operand_src1(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    instr->operand_dest(tempReg, NULL, VREG_INT);

	    instrList->addInstruction(instr);

	    /* Move the LHS to a temporary register */
	    movInstr = new Instruction(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::MOVI));
	    movInstr->operand_src1(arg(0)->getReg(), NULL, arg(0)->reg_type());
	    movInstr->operand_dest(tempRegMain, NULL, arg(0)->reg_type());

	    instrList->addInstruction(movInstr);

	    /* Move immediate 2 to a temporary register */
	    immediate = new Value(2, Type::TypeTag::INT);
	    movImmInstr = new Instruction(Instruction::Mnemonic::MOVI);
	    movImmInstr->operand_src1(-1, immediate, Instruction::OpType::IMM);
	    movImmInstr->operand_dest(tempRegImm, NULL, VREG_INT);

	    instrList->addInstruction(movImmInstr);

	    /* Begin label for this SHL loop */
	    newBeginLabel = Instruction::Label::get_label();
	    newLabelInstr = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr->label(newBeginLabel);

	    instrList->addInstruction(newLabelInstr);

	    /* JMPC for checking if the RHS is 0 yet. */
	    immediate0 = new Value(0, Type::TypeTag::INT);
	    newLabel = Instruction::Label::get_label();
	    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);
	    jmpcInstr->relational_op(Instruction::Mnemonic::EQ);
	    jmpcInstr->operand_src1(tempReg, NULL, VREG_INT);
	    jmpcInstr->operand_src2(-1, immediate0, Instruction::OpType::IMM);
	    jmpcInstr->label(newLabel);

	    instrList->addInstruction(jmpcInstr);

	    /* Multiply LHS with 2. */
    	    mulordivInstr = new Instruction(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::MUL));
	    mulordivInstr->operand_src1(tempRegImm, NULL, VREG_INT);
	    mulordivInstr->operand_src2(tempRegMain, NULL, arg(0)->reg_type());
	    mulordivInstr->operand_dest(tempRegMain, NULL, arg(0)->reg_type());

	    instrList->addInstruction(mulordivInstr);

	    /* Decrement RHS by 1. */
	    immediate1 = new Value(1, Type::TypeTag::INT);
	    subInstr = new Instruction(Instruction::Mnemonic::SUB);
	    subInstr->operand_src1(tempReg, NULL, VREG_INT);
	    subInstr->operand_src2(-1, immediate1, Instruction::OpType::IMM);
	    subInstr->operand_dest(tempReg, NULL, VREG_INT);

	    instrList->addInstruction(subInstr);

	    /* JMP to beginning of SHL loop to check if done. */
	    jmpInstr = new Instruction(Instruction::Mnemonic::JMP);
	    jmpInstr->label(newBeginLabel);

	    instrList->addInstruction(jmpInstr);

	    /* Loop Exit Label. */
	    newLabelInstr2 = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr2->label(newLabel);

	    instrList->addInstruction(newLabelInstr2);

	    /* Final move of result into destination register. */
	    movFinalInstr = new Instruction(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::MOVI));
	    movFinalInstr->operand_src1(tempRegMain, NULL, arg(0)->reg_type());
	    movFinalInstr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(movFinalInstr);

	    return;
    case static_cast<int>(OpNode::OpCode::SHR):
	    tempReg = get_vreg_int();
	    tempRegMain = get_vreg_int();
	    tempRegImm = get_vreg_int();

	    /* Move the RHS to a temporary register */
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::MOVI));
	    instr->operand_src1(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    instr->operand_dest(tempReg, NULL, VREG_INT);

	    instrList->addInstruction(instr);

	    /* Move the LHS to a temporary register */
	    movInstr = new Instruction(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::MOVI));
	    movInstr->operand_src1(arg(0)->getReg(), NULL, arg(0)->reg_type());
	    movInstr->operand_dest(tempRegMain, NULL, arg(0)->reg_type());

	    instrList->addInstruction(movInstr);

	    /* Move immediate 2 to a temporary register */
	    immediate = new Value(2, Type::TypeTag::INT);
	    movImmInstr = new Instruction(Instruction::Mnemonic::MOVI);
	    movImmInstr->operand_src1(-1, immediate, Instruction::OpType::IMM);
	    movImmInstr->operand_dest(tempRegImm, NULL, VREG_INT);

	    instrList->addInstruction(movImmInstr);

	    /* Begin label for this SHR loop */
	    newBeginLabel = Instruction::Label::get_label();
	    newLabelInstr = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr->label(newBeginLabel);

	    instrList->addInstruction(newLabelInstr);

	    /* JMPC for checking if the RHS is 0 yet. */
	    immediate0 = new Value(0, Type::TypeTag::INT);
	    newLabel = Instruction::Label::get_label();
	    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);
	    jmpcInstr->relational_op(Instruction::Mnemonic::EQ);
	    jmpcInstr->operand_src1(tempReg, NULL, VREG_INT);
	    jmpcInstr->operand_src2(-1, immediate0, Instruction::OpType::IMM);
	    jmpcInstr->label(newLabel);

	    instrList->addInstruction(jmpcInstr);

	    /* Multiply LHS with 2. */
    	    mulordivInstr = new Instruction(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::DIV));
	    mulordivInstr->operand_src1(tempRegImm, NULL, VREG_INT);
	    mulordivInstr->operand_src2(tempRegMain, NULL, arg(0)->reg_type());
	    mulordivInstr->operand_dest(tempRegMain, NULL, arg(0)->reg_type());

	    instrList->addInstruction(mulordivInstr);

	    /* Decrement RHS by 1. */
	    immediate1 = new Value(1, Type::TypeTag::INT);
	    subInstr = new Instruction(Instruction::Mnemonic::SUB);
	    subInstr->operand_src1(tempReg, NULL, VREG_INT);
	    subInstr->operand_src2(-1, immediate1, Instruction::OpType::IMM);
	    subInstr->operand_dest(tempReg, NULL, VREG_INT);

	    instrList->addInstruction(subInstr);

	    /* JMP to beginning of SHR loop to check if done. */
	    jmpInstr = new Instruction(Instruction::Mnemonic::JMP);
	    jmpInstr->label(newBeginLabel);

	    instrList->addInstruction(jmpInstr);

	    /* Loop Exit Label. */
	    newLabelInstr2 = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr2->label(newLabel);

	    instrList->addInstruction(newLabelInstr2);

	    /* Final move of result into destination register. */
	    movFinalInstr = new Instruction(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::MOVI));
	    movFinalInstr->operand_src1(tempRegMain, NULL, arg(0)->reg_type());
	    movFinalInstr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(movFinalInstr);

	    return;
    case static_cast<int>(OpNode::OpCode::AND):
	    /* AND the arg(0) with arg(1). If 0, then result is 0, else result is 1 */
	    tempReg = get_vreg_int();

	    /* Step 1: Perform a bitwise AND of the two operands. */
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::AND));
	    instr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
    	    instr->operand_src1(arg(0)->getReg(), NULL, arg(0)->reg_type());
	    instr->operand_dest(tempReg, NULL, VREG_INT);

	    instrList->addInstruction(instr);

	    /* Step 2: MOVI 0 to actual destReg */
	    immediate0 = new Value(0, Type::TypeTag::INT);
	    movInstr = new Instruction(Instruction::Mnemonic::MOVI);
	    movInstr->operand_src1(-1, immediate0, Instruction::OpType::IMM);
    	    movInstr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(movInstr);

	    /* Step 3: JMPC EQ tempReg 0 newLabel */
	    newLabel = Instruction::Label::get_label();
	    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);
	    jmpcInstr->relational_op(Instruction::Mnemonic::EQ);
	    jmpcInstr->operand_src1(tempReg, NULL, VREG_INT);
	    jmpcInstr->operand_src2(-1, immediate0, Instruction::OpType::IMM);
	    jmpcInstr->label(newLabel);

	    instrList->addInstruction(jmpcInstr);

	    /* Step 4: MOVI 1 to actual destReg */
	    immediate1 = new Value(1, Type::TypeTag::INT);
	    mov1Instr = new Instruction(Instruction::Mnemonic::MOVI);
	    mov1Instr->operand_src1(-1, immediate1, Instruction::OpType::IMM);
    	    mov1Instr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(mov1Instr);

	    /* Step 5: Label newLabel */
	    newLabelInstr = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr->label(newLabel);

	    instrList->addInstruction(newLabelInstr);

	    return;
    case static_cast<int>(OpNode::OpCode::OR):
	    /* OR the arg(0) with arg(1). If 0, then result is 0, else result is 1 */
	    tempReg = get_vreg_int();

	    /* Step 1: Perform a bitwise OR of the two operands. */
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::OR));
	    instr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
    	    instr->operand_src1(arg(0)->getReg(), NULL, arg(0)->reg_type());
	    instr->operand_dest(tempReg, NULL, VREG_INT);

	    instrList->addInstruction(instr);

	    /* Step 2: MOVI 0 to actual destReg */
	    immediate0 = new Value(0, Type::TypeTag::INT);
	    movInstr = new Instruction(Instruction::Mnemonic::MOVI);
	    movInstr->operand_src1(-1, immediate0, Instruction::OpType::IMM);
    	    movInstr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(movInstr);

	    /* Step 3: JMPC EQ tempReg 0 newLabel */
	    newLabel = Instruction::Label::get_label();
	    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);
	    jmpcInstr->relational_op(Instruction::Mnemonic::EQ);
	    jmpcInstr->operand_src1(tempReg, NULL, VREG_INT);
	    jmpcInstr->operand_src2(-1, immediate0, Instruction::OpType::IMM);
	    jmpcInstr->label(newLabel);

	    instrList->addInstruction(jmpcInstr);

	    /* Step 4: MOVI 1 to actual destReg */
	    immediate1 = new Value(1, Type::TypeTag::INT);
	    mov1Instr = new Instruction(Instruction::Mnemonic::MOVI);
	    mov1Instr->operand_src1(-1, immediate1, Instruction::OpType::IMM);
    	    mov1Instr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(mov1Instr);

	    /* Step 5: Label newLabel */
	    newLabelInstr = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr->label(newLabel);

	    instrList->addInstruction(newLabelInstr);

	    return;
    case static_cast<int>(OpNode::OpCode::NOT):
	    /* Step 1: MOVI 1 to actual destReg */
	    immediate0 = new Value(0, Type::TypeTag::INT);
	    immediate1 = new Value(1, Type::TypeTag::INT);
	    movInstr = new Instruction(Instruction::Mnemonic::MOVI);
	    movInstr->operand_src1(-1, immediate1, Instruction::OpType::IMM);
    	    movInstr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(movInstr);

	    /* Step 2: JMPC EQ arg(0) 0 newLabel */
	    newLabel = Instruction::Label::get_label();
	    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);
	    jmpcInstr->relational_op(Instruction::Mnemonic::EQ);
	    jmpcInstr->operand_src1(arg(0)->getReg(), NULL, VREG_INT);
	    jmpcInstr->operand_src2(-1, immediate0, Instruction::OpType::IMM);
	    jmpcInstr->label(newLabel);

	    instrList->addInstruction(jmpcInstr);

	    /* Step 3: MOVI 0 to actual destReg */
	    mov1Instr = new Instruction(Instruction::Mnemonic::MOVI);
	    mov1Instr->operand_src1(-1, immediate0, Instruction::OpType::IMM);
    	    mov1Instr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(mov1Instr);

	    /* Step 4: Label newLabel */
	    newLabelInstr = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr->label(newLabel);

	    instrList->addInstruction(newLabelInstr);

	    return;
    case static_cast<int>(OpNode::OpCode::ASSIGN):
	    instr->opcode(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::STI));
    	    instr->operand_dest(arg(0)->getReg(), NULL, arg(0)->reg_type());
            instr->operand_src1(arg(1)->getReg(), NULL, arg(1)->reg_type());
    	    instrList->addInstruction(instr);
	    return;
    case static_cast<int>(OpNode::OpCode::EQ):
	    /* Step 1: MOVI 1 to actual destReg */
	    immediate0 = new Value(0, Type::TypeTag::INT);
	    immediate1 = new Value(1, Type::TypeTag::INT);
	    movInstr = new Instruction(Instruction::Mnemonic::MOVI);
	    movInstr->operand_src1(-1, immediate1, Instruction::OpType::IMM);
    	    movInstr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(movInstr);

	    /* Step 2: JMPC EQ arg(0) arg(1) newLabel */
	    newLabel = Instruction::Label::get_label();
	    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);
	    jmpcInstr->relational_op(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::EQ));
	    jmpcInstr->operand_src1(arg(0)->getReg(), NULL, arg(0)->reg_type());
	    jmpcInstr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    jmpcInstr->label(newLabel);

	    instrList->addInstruction(jmpcInstr);

	    /* Step 3: MOVI 0 to actual destReg */
	    mov1Instr = new Instruction(Instruction::Mnemonic::MOVI);
	    mov1Instr->operand_src1(-1, immediate0, Instruction::OpType::IMM);
    	    mov1Instr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(mov1Instr);

	    /* Step 4: Label newLabel */
	    newLabelInstr = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr->label(newLabel);

	    instrList->addInstruction(newLabelInstr);

	    return;
    case static_cast<int>(OpNode::OpCode::NE):
	    /* Step 1: MOVI 1 to actual destReg */
	    immediate0 = new Value(0, Type::TypeTag::INT);
	    immediate1 = new Value(1, Type::TypeTag::INT);
	    movInstr = new Instruction(Instruction::Mnemonic::MOVI);
	    movInstr->operand_src1(-1, immediate1, Instruction::OpType::IMM);
    	    movInstr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(movInstr);

	    /* Step 2: JMPC NE arg(0) arg(1) newLabel */
	    newLabel = Instruction::Label::get_label();
	    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);
	    jmpcInstr->relational_op(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::NE));
	    jmpcInstr->operand_src1(arg(0)->getReg(), NULL, arg(0)->reg_type());
	    jmpcInstr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    jmpcInstr->label(newLabel);

	    instrList->addInstruction(jmpcInstr);

	    /* Step 3: MOVI 0 to actual destReg */
	    mov1Instr = new Instruction(Instruction::Mnemonic::MOVI);
	    mov1Instr->operand_src1(-1, immediate0, Instruction::OpType::IMM);
    	    mov1Instr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(mov1Instr);

	    /* Step 4: Label newLabel */
	    newLabelInstr = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr->label(newLabel);

	    instrList->addInstruction(newLabelInstr);

	    return;
    case static_cast<int>(OpNode::OpCode::GE):
	    /* Step 1: MOVI 1 to actual destReg */
	    immediate0 = new Value(0, Type::TypeTag::INT);
	    immediate1 = new Value(1, Type::TypeTag::INT);
	    movInstr = new Instruction(Instruction::Mnemonic::MOVI);
	    movInstr->operand_src1(-1, immediate1, Instruction::OpType::IMM);
    	    movInstr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(movInstr);

	    /* Step 2: JMPC GE arg(0) arg(1) newLabel */
	    newLabel = Instruction::Label::get_label();
	    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);

	    if (isInt && !isSigned)
	        jmpcInstr->relational_op(Instruction::Mnemonic::UGE);
	    else
	    	jmpcInstr->relational_op(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::GE));

	    jmpcInstr->operand_src1(arg(0)->getReg(), NULL, arg(0)->reg_type());
	    jmpcInstr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    jmpcInstr->label(newLabel);

	    instrList->addInstruction(jmpcInstr);

	    /* Step 3: MOVI 0 to actual destReg */
	    mov1Instr = new Instruction(Instruction::Mnemonic::MOVI);
	    mov1Instr->operand_src1(-1, immediate0, Instruction::OpType::IMM);
    	    mov1Instr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(mov1Instr);

	    /* Step 4: Label newLabel */
	    newLabelInstr = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr->label(newLabel);

	    instrList->addInstruction(newLabelInstr);

	    return;
    case static_cast<int>(OpNode::OpCode::GT):
	    /* Step 1: MOVI 1 to actual destReg */
	    immediate0 = new Value(0, Type::TypeTag::INT);
	    immediate1 = new Value(1, Type::TypeTag::INT);
	    movInstr = new Instruction(Instruction::Mnemonic::MOVI);
	    movInstr->operand_src1(-1, immediate1, Instruction::OpType::IMM);
    	    movInstr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(movInstr);

	    /* Step 2: JMPC GE arg(0) arg(1) newLabel */
	    newLabel = Instruction::Label::get_label();
	    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);

	    if (isInt && !isSigned)
	        jmpcInstr->relational_op(Instruction::Mnemonic::UGT);
	    else
	    	jmpcInstr->relational_op(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::GT));

	    jmpcInstr->operand_src1(arg(0)->getReg(), NULL, arg(0)->reg_type());
	    jmpcInstr->operand_src2(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    jmpcInstr->label(newLabel);

	    instrList->addInstruction(jmpcInstr);

	    /* Step 3: MOVI 0 to actual destReg */
	    mov1Instr = new Instruction(Instruction::Mnemonic::MOVI);
	    mov1Instr->operand_src1(-1, immediate0, Instruction::OpType::IMM);
    	    mov1Instr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(mov1Instr);

	    /* Step 4: Label newLabel */
	    newLabelInstr = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr->label(newLabel);

	    instrList->addInstruction(newLabelInstr);

	    return;
    case static_cast<int>(OpNode::OpCode::LE):
	    /* Step 1: MOVI 1 to actual destReg */
	    immediate0 = new Value(0, Type::TypeTag::INT);
	    immediate1 = new Value(1, Type::TypeTag::INT);
	    movInstr = new Instruction(Instruction::Mnemonic::MOVI);
	    movInstr->operand_src1(-1, immediate1, Instruction::OpType::IMM);
    	    movInstr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(movInstr);

	    /* Step 2: JMPC GE arg(0) arg(1) newLabel */
	    newLabel = Instruction::Label::get_label();
	    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);

	    if (isInt && !isSigned)
	        jmpcInstr->relational_op(Instruction::Mnemonic::UGE);
	    else
	    	jmpcInstr->relational_op(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::GE));

	    jmpcInstr->operand_src1(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    jmpcInstr->operand_src2(arg(0)->getReg(), NULL, arg(0)->reg_type());
	    jmpcInstr->label(newLabel);

	    instrList->addInstruction(jmpcInstr);

	    /* Step 3: MOVI 0 to actual destReg */
	    mov1Instr = new Instruction(Instruction::Mnemonic::MOVI);
	    mov1Instr->operand_src1(-1, immediate0, Instruction::OpType::IMM);
    	    mov1Instr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(mov1Instr);

	    /* Step 4: Label newLabel */
	    newLabelInstr = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr->label(newLabel);

	    instrList->addInstruction(newLabelInstr);

	    return;
    case static_cast<int>(OpNode::OpCode::LT):
	    /* Step 1: MOVI 1 to actual destReg */
	    immediate0 = new Value(0, Type::TypeTag::INT);
	    immediate1 = new Value(1, Type::TypeTag::INT);
	    movInstr = new Instruction(Instruction::Mnemonic::MOVI);
	    movInstr->operand_src1(-1, immediate1, Instruction::OpType::IMM);
    	    movInstr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(movInstr);

	    /* Step 2: JMPC GE arg(0) arg(1) newLabel */
	    newLabel = Instruction::Label::get_label();
	    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);

	    if (isInt && !isSigned)
	        jmpcInstr->relational_op(Instruction::Mnemonic::UGT);
	    else
	    	jmpcInstr->relational_op(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::GT));

	    jmpcInstr->operand_src1(arg(1)->getReg(), NULL, arg(1)->reg_type());
	    jmpcInstr->operand_src2(arg(0)->getReg(), NULL, arg(0)->reg_type());
	    jmpcInstr->label(newLabel);

	    instrList->addInstruction(jmpcInstr);

	    /* Step 3: MOVI 0 to actual destReg */
	    mov1Instr = new Instruction(Instruction::Mnemonic::MOVI);
	    mov1Instr->operand_src1(-1, immediate0, Instruction::OpType::IMM);
    	    mov1Instr->operand_dest(getReg(), NULL, reg_type());

	    instrList->addInstruction(mov1Instr);

	    /* Step 4: Label newLabel */
	    newLabelInstr = new Instruction(Instruction::Mnemonic::LABEL);
	    newLabelInstr->label(newLabel);

	    instrList->addInstruction(newLabelInstr);

	    return;
    default:
	    LOG("No such OpCode exists!");
	    return;
    }

    instr->operand_dest(getReg(), NULL, reg_type());
    instr->operand_src1(arg(0)->getReg(), NULL, arg(0)->reg_type());

    instrList->addInstruction(instr);

    return;
}

/*************************************** Below this , I need to implement my own stuff ************************************************/

/*******        Here, I neeed to initialize my constructors as per the requirements            ********/

RefExprNode::RefExprNode(string ext, const SymTabEntry* ste, int line, int column, string file): 
ExprNode::ExprNode(ExprNode::ExprNodeType::REF_EXPR_NODE, NULL, line, column, file)
{
    RefExprNode::ext_ = ext;
    RefExprNode::sym_ = ste;
}

RefExprNode::RefExprNode(const RefExprNode& refExprNode): 
ExprNode::ExprNode(refExprNode)
{
       RefExprNode::ext_ = refExprNode.ext();
       RefExprNode::sym_ = refExprNode.symTabEntry();
}

void RefExprNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

    bool isInt;
    int regPtr = -1;
    Value *immediate = NULL;

    /* Register already allocated. */
//    if (getReg() > -1)
//            return;

    /* TODO: Handle strings :?  */
    if (symTabEntry() && (symTabEntry()->getReg() > -1)) {
            setReg(symTabEntry()->getReg(), reg_type());
    } else {
            LOG("Internal Error!");
            return;
            /*if (type()->isIntegral(type()->tag()))
                setReg(get_vreg_int(), VREG_INT);
            else
                setReg(get_vreg_float(), VREG_FLOAT);*/
    }

    const VariableEntry *var = dynamic_cast<const VariableEntry*>(symTabEntry());

    Instruction *instrAddOffset = new Instruction();
    Instruction *instrLoadData = new Instruction();

    switch(var->varKind()) {
    case VariableEntry::VarKind::GLOBAL_VAR:
            instrAddOffset->opcode(Instruction::Mnemonic::ADD);
            instrAddOffset->operand_src1(get_vreg_global(), NULL, VREG_INT);
	    immediate = new Value(var->offSet(), Type::TypeTag::INT);
            instrAddOffset->operand_src2(-1, immediate, Instruction::OpType::IMM);
            regPtr = get_vreg_int();
            instrAddOffset->operand_dest(regPtr, NULL, VREG_INT);
            break;
    case VariableEntry::VarKind::LOCAL_VAR:
            instrAddOffset->opcode(Instruction::Mnemonic::SUB);
            instrAddOffset->operand_src1(get_vreg_bp(), NULL, VREG_INT);
	    immediate = new Value(-var->offSet(), Type::TypeTag::INT);
            instrAddOffset->operand_src2(-1, immediate, Instruction::OpType::IMM);
            regPtr = get_vreg_int();
            instrAddOffset->operand_dest(regPtr, NULL, VREG_INT);
            break;
    case VariableEntry::VarKind::PARAM_VAR:
            instrAddOffset->opcode(Instruction::Mnemonic::ADD);
            instrAddOffset->operand_src1(get_vreg_bp(), NULL, VREG_INT);
	    immediate = new Value(var->offSet(), Type::TypeTag::INT);
            instrAddOffset->operand_src2(-1, immediate, Instruction::OpType::IMM);
            regPtr = get_vreg_int();
            instrAddOffset->operand_dest(regPtr, NULL, VREG_INT);
            break;
    default:
            LOG("PANIC PANIC!");
            return;
    }

    if(coercedType())
            isInt = Type::isIntegral(coercedType()->tag());
    else
            isInt = Type::isIntegral(type()->tag());

    if(isInt)
            instrLoadData->opcode(Instruction::Mnemonic::LDI);
    else
            instrLoadData->opcode(Instruction::Mnemonic::LDF);

    instrLoadData->operand_dest(getReg(), NULL, reg_type());
    instrLoadData->operand_src1(regPtr, NULL, VREG_INT);

    instrList->addInstruction(instrAddOffset);
    instrList->addInstruction(instrLoadData);

    return;
}

InvocationNode::InvocationNode(const SymTabEntry *ste, vector<ExprNode*>* param, int line, int column, string file):
ExprNode::ExprNode(ExprNode::ExprNodeType::INV_NODE, NULL, line, column, file)
{
    InvocationNode::ste_ = ste;
    InvocationNode::params_ = param;
}

InvocationNode::InvocationNode(const InvocationNode& invcNode):
ExprNode::ExprNode(invcNode)
{
    InvocationNode::params_ = new vector<ExprNode*>(*invcNode.params());
    InvocationNode::ste_ = invcNode.symTabEntry();
}

void InvocationNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

    int retAddrLabel, isInt;
    Value *immediate1 = NULL;
    Instruction *instr = NULL;
    Instruction *movlInstr = NULL;
    Instruction *subInstr = NULL;
    Instruction *jmpInstr = NULL;
    Instruction *labelInstr = NULL;
    const vector<ExprNode*> *exps = params();

    /* XXX TODO: Figure out where to initialize the SP */

    retAddrLabel = Instruction::Label::get_label();
    immediate1 = new Value(1, Type::TypeTag::INT);

    if(exps != NULL && exps->size() != 0) {
	for(std::vector<ExprNode*>::const_reverse_iterator it = exps->crbegin(); it != exps->crend(); it++) {
	    (*it)->codeGen(instrList);

	    if (((*it)->coercedType() && Type::isIntegral((*it)->coercedType()->tag())) || Type::isIntegral((*it)->type()->tag()))
		isInt = 1;
	    else
		isInt = 0;

	    instr = new Instruction(Instruction::typedMnemonic(isInt, Instruction::Mnemonic::STI));
	    instr->operand_src1((*it)->getReg(), NULL, (*it)->reg_type());
	    instr->operand_dest(get_vreg_sp(), NULL, VREG_INT);

	    instrList->addInstruction(instr);

	    subInstr = new Instruction(Instruction::Mnemonic::SUB);
	    subInstr->operand_src1(get_vreg_sp(), NULL, VREG_INT);
	    subInstr->operand_src2(-1, immediate1, Instruction::OpType::IMM);
	    subInstr->operand_dest(get_vreg_sp(), NULL, VREG_INT);

	    instrList->addInstruction(subInstr);
	}
    }

    int tempReg = get_vreg_int();
    movlInstr = new Instruction(Instruction::Mnemonic::MOVL);
    movlInstr->label(retAddrLabel);
    movlInstr->operand_dest(tempReg, NULL, VREG_INT);

    instrList->addInstruction(movlInstr);

    instr = new Instruction(Instruction::Mnemonic::STI);
    instr->operand_src1(tempReg, NULL, VREG_INT);
    instr->operand_dest(get_vreg_sp(), NULL, VREG_INT);
    
    instrList->addInstruction(instr);
    
    subInstr = new Instruction(Instruction::Mnemonic::SUB);
    subInstr->operand_src1(get_vreg_sp(), NULL, VREG_INT);
    subInstr->operand_src2(-1, immediate1, Instruction::OpType::IMM);
    subInstr->operand_dest(get_vreg_sp(), NULL, VREG_INT);
    
    instrList->addInstruction(subInstr);

    jmpInstr = new Instruction(Instruction::Mnemonic::JMP);
    jmpInstr->funLabel(symTabEntry()->name());
    
    instrList->addInstruction(jmpInstr);

    labelInstr = new Instruction(Instruction::Mnemonic::LABEL);
    labelInstr->label(retAddrLabel);
    
    instrList->addInstruction(labelInstr);

    return;
}

IfNode::IfNode(ExprNode* cond, StmtNode* thenStmt, StmtNode* elseStmt, int line, int column, string file):
StmtNode(StmtNode::StmtNodeKind::IF, line, column, file) 
{
    IfNode::cond_ = cond;
    IfNode::then_ = thenStmt;
    IfNode::else_ = elseStmt;
}

void IfNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

    Instruction *jmpcInstr = NULL;
    Instruction *jmpInstr = NULL;
    Instruction *labelInstr = NULL;
    Instruction *labelInstr2 = NULL;
    Value * immediate0 = NULL;
    int newLabelElse = -1;
    int newLabelNext = -1;

    if (!cond())
	return;

    cond()->codeGen(instrList);

    newLabelElse = Instruction::Label::get_label();
    immediate0 = new Value(0, Type::TypeTag::INT);
    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);
    jmpcInstr->relational_op(Instruction::Mnemonic::EQ);
    jmpcInstr->operand_src2(-1, immediate0, Instruction::OpType::IMM);
    jmpcInstr->operand_src1(cond()->getReg(), NULL, cond()->reg_type());
    jmpcInstr->label(newLabelElse);

    instrList->addInstruction(jmpcInstr);

    if (!elseStmt())
    	newLabelNext = newLabelElse;
    else
	newLabelNext = Instruction::Label::get_label();

    if (thenStmt()) {
	thenStmt()->codeGen(instrList);

	jmpInstr = new Instruction(Instruction::Mnemonic::JMP);
	jmpInstr->label(newLabelNext);

	instrList->addInstruction(jmpInstr);
    }

    labelInstr = new Instruction(Instruction::Mnemonic::LABEL);
    labelInstr->label(newLabelElse);

    instrList->addInstruction(labelInstr);

    if (elseStmt()) {
	elseStmt()->codeGen(instrList);

        labelInstr2 = new Instruction(Instruction::Mnemonic::LABEL);
        labelInstr2->label(newLabelNext);

        instrList->addInstruction(labelInstr2);
    }

    return;
}

WhileNode::WhileNode(ExprNode* cond, StmtNode* doStmt, int line, int column, string file):
StmtNode(StmtNode::StmtNodeKind::WHILE, line, column, file) 
{
    WhileNode::cond_ = cond;
    WhileNode::do_ = doStmt;
}

void WhileNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

    int newStartLabel = -1;
    int newExitLabel = -1;
    Instruction *startLabel = NULL;
    Instruction *exitLabel = NULL;
    Instruction *jmpcInstr = NULL;
    Instruction *jmpInstr = NULL;
    Value * immediate0 = NULL;

    if (!cond())
	return;

    newStartLabel = Instruction::Label::get_label();
    startLabel = new Instruction(Instruction::Mnemonic::LABEL);
    startLabel->label(newStartLabel);

    instrList->addInstruction(startLabel);

    cond()->codeGen(instrList);
    
    newExitLabel = Instruction::Label::get_label();
    immediate0 = new Value(0, Type::TypeTag::INT);
    jmpcInstr = new Instruction(Instruction::Mnemonic::JMPC);
    jmpcInstr->relational_op(Instruction::Mnemonic::EQ);
    jmpcInstr->operand_src2(-1, immediate0, Instruction::OpType::IMM);
    jmpcInstr->operand_src1(cond()->getReg(), NULL, cond()->reg_type());
    jmpcInstr->label(newExitLabel);
    
    instrList->addInstruction(jmpcInstr);
    
    if (doStmt()) {
        doStmt()->codeGen(instrList);
    
        jmpInstr = new Instruction(Instruction::Mnemonic::JMP);
        jmpInstr->label(newStartLabel);
    
        instrList->addInstruction(jmpInstr);
    }
    
    exitLabel = new Instruction(Instruction::Mnemonic::LABEL);
    exitLabel->label(newExitLabel);
    
    instrList->addInstruction(exitLabel);

    return;
}

PrimitivePatNode::PrimitivePatNode(EventEntry* ee, vector<VariableEntry*>* params, ExprNode* c, int line, int column, string file):
BasePatNode(BasePatNode::PatNodeKind::PRIMITIVE, line, column, file)
{
    PrimitivePatNode::ee_ = ee;
    PrimitivePatNode::params_ = params;
    PrimitivePatNode::cond_ = c;
}

void PrimitivePatNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

}

PatNode::PatNode(PatNodeKind pk, BasePatNode *p1, BasePatNode*p2, int line, int column, string file):
BasePatNode(pk, line, column, file)
{
    PatNode::pat1_ = p1;
    PatNode::pat2_ = p2;
}

void PatNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

}

RuleNode::RuleNode(BlockEntry *re, BasePatNode* pat, StmtNode* reaction, int line, int column, string file):
AstNode(AstNode::NodeType::RULE_NODE, line, column, file)
{
    RuleNode::rste_ = re;
    RuleNode::pat_ = pat;
    RuleNode::reaction_ = reaction;
}

void RuleNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

    /* TODO: This is mostly incomplete, complete this. */
    if (pat())
	pat()->codeGen(instrList);

    if (reaction())
	reaction()->codeGen(instrList);

    return;
}

/*****************        Add printing Logic Here for Each Node     *****************/

/***  Just to remember :  RuleNode->PatNode->PrimitiveNode->StmtNode(s)->ExprNode(s)->ValueNode(s)        ***/


void ValueNode::print(ostream& out, int indent) const
{
    value()->print(out, indent);
}

const Type *
ValueNode::typeCheck()
{
	LOG("");
	type((Type*) value()->type()); 
	return type();
}

void ValueNode::typePrint(ostream& out, int indent) const
{
    if (type())
        type()->print(out, indent);
   // cout << "Value:" << value()->ival() << endl;
}

void ValueNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

//    if (getReg() > -1)
//            return;

    Instruction *instrMov = new Instruction();

    if (Type::isIntegral(value()->type()->tag()) || Type::isBool(value()->type()->tag())) {
            setReg(get_vreg_int(), VREG_INT);
            instrMov->opcode(Instruction::Mnemonic::MOVI);
    } else if (Type::isString(value()->type()->tag())) {
            setReg(get_vreg_int(), VREG_INT);
    	    instrMov->opcode(Instruction::Mnemonic::MOVS);
    } else {
            setReg(get_vreg_float(), VREG_FLOAT);
            instrMov->opcode(Instruction::Mnemonic::MOVF);
    }

    instrMov->operand_src1(-1, (const Value *)value(), Instruction::OpType::IMM);
    instrMov->operand_dest(getReg(), NULL, reg_type());

    instrList->addInstruction(instrMov);

    return;
}

void RefExprNode::print(ostream& out, int indent) const
{
    out << ext();
}

const Type *
RefExprNode::typeCheck()
{
  LOG("");
  /* Lookup Symbol table to find type and set it. */
  if (symTabEntry()) {
    type((Type *)symTabEntry()->type());
  } else {
    LOG("TypeTag::ERROR");
    type(new Type(Type::TypeTag::ERROR));
  }

  return type();
}

void RefExprNode::typePrint(ostream& out, int indent) const
{
    if (type())
        type()->print(out, indent);
}

void CompoundStmtNode::print(ostream& out, int indent) const 
{
    out << "{";
    if(stmts() != NULL && stmts()->size() > 0) 
        prtln(out, indent);
    CompoundStmtNode::printWithoutBraces(out, indent);
    out << "};";
    prtln(out, indent);
}

void CompoundStmtNode::printWithoutBraces(ostream& out, int indent) const 
{
    const list<StmtNode*>* stmts = CompoundStmtNode::stmts();
    if(stmts != NULL && stmts->size() > 0) {
        for(std::list<StmtNode*>::const_iterator it = stmts->begin(); it != stmts->end(); it++) {
            prtSpace(out, indent);
            (*it)->print(out, indent);
            if((*it)->stmtNodeKind() == StmtNode::StmtNodeKind::EXPR || (*it)->stmtNodeKind() == StmtNode::StmtNodeKind::RETURN)
                endln(out, indent);
        }
    }
}

void CompoundStmtNode::typePrint(ostream& out, int indent) const 
{
    out << "{";
    if(stmts() != NULL && stmts()->size() > 0) 
        prtln(out, indent);
    CompoundStmtNode::typePrintWithoutBraces(out, indent);
    out << "};";
    prtln(out, indent);
}

void CompoundStmtNode::typePrintWithoutBraces(ostream& out, int indent) const 
{
    const list<StmtNode*>* stmts = CompoundStmtNode::stmts();
    if(stmts != NULL && stmts->size() > 0) {
        for(std::list<StmtNode*>::const_iterator it = stmts->begin(); it != stmts->end(); it++) {
            prtSpace(out, indent);
            (*it)->typePrint(out, indent);
            if((*it)->stmtNodeKind() == StmtNode::StmtNodeKind::EXPR || (*it)->stmtNodeKind() == StmtNode::StmtNodeKind::RETURN)
                endln(out, indent);
        }
    }
}

const Type* CompoundStmtNode::typeCheck() {
    LOG("");
    const list<StmtNode*>* stmts = CompoundStmtNode::stmts();
    if(stmts != NULL && stmts->size() > 0) {
        for(std::list<StmtNode*>::const_iterator it = stmts->begin(); it != stmts->end(); it++) {
            (*it)->typeCheck();
        }
    }
    return NULL;
}

void CompoundStmtNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

    const list<StmtNode*>* stmts = CompoundStmtNode::stmts();
    if(stmts != NULL && stmts->size() > 0) {
        for(std::list<StmtNode*>::const_iterator it = stmts->begin(); it != stmts->end(); it++) {
            (*it)->codeGen(instrList);
        }
    }
    return;
}

void InvocationNode::print(ostream& out, int indent) const 
{
    if(symTabEntry() != NULL) {
        out << symTabEntry()->name();
        out << "(";
        bool prComma = false;
        const vector<ExprNode*> *exps = params();
        if(exps != NULL && exps->size() > 0) {
            for(std::vector<ExprNode*>::const_iterator it = exps->begin(); it != exps->end(); it++) {
                if(prComma)
                    out << ", ";
                (*it)->print(out, indent);
                prComma = true;
            }
        }
        out << ")";
    }
}

void InvocationNode::typePrint(ostream& out, int indent) const 
{
    if(symTabEntry() != NULL) {
        out << symTabEntry()->name();
        out << "(";
        bool prComma = false;
        const vector<ExprNode*> *exps = params();
        if(exps != NULL && exps->size() > 0) {
            for(std::vector<ExprNode*>::const_iterator it = exps->begin(); it != exps->end(); it++) {
                if(prComma)
                    out << ", ";
		if ((*it)->coercedType()) {
			out << "(";
			(*it)->coercedType()->print(out, indent);
			out << ")";
		}
                (*it)->typePrint(out, indent);
                prComma = true;
            }
        }
        out << ")";
    }
}

const Type *
InvocationNode::typeCheck()
{
  LOG("");
  int num_params = 0, i;
  const vector<ExprNode*> *parameters = params();
  vector<Type*> *formal_param = NULL;

  /* Need to first check if number of params match number of types in SymTabEntry.
   * Next check that each parameter is a subtype of formal param in SymTabEntry.*/
  if (symTabEntry() && symTabEntry()->type()) {
    if ((!parameters && !symTabEntry()->type()->argTypes()) || (parameters && !parameters->size() && symTabEntry()->type()->argTypes() && !symTabEntry()->type()->argTypes()->size())) {
      type((Type *)symTabEntry()->type()->retType());

      return type();
    }

    if (!parameters || !symTabEntry()->type()->argTypes()) {
      cout << "Either parameters or symTabEntry argTypes is null!" << endl;
      type((Type *)symTabEntry()->type()->retType());
      return type();
    }

    if (parameters && (int)parameters->size() != symTabEntry()->type()->arity()) {
        char *ival = (char *)malloc(10);
	sprintf(ival, "%d", symTabEntry()->type()->arity());
	string message = ival;
	message.append(" arguments expected for ");
	message.append(symTabEntry()->name());
	if (parameters->size() > 0)
		errMsg(message, parameters->at(0));
	else
		errMsg(message, symTabEntry());
    }

    /* Even if number of parameters is wrong, we still go ahead with the typeCheck() */
    if ((int)parameters->size() <= symTabEntry()->type()->arity())
      num_params = parameters->size();
    else
      num_params = symTabEntry()->type()->arity();

    formal_param = (std::vector<Type *>*)symTabEntry()->type()->argTypes();

    for (i = 0; i < num_params; i++) {
      parameters->at(i)->typeCheck();

      if(formal_param->at(i)->isSubType((Type *)parameters->at(i)->type())) {
        if (!parameters->at(i)->type()->isSubType((Type *)formal_param->at(i)))
          parameters->at(i)->coercedType(formal_param->at(i));
      } else {
        char *ival = (char *)malloc(10);
	sprintf(ival, "%d", i+1);
	string message = "Type mismatch for argument ";
	message.append(ival);
	message.append(" to ");
	message.append(symTabEntry()->name());
	errMsg(message, parameters->at(i));
      }
    }

  }

  type((Type *)symTabEntry()->type()->retType());
  return type();
}

const Type *
ExprStmtNode::typeCheck()
{
    LOG("");
    /* TODO: Add Check: LHS of Assignments in Rules must be Global Variables */
    if (expr_)
	    expr_->typeCheck();

    type((Type *)expr_->type());
    return type();
}

void ExprStmtNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

    if (expr_)
	    expr_->codeGen(instrList);

    return;
}

const Type *
ReturnStmtNode::typeCheck()
{
  LOG("");

  if (expr_)
    expr_->typeCheck();

  if (fun_ && expr_ && expr_->type() && fun_->type() &&
		  fun_->type()->retType() &&
		  fun_->type()->retType()->isSubType((Type *)expr_->type())) {

    if (!expr_->type()->isSubType((Type *)fun_->type()->retType()))
      expr_->coercedType(fun_->type()->retType());
    type((Type *)fun_->type()->retType());
  } else {
    if (fun_ && expr_ && expr_->type() && fun_->type() &&
		                      fun_->type()->retType() && fun_->type()->retType()->tag() == Type::TypeTag::VOID
				      && expr_->type()->tag() != Type::TypeTag::VOID)
    	errMsg("No return value expected for a void function", expr_);
    else
    	errMsg("Return value incompatible with current function's type", expr_);
    type(new Type(Type::TypeTag::ERROR));
  }

  return type();
}

void ReturnStmtNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

}

const Type *
BreakStmtNode::typeCheck()
{
  LOG("");

  if (expr_){
    expr_->typeCheck();
    type((Type *)expr_->type());
  } else {
    type(new Type(Type::TypeTag::INT));
  }

  return type();
}

void BreakStmtNode::codeGen(IntermediateCodeGen *instrList)
{
    LOG("");

}

const Type *
IfNode::typeCheck()
{
  LOG("");
  if (cond())
      cond()->typeCheck();

  if (thenStmt())
      thenStmt()->typeCheck();

  if (elseStmt())
      elseStmt()->typeCheck();

  if (cond() && cond()->type() &&
		  cond()->type()->isBool(cond()->type()->tag()))
      type(new Type(Type::TypeTag::BOOL));
  else {
      errMsg("Boolean argument expected", cond());
      type(new Type(Type::TypeTag::ERROR));
  }
  return type();
}

const Type *
WhileNode::typeCheck()
{
  LOG("");
  if (cond())
      cond()->typeCheck();

  if (doStmt())
      doStmt()->typeCheck();

  if (cond() && cond()->type() &&
		  cond()->type()->isBool(cond()->type()->tag()))
      type(new Type(Type::TypeTag::BOOL));
  else
      type(new Type(Type::TypeTag::ERROR));
  return type();
}
  
void IfNode::print(ostream& out, int indent) const 
{
    out << "if (";
    if(cond() != NULL)
        cond()->print(out, indent);
    out << ") ";
    if(thenStmt() != NULL) {
        thenStmt()->print(out, indent + STEP_INDENT);
        if(thenStmt()->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND) 
            endln(out, indent);
    }
    else 
        endln(out, indent);
    
    if(elseStmt() != NULL) {
        prtSpace(out, indent);
        out << "else ";
        elseStmt()->print(out, indent + STEP_INDENT);
        if(elseStmt()->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND) 
            endln(out, indent);
    }
}


void WhileNode::print(ostream& out, int indent) const 
{
    out << "while (";
    if(cond() != NULL)
        cond()->print(out, indent);
    out << ") ";
    if(doStmt() != NULL) {
        doStmt()->print(out, indent + STEP_INDENT);
        if(doStmt()->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND) 
            endln(out, indent);
    }
    else 
        endln(out, indent);
}

void IfNode::typePrint(ostream& out, int indent) const 
{
    out << "if (";
    if(cond() != NULL)
        cond()->typePrint(out, indent);
    out << ") ";
    if(thenStmt() != NULL) {
        thenStmt()->typePrint(out, indent + STEP_INDENT);
        if(thenStmt()->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND) 
            endln(out, indent);
    }
    else 
        endln(out, indent);
    
    if(elseStmt() != NULL) {
        prtSpace(out, indent);
        out << "else ";
        elseStmt()->typePrint(out, indent + STEP_INDENT);
        if(elseStmt()->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND) 
            endln(out, indent);
    }
}


void WhileNode::typePrint(ostream& out, int indent) const 
{
    out << "while (";
    if(cond() != NULL)
        cond()->typePrint(out, indent);
    out << ") ";
    if(doStmt() != NULL) {
        doStmt()->typePrint(out, indent + STEP_INDENT);
        if(doStmt()->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND) 
            endln(out, indent);
    }
    else 
        endln(out, indent);
}

void PrimitivePatNode::print(ostream& out, int indent) const 
{
    out << "(";
    if(event() != NULL) {
        out << event()->name();
        if(event()->name().compare("any") == 0) {
            
        }
        else {
            out << "(";
            bool prComma = false;
            const vector<const VariableEntry*> *vars = params();
            if(vars != NULL && vars->size() > 0) {
                if(vars != NULL) {
                    for(std::vector<const VariableEntry*>::const_iterator it =  vars->begin(); it != vars->end(); it++) {
                        if(prComma) 
                            out << ", ";
                        (*it)->print(out, indent);
                        prComma = true;
                    }
                }
            }
        out << ")";
        }
    }
    
    if(cond() != NULL) {
        out << "|";
        cond()->print(out, indent);
    }
    out << ")";
}

const Type* PrimitivePatNode::typeCheck() {
	LOG("");
   
    if(event() != NULL) {
	if (cond())
		cond()->typeCheck();

        if(event()->name().compare("any") == 0) {
            
        }
        else {
            int num_params = 0, i;
            const vector<VariableEntry*> *parameters = params();
            vector<Type*> *formal_param = NULL;

            /* Need to first check if number of params match number of types in SymTabEntry.
            * Next check that each parameter is a subtype of formal param in SymTabEntry.*/
            if (event() && event()->type()) {
                if ((!parameters && !event()->type()->argTypes()) || (parameters && !parameters->size() && event()->type()->argTypes() && !event()->type()->argTypes()->size())) {
                    type((Type *)event()->type()->retType());
                    return type();
                }

                if (!parameters || !event()->type()->argTypes()) {
                    cout << "Event : Either parameters or symTabEntry argTypes is null!" << endl;
                    type((Type *)event()->type()->retType());
                     return type();
                }

                if ((int)parameters->size() != event()->type()->arity()) {
                    cout << "Event : Incorrect number of parameters passed. Call: " << parameters->size() << " Decl: " << event()->type()->arity() << endl;
                }

                /* Even if number of parameters is wrong, we still go ahead with the typeCheck() */
                if ((int)parameters->size() <= event()->type()->arity())
                    num_params = parameters->size();
                else
                    num_params = event()->type()->arity();

                formal_param = (std::vector<Type *>*)event()->type()->argTypes();

                for (i = 0; i < num_params; i++) {
                    parameters->at(i)->typeCheck();

                    if(formal_param->at(i)->isSubType((Type *)parameters->at(i)->type())) {
                        if (!parameters->at(i)->type()->isSubType((Type *)formal_param->at(i)))
                            parameters->at(i)->initVal()->coercedType(formal_param->at(i));
                    } else {
                        cout << "Event : Parameter mismatch........." << endl;
                    }
                }

            }

            type((Type *)event()->type()->retType());
            return type();
        }
    }
    return NULL;
}

void PrimitivePatNode::typePrint(ostream& out, int indent) const 
{
    out << "(";
    if(event() != NULL) {
        out << event()->name();
        if(event()->name().compare("any") == 0) {
            
        }
        else {
            out << "(";
            bool prComma = false;
            const vector<const VariableEntry*> *vars = params();
            if(vars != NULL && vars->size() > 0) {
                if(vars != NULL) {
                    for(std::vector<const VariableEntry*>::const_iterator it =  vars->begin(); it != vars->end(); it++) {
                        if(prComma) 
                            out << ", ";
                        (*it)->typePrint(out, indent);
                        prComma = true;
                    }
                }
            }
        out << ")";
        }
    }
    
    if(cond() != NULL) {
        out << "|";
        cond()->typePrint(out, indent);
    }
    out << ")";
}

bool PrimitivePatNode::hasSeqOps() const 
{
    if(kind() == BasePatNode::PatNodeKind::SEQ || kind() == BasePatNode::PatNodeKind::STAR)
        return true;
    return false;
}

bool PrimitivePatNode::hasNeg() const 
{
    if(kind() == BasePatNode::PatNodeKind::NEG)
        return true;
    return false;
}

bool PrimitivePatNode::hasAnyOrOther() const
{
    if(kind() == BasePatNode::PatNodeKind::UNDEFINED)
        return true;
    return false;
}

void PatNode::print(ostream& out, int indent) const 
{
    out << "(";
    switch(kind()) {
    case BasePatNode::PatNodeKind::NEG:
            out << "!";
            if(pat1() != NULL)
                pat1()->print(out, indent);
            break;
    case BasePatNode::PatNodeKind::STAR: 
            if(pat1() != NULL)
                pat1()->print(out, indent);
            out << "**";
            break;
    case BasePatNode::PatNodeKind::SEQ:
            if(pat1() != NULL)
                pat1()->print(out, indent);
            out << ":";
            if(pat2() != NULL)
                pat2()->print(out, indent);
            break;
    case BasePatNode::PatNodeKind::OR:
            if(pat1() != NULL)
                pat1()->print(out, indent);
            out << " \\/ ";
            if(pat2() != NULL)
                pat2()->print(out, indent);
            break;
    default:
            if(pat1() != NULL)
                pat1()->print(out, indent);
            if(pat2() != NULL)
                pat2()->print(out, indent);
            break;
    }
    out << ")";
}

const Type* PatNode::typeCheck() {
    LOG("");
    switch(kind()) {
    case BasePatNode::PatNodeKind::NEG:
            if(pat1() != NULL) {
                pat1()->typeCheck();
                if(!(pat1()->isNegatable()))
			errMsg("Only simple patterns without `.', `*', and `!' operators can be negated", pat1());
            }
            break;
    case BasePatNode::PatNodeKind::STAR: 
            if(pat1() != NULL) {
                pat1()->typeCheck();
            }
            break;
    case BasePatNode::PatNodeKind::SEQ:
    case BasePatNode::PatNodeKind::OR:
    default:
            if(pat1() != NULL)
                pat1()->typeCheck();
            if(pat2() != NULL)
                pat2()->typeCheck();
            break;
    }

    return NULL;
}

void PatNode::typePrint(ostream& out, int indent) const 
{
    out << "(";
    switch(kind()) {
    case BasePatNode::PatNodeKind::NEG:
            out << "!";
            if(pat1() != NULL)
                pat1()->typePrint(out, indent);
            break;
    case BasePatNode::PatNodeKind::STAR: 
            if(pat1() != NULL)
                pat1()->typePrint(out, indent);
            out << "**";
            break;
    case BasePatNode::PatNodeKind::SEQ:
            if(pat1() != NULL)
                pat1()->typePrint(out, indent);
            out << ":";
            if(pat2() != NULL)
                pat2()->typePrint(out, indent);
            break;
    case BasePatNode::PatNodeKind::OR:
            if(pat1() != NULL)
                pat1()->typePrint(out, indent);
            out << " \\/ ";
            if(pat2() != NULL)
                pat2()->typePrint(out, indent);
            break;
    default:
            if(pat1() != NULL)
                pat1()->typePrint(out, indent);
            if(pat2() != NULL)
                pat2()->typePrint(out, indent);
            break;
    }
    out << ")";
}

bool PatNode::hasSeqOps() const 
{
    if(kind() == BasePatNode::PatNodeKind::SEQ || kind() == BasePatNode::PatNodeKind::STAR)
        return true;
    return false;
}

bool PatNode::hasNeg() const 
{
    if(kind() == BasePatNode::PatNodeKind::NEG)
        return true;
    return false;
}

bool PatNode::hasAnyOrOther() const
{
    if(kind() == BasePatNode::PatNodeKind::UNDEFINED)
        return true;
    return false;
}

void RuleNode::print(ostream& out, int indent) const 
{
    prtSpace(out, indent);
    if(pat() != NULL) 
        pat()->print(out, indent);
    out << "-->";
    prtSpace(out, indent);
    if(ruleEntry() != NULL) 
        ruleEntry()->print(out, indent);
    if(reaction() != NULL) 
        reaction()->print(out, indent);
    out << ";";
} 

void RuleNode::typePrint(ostream& out, int indent) const 
{
    prtSpace(out, indent);
    if(pat() != NULL) 
        pat()->typePrint(out, indent);
    out << "-->";
    prtSpace(out, indent);
    if(ruleEntry() != NULL) 
        ruleEntry()->typePrint(out, indent);
    if(reaction() != NULL) 
        reaction()->typePrint(out, indent);
    out << ";";
} 

const Type* RuleNode::typeCheck() {
	LOG("");
	if(pat() != NULL)
		pat()->typeCheck();
	if(ruleEntry() != NULL)
		ruleEntry()->typeCheck();
	if(reaction() != NULL)
		reaction()->typeCheck();
	return NULL;
}
