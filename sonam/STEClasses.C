#include "STEClasses.h"
#include "Value.h"
#include "ParserUtil.h"

void GlobalEntry::print(ostream& out, int indent) const
{

//    prtSpace(out, indent);
//    printST(out, indent, '\0', ';', true);
//    prtln(out, indent);
 //   const vector<RuleNode*> pr = GlobalEntry::rules();
 //   if(pr.size() == 0 ) 
   //     prtln(out, indent);
 //   for(vector<RuleNode*>::const_iterator it = pr.begin(); it != pr.end(); it++) {
   //     (*it)->print(out, indent + STEP_INDENT);
     //   endln(out, indent);
  //  }
  //  prtSpace(out, indent + STEP_INDENT);

    this->printST(out, indent, 0, ';', true);

	for(std::vector<RuleNode*>::const_iterator it = rules_.begin(); it != rules_.end(); ++it) {
		(*it)->print(out, indent+2);
	}
}

void EventEntry::print(ostream& out, int indent) const
{
	prtln(out, indent);
	out << "event " << this->name();

	if (this->name() != "any")
		this->printST(out, indent, '(', ')', false);
	else
		this->printST(out, indent, 0, 0, false);
}

void VariableEntry::print(ostream& os, int indent) const
{
	this->type()->print(os, indent);
	os << " " << this->name();

	if (this->initVal()) {
		os << " = ";
		this->initVal()->print(os, indent);
	}
}

void ClassEntry::print(ostream& os, int indent) const
{
	prtln(os, indent);
	os << "class " << this->name();
	this->printST(os, indent);
}

void FunctionEntry::print(ostream& os, int indent) const
{
	os << this->type()->retType()->fullName() << " ";
	os << this->name();

	if (this->type()->arity())
		this->printST(os, indent, '(', ')', false, 0, this->type()->arity());
	else
		os << "()";

	if (this->body()) {
		os << " {";
		prtln(os, indent+2);
		this->printST(os, indent, '\0', ';', true, this->type()->arity(), 10000);
		this->body()->printWithoutBraces(os, indent);
		os << "}";
	}
}

void BlockEntry::print(ostream& os, int indent) const
{
	os << this->name();
	this->printST(os, indent+2);
}
