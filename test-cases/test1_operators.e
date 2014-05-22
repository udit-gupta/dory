/* Test Program for Operators */

event f(); /* Event Name can be only one character */

void operators_test() {
    print("\nEntering Operator Testing Function\n");
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
    int q =  !a || (b<d) && (e>=f) || (g==h)


    print("\n a = (1+2): ",a);
    print("\n b = (a-(-3)): ", b);
    print("\n c = (5.67*10): ", c);
    print("\n d = (4*b): ", d);
    print("\n e = (2-a): ", e);
    print("\n f = (6/2): ", f);
    print("\n g = (a/2): ", g);
    print("\n h = (8%2): ", h);
    print("\n i = (0|1&0): ", i);
    print("\n j = (~i): ", j);
    print("\n k = (1^1): ", k);
    print("\n l = (a<<2): ", l);
    print("\n m = (a>>2): ", m);
    print("\n n = (a % b - d / 3): ", n);
    print("\n p = (true || false): ", p);
    print("\n q =  !a || (b<d) && ((e>=f) || (g==h)): ",q);
    print("\nLeaving Operator Testing Function\n");
}

void call_test() {
    print("\n................Start-Test................\n");
    operators_test();
    print("\n.................End-Test..................\n");
}


f() -> {
    call_test();
};
