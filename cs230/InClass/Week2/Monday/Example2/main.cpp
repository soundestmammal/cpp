#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

// Function Header/Prototype Things:
int getAndReplaceMin(int x[], int SIZE);
int* selectionSort(int x[], int SIZE);

using namespace std;

int main() {
    srand(time(NULL));

    const int SIZE = 6;
    double myNums[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        *(myNums + i) = (rand() % 1000 / 1000.0);
    }

    cout << myNums << endl;

    cout << *myNums << endl;

    cout << myNums + 1 << endl;

    cout << *(myNums + 6) << endl;
    
    return 0;
}
