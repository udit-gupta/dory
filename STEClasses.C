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

const Type* GlobalEntry::typeCheck()
{
    /* TODO: Figure out how to indicate error in Type Checking Phase */
    const Type *type = NULL;
    const vector<RuleNode*> pr = GlobalEntry::rules();

    typeST(0, 0);

    for(vector<RuleNode*>::const_iterator it = pr.begin(); it != pr.end(); it++) {
      /* XXX: We have the type, now what to do? */
      type = (*it)->typeCheck();
    }

    return NULL;
}

void EventEntry::print(ostream& out, int indent) const
{
    out << "event " << name();
    printST(out, indent, '(', ')', false);
}

const Type* EventEntry::typeCheck()
{
    return NULL;
}

void ClassEntry::print(ostream& out, int indent) const 
{
    out << "class " << name();
} 

const Type* ClassEntry::typeCheck()
{
    return NULL;
}

void VariableEntry::print(ostream& out, int indent) const
{
    out << type()->fullName() << " " << name();
    if(initVal() != NULL) {
        out << " = ";
        initVal()->print(out, indent);
    }
}

const Type* VariableEntry::typeCheck()
{
    Type *init_type = NULL;
    const Type *return_type = NULL;

    if (initVal()) {
        init_type = (Type *)initVal()->typeCheck();

        if (type()->isSubType((Type *)init_type)) {
            if (!init_type->isSubType(type()))
                initVal()->coercedType(type());
            return_type = type();
        } else {
            return_type = new Type(Type::TypeTag::ERROR);
        }
    }

    return return_type;
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

const Type* FunctionEntry::typeCheck()
{
    /* TODO: Call typeST() for this scope.
     * VariableEntry contains type information for variable declarations.
     * Need to validate that they are correct.
     */
    typeST(0, 0);
    return NULL;
}

void BlockEntry::print(ostream& out, int indent) const
{
    printST(out, indent, '{', '}', true);
}

const Type* BlockEntry::typeCheck()
{
    typeST(0, 0);
    return NULL;
}
