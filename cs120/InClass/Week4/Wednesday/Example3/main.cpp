#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

double calculateCharge(double weight, double distance);

using namespace std;

int main() {
    
    double weight = 1.0, distance = 0, total = 0;
    int packageNum = 0;
    vector<double> priceQueue;
    while (weight != 0) {
        cout << "Provide me with the weight of the package:     ";
        cin >> weight;
        cout << "Provide me with the distance:  ";
        cin >> distance;
        total = calculateCharge(weight, distance);
        priceQueue.push_back(total); 
    }
    for (int i = 0; i < priceQueue.size(); i++) {
        total += priceQueue[i];
        cout << total << endl;
    }

    cout << total << endl;
    

    return 0;
}

double calculateCharge(double weight, double distance) {
    if(weight > 10) {
        return 6.40*(distance/500);
    } else if (weight > 6) {
        return 5.30*(distance/500);
    } else if (weight > 2) {
        return 4.20*(distance/500);
    } else if (weight > 0) {
        return 3.10*(distance/500);
    } else {
        return 0;
    }
}