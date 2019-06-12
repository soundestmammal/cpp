#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string password = "abc123", guess = "";
    
    for ( int i = 0; i < 3; i++)
    {
        if (password == guess) {
            cout << "You've got it!\n";
            break;
        }
        cout << "What is the password?\n";
        cin >> guess;
    }
    return 0;
}