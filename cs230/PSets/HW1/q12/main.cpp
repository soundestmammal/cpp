#include <iostream>
using namespace std;

const double TAX = 0.0875;

double thePrice(int units, double basePrice);

int main() {

    int u1 = 10;
    double bp1 = 99.99;
    cout << thePrice(u1, bp1) << endl;
    int u2 = 30;
    double bp2 = 99.99;
    cout << thePrice(u2, bp2) << endl;

    return 0;
}

double thePrice(int units, double basePrice) {
    double subtotal;
    if(units > 20) {
        subtotal = ((units*basePrice) * 0.95);
    } else {
        subtotal = (units*basePrice);
    }

    return (subtotal * (1+TAX));
}