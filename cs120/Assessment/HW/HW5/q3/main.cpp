#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {

    int total {0};
    for (int i = 1; i <= 10; i++) {
        total += i;
    }
    cout << "The total is:  " << total << endl;
    
    return 0;
}

