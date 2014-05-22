/* Test Program for Operators */

event f(); /* Event Name can be only one character */

void operators_test() {
    int a = (1+2);
    int b = a - (-3);
    double c = 5.67 * 10;
    int d = (4 * b);
    int e = 2 - a;
    int f = 6 / 2;
    int g = a / 2;
    int h = 8 % 2;
    int i = 0 | 1 & 0;
    int j = ~i;
    int k = 1 ^ 1;
    int l = a << 2;
    int m = a >> 2;
    double n = (a % b - d / 3);
    bool p = (true || false);
    int q =  !a || (b<d) && (e>=f) || (g==h);


    printf("\nEntering Operator Testing Function\n");
    printf("\n a = (1+2): ",a);
    printf("\n b = (a-(-3)): ", b);
    printf("\n c = (5.67*10): ", c);
    printf("\n d = (4*b): ", d);
    printf("\n e = (2-a): ", e);
    printf("\n f = (6/2): ", f);
    printf("\n g = (a/2): ", g);
    printf("\n h = (8%2): ", h);
    printf("\n i = (0|1&0): ", i);
    printf("\n j = (~i): ", j);
    printf("\n k = (1^1): ", k);
    printf("\n l = (a<<2): ", l);
    printf("\n m = (a>>2): ", m);
    printf("\n n = (a % b - d / 3): ", n);
    printf("\n p = (true || false): ", p);
    printf("\n q =  !a || (b<d) && ((e>=f) || (g==h)): ",q);
    printf("\nLeaving Operator Testing Function\n");
}

void call_test() {
    printf("\n................Start-Test................\n");
    operators_test();
    printf("\n.................End-Test..................\n");
}


f() -> {
    call_test();
};
