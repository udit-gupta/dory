
/* Test Program for events */

event f(); /* Event Name can be only one character */

double result = 0;

f()-> {
    result = 1 + 2 * 3 / 4;
    printf("\n Computation result inside Event: %f", result);
}

