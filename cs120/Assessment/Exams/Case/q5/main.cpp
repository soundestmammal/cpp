#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

/*
Question 5: Full Credit - Works fine for me in all cases
Q: Provide a number between 1 and 100, give user two chances to provide a valid number. 
*/ 
    int response5 {};
    cout << "Give me a number between 1 and 100     ";
    cin >> response5;
    ofstream output;
    output.open("file.txt");

    // Will run if given an INVALID number on first response
    if(response5 < 1 || response5 > 100) {
        cout << "That was not a valid response. I'll give you one more chance to give me a valid number." << endl;
        cout << "Give me a number between 1 and 100     ";
        cin >> response5;
        if(response5 < 1 || response5 > 100) {
            cout << "That was not a valid response. Good bye" << endl;
        } else {
            if (response5 % 2) {
                output << "Odd" << endl;
            } else {
                output << "Even" << endl;
            }
        }
        // Will run if given a valid number on first response
    } else {
        if (response5 % 2) {
            // runs when odd
            output << "Odd" << endl;
        } else {
            output << "Even" << endl;
        }
    }
    output.close();
    return 0;
}