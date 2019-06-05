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

   // Question 2 on Problem Set
   /*
   2. Create a random number between 1 and 100.  
   If it is less than 50 output "you chose a number less than 50." 
   If it is more than 50, output "you chose a number more than 50."
   */
    srand(time(NULL));
    // Generate a Random number between 0-99 (Add one to make 1-100)
    int randNum = rand() % 100 + 1;
    if (randNum < 50) {
        cout << "You chose a number less than or equal to 50" << endl;
    } else if (randNum > 50){
        cout << "You chose a number greater than 50" << endl;
    } else {
        cout << "The number you chose is 50" << endl;
    }

    // Question 3
    /*
    3. Create a random number between 1 and 6. 
    If it is even, output to a file the number and "it is even"; 
    if it is odd, output to a file the number and "it is odd".
    */
   srand(time(NULL));
   int randDieRoll = rand() % 6 + 1;

   if (randDieRoll % 2 == 0) {
       ofstream output;
       output.open("file.txt");
       output << "The random number is: " << randDieRoll << " and it is even." << endl;
   } else {
       ofstream output;
       output.open("file.txt");
       output << "The random number is: " << randDieRoll << " and it is odd." << endl;
   }
    // Question 4 on Problem Set
    /*
    4. Create 2 random numbers between 1 and 6. 
    If when the two numbers are added together their sum is 
    less than 5 or greater than 12, 
    output to the console: "you win"
    */
    
    srand(time(NULL));
   int randDieRoll1 = rand() % 6 + 1;
   int randDieRoll2 = rand() % 6 + 1;
    cout << randDieRoll1 << endl;
    cout << randDieRoll2 << endl;
   int sum = randDieRoll1 + randDieRoll2;
    cout << sum << endl;
   if (sum < 5 || sum > 12) {
       cout << "You Win!" << endl;
   } else {
       cout << "You didn't win." << endl;
   }

   // Question 5
   /*
   5. Use the conditional operator for this problem. 
   PAY_RATE is 50. 
   Let the user put in their HOURS_WORKED. 
   If the hours worked is greater than 10, output to a file the pay (pay_rate * hours_worked) 
   otherwise output 0.
   */

  int pay_rate {50};
  double hours_worked {};
  cout << "How many hours did you work?     ";
  cin >> hours_worked;

  if (hours_worked > 10) {
      ofstream output;
      output.open("wages.txt");
      output << "The total pay is:  " << (pay_rate * hours_worked) << endl;
  } else {
      ofstream output;
      output.open("wages.txt");
      output << 0 << endl;
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
        cout << "The Width of Rectangle1 is larger than Width of Rectangle2\nThe Area of Rectangle 1 is:  " << (width1 * length1) << " Units."<< endl;
    }
    else {
        // This runs when the Width2 is larger
        cout << (width2 * length2) << endl;
    }
    
    return 0;
}