
/* Test Program for events */

event f(); /* Event Name can be only one character */
event g(int a);

int result = 0;

void call_test2() {
    result = 1 + 2 * 3 / 3;
    printf("\n Computation result inside Event G: %d\n", result);
    printf("\n\n");
}

void call_test() {
    result = 1 + 2 * 3 / 2;
    printf("\n Computation result inside Event: F %d\n", result);
    printf("\n\n");
}


f()-> {
    call_test();
}

g(file)-> {
    call_test2();
}

