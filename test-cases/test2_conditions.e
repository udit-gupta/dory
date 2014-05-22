/* Test Program for if-else */

event f(); /* Event Name can be only one character */
void if_test();

void if_test() {
    int a = 1;
    int b = 2;
    b=b+1;
        
    printf("\\nEntering IF Function\\n");
    if(b==15) {
        printf("\\n In b block \\n");
    }
    
    if(a <= 4) {
        a=a+1;
        if(a==2) {
            printf("\\n leaving last If");
        }
    }
    printf("\\nLeaving IF Function\\n");
} 

void call_test() {
    printf("\\n................Start-Test................\\n");
    if_test();
    printf("\\n.................End-Test..................\\n");
}


f() -> {
    call_test();
};
