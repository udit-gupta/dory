/* Test Program for Tower Of Hanoii recursion */

event f(); /* Event Name can be only one character */

int start = 3;

int TOH(int n, int startPole, int endPole) {
    int intermediatePole = 6 - startPole - endPole;

    if (n== 0){
      return 0; 
    }

    move(n-1, startPole, intermediatePole);
    printf("\n"); 
    printf("Move "); 
    printf(n); 
    printf(" from "); 
    printf(startPole); 
    printf(" to "); 
    printf(endPole);
    printf("\n"); 
    TOH(n-1, intermediatePole, endPole);
}

void call_test(int n) {
    printf("\n................Start-Test................\n");
    TOH(n,1,3);
    printf("\n.................End-Test..................\n");
}

f() -> {
    call_test(start);
};






















