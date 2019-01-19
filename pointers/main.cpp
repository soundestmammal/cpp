#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int num {10};
    cout << num << endl;
    cout << sizeof num << endl;
    cout << &num << endl;

    int *p;
    cout << p << endl; //garbage data
    cout << &p << endl; //hex address
    cout << sizeof p << endl; //4

    p = nullptr;
    cout << p << endl;
    return 0;
}