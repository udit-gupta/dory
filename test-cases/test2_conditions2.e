/* Test Program for Operators */

event f(); /* Event Name can be only one character */

void if_test() {
    int a = 1;
    int b = 2;
    printf("\nInside IF\n");
}

void call_test() {
    printf("\n................Start-Test................\n");
    if_test();
    if_test();
    printf("\n.................End-Test..................\n");
}


f() -> {
    call_test();
};
