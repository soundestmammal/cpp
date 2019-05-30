#include <iostream>
#include <string>
#include <math.h>
#include <ctime>

using namespace std;

int main() {
    
    // Numbers between 1 and 6
    srand(time(NULL));
    cout << (rand() % 6) + 1 << endl; // numbers between 1 and 6
    cout << (rand() % 100) + 1 << endl; // numbers between 1 and 100
    cout << (rand() % 51) + 50 << endl; //  numbers between 50 and 100

    return 0;
}