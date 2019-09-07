#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

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

void addInfo(int x[], int SIZE, int newInfo, int position) {
    int *newArray;    
    newArray = new int[SIZE + 1];

    for (int i = 0; i < position; i++) {
        newArray[i] = x[i];
    }

    newArray[position] = newInfo;
    for (int i = (position+1); i < (SIZE+1); i++)
    {
        newArray[i] = x[i -1];
    }
    
}