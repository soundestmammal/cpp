#pragma once
#include <iostream>
#include <string>
using namespace std;

class Bottle {
    private:
        double numOunces;
        string bottleColor;

    public:
        Bottle() {
            numOunces = 1;
            bottleColor = "green";
        }
        Bottle(double nO, string bC) : numOunces(nO), bottleColor(bC) { ; }

        void setNumOunces(double numOunces) {this->numOunces = numOunces; }
        void setBottleColor(string bottleColor) {this->bottleColor = bottleColor; }
        double getNumOunces() { return numOunces; }
        string getBottleColor() { return bottleColor; }
        void toString();
};