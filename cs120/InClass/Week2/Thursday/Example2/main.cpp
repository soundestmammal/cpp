#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {

    char option {};
    string output;

    cout << "Please choose either a, b, or c. \n";
    cin >> option;

    switch(option) {
        case 'a':
        case 'A':
            output = "You won $1\n";
            break;
        case 'b':
        case 'B':
            output = "You won $2\n";
            break;
        case 'c':
        case 'C':
            output = "You won nothing\n";
            break;
        default:
            output = "Illegal input\n";
            break;      
    }

    ofstream toFile;
    toFile.open("switch.txt");
    toFile << output;
    toFile.close();
    
   return 0;
}