#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

int Bravo();

int main() {

    cout << Bravo() << endl;

    return 0;
}

int Bravo() {
    int total = 0;
    for (int i = 0; i < 11; i++)
    {
        total += i;
    }
    return total;
    
}