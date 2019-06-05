#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL));

    int num = rand() % 1000 + 1;
    cout << "The number is: " << num << endl;

    if (num % 2 == 0) cout << "it is even\n";
    else cout << "It is odd.\n";

    if (num > 333) {
        cout << "The number is greater than 333" << endl;
    } else {
        cout << "The number is less than 333" << endl;
    }

    return 0;
}

// rand between 1 and 1000 and tell if it is greater than 333