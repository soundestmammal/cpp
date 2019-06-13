#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    // Average of a few numbers
    double num1, num2, num3;
    cout << "What is the first number ";
    cin >> num1;
    cout << "What is the second number? ";
    cin >> num2;
    
    num3 = (num1 + num2) / 2;
    cout << "The average is " << num3 << endl;

    return 0;
}