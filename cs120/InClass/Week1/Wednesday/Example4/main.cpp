#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    double miles {};
    double gallons {};
    double mpg {};

    cout << "How many miles did you go? " << endl;
    cin >> miles;
    cout << "How many gallons did you use? " << endl;
    cin >> gallons;

    mpg = miles/gallons;

    cout << "Your miles per gallon (mpg) is " << mpg << endl;

    // Can also be done by:

    // int miles, gallons;
    // double mpg;
    // mpg = (double)miles / gallons;
    // //or
    // mpg = double(miles) / gallons;

    return 0;
}