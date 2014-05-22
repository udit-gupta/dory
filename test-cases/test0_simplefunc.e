/* Test Program for Operators */

event f(); /* Event Name can be only one character */

void call_test() {
    int a = 3;
    int b = 4;
    int c = 5;
    double d = 5.0;
    printf("\nValue of a: %d\n", a);
    printf("\nValue of b: %d\n", b);
    printf("\nValue of c: %d\n", c);
    printf("\nValue of d: %f\n", d);
    printf("\n................Start-Test................\n");
    printf("\n.................End-Test..................\n");
}


f() -> {
    call_test();
};
