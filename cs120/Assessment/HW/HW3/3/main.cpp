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

    int counter {0};
    
    while ((age < 1 || age > 100) && counter < 3) {
        counter++;
        cout << "What is your age?";
        cin >> age;
        if (counter >= 3) cout << "Sorry you exceeded the number of attempts" << endl;
    }

    return 0;
}