#pragma once

#include <iostream>
#include <string>

using namespace std;

class Shape {
    protected:
        int numSides;
        string color;
    public:
        // Shape(int numSides, string color) {
        //     this->numSides = numSides;
        //     this->color = color;
        // }
        Shape(int numSides = 1, string color = "White") : numSides(numSides),color(color) { // Constructor initial
            cout << "This is inside the constructor!" << endl;
        }
        ~Shape() {
            cout << "You are destroying the shape!";
        }

        // setter
        void setNumSides(int num) {
            if (num < 0)
                num = 1;
            else
                numSides = num;
        }

        void setColor(string c) {
            color = c;
        }

        //getter
        int getNumSides() { return numSides; };
        string getColor() { return color; };
};