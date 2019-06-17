#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

/*
Question 3: Full Credit
[YES - Lines 17, 18, 19] Create a random number between 1 and 6.
[YES - Lines 25, 26] If it is 1,3,5 say "Amazing"
[YES - Lines 27, 28] If it is 2,4,6 say "Wonderful"
*/
    int randomDieRoll {};
    srand(time(NULL));
    randomDieRoll = rand() % 6 + 1;

    cout << randomDieRoll << endl;

    if(randomDieRoll % 2) {
        cout << "Amazing" << endl;
    } else {
        cout << "Wonderful" << endl;
    }

    return 0;
}
/*
Critique: Line 23 was a test line for when I ran the program to validate the if condition ran properly.
Obviously, I understood the scope of the problem. In the future, I will comment it out or delete.

Why it is correct: 
I generate a random number [1,6], and mod it by 2.
Mod 2 can only evaluate to 0 or 1.
CASE A: (evaluates to 0) Meaning that the random die roll is evenly divisible by 2 -> it is even -> it must either be [2, 4, 6]
The if statement will evaluate to false, and the code in the else will run. "Wonderful"
CASE B: (evalutes to 1) Meaning that the random die roll has a remainder of 1 when divided by 2. -> it is odd -> it must either be 1, 3, 5
The if statement will evaluate to 1 (truthy) and will run the code within the code block.
*/
