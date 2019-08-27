#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Function Header/Prototype Things:
void sort(int x[], int size);

int main() {
    srand(time(NULL));
    const int SIZE7 = 10;
    int emptyArray7[SIZE7];

    // Populate an array
    for (int i = 0; i < SIZE7; i++) {
        emptyArray7[i] = rand() % 100 + 1;
    }

    ofstream output7;
    output7.open("unsorted7.txt");
    for (int i = 0; i < SIZE7; i++)
    {
        output7 << emptyArray7[i] << endl;;
    }

    sort(emptyArray7, SIZE7);

    output7.close();

    output7.open("sorted7.txt");

    for (int i = 0; i < SIZE7; i++)
    {
        output7 << emptyArray7[i] << endl;;
    }
    
    output7.close();
    return 0;
}

void sort(int x[], int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i; j++)
        {
            if(x[j] < x[j+1]) {
                int temp;
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
        
    }
}

