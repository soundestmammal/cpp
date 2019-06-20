#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

bool isOdd(long x);

int main() {



    return 0;
}

long collatzFunction(long num) {
    cout << num << endl;
     if(isOdd(num)) {
         num = oddCalc(num);
         return collatzFunction(num);
     } else {
         num = evenCalc(num);
         return collatzFunction(num);
     }
}

long evenCalc(long a) {
    return a/2;
}

long oddCalc(long b) {
    return 3*b + 1;
}

bool isOdd(long x) {
    if (x%2) {
        return true;
    }
    return false;
}