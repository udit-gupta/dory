#include "STEClasses.h"
#include "Value.h"
#include "ParserUtil.h"

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

void EventEntry::print(ostream& out, int indent) const
{
    out << "event " << name();
    printST(out, indent, '(', ')', false);
}

void ClassEntry::print(ostream& out, int indent) const 
{
    out << "class " << name();
} 

void VariableEntry::print(ostream& out, int indent) const
{
    out << type()->fullName() << " " << name();
    if(initVal() != NULL) {
        out << " = ";
        initVal()->print(out, indent);
    }
}

void FunctionEntry::print(ostream& out, int indent) const 
{
	int prmCnt = 0;
	int tot= 0;
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

void BlockEntry::print(ostream& out, int indent) const
{
    printST(out, indent, '{', '}', true);
}

