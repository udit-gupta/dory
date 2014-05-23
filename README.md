By:

Arun Olappamanna
Sonam Mandal
Udit Gupta

Compilation of code:

make clean && make

Running the code:

./demo <input file> <output file>

Input File: Input E-- code file.
Output File: Output file for intermediate code generation.


Converting intermediate code to machine code:

cd icodegen
cp <output file> .
./demo <output file>

The above will create an executable which can be run.
The executable will have the same basename as the <output file>

Location of test intermediate codegen: intermediate-codegen-tests folder
