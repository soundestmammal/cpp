#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Initialization
    int num1 {10};
    int num2 {20};

    cout << "The number 1 is " << num1 << endl;
    cout << "The number 2 is " << num2 << endl;

    // Assignment
    // Can not assign
    // 1. Of different type
    // 2. Constants
    // 3. Literals
    num1 = 100;
    num2 = 200;

    cout << "The number 1 is " << num1 << endl;
    cout << "The number 2 is " << num2 << endl;

    int result = {};
    
    result = num1+num2;
    cout << num1 << '+' << num2 << '=' << result << endl;
    result = num2-num1;
    cout << num2 << '-' << num1 << '=' << result << endl;
    result = num1*num2;
    cout << num1 << '*' << num2 << '=' << result << endl;
    result = num2/num1;
    cout << num2 << '/' << num1 << '=' << result << endl;
    result = num2 % num1;
    cout << num2 << '%' << num1 << '=' << result << endl;

    return 0;
}

/* 
Assignment Operator in C++
lhs = rhs
This means take value of rhs and assign it to the lhs
lhs must be assignment (can not be literal or a constant)

*/