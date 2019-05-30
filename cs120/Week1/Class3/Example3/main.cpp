#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    string name {};
    int age {};

    cout << "What is your name: ";
    getline(cin, name);
    cout << "What is your age:  ";
    cin >> age;

    cout << "\nYour name is: " << name << endl;
    cout << "Your age is: " << age << endl;

    return 0;
}