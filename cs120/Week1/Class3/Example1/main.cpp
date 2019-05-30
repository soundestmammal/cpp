#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int x {-1};
    double y {-1};
    float z {-1};
    string s {"-1"};
    long long a {1};
    long double b {1};
    char letter {'c'};
    bool test = true;

    cout << "The size of an int: " << sizeof(x) << endl;
    cout << "The size of a double: " << sizeof(y) << endl;
    cout << "The size of a float: " << sizeof(z) << endl;
    cout << "The size of a string: " << sizeof(s) << endl;
    cout << "The size of a long long: " << sizeof(a) << endl;
    cout << "The size of a long double: " << sizeof(b) << endl;
    cout << "The size of a letter: " << sizeof(letter) << endl;
    cout << "The size of a bool: " << sizeof(test) << endl; 

    return 0;
}