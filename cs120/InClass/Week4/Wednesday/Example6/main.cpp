#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

int getAge();

int main() {
    cout << getAge() << endl;
    return 0;
}

int getAge() {
    int age = -1;
    while (age < 0 || age > 100) {
        cout << "What is your age:  ";
        cin >> age;
    }
    return age;
}