#include <iostream>
#include <cmath>

using namespace std;

// Function Prototype
void checkSquares(int bottom, int top);

int main() {

    int a = 5;
    int b = 20;

    checkSquares(a, b); // 9, 16
    return 0;
}

void checkSquares(int bottom, int top) {
    int counter = bottom;
    double calc;
    while(counter < top) {
        calc = sqrt(counter);
        if(roundf(calc) == calc) {
            cout << counter << endl;
        }
        counter++;
    }
}