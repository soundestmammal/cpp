#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

double fallingDistance(int time);

int main() {
    double distance;
    for (int i = 1; i < 10; i++)
    {
        distance = fallingDistance(i);
        cout << "After " << i << " seconds, the item has fallen " << distance << " meters." << endl;
    }
    


    return 0;
}

double fallingDistance(int time) {
    double distance;
    distance = 0.5*9.8*(time*time);
    return distance;
}

double fact(int n) {
    if (n==1) return 1;
    else return  n*fact(n-1);
}