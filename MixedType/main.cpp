#include <iostream>

using namespace std;

int main()
{
    int total {};
    int num1 {}, num2 {}, num3 {};
    const int count {3};
    cout << "Enter three integers separated by spaces ";
    cin >> num1 >> num2 >> num3;
    total = num1 + num2 + num3;
    int average {};
    average = total/count;
    cout << "The three numbers were " << num1 << ',' << num2 << ',' << num3 << endl;
    cout << "The sum of the three numbers is " << total << endl;
    cout << "The average of the three numbers is " << average << endl;
    return 0;
}
/*
type coercion: The compiler

express where operands of different types
C++ will try and change one of the operands
Higher and lower types. Ex. an Int can fit in a float. But a float can not fit in an int.
Promotion lower to higher. Integer to a floating point.
Demotion store 12.5 into an integer => 12
*/
