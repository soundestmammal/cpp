#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
    const int SIZE = 10;
    srand(time(NULL));
    int randNums[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        randNums[i] = rand() % 100 + 1;
    }

    double avg = 0, total = 0;
    for (int i = 0; i < SIZE; i++)
    {
        total += randNums[i];
    }
    avg = total/SIZE;
    cout << avg << endl;

    double stdev = 0;
    total = 0;

    for (int i = 0; i < SIZE; i++)
    {
        total += pow(randNums[i] - avg, 2);
    }
    
    stdev = sqrt(total/SIZE);
    return 0;
}