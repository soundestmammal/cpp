#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

enum Colors { Red = 1, Blue = 2, Green = 3 };

int main() {

    /* 
    1. Passing
    2. Passing
    3. Passing
    4. Passing
    5.
    6.
    7.
    8.
    9.
    10.
    11.
    
    */

// 1. Ask the user for fav num from 1 to 100.
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

// 2. Create random number between 100 and 200. 

    int randomNumber {};
    int response {};
    srand(time(NULL));
    randomNumber = rand() % 101 + 100;

    cout << "Give me a number from 100 to 200:      ";
    cin >> response;

    cout << (randomNumber == response ? "Shrubbery" : "Piccadilly") << endl;

// 3. Create a random number between 1 and 6 if odd -> amazing : if even -> wonderful

    int randomDieRoll {};
    srand(time(NULL));
    randomDieRoll = rand() % 6 + 1;

    cout << randomDieRoll << endl;

    if(randomDieRoll % 2) {
        cout << "Amazing" << endl;
    } else {
        cout << "Wonderful" << endl;
    }

/*  4. Create three random numbers between 1 and 6.
multiply them together
take the log
find just the integer part
and if even -> I knew it
else -> "too bad"
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

cout << randomRoll1 << endl;
cout << randomRoll2 << endl;
cout << randomRoll3 << endl;

product = randomRoll1 * randomRoll2 * randomRoll3;

cout << product << endl;

loggedProduct = log(product);

cout << loggedProduct << endl;

cout << int(loggedProduct) << endl;

if (!(int(loggedProduct) % 2)) {
    cout << "I knew it!" << endl;
} else {
    cout << "Too bad" << endl;
}

// 5. 
    int response5 {};
    cout << "Give me a number between 1 and 100     ";
    cin >> response5;
    ofstream output;
    output.open("file.txt");

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
    } else {
        if (response5 % 2) {
            // runs when odd
            output << "Odd" << endl;
        } else {
            output << "Even" << endl;
        }
    }
    output.close();

// 6. 

    ofstream output6;
    output6.open("friends.txt");

    string friend1, friend2, friend3;
    cout << "I'm going to ask you for the first names of your three best friends:    " << endl;
    cout << "Friend 1 - First Name:     ";
    cin >> friend1;
    cout << "Friend 2 - First Name:     ";
    cin >> friend2;
    cout << "Friend 3 - First Name:     ";
    cin >> friend3;

    output6 << friend1 << " " << friend2 << " " << friend3 << endl;
    output6.close();

// 7. 
    int response7 {};
    cout << "Give me a negative number:     ";
    cin >> response7;

    if (response7 >= 0) {
        cout << "Give me a negative number (Last Try):     ";
        cin >> response7;
        if (response7 >= 0) {
            cout << "Goodbye" << endl;
        } else {
            cout << response7 * -1 << endl;
        }
    } else {
        cout << response7 * -1 << endl;
    }

// 8. 
    int width1 {};
    int width2 {};
    int length1 {};
    int length2 {};

    cout << "Give me the width of Rectangle 1:      ";
    cin >> width1;

    cout << "Give me the length of Rectangle 1:     ";
    cin >> length1;

    cout << "Give me the width of Rectangle 2:      ";
    cin >> width2;

    cout << "Give me the length of Rectangle 2:     ";
    cin >> length2;

    if (width1 == width2) {
        cout << "The widths are equal" << endl;
    } else if (width1 < width2) {
        cout << "Area of rectangle 1: " << width1 * length1 << endl;
    } else {
        cout << "Area of rectangle 2: " << width2 * length2 << endl;
    }

// 9. 
    int res9 {};
    cout << "Give me a number between -100 and 100" << endl;
    cin >> res9;

    cout << (res9 > 0 ? "Positive" : "Negative") << endl;

// 10.
    int colorChoice {};
    cout << "There are three color choices: red [1], blue [2], green[3]." << endl;
    cout << "Pick a color using the corresponding numbers above ex. 2 for blue:     ";
    cin >> colorChoice;

    switch (colorChoice) {
        case Red:
        cout << "Terrible Choice" << endl;
        break;

        case Blue:
        cout << "Great choice" << endl;
        break;

        case Green:
        cout << "Not a bad choice" << endl;
        break;

        default:
        cout << "Illegal option" << endl;
    }

// 11. There are two types of soda type A and type B

    double blackA {1.50};
    double blackB {0.75};
    double orangeA {2.14};
    double orangeB {1.25};
    int colorRes {};
    int typeRes {};

    cout << "Would you like black[1] or orange soda[0]? (Use corresponding number)";
    cin >> colorRes;

    if(colorRes) {
        cout << "Would you like type A[1] or B[0] (use corresponding number)";
        cin >> typeRes;
        if (typeRes) {
            cout << blackA << endl;
        } else {
            cout << blackB << endl;
        }
    } else {
        cout << "Would you like type A[1] or B[0]" << endl;
        cin >> typeRes;
        if (typeRes) {
            cout << orangeA << endl;
        } else {
            cout << orangeB << endl;
        }

    }
    return 0;
}