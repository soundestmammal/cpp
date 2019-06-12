#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

enum Cars { McClaren = 1, Tesla = 2, Jaguar = 3, Aston_Martin = 4 };

int main() {
    int car {};
    cout << "Which car would you like option 1, 2, 3, 4?\n";
    cin >> car;

    switch(car) {
        case McClaren:
            cout << "Cool" << endl;
            break;
        case Tesla:
            cout << "Hold on during acceleration..." << endl;
            break;
        case Jaguar:
            cout << "Everyone says this one differently" << endl;
            break;
        case Aston_Martin:
            cout << "This name has two words" << endl;
            break;
        default:
            cout << "I don't know that kind of car... " << endl;
            break;
    }
    return 0;
}

/*
if statements
switch statements
enum example
fixed set precision
output to a file
generate a random number
set width 
*/