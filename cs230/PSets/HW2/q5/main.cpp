#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

// Function Header/Prototype Things:
int min(int x[], int size);
int max(int x[], int size);
double average(int x[], int size);
void summaryStats(int x[], int size);

using namespace std;

int main() {
    srand(time(NULL));
    int original[100];

    // Populate an array
    for (int i = 0; i < 100; i++)
    {
        original[i] = rand() % 100 + 1;
    }

    summaryStats(original, 100);
    return 0;
}

// Functions

int min(int x[], int size) {
    int min = 9999;
    for (int i = 0; i < size; i++)
    {
        if(x[i] < min) {
            min = x[i];
        }
    }
    return min;
}

int max(int x[], int size) {
    int max = -9999;
    for (int i = 0; i < size; i++)
    {
        if(x[i] > max) {
            max = x[i];
        }
    }
    return max;
}

double average(int x[], int size) {
    int total = 0;
    double average;
    for (int i = 0; i < size; i++)
    {
        total += x[i];
    }
    average = (total/double(size));
    return average;
}

void summaryStats(int x[], int size) {
    cout << "MIN:   " << min(x, size) << endl;
    cout << "MAX:   " << max(x, size) << endl;
    cout << "Average:   " << average(x, size) << endl;
}