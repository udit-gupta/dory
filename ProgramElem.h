#ifndef PROGRAM_ELEM_H
#define PROGRAM_ELEM_H

// This is a class designed to hold info common to all program components,
// which is primarily just the location where the component occurs.

#include <string>
#include "Type.h"
#include "Reg.h"

extern int yylineno, yycolumnno;
extern const char* yyfilename;

class ProgramElem {
 public:

  ProgramElem(Type* t=NULL, int line=0, int column=0, string file="") {
    type_ = t;
    line_ = (line == 0) ?  yylineno : line;
    column_ = (column == 0) ? yycolumnno : column;
    file_ = file == "" ? string(yyfilename) : file;
	reg_ = -1;
	regType_ = REG_INT;
  }

  ProgramElem(const ProgramElem& pe) {
	operator=(pe);
  }
  ~ProgramElem() { }

  int line() const { return line_; };
  void line(int l) { line_ = l;}

  int column() const { return column_; };
  void column(int c) { column_ = c; }

  string file() const { return file_; };
  void file(string filename) { file_ = filename; }

  const Type* type() const { return type_;}
  Type* type() { return type_;}
  void type(Type* t) {type_ = t;};
  Type::TypeTag typeTag() const { 
    if (type_ != NULL) 
      return type_->tag(); 
    else return Type::ERROR;
  }

  const ProgramElem& operator=(const ProgramElem& pe) {
	line_ = pe.line_;
	column_ = pe.column_;
	file_ = pe.file_;
	type_ = pe.type_;
	return *this;
  };

  void setReg(int reg, RegType regType) {
	  reg_ = reg;
	  regType_ = regType;
  }

  //int getReg(void) { return reg_; }
  int getReg(void) const { return reg_; }

  enum RegType reg_type(void) const { return regType_; };

 private:
  int line_; 
  int column_;
  string file_;
  Type* type_;
  // reg_ = -1 for not assigned
  int reg_;
  RegType regType_;
};

#endif
