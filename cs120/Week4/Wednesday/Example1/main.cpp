#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

void calculateRetail(double wholesale, double markUp);

int main() {
    double cost = 39.75, markUp = 10;
    calculateRetail(cost, markUp);

    return 0;
}

void calculateRetail(double wholesale, double markUp) {
    if (markUp > 1) { markUp /= 100; }
    cout << "Cost: " << fixed << setprecision(2) << wholesale*(1 + markUp) << endl;
}