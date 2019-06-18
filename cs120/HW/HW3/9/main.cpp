#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {

    ofstream output9;
    output9.open("theFile.txt");
    for (int i = 0; i <= 10; i++)
    {
        output9 << i * i << endl;
    }
    
    output9.close();

    return 0;
}