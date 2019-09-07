#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    double a, b, c;
    cout << "Give me the length first side of the triangle: " << endl;
    cin >> a;
    cout << "Give me the length of the second side of the triangle: " << endl;
    cin >> b;

    c = sqrt(pow(a, 2) + pow(b, 2));
    cout << "The third size of the triangle is: " << c << endl;
    return 0;
}