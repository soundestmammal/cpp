#include <iostream>

using namespace std;
const double pi {3.14159};

double calc_area_circle(double radius) {
    return pi * radius * radius;
}
void area_circle() {
    double radius {};
    cout << "\nEnter the radius of the circle ";
    cin >> radius;
    cout << "\nThe area of the circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}
int main()
{
    area_circle();
    //volume_cylinder();
    return 0;
}