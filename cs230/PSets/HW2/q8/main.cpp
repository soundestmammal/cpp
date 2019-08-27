#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Function Header/Prototype Things:
void searchArray(int a[], int size);

int main() {
    srand(time(NULL));

    const int SIZE8 = 100;
    int list8[SIZE8];

    for (int i = 0; i < SIZE8; i++)
    {
        list8[i] = rand() % 1000 + 1;
    }
    
    for (int i = 0; i < SIZE8; i++)
    {
        cout << list8[i] << endl;
    }
    
    searchArray(list8, SIZE8);

    return 0;
}

void searchArray(int a[], int size) {
    int response;
    cout << "Give me a number to search for...  ";
    cin >> response;

    int counter = 0;
    while(counter < size) {
        if (a[counter] == response) {
            cout << "The number is in the list!" << endl;
            cout << "It took " << counter << " iterations to find the number" << endl;
            exit(0);
        } 
        counter++;
    }
    cout << "Sorry the number is not in the list..." << endl;
}
