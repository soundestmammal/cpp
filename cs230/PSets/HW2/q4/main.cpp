#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

// Function Header/Prototype Things:
void deleteValueFromArray(int oldArray[], int size1, int newArray[], int size2, int position);
void printToFile(int a[], int b[]);

using namespace std;

int main() {
    srand(time(NULL));
    int emptyArray4[9];
    int original4[10];

    // Populate an array
    for (int i = 0; i < 10; i++)
    {
        original4[i] = rand() % 101 + 1;
    }

    deleteValueFromArray(original4, 11, emptyArray4, 10, 5);

    printToFile(emptyArray4, original4);
    
    return 0;
}

void deleteValueFromArray(int oldArray[], int size1, int newArray[], int size2, int position) {
    for (int i = 0; i < size2; i++)
    {
        if(i == position-1) {

        } else if( i < position-1) {
            newArray[i] = oldArray[i];
        } else {
            newArray[i-1] = oldArray[i];
        }
    }
    
}

void printToFile(int a[], int b[]) {
    ofstream output4;
    output4.open("new.txt");

    for (int i = 0; i < 9; i++)
    {
        output4 << a[i] << endl;
    }
    
    output4.close();

    output4.open("original4.txt");

    for (int i = 0; i < 10; i++)
    {
        output4 << b[i] << endl;
    }

    output4.close();
}