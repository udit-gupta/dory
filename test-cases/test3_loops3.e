/* Test Program for While-loop */

event f(); /* Event Name can be only one character */

//void while_test();

void while_test() {
    int a = 1;
    int b = 2;
        
    printf("\\nEntering While Function\\n");
    while(b<15) {
        b=b+1;
        printf("\\n In First While block \\n");
    }
    
    while(a <= 4) {
        a=a+1;
        if(a==4) {
            printf("\\n leaving last While");
        }
    }
    printf("\\nLeaving While Function\\n");
} 

void call_test() {
    printf("\\n................Start-Test................\\n");
    while_test();
    printf("\\n.................End-Test..................\\n");
}


f() -> {
    call_test();
};
