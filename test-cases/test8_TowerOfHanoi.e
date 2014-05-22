/* Test Program for Tower Of Hanoii recursion */

event f(int number); /* Event Name can be only one character */

void TOH(int n,int first,int last);

void call_test(int n) {
    print("\n................Start-Test................\n");
    /* n is number of plates */
    TOH(n,1,3);
    print("\n.................End-Test..................\n");
}

void TOH(int n, int startPole, int endPole) {
    if (n== 0){
      return; 
    }
    int intermediatePole = 6 - startPole - endPole;
    move(n-1, startPole, intermediatePole);
    System.out.println("Move " +n + " from " + startPole + " to " +endPole);
    TOH(n-1, intermediatePole, endPole);
}

f(i) -> {
    call_test(i);
};






















