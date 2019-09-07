#include <iostream>
#include <string>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {

    double num = 1234.5678;
    double var1 = 123e8;
    double var2 = 123.456e-5;

    cout << setw(10) << left << num << "Hello" << endl;
    cout << setw(20) << right << num << "Hello" << endl;

    // How to force it to show non-scientific notation?
    // To force scientific notation... cout << scientific << var1 << endl;
    // setprecision(3)

    cout << setprecision(3) << var1 << endl;
    cout << fixed << setprecision(3) << var1 << endl;
    cout << setprecision(4) << var2 << endl;

    return 0;
}
