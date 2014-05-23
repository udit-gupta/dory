/* Test Program for Fibonacci Recursion */

event f(); /* Event Name can be only one character */
int num;
int start;

int fibonacci(int x)
{
    if (x <= 0) {
        return 0;
    } 
    if (x == 1) {
        return (1 + fibonacci(x-1));
    }
    return (fibonacci(x-2) + fibonacci(x-1));
}

void call_test(int n) {
    printf("\n................Start-Test................\n");
    num = fibonacci(n);
    printf("\n , i: %d th Fibonacci Number: ", num);
    printf("\n.................End-Test..................\n");
}


f() -> {
    start = 4;
    call_test(start);
};
