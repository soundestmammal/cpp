#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string password = "abc123";
    string guess = "";

    int numTries = 1;
    
    // If you guess password it'll exit, or if 
    while (guess != password && numTries <= 3) {
        numTries++;
        cout << "What is the password\n";
        cin >> guess;
    }

    while(guess != password) {
        if (numTries > 3) {
            break;
        }
        numTries++;
        cout << "What is the password\n";
        cin >> guess;
    }

    cout << endl;
    return 0;
}