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
    const int SIZE = 10;
    int emptyArray[SIZE];

    // Populate an array
    for (int i = 0; i < SIZE; i++) {
        emptyArray[i] = rand() % 100 + 1;
    }

    ofstream output;
    output.open("unsorted.txt");
    for (int i = 0; i < SIZE; i++)
    {
        output << emptyArray[i] << endl;;
    }

    int* sortedList  = selectionSort(emptyArray, SIZE);

    output.close();
    output.open("sorted.txt");

    for (int i = 0; i < SIZE; i++)
    {
        output << emptyArray[i] << endl;;
    }
    
    output.close();
    return 0;
}

int* selectionSort(int x[], int SIZE) {
    int *newList = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        newList[i] = getAndReplaceMin(x, SIZE);
    }

    return newList;
}

int getAndReplaceMin(int x[], int SIZE) {
    int min = x[0];
    int position = 0;
    for (int i = 1; i < SIZE; i++) {
        if(x[i] < min) {
            min = x[i];
            position = i;
        }
    }
    x[position] = 100;
    return min;
}