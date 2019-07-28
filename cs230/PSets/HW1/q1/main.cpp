#include <iostream>
#include <cmath>

using namespace std;

// Function Prototypes
void quadraticFormula(int a, int b, int c);

int main() {

    quadraticFormula(10, 6, 7);

    return 0;
}

void quadraticFormula(int a, int b, int c) {
    int discriminant = (b*b) - (4*a*c);
    double x1, x2;
    if (discriminant < 0) {
        cerr << "There was a problem here!" << endl;
        exit(1);
    }

    x1 = (-b + (sqrt(discriminant)))/(2.0*a);
    x2 = (-b - (sqrt(discriminant)))/(2.0*a);

    cout << "X1:    " << x1 << endl;
    cout << "X2:    " << x2 << endl;

}