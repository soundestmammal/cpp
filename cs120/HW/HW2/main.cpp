#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {

    /* 1. Ask the user for their favorite color.  
    Create a variable named COLOR to store it. 
    If they choose blue, output "Great choice." 
    if they choose red, output "Poor choice"; if they choose green, 
    output "Not a bad choice." ; if they choose anything else, 
    say "Sorry, that's not a primary number." (Use an if/else-if/else statement).
    */
   string color;

   cout << "What is your favorite color:    ";
   cin >> color;

   if (color == "blue") {
       cout << "Great Choice" << endl;
   } 
   else if (color == "red") {
       cout << "Poor Choice" << endl;
   } 
   else if (color == "green") {
       cout << "Not a bad choice" << endl;
   } 
   else {
       cout << "Sorry, that's not a primary color." << endl;
   }

    // Question 8 on Problem Set
    double length1 {};
    double width1 {};
    double length2 {};
    double width2 {};

    cout << "What is the length of the rectangle 1:     ";
    cin >> length1;
    cout << "What is the width of the rectangle 1:      ";
    cin >> width1;
    cout << "What is the length of rectangle 2:         ";
    cin >> length2;
    cout << "What is the width of rectangle 2:          ";
    cin >> width2;

    // Check if the width1 is larger
    if (width1 > width2) {
        // This code will only run if Width 1 is larger 
        cout << "The Width of Rectangle1 is larger than Width of Rectangle2 \n The Area of Rectangle 1 is:  " << (width1 * length1) << " Units."<< endl;
    }
    else {
        // This runs when the Width2 is larger
        cout << (width2 * length2) << endl;
    }
    
    return 0;
}