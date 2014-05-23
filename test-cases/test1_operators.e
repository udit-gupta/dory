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
    int m = a >> 1;
    double n = (a % b - d / 3);
    bool p = (true || false);


    printf("\nEntering Operator Testing Function\n");
    printf("\n a = (1+2): %d",a);
    printf("\n b = (a-(-3)): %d", b);
    printf("\n c = (5.67*10): %f", c);
    printf("\n d = (4*b): %d", d);
    printf("\n e = (2-a): %d", e);
    printf("\n f = (6/2): %d", f);
    printf("\n g = (a/2): %d", g);
    printf("\n h = (8 mod 2): %d", h);
    printf("\n i = (0|1&0): %d", i);
    printf("\n j = (~i): %d", j);
    printf("\n k = (1^1): %d", k);
    printf("\n l = (a<<2): %d", l);
    printf("\n m = (a>>2): %d", m);
    printf("\n n = (a mod b - d / 3): %f", n);
    printf("\n p = (true || false): %d", p);
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
