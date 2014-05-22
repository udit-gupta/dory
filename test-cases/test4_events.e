
/* Test Program for events */

event f(); /* Event Name can be only one character */

int result = 0;


void call_test()-> {
    result = 1 + 2 * 3 / 4;
    printf("\n Computation result inside Event: %f", result);
}


f()-> {
    call_test();
}



