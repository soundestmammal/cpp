#include <iostream>
using namespace std;

void fun1();

int main() {
    for (int i = 0; i < 100; i++)
    {
        fun1();
        /*
        On the last iteration:
        counter1 is 100
        and 
        counter2 is 0
        because counter1 is defined outside of the funcion scope
        */
    }
    return 0;
}

void fun1() {
    static int counter1 = 0;
    int counter2 = 0;
    counter1++;
    counter2++;
    cout << counter1 << endl;
    cout << counter2 << endl;
}