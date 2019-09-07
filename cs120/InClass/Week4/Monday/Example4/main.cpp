#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;
double celsiusToFahrenheit(double value);
int main() {
    for (int i = 0; i < 20; i++)
    {
        cout << celsiusToFahrenheit(i) << endl;
    }
    

    return 0;
}

double celsiusToFahrenheit(double value) {
    return (9/5.0)*value+32;
}