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
    } else
      type(new Type(Type::TypeTag::ERROR));

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
        /* This should not happen. Return error. */
        type(new Type(Type::TypeTag::ERROR));
      }
    } else
      type(new Type(Type::TypeTag::ERROR));

    return type();
  }

  if (opCode_ == OpNode::OpCode::BITNOT) {
    assert(arity_ == 1);

    if (arg(0)->type()->isNumeric(arg(0)->type()->tag()))
      type(arg(0)->type());
    else
      type(new Type(Type::TypeTag::ERROR));

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

    if (arg(0)->type()->isNumeric(arg(0)->type()->tag()))
      type(arg(0)->type());
    else
      type(new Type(Type::TypeTag::ERROR));

    return type();
  }

  if (opCode_ == OpNode::OpCode::ASSIGN) {
    if (arg(0)->type()->isSubType(arg(1)->type())) {
      if (!arg(1)->type()->isSubType(arg(0)->type()))
        arg(1)->coercedType(arg(0)->type());
      
      type(new Type(Type::TypeTag::BOOL));
    } else
      type(new Type(Type::TypeTag::ERROR));

    return type();
  }

  type(new Type(Type::TypeTag::ERROR));
  return type();
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

IfNode::IfNode(ExprNode* cond, StmtNode* thenStmt, StmtNode* elseStmt, int line, int column, string file):
StmtNode(StmtNode::StmtNodeKind::IF, line, column, file) 
{
    IfNode::cond_ = cond;
    IfNode::then_ = thenStmt;
    IfNode::else_ = elseStmt;
}

PrimitivePatNode::PrimitivePatNode(EventEntry* ee, vector<VariableEntry*>* params, ExprNode* c, int line, int column, string file):
BasePatNode(BasePatNode::PatNodeKind::PRIMITIVE, line, column, file)
{
    PrimitivePatNode::ee_ = ee;
    PrimitivePatNode::params_ = params;
    PrimitivePatNode::cond_ = c;
}

PatNode::PatNode(PatNodeKind pk, BasePatNode *p1, BasePatNode*p2, int line, int column, string file):
BasePatNode(pk, line, column, file)
{
    PatNode::pat1_ = p1;
    PatNode::pat2_ = p2;
}

RuleNode::RuleNode(BlockEntry *re, BasePatNode* pat, StmtNode* reaction, int line, int column, string file):
AstNode(AstNode::NodeType::RULE_NODE, line, column, file)
{
    RuleNode::rste_ = re;
    RuleNode::pat_ = pat;
    RuleNode::reaction_ = reaction;
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

    if ((int)parameters->size() != symTabEntry()->type()->arity()) {
      cout << "Incorrect number of parameters passed. Call: " << parameters->size() << " Decl: " << symTabEntry()->type()->arity() << endl;
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
        cout << "Parameter mismatch........." << endl;
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
    type(new Type(Type::TypeTag::ERROR));
  }

  return type();
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
    if(kind() == BasePatNode::PatNodeKind::SEQ)
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
    if(kind() == BasePatNode::PatNodeKind::SEQ)
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
