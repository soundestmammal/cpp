#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

double average(int x[], int SIZE);

int main() {
    const int SIZE = 10;
    srand(time(NULL));
    int randNums[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        randNums[i] = rand() % 100 + 1;
    }

    double theAverage = average(randNums, SIZE);
    cout << "The Average is: " << theAverage << endl;
    return 0;
}

double average(int x[], int SIZE) {
    double total = 0;
    for (int i = 0; i < SIZE; i++)
    {
        total += x[i];
    }
    return total / SIZE;
}