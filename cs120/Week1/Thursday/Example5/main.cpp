#include <iostream>
#include <string>
#include <math.h>
#include <ctime>

using namespace std;

const double TAX = .065;

int main() {
    // Cash Register
    double subtotal {};
    cout << "What is the subtotal of the transaction:   ";
    cin >> subtotal;
    double total {};
    total = subtotal * (1 + TAX);
    cout << "The total with tax included is:    " << total << endl;

    return 0;
}