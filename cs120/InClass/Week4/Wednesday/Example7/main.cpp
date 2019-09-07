#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

void getAgeByReference(int& age);

int main() {
    int age = -1;
    cout << age << endl;
    getAgeByReference(age);
    cout << age << endl;
    return 0;
}

void getAgeByReference(int& age) {
    while (age < 0 || age > 100) {
        cout << "What is your age:  ";
        cin >> age;
    }
}