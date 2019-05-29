#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int age {};
    cout << "How old are you? ";
    cin >> age;
    age = age * 365 * 24 * 60 * 60;
    cout << "Your age is " << age << "." << endl;
    return 0;
}