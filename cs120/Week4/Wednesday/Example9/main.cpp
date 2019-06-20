#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

double doubleIt(double n);

int main() {
    int num = 1;
    for (int i = 1; i <= 10; i++)
    {
        cout << num << endl;
        num = doubleIt(num);
    }
    

    return 0;
}

double doubleIt(double n) {
    return 2*n;
}