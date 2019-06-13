#include <iostream>

using namespace std;
//function prototype is only:
// The name of the function
// And what it accepts as parameters
// And what it returns
// I could get rid of the variable names if I wanted to.
double calc_volume_cylinder(double radius, double height);
double calc_area_circle(double radius);
void area_circle();
void volume_cylinder();
const double pi {3.14159};

int main()
{
    area_circle();
    volume_cylinder();
    return 0;
}
double calc_area_circle(double radius) {
    return pi * radius * radius;
}
void area_circle() {
    double radius {};
    cout << "\nEnter the radius of the circle ";
    cin >> radius;
    cout << "\nThe area of the circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}
double calc_volume_cylinder(double radius, double height) {
    //return pi * radius * radius * height;
    return calc_area_circle(radius) * height;
}
void volume_cylinder() {
    double radius {};
    double height {};
    cout << "\nEnter the radius of the cylinder: ";
    cin >> radius;
    cout << "\nEnter the height of the cylinder: ";
    cin >> height;
    cout << "\nThe volume of cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height) << endl;
}