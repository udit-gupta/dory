/* Test Program for loops */

event f(); /* Event Name can be only one character */

void while_test() {
    int c = 0;
    int a = 10;
    int b = 20;
    printf("\nEntering While Function\n");
    while(b>0) {
        while(a > 0) {
	    c = c+a*b;
            a=a-1;
        }
        b=b-1;
    }    
    printf("\nLeaving While Function\n");

    printf("\nReturned value: %d\n", c);
} 

void call_test() {
    printf("\n................Start-Test................\n");
    while_test();
    printf("\n.................End-Test..................\n");
}


f() -> {
    call_test();
};
