#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

long collatzFunction(long num);
void collatzTest(long startNum);

int main() {
    collatzTest(31);
    return 0;
}

void collatzTest(long startNum) {
    while (startNum != 1) {
        cout << startNum << endl;
        startNum = collatzFunction(startNum);
    }
}

long collatzFunction(long num){
    if (num %2 == 0) {
        return num/2;
    } else {
        return 3 * num + 1;
    }
}