#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

class Circle {
private:
    double radius;
public:
    Circle() {
        cout << "I am constructing the object right now \n";
        radius = 1;
    }
    Circle(double r) {
        cout << "I am constructing the object right now! \n";
        if(r < 0) {
            radius = -r;
        } else {
            radius = r;
        }
    }

    void setRadius(double r) { radius = r; } // setter - mutator
    double getRadius() { return radius; } //getter - accessor

    double getArea() { return radius * radius*3.14; }
    double getDiameter() { return 3.14 * 2 * radius; }
};

int main