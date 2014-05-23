/* Test Program for Operators */

event f(); /* Event Name can be only one character */

void operators_test() {
    printf("\nEntering Operator Testing Function\n");
    printf("\nLeaving Operator Testing Function\n");
}

void call_test() {
    printf("\n................Start-Test................\n");
    operators_test();
    printf("\n.................End-Test..................\n");
}


f() -> {
    call_test();
};
