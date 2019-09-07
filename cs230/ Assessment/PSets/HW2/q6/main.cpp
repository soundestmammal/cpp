#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Function Header/Prototype Things:
void sumOfEntries(int x[][3], int rows, int columns);



int main() {
    srand(time(NULL));
    const int rows = 3, columns = 3;
    int emptyArray[rows][columns];

    // This is dope!
    int** ptr = new int*[3];
    for (int i = 0; i < 3; i++)
    {
       *(ptr+i) = new int[3];
    }
    
    // Populate an array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
        {
            emptyArray[i][j] = rand() % 10 + 1;
        }
    }

    sumOfEntries(emptyArray, rows, columns);
    return 0;
}

void sumOfEntries(int x[][3], int rows, int columns) {
    int total = 0;
    ofstream output;
    output.open("sumQ6.txt");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {   
            total += x[i][j];
        }
    }
    output << total << endl;
    output.close();
}

void twoDimensionalExample(int** x, int row, int column) {

}