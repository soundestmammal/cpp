#include <iostream>

const double pi {3.14159};

void area_circle();
double calc_area_circle(double radius);
double calc_volume_cylinder(double radius, double height);
void volume_cylinder();


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
    std::cout << "\nEnter the radius of the circle ";
    std::cin >> radius;
    std::cout << "\nThe area of the circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}
double calc_volume_cylinder(double radius, double height) {
    return calc_area_circle(radius) * height;
}
void volume_cylinder() {
    double radius {};
    double height {};
    std::cout << "\nEnter the radius of the cylinder: ";
    std::cin >> radius;
    std::cout << "\nEnter the height of the cylinder: ";
    std::cin >> height;
    std::cout << "\nThe volume of cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height) << endl;
}