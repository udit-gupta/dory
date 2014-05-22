/* Test Program for loops */

event f(); /* Event Name can be only one character */

void while_test() {
    print("\nEntering While Function\n");
    int a = 1;
    int b = 2;
    while(true) {
        print("\n Outer Loop: \n");
        b=b+1;
        if(b==15) {
            print("\nexit\n");
            break;
        }
        while(a <= 15) {
            a=a+1;
            print("\n Inner Loop: \n");
            if(a==13) {
                print("\n break from outer while\n");
                break 2;
            }
        }
    }    
    print("\nLeaving While Function\n");
} 

void call_test() {
    print("\n................Start-Test................\n");
    while_test();
    print("\n.................End-Test..................\n");
}


f() -> {
    call_test();
};
