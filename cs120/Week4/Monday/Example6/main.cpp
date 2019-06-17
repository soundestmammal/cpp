// in number double return a,b,c,d

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;
string gradeCalculator(double num);

int main() {
    double grade;
    cout << "Give me the number grade:  ";
    cin >> grade;
    cout << "Your number grade is a letter grade of:     " << gradeCalculator(grade) << endl;
    return 0;
}

string gradeCalculator(double num) {
    if (num < 0 || num > 100) {
       return "This was an invalid grade. Try again later";
        
    } else if (num >= 93) {
        return "A";
    } else if (num >= 80) {
        return "B";
    } else if (num >= 70) {
        return "C";
    } else {
        return "F";
    }
}