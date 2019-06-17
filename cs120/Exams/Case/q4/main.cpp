#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

/*
Question 4: 

4. Create three random numbers between 1 and 6. [Yes, Lines 22, 23, 24 and 30-32]
multiply them together [Yes, Line 38]
take the log [Yes, Line 42]
find just the integer part [Yes, Line 46]
and if even -> I knew it [Yes, Line 51]
else -> "too bad" [Yes, Line 52]
*/

    int randomRoll1 {};
    int randomRoll2 {};
    int randomRoll3 {};
    int product {};
    double loggedProduct {};

    srand(time(NULL));

    randomRoll1 = rand() % 5 + 1;
    randomRoll2 = rand() % 5 + 1;
    randomRoll3 = rand() % 5 + 1;

    // Output the random rolls to check if working
    cout << randomRoll1 << endl;
    cout << randomRoll2 << endl;
    cout << randomRoll3 << endl;

    product = randomRoll1 * randomRoll2 * randomRoll3;

    // Output the Product for testing purposes
    cout << product << endl;

    loggedProduct = log(product);
    
    // Output the logged product for checking purposes
    cout << loggedProduct << endl;
    cout << int(loggedProduct) << endl;

    // If it is even (Mod 2 will evaluate to false {0} so I flip the sign to ouput true first)
    if (!(int(loggedProduct) % 2)) {
        cout << "I knew it!" << endl;
    } else {
        // else then it must be odd
        cout << "Too bad" << endl;
    }

    return 0;
}

// Critique: I should document my test code better with comments
// I am just trying to be clear with my solving approach