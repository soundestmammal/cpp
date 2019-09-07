#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void deleteInfo(int x[], int SIZE, int deletedInfo, int position);

int main() {

    srand(time(NULL));

    const int SIZE = 100;
    int nums[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        nums[i] = rand() & 10000;
    }

    return 0;
}

void searchIt(int x[], int SIZE, int searchNum) {
    bool gotIt = false;
    for (int i = 0; i < SIZE; i++)
    {
        if (searchNum == x[i]) {
            gotIt = true;
            cout << "Got it" << endl;
        }
    }
    if(!gotIt) {
        cout << "It is not there" << endl;
    }
    
}

int& deleteInfo(int x[], int SIZE, int position) {
    int *newArray;    
    newArray = new int[SIZE - 1];

    for (int i = 0; i < position; i++) {
        newArray[i] = x[i];
    }

    for (int i = (position); i < (SIZE - 1); i++)
    {
        newArray[i] = x[i + 1];
    }
    
    return *newArray;
}