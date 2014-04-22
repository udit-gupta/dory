// C Program corresponding to ICode program below
//
// int gvar;
//
// L_add: 
//   while (gvar != 10) 
//     ++gvar; 
//   goto L_past_add
// 
// L_main:
//   gvar = 5;
//   printf("Value of global variable before incrementing till 10: %d\n", gvar);
//   goto L_add;
// L_past_add:
//   printf("Value of global variable after incrementing till 10: %d\n", gvar);
//  

JMP L_MAIN

L_add: LDI R000 R200 // load the value of global var into R200
ADD R200 1 R200
STI R200 R000 // store the computed value of global var back to memory
JMPC NE 10 R200 L_add // add till the value is not equal to 10.
JMP L_past_add // otherwise jump to past_add label

L_MAIN: PRTS "Value of global variable before incrementing till 10: "
MOVI 100 R000 // R000 contains address of global variable. Lets say the
              // compiler decided to allocate address [100-104] to global var
              // because it was of type int.
STI 5 R000 // Assign global var to 1
LDI R000 R900 // Load back value into reg and print it.
PRTI R900
PRTS "\n"

JMP L_add

L_past_add: PRTS "Value of global variable after incrementing till 10: "
LDI R000 R900 // Load back value into reg and print it.
PRTI R900
PRTS "\n"
