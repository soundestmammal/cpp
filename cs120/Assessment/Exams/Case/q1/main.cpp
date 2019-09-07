#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

/* 
Question 1: Full Credit
[YES - Line 22] Ask the user for fav num from 1 to 100.
[YES - Line 25-26] If the number is between 2 and 13 say "Nice"
[YES - Line 27-28] If it is between 21 and 84 say "Not bad"
[YES - Line 29-30] If it is between 85 and 99 say "Great"
[YES - Line 31-32] If it is anything else say "Too bad"
Hint: (use an if/else if/else statement)

*/ 
    int favoriteNumber {};
    cout << "Please tell me of your favorite number from 1 to 100:      " ;
    cin >> favoriteNumber;

    if (favoriteNumber > 2 && favoriteNumber < 13) {
        cout << "Nice" << endl;
    } else if (favoriteNumber > 21 && favoriteNumber < 84) {
        cout << "Not Bad" << endl;
    } else if (favoriteNumber > 85 && favoriteNumber < 99) {
        cout << "Great" << endl;
    } else {
        cout << "Too bad" << endl;
    }
    return 0;
}