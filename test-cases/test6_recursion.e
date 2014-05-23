/* Test Program for recursion */

event f(); /* Event Name can be only one character */

int recursion_test(int counter) {
    printf("\nEntering Recursion Function\n");
    if(counter == 0) {
        printf("\ncounter is 0\n");
        return 0;
    } else {
       printf("Count before: %d", counter);
       printf("\n");
       counter=counter-1;
       recursion_test(counter);
       printf("Count After: %d", counter);
       printf("\n");
       return counter;
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
