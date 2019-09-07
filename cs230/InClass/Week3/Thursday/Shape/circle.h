#pragma once
#include <iostream>
#include <string>

using namespace std;

class Circle : Shape {
    private:
        double radius;
    public:
        Circle(double radius, string color): Shape(1, color), radius(radius) {
            this->radius = radius;
            this->numSides = numSides;
            this->color = color;
            cout << "A circle was just created" << endl;
        }
        ~Circle() {
            cout << "A circle was just destroyed.\n" << endl;
        }
        
};

/*
Woah, I need to review this, some funky syntax!!! But totally valid I suppose...
 */