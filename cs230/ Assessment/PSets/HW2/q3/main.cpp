#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

// Function Header/Prototype Things:
void copyAndInsertArray(int a[], int size1, int b[], int size2, int position, int payload);

using namespace std;

int main() {
    srand(time(NULL));
    const int SIZE3 = 10;
    int emptyArray[11];
    int original[SIZE3];

    for (int i = 0; i < SIZE3; i++)
    {
        original[i] = rand() % 101 + 1;
    }

    copyAndInsertArray(emptyArray, 11, original, SIZE3, 5, 69);
    
    ofstream output;
    output.open("new.txt");

    for (int i = 0; i < 11; i++)
    {
        output << emptyArray[i] << endl;
    }
    
    output.close();

    output.open("original.txt");

    for (int i = 0; i < 10; i++)
    {
        output << original[i] << endl;
    }

    output.close();
    return 0;
}

// The first array and size is empty.
// The second array and size is the array to be copied.
void copyAndInsertArray(int a[], int size1, int b[], int size2, int position, int payload) {
    for (int i = 0; i < size1; i++)
    {
        if(i == position) {
            a[position] = payload;
        } else if (i < position){
            a[i] = b[i];
        } else {
            a[i] = b[i-1];
        }
    }
}

