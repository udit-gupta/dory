#include "Value.h"

#include <stdlib.h>

// @@@@ arch-dependent => should be somewhere else!

const int MININT = (int)(1 << 31);
const int MAXINT = ~(MININT);
const unsigned MAXUNSIGNEDINT = ~0;

Value::Value(int i, Type::TypeTag t) {
  if (!Type::isInt(t)) {
    internalErr("Value::Value(int, TypeTag): TypeTag incompatible with int");
	type_ = &Type::errorType;
  }
  else {
	type_ = Type::type[t];
	iVal_ = i;
  }
}

Value::Value(unsigned int i, Type::TypeTag t) {
  if (Type::isInt(t) && Type::isUnsigned(t)) {
	type_ = Type::type[t];
	iVal_ = i;
  }
  else {
    internalErr("Value::Value(unsigned, TypeTag): TypeTag incompatible with int");
	type_ = &Type::errorType;
  }
}

Value::Value(const Value& v) {
  type_ = v.type_;
  sVal_ = NULL;
  operator=(v);
}

// **** Invariant for all constructors: type_ is non-null and correctly set,
// **** and appropriate union field is properly initialized.

void 
Value::print(ostream& os, int indent) const {
  Type::TypeTag t;
  switch (t = type_->tag()) {
  case Type::ERROR: 
	os << "ErrorValue "; break;
  case Type::VOID: 
	os << "VoidValue"; break;
  case Type::BOOL: 
	os << ((bVal_ == false) ? "false" : "true"); 
	break;
  default: 
	if (Type::isString(type_->tag()))
	  if (sVal_ == NULL)
		os << "NULL POINTER";
	  else os << "\"" << *sVal_ << "\""; 
	else if (Type::isInt(t))
	  if (Type::isSigned(t))
		os << iVal_; 
	  else os << (unsigned int)iVal_;
	else if (Type::isFloat(t)) 
	  os << dVal_;
	else internalErr("Value::print: unsupported value type");
  }
}

string 
Value::sval() const {
  if ((Type::isString(type_->tag())) && (sVal_ != NULL))
      return *sVal_;
  else {
    internalErr("Value::sval: Incorrect Type ");
	return string();
  }
}

bool 
Value::bval() const {
  if (type_->tag() != Type::BOOL)
	internalErr("Value::bval: stored type is not bool");
  return bVal_;
}

int 
Value::ival() const {  // for bit, byte, unsigned/signed short/int, long
  if (Type::isInt(type_->tag())) 
	return iVal_;
  internalErr("Value::ival: Incorrect Type ");
  return 0;
}

double
Value::dval() const { 
  if (Type::isFloat(type_->tag()))
    return dVal_; 
  else {
    internalErr("Value::dval: Incorrect Type ");
	return 0.0;
  }
}

void
Value::sval(string s) { 
  if (Type::isString(type_->tag())) {
	//if  (sVal_ != NULL)
	//  delete sVal_;
	sVal_ = new string(s);
  }
  else internalErr("Value::sval: Incorrect Type ");
}

void 
Value::ival(int i) {
  if (Type::isInt(type_->tag())) 
	iVal_ = i;
  else internalErr("Value::ival: Incorrect Type ");
}

void 
Value::dval(double d) {
  if (Type::isFloat(type_->tag()))
    dVal_ = d; 
  else internalErr("Value::dval: Incorrect Type ");
}


