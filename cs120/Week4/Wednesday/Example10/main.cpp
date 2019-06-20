#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

void itsDouble(double &n);

int main() {

    double n = 4;
    itsDouble(n);
    return 0;
}

void itsDouble(double &n) {
    n *=2;
}