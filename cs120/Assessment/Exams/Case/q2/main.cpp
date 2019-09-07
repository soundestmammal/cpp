#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

/*
Question 2: Full Credit
[YES - 19, 21, 22] Create random number between 100 and 200
[YES - 24-25] Ask the user for a number between the same range.
[YES - 27] If the numbers are the same then say "Shrubbery"
[Yes - 27] If not say "Piccadilly"
*/

    int randomNumber {};
    int response {};
    srand(time(NULL));
    randomNumber = rand() % 101 + 100;

    cout << "Give me a number from 100 to 200:      ";
    cin >> response;

    cout << (randomNumber == response ? "Shrubbery" : "Piccadilly") << endl;

    return 0;
}