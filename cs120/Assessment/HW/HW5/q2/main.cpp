#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {

    int age {0};
    while (age < 1 || age > 100) {
        cout << "What is your age ";
        cin >> age;
    }
    cout << "Your age is:   " << age << endl;
    
    
    return 0;
}

