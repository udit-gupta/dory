/* Test Program for recursion */

event f(); /* Event Name can be only one character */

int recursion_test(int counter) {
    printf("\nEntering Recursion Function\n");
    if(counter == 0)
        return 0;
    else {
       printf("Count before:");
       printf(counter);
       printf("\n");
       counter=counter-1;
       recurion_test(counter);
       printf("Count After:");
       printf(counter);
       printf("\n");
       return 0;
    }
    printf("\nLeaving Recursion Function\n");
} 

void call_test() {
    printf("\n................Start-Test................\n");
    recursion_test(10);
    printf("\n.................End-Test..................\n");
}


f() -> {
    call_test();
};
