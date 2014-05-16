CXX=g++
#CXX=clang++
CXXFLAGS_DEF = -g -O -Wno-deprecated -std=c++0x -Wall
CXXFLAGS = $(CXXFLAGS_DEF)
ifeq ($(DEBUG), 1)
CXXFLAGS = $(CXXFLAGS_DEF) -DDEBUG
endif
FLEX = flex
BISON = bison

demo:	driveParse.o E--_lexer.o E--_parser.o Ast.o STEClasses.o SymTabMgr.o Value.o Type.o IntermediateCodeGen.o SymTabEntry.o Error.o ParserUtil.o SymTab.o MemAllocUtil.o Reg.o Instruction.o
	$(CXX) -o $@ $^ -lfl

E--_lexer.o:	E--_lexer.C E--.tab.h
E--_parser.o: E--_parser.C E--.tab.h

E--_parser.C: E--_parser.y++
	$(BISON) -t -d -v -o E--_parser.C E--_parser.y++; \
  mv E--_parser.H E--.tab.h

SymTabMgr.o: SymTabMgr.h SymTabMgr.C
SymTabEntry.o: SymTabEntry.h SymTabEntry.C
STEClasses.o: STEClasses.h STEClasses.C
Ast.o: Ast.h Ast.C
Value.o: Value.h Value.C
Type.o: Type.h Type.C
Error.o: Error.h Error.C
ParserUtil.o: ParserUtil.h ParserUtil.C
SymTab.o: SymTab.h SymTab.C
MemAllocUtil.o: MemAllocUtil.h MemAllocUtil.C
Reg.o: Reg.h Reg.C
#CodeGen.o: CodeGen.h CodeGen.C
Instruction.o: Instruction.h Instruction.C
IntermediateCodeGen.o: IntermediateCodeGen.h IntermediateCodeGen.C

clean:
	-echo "Removing all object files!"
	-rm -f demo *.o
	-echo "Removing intermediate C files!"
	-rm -f E--_parser.C
