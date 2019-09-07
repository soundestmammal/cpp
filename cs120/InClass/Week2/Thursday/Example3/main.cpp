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
    int num = (rand() % 1000 + 1);
    cout << "The number is:     " << num << endl;
    num %= 2;
    switch(num) {
        case 0:
            cout << "You picked an even number." << endl;
            break;
        case 1:
            cout << "You picked an odd number." << endl;
            break;
    }

    return 0;
}