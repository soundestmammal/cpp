#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

void superRandomNumber(int top);

int main() {
    superRandomNumber(10);
    return 0;
}

void superRandomNumber(int top) {
    ofstream output;
    output.open("theFile.txt");
    for (int i = 0; i < 100; i++) {
        output << rand() % top << endl;        
    }
    output.close();
}