/* Test Program for if-else */

event f(); /* Event Name can be only one character */

void if_test() {
    print("\nEntering IF Function\n");
    int a = 1;
    int b = 2;
    b=b+1;
        
    if(b==15) {
        print("\nexit\n");
        break;
    }
    
    if(a <= 15) {
        a=a+1;
        if(a==13) {
            print("\n leaving last If");
        }
    }
    print("\nLeaving IF Function\n");
} 

void call_test() {
    print("\n................Start-Test................\n");
    if_test();
    print("\n.................End-Test..................\n");
}


f() -> {
    call_test();
};
