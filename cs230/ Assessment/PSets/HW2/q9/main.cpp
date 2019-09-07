#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

// Function Header/Prototype Things:

using namespace std;

int main() {
    srand(time(NULL));

    const int SIZE9 = 10;
    int emptyArray9[SIZE9];

    // Populate an array
    for (int &i : emptyArray9) {
        i = rand() % 100 + 1;
    }

    // Output array elements
    for(int k : emptyArray9) {
        cout << k << endl;
    }

    return 0;
}


// const int SIZE9 = 10;
// int emptyArray9[SIZE9];

// for(int i : emptyArray9) {
//     i = rand() % 100 + 1;
// }