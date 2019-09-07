#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {

    double price {199};
    int quantity {};
    cout << "What quantity do you want to buy? ";
    cin >> quantity;

    if (quantity < 0) {
        cout << "That is not a valid quantity" << endl;
    }
    else if (quantity >= 100) {
        cout << "The total before discount is " << (quantity * price) << endl;
        cout << "The cost of this is: " << quantity * price * (1.0 - 0.5) << " dollars" << endl;
        cout << "This discount was 50%" << endl;
    }
    else if (quantity >= 50) {
        cout << "The total before discount is " << (quantity * price) << endl;
        cout << "The cost of this is: " << quantity * price * (1.0-0.4) << " dollars" << endl;
        cout << "This discount was 40%" << endl;
    }
    else if (quantity >=20) {
        cout << "The total before discount is " << (quantity * price) << endl;
        cout << "The cost of this is: " << quantity * price * (1.0-0.3) << " dollars" << endl;
        cout << "This discount was 30%" << endl;
    }
    else if (quantity >= 10) {
        cout << "The total before discount is " << (quantity * price) << endl;
        cout << "The cost of this is: " << quantity * price * (1.0-0.2) << " dollars" << endl;
        cout << "This discount was 20%" << endl;
    }
    else {
        cout << "The total before discount is " << (quantity * price) << endl;
        cout << "The cost of this is: " << (quantity * price) << " dollars" << endl;
        cout << "There is no discount" << endl;
    }

    return 0;
}