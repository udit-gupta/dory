#include "SymTabEntry.h"


static const char* const kindtag[] = {
  "UNKNOWN_KIND",
  "GLOBAL_KIND",
  "CLASS_KIND","FUNCTION_KIND", 
  "VARIABLE_KIND", 
  "EVENT_KIND", 
  "RULE_KIND", 
  "BLOCK_KIND", "RULE_BLOCK_KIND", "EVENT_BLOCK_KIND",
  "ERROR_KIND"
};

string 
SymTabEntry::kindTag(SymTabEntry::Kind k){
  if ((k >= SymTabEntry::Kind::UNKNOWN_KIND) && 
			(k < SymTabEntry::Kind::ERROR_KIND))
    return kindtag[static_cast<int>(k)];
  else return kindtag[static_cast<int>(SymTabEntry::Kind::ERROR_KIND)];
}

SymTabEntry::SymTabEntry(string name, SymTabEntry::Kind k, 
			 int lineno, int columnno, string filename, Type *t) 
  : ProgramElem(t,lineno,columnno,filename) {
  name_ = name;
  kind_ = k;
  if (type() == NULL)
    type(new Type(Type::voidType));
  st_ = NULL;
  next_ = prev_ = NULL;
}

bool 
SymTabEntry::operator==(const SymTabEntry& ste)const {
  // @@@@ Reference comparison implemented, but is this appropriate?
  // Probably: STE cannot be copied or assigned, and there isn't much
  // reason to create multiple STEs for the same symbol, so this is enough
  return (&ste == this);
}

