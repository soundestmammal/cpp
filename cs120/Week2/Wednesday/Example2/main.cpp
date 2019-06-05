#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

const double TAX = 0.975;

int main() {

    int groupSize {};
    string ageType {};
    double basePrice, total;
    double extraServiceCharge {1.1};
    double ageTypePrice {};

    cout << "How many people are in your group? \n";
    cin >> groupSize;
    if (groupSize < 1 || groupSize > 50) {
        cout << "How many people are in your group? \n";
        cin >> groupSize;
    }
    
    cout << "Are you a child, adult or senior?\n";
    cin >> ageType;
    if (ageType != "child" || ageType != "adult" || ageType != "senior") {
        cout << "Are you a child, adult or senior?\n";
        cin >> ageType;
    }

    if (groupSize < 10) {
        if (ageType == "child") {
            ageTypePrice = 10;
        } 
        else if (ageType == "adult") {
            ageTypePrice = 20;
        }
        else if (ageType == "senior") {
            ageTypePrice = 15;
        }
        basePrice = groupSize * ageTypePrice;
    } else if (groupSize >= 10) {
        if (ageType == "child") {
            ageTypePrice = 10;
        } 
        else if (ageType == "adult") {
            ageTypePrice = 20;
        }
        else if (ageType == "senior") {
            ageTypePrice = 15;
        }
        basePrice = groupSize * ageTypePrice * extraServiceCharge;
    }
    total = basePrice * (1+TAX);
    cout << "Your total cost is " << total << endl;

    
    return 0;
}