#include "all.h"
#include "SymTab.h"
#include "SymTabEntry.h"
#include "IntermediateCodeGen.h"

SymTab::iterator&
SymTab::iterator::operator++ () {
 if (current != nullptr)  
   current = current->next();
 return *this; 
}

SymTab::const_iterator&
SymTab::const_iterator::operator++ () {
  if (current != nullptr) 
    current = current->next();
  return *this; 
}

SymTab::SymTab(int n):map_(n) {
  first_ = last_ = nullptr;
}

const SymTabEntry* 
SymTab::lookUp(string name) const {
  if (map_.count(name) > 0)
    return map_.find(name)->second; 
  else return nullptr;
}

ErrorST 
SymTab::insert(SymTabEntry* se) {
  if (map_.count(se->name()) > 0) {
    //errMsg("Duplicate Symbol " + se->name());
    return DUPLICATE_SYM;
  } 
  else {
    map_[se->name()] = se;

    se->next(NULL);
    se->prev(last_);
    if (map_.size() == 1)
      first_ = se;
    else last_->next(se);
    last_ = se;
  }
  if (map_.bucket_count() <= map_.size())
    map_.resize(map_.bucket_count()*2);
  return OK;
}

void 
SymTab::printST(ostream& os, int indent, char leftdelim, char rightdelim, 
                bool linebreak, int first, int last) const {
  int i; SymTab::const_iterator it = begin(); int n_printed=0;

  if ((first == 0) && (last == 0))
    last = 1000000;

  for (i=0; (it != end()) && (i < last); i++, ++it)  {
    SymTabEntry *ste = (SymTabEntry *)(*it);
    if (i >= first) {
      if ((ste->kind() != SymTabEntry::Kind::RULE_BLOCK_KIND) && 
          (ste->kind() != SymTabEntry::Kind::EVENT_BLOCK_KIND) && 
          (ste->name() != "any")) {
        n_printed++;
      }
    }
  }

  if (leftdelim != '\0') {
    os << leftdelim;
  }

    if ((n_printed > 0) && (linebreak))
      prtln(os, indent+STEP_INDENT);

  for (i=0, it=begin();
       (it != end()) && (i < last); i++, ++it)  {
    SymTabEntry *ste = (SymTabEntry *)(*it);
    if (i >= first) {
      if ((ste->kind() != SymTabEntry::Kind::RULE_BLOCK_KIND) && 
          (ste->kind() != SymTabEntry::Kind::EVENT_BLOCK_KIND) && 
          (ste->name() != "any")) {
        ste->print(os,indent+STEP_INDENT);
        if ((leftdelim == '\0') && (rightdelim != '\0'))
          os << rightdelim;
        if (--n_printed > 0) {
          if (linebreak)
            prtln(os,indent+STEP_INDENT);
          else os << ", ";
        }
        else if (linebreak)
          prtln(os,indent);
      }
    }
  }

  if (leftdelim != '\0') // This is not a typo -- we shd check leftdelim
    os << rightdelim;
}

void 
SymTab::typePrintST(ostream& os, int indent, char leftdelim, char rightdelim, 
                bool linebreak, int first, int last) const {
  int i; SymTab::const_iterator it = begin(); int n_printed=0;

  if ((first == 0) && (last == 0))
    last = 1000000;

  for (i=0; (it != end()) && (i < last); i++, ++it)  {
    SymTabEntry *ste = (SymTabEntry *)(*it);
    if (i >= first) {
      if ((ste->kind() != SymTabEntry::Kind::RULE_BLOCK_KIND) && 
          (ste->kind() != SymTabEntry::Kind::EVENT_BLOCK_KIND) && 
          (ste->name() != "any")) {
        n_printed++;
      }
    }
  }

  if (leftdelim != '\0') {
    os << leftdelim;
  }

    if ((n_printed > 0) && (linebreak))
      prtln(os, indent+STEP_INDENT);

  for (i=0, it=begin();
       (it != end()) && (i < last); i++, ++it)  {
    SymTabEntry *ste = (SymTabEntry *)(*it);
    if (i >= first) {
      if ((ste->kind() != SymTabEntry::Kind::RULE_BLOCK_KIND) && 
          (ste->kind() != SymTabEntry::Kind::EVENT_BLOCK_KIND) && 
          (ste->name() != "any")) {
        ste->typePrint(os,indent+STEP_INDENT);
        if ((leftdelim == '\0') && (rightdelim != '\0'))
          os << rightdelim;
        if (--n_printed > 0) {
          if (linebreak)
            prtln(os,indent+STEP_INDENT);
          else os << ", ";
        }
        else if (linebreak)
          prtln(os,indent);
      }
    }
  }

  if (leftdelim != '\0') // This is not a typo -- we shd check leftdelim
    os << rightdelim;
}

void 
SymTab::typeST(int first, int last) const {
  int i; SymTab::const_iterator it = begin();

  if ((first == 0) && (last == 0))
    last = 1000000;

  for (i=0, it=begin();
       (it != end()) && (i < last); i++, ++it)  {
    SymTabEntry *ste = (SymTabEntry *)(*it);
    if (i >= first) {
        ste->typeCheck();
    }
  }
}

void 
SymTab::memAllocST(int first, int last, int reset_AR) const {
  int i; SymTab::const_iterator it = begin();

  if ((first == 0) && (last == 0))
    last = 1000000;

  for (i=0, it=begin();
       (it != end()) && (i < last); i++, ++it)  {
    SymTabEntry *ste = (SymTabEntry *)(*it);
    if (i >= first) {
	if (i == first)
	    ste->memAlloc(reset_AR);
	else
	    ste->memAlloc(0);
    }
  }
}

int 
SymTab::codeGenST(int first, int last, IntermediateCodeGen *list) const {
  int i; SymTab::const_iterator it = begin();
  int count = 0;

  if ((first == 0) && (last == 0))
    last = 1000000;

  for (i=0, it=begin();
       (it != end()) && (i < last); i++, ++it)  {
    SymTabEntry *ste = (SymTabEntry *)(*it);
    if (i >= first) {
	count++;
        ste->codeGen(list);
    }
  }

  return count;
}

vector<SymTabEntry*> *
SymTab::getEventEntry(void) const
{
    SymTab::const_iterator it = begin();
    vector<SymTabEntry*> * eventEntry = new vector<SymTabEntry*>();

    for (it=begin();
	    (it != end()); ++it)  {
	SymTabEntry *ste = (SymTabEntry *)(*it);

	if (ste->kind() == SymTabEntry::Kind::EVENT_KIND)
	    eventEntry->push_back(ste);
    }

    return eventEntry;
}

vector<SymTabEntry*> *
SymTab::getVariableEntry(void) const
{
    SymTab::const_iterator it = begin();
    vector<SymTabEntry*> * eventEntry = new vector<SymTabEntry*>();

    for (it=begin();
	    (it != end()); ++it)  {
	SymTabEntry *ste = (SymTabEntry *)(*it);

	if (ste->kind() == SymTabEntry::Kind::VARIABLE_KIND)
	    eventEntry->push_back(ste);
    }

    return eventEntry;
}
