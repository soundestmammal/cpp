#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <ctime>
#include <time.h>

using namespace std;

class Rectangle {
    private:
        double length, width;

    public:
        Rectangle(double l, double w) {
            length = l;
            width = w;
        }
        Rectangle() {
            length = width = 1;
        }

        void setLength(double l) { length = l; }
        void setWidth(double w) { width = w; }

        double getLength() { return length; }
        double getWidth() { return width; }

        double getArea() { return length*width; }
        double getPerimeter() { return 2*length + 2*width; }
};

int main() {

    Rectangle r1(7, 10);
    Rectangle r2;
    Rectangle r3(1.4, 2.7);

    r1.setLength(25);
    r1.setWidth(3.6);

    r2.setLength(600);
    cout << r2.getLength() << endl;
    cout << r3.getArea() << endl;
    cout << &r3 << endl;

    return 0;
}