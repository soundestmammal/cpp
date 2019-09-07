#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

void Alpha(int stopNum);

int main() {

    Alpha(10);


    return 0;
}

void Alpha(int stopNum) {
    int startNum = 1;
    while (startNum <= stopNum) {
        cout << startNum++ << endl;
    }
}