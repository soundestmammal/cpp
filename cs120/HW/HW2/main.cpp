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
   } else if (color == "green") {
       cout << "Not a bad choice" << endl;
   } 
   
   else {
       cout << "Sorry, that's not a primary color." << endl;
   }

    string brand;
    cout << "What type of volleyball do you like the best   ";
    cin >> brand;

    if (brand == "KOB") {
        cout << "Nice choice!" << endl;
    }
    else if (brand == "WilsonAVP") {
        cout << "Ok, fair choice" << endl;
    }
    else if (brand == "Mikasa") {
        cout << "Wow $$$" << endl;
    }
    else {
        cout << "You may want to upgrade" << endl;
    }

    double length1 {};
    double width1 {};
    double length2 {};
    double width2 {};
    double area1 {};
    double area2 {};

    cout << "What is the length of the rectangle 1:     ";
    cin >> l;

    cout << "What is the width of the rectangle 2:      ";
    cin >> w;
    
    return 0;
}