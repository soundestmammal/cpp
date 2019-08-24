#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

// Function Header/Prototype Things:
void doubleFillArray(double x[], int size);
void outputArrayToFile(double x[], int size);
void readTheArray(double x[]);

using namespace std;

int main() {
    srand(time(NULL));
    const int SIZE1 = 100;
    double x[SIZE1];
    double theNewArray[SIZE1];

    doubleFillArray(x, SIZE1);
    outputArrayToFile(x, SIZE1);
    readTheArray(theNewArray);

    for (int i = 0; i < SIZE1; i++)
    {
        cout << fixed << setprecision(3) << theNewArray[i] << endl;
    }
    
    return 0;
}

// Functions
void doubleFillArray(double x[], int size) {
    for (int i = 0; i < size; i++)
    {
        x[i] = rand() % 1001 / 1000.0;
    }
}

void outputArrayToFile(double x[], int size) {
    ofstream output;
    output.open("THEFILE.txt");
    for (int i = 0; i < size; i++)
    {
        output << fixed << setprecision(3) << x[i] << endl;
    }
    output.close();
}

void readTheArray(double x[]) {
    double a;
    int counter = 0;
    ifstream input;
    input.open("THEFILE.txt");
    while(input >> a) {
        x[counter] = a;
        counter++;
    }
}