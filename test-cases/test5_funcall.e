/* Test Program for Function Calls */

event f(); /* Event Name can be only one character */
int num;

void fun1(int i) {
    printf("\nEntering Fun1\n");
    fun2(i);
    printf("\nLeaving Fun1\n");
}


void fun2(int i) {
    printf("\nEntering Fun2\n");
    fun3(i);
    printf("\nLeaving Fun2\n");
}


void fun3(int i) {
    printf("\nEntering Fun3\n");
    fun4(i);
    printf("\nLeaving Fun3\n");
}


void fun4(int i) {
    printf("\nEntering Fun4\n");
    fun5(i);
    printf("\nLeaving Fun4\n");
}


void fun5(int i) {
    printf("\nEntering Fun5\n");
    fun6(i);
    printf("\nLeaving Fun5\n");
}


void fun6(int i) {
    printf("\nEntering Fun6\n");
    fun7(i);
    printf("\nLeaving Fun6\n");
}


void fun7(int i) {
    printf("\nEntering Fun7\n");
    fun8(i);
    printf("\nLeaving Fun7\n");
}


void fun8(int i) {
    printf("\nEntering Fun8\n");
    fun9(i);
    printf("\nLeaving Fun8\n");
}


void fun9(int i) {
    printf("\nEntering Fun9\n");
    fun10(i);
    printf("\nLeaving Fun9\n");
}


void fun10(int i) {
    printf("\nEntering & Leaving final function\n");
}

void call_test() {
    int j=0;     
    printf("\n................Start-Test................\n");
    fun1(j);
    j=1;
    fun1(j);
    j=2;
    fun1(j);
    j=3;
    fun1(j);
    j=4;
    fun1(j);
    printf("\n................End-Test................\n");
}

f()-> {
    call_test();
}
