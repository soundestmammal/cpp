#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

double totalCost(double weight, double miles);

using namespace std;

int main() {
    
    double w = -1, m = -1;
    while (w != 0) {
        cout << "What is the weight and distance? \n";
        cin >> w >> m;
        cout << totalCost(w,m);
    }
    return 0;
}



double totalCost(double weight, double miles) {
    double total = 0, milesCharge = int(miles / 500) + 1;

    if (weight > 10) {
        total = 6.40*milesCharge;
    } else if (weight > 6) {
        total = 5.30*milesCharge;
    } else if (weight > 2) {
        total = 4.20*milesCharge;
    } else if(weight > 0) {
        total = 3.10*milesCharge;
    } else {
        return 0;
    }

    // to be continued... 
}