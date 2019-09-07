#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

int* createArrayInFunction();

int main () {
    
    int a = 5;
    int* ptr = &a;
    int** holdPtr = &ptr;

    int* arrayPtr = new int[5];

    cout << a << endl;
    cout << &a << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << holdPtr << endl;
    cout << *holdPtr << endl;
    cout << **holdPtr << endl;
    cout << &ptr << endl;

    int* holderArray = createArrayInFunction();

    for (int i = 0; i < 10; i++) {
        cout << *(holderArray + i) << endl;
    }

    delete[]holderArray;
    
    return 0;
}

int* createArrayInFunction() {
    int* inFunc = new int[10];
    for (int i = 0; i < 10; i++)
    {
        *(inFunc + i) = pow(2, i);
    }
    return inFunc;
}

