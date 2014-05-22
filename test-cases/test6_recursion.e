/* Test Program for recursion */

event f(); /* Event Name can be only one character */

void recursion_test(int counter) {
    print("\nEntering Recursion Function\n");
    if(counter == 0)
        return;
    else {
       print("Count before:");
       print(counter);
       print("\n");
       counter=counter-1;
       recurion_test(counter);
       print("Count After:");
       print(counter);
       print("\n");
       return;
    }
    print("\nLeaving Recursion Function\n");
} 

void call_test() {
    print("\n................Start-Test................\n");
    recursion_test(10);
    print("\n.................End-Test..................\n");
}


f() -> {
    call_test();
};
