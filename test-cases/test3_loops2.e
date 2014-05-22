/* Test Program for loops */

event f(); /* Event Name can be only one character */

void while_test();

void while_test() {
    int a = 1;
    int b = 2;
    printf("\nEntering While Function\n");
    while(b<=15) {
        printf("\n Outer Loop: \n");
        b=b+1;
        if(b==15) {
            printf("\nexit\n");
        }
        while(a <= 15) {
            a=a+1;
            printf("\n Inner Loop: \n");
            if(a==13) {
                printf("\n break from outer while\n");
            }
        }
    }    
    printf("\nLeaving While Function\n");
} 

void call_test() {
    printf("\n................Start-Test................\n");
    while_test();
    printf("\n.................End-Test..................\n");
}


f() -> {
    call_test();
};
