#ifndef STE_CLASSES_H
#define STE_CLASSES_H

#include "SymTab.h"
#include "SymTabEntry.h"
#include "Ast.h"

class StmtNode;
class RuleNode;
class ExprNode;
class PatNode;
class VariableEntry;
class OpNode;
class PrimitivePatNode;
extern string newName(const string&);

/****************************************************************
  The first few classes dont really add any functionality over
  the base class, except for providing a convenient constructor.
****************************************************************/

class GlobalEntry: public SymTabEntry {
 public:
  GlobalEntry(string name, int line=0, int column=0, string file=""):
    SymTabEntry(name, SymTabEntry::Kind::GLOBAL_KIND, line, column,file), rules_() {};
  ~GlobalEntry() {};

  const vector<RuleNode*> rules() const { return rules_;};
  vector<RuleNode*> rules() { return rules_;};
  const RuleNode* rule(int i) const { return rules_[i];}
  RuleNode* rule(int i) { return rules_[i];}
  void addRule(RuleNode* re) { rules_.push_back(re);};

  void print(ostream&, int indent=0) const;

 private:
  vector<RuleNode*> rules_;
};

class BlockEntry: public SymTabEntry {
 public:
  BlockEntry(string name, int line=0, int column=0, string file=""):
    SymTabEntry(name, SymTabEntry::Kind::BLOCK_KIND, line, column, file, (Type*)&Type::voidType) {};
  ~BlockEntry() {};
  void print(ostream& out, int indent=0) const; 
};

class RuleBlockEntry: public BlockEntry {
 public:
  RuleBlockEntry(int line=0, int column=0, string file=""):
    BlockEntry(newName("rule"), line,column, file) { kind(SymTabEntry::Kind::RULE_BLOCK_KIND);};
  ~RuleBlockEntry() {};
};

/****************************************************************
  Following classes add more significant functionality to that
  provided by SymTabEntry.
****************************************************************/

class VariableEntry: public SymTabEntry {
 public:
  enum VarKind {GLOBAL_VAR, LOCAL_VAR, PARAM_VAR, UNDEFINED};

 public:
  VariableEntry(string name, VarKind v, Type* type=nullptr,
				ExprNode* init=nullptr, int ln=0, int col=0, string file=""):
    SymTabEntry(name, SymTabEntry::Kind::VARIABLE_KIND, ln, col, file, type) {
    vkind_ = v; initVal(init);
 };

  VariableEntry(const VariableEntry &v);
  ~VariableEntry() {};

  VarKind varKind() const { return vkind_;};
  void varKind(VarKind v) { vkind_ = v;};

  int offSet() const { return offSet_;} ;
  void offSet(int o) {offSet_ = o;};

  const ExprNode* initVal() const { return initVal_;}
  ExprNode* initVal() { return initVal_;};
  void initVal(ExprNode *init) { initVal_ = init;};

  void print(ostream& os, int indent=0) const;

 private:
  VarKind vkind_;
  int offSet_;
  ExprNode* initVal_;
};

class ClassEntry: public SymTabEntry {
 public:
  ClassEntry(string name, int line=0, int column=0, string file="")
    : SymTabEntry(name, SymTabEntry::Kind::CLASS_KIND, line,column, file) {};
  ~ClassEntry() {};

  void print(ostream& os, int indent) const;
};

class FunctionEntry: public SymTabEntry {
 public:
  FunctionEntry(string name, Type* type=nullptr,
				int line=0, int column=0, string file=""):
    SymTabEntry(name, SymTabEntry::Kind::FUNCTION_KIND, line,column, file, type) {
      body_ = nullptr;
 	};
  ~FunctionEntry() {};

  const CompoundStmtNode* body() const { return body_;};
  CompoundStmtNode* body() {return body_;};
  void body(CompoundStmtNode* n) { body_ = n;};

  void print(ostream& os, int indent) const;

 private:
  CompoundStmtNode* body_;
};

class EventEntry: public SymTabEntry {
 public:
  EventEntry(string name, int line=0, int column=0, string file=""):
    SymTabEntry(name, SymTabEntry::Kind::EVENT_KIND, line,column, file) {};
  ~EventEntry() {};

  void print(ostream& out, int indent=0) const; 
};  

#endif
