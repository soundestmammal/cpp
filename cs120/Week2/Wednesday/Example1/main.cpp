#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    double grade {};
    cout << "What is your grade?\n";
    cin >> grade;

    if (grade <= 60) { cout << "F" << endl; }
    else if (grade <= 70) { cout << "D" << endl; }
    else if (grade <= 80) { cout << "C" << endl; }
    else if (grade <= 90) { cout << "B" << endl; }
    else { cout << "A" << endl; }
    
    return 0;
}