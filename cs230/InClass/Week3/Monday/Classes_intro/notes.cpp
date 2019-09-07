#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include "Triangle.h"

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

class Triangle {
    private:
        double base, height;
        static int counter;
    public:
        Triangle(): base(1), height(1) { // default constructor, w/ constructor initializer notation
            cout << "I am constructing the object right now!\n";
        }
        Triangle(double height, double base) {
            this->height = height;
            this->base = base;
        }

        void setBase(double b);
        void setHeight(double h);

        void setBase(double b) { this->base = base; }
};

class TriangleSkeleton {
    private:
        double base, height;
    public:
        TriangleSkeleton(double height, double base);

        void setBase(double b);
        void setHeight(double h);
        double getBase();
        double getHeight();
};

TriangleSkeleton::TriangleSkeleton(double height, double base) {
    this->height = height;
    this->base - base;
}

void TriangleSkeleton::setBase(double b) { base = b; };
void TriangleSkeleton::setHeight(double h) { height = h; };
double TriangleSkeleton::getBase() { return base; };
double TriangleSkeleton::getHeight() { return height; };


int main() {

    Circle c(5);
    cout << c.getArea() << endl;
    cout << c.getDiameter() << endl; 

    Circle bircle;

    cout << bircle.getRadius() << endl;

    return 0;
}