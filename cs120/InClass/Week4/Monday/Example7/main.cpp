#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

double setItemPrice();
double totalCost(double itemPrice);

const double TAX = .075;

int main() {

    double item = setItemPrice();
    double theCost = totalCost(item);
    cout << "the total cost is " << theCost << endl;

    return 0;
}

double setItemPrice() {
    double itemPrice = 0;
    while (itemPrice <= 0) {
        cout << "What is the item price\n";
        cin >> itemPrice;
    }
    return itemPrice;
}

double totalCost(double itemPrice) {
    return (1+TAX)*itemPrice;
}