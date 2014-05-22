/* Test Program for Function Calls */

event f(); /* Event Name can be only one character */
int num;

void fun1(int i) {
    print("\nEntering Fun1\n");
    fun2(i);
    print("\nLeaving Fun1\n");
}


void fun2(int i) {
    print("\nEntering Fun2\n");
    fun3(i);
    print("\nLeaving Fun2\n");
}


void fun3(int i) {
    print("\nEntering Fun3\n");
    fun4(i);
    print("\nLeaving Fun3\n");
}


void fun4(int i) {
    print("\nEntering Fun4\n");
    fun5(i);
    print("\nLeaving Fun4\n");
}


void fun5(int i) {
    print("\nEntering Fun5\n");
    fun6(i);
    print("\nLeaving Fun5\n");
}


void fun6(int i) {
    print("\nEntering Fun6\n");
    fun7(i);
    print("\nLeaving Fun6\n");
}


void fun7(int i) {
    print("\nEntering Fun7\n");
    fun8(i);
    print("\nLeaving Fun7\n");
}


void fun8(int i) {
    print("\nEntering Fun8\n");
    fun9(i);
    print("\nLeaving Fun8\n");
}


void fun9(int i) {
    print("\nEntering Fun9\n");
    fun10(i);
    print("\nLeaving Fun9\n");
}


void fun10(int i) {
    print("\nEntering & Leaving final function\n");
}

void call_test() {
    int j=0;     
    print("\n................Start-Test................\n");
    fun1(j);
    j=1;
    fun1(j);
    j=2;
    fun1(j);
    j=3;
    fun1(j);
    j=4;
    fun1(j);
    print("\n................End-Test................\n");
}

f()-> {
    call_test();
}
