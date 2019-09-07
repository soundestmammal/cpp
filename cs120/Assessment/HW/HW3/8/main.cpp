#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {

    // 8. Output a list of numbers from 100 to 1 (using a for loop) to a file

    ofstream output8;
    output8.open("eight.txt");

    for (int i = 100; i > 0; i--)
    {
        output8 << i << " " << endl;
    }
    
    output8.close();

    return 0;
}