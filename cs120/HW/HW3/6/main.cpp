#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {

    /*
    Question 1: Passing
    Question 2: Passing
    Question 3: Needs to be tweaked. Working but is not ideal. (Has a repetitive statement after the last attempt.)
    Question 4: Passing
    Question 5: Passing
    Question 6: -------
    Question 7: -------
    Question 8: -------
    Question 9: -------
    Question 10: ------
    */

   // 6. Create a triangle using 2 for loops and the "*"

    for (int i = 0; i < 10; i++)
    {
        for (int j = i; j < 10; j++)
        {
            cout << "*";
        }
        cout << endl;
        
    }
    
    return 0;
}