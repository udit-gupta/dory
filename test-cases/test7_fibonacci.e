/* Test Program for Fibonacci Recursion */

event f(int number); /* Event Name can be only one character */
int num;

int fibonacci(int x)
{
    if (x <= 0)
        return 0;
    else if (x == 1)
        return 1 + fibonacci(x-1);
    else return fibonacci(x-2) + fibonacci(x-1);
}

void call_test(int n) {
    printf("\n................Start-Test................\n");
    num = fibonacci(n);
    printf("\\n" , i , "th Fibonacci Number: ", num);
    printf("\n.................End-Test..................\n");
}


f(i) -> {
    call_test(i);
};
