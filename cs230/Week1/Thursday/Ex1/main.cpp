#include <iostream>
#include <cmath>

using namespace std;

void outputArray(int x[], int SIZE);
void setArrayValues(int x[], int SIZE);


int main () {
    const int SIZE = 5;
    int nums[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        nums[i] = i * i;
    }
    
    setArrayValues(nums, SIZE);
    outputArray(nums, SIZE);

    return 0;
}

void outputArray(int x[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << x[i] << endl;
    }
}

void setArrayValues(int x[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        x[i] = pow(i, 3);
    }
}