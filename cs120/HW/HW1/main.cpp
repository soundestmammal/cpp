#include <iostream>
#include <string>
#include <math.h>
#include <ctime>

using namespace std;

int main() {

    /* 
    1. Create a variable to hold the date, 
    ask the user for it 
    and store it in the created variable called DATE. 
    */

   string date {};
   cout << "Give a date in the form mm/dd/yyyy:    ";
   getline(cin, date);
   cout << "This is the date you provided: " << date << endl;


    /* 
    2. Ask the user for the temperature in Celsius, 
    store the result in a variable called CELSIUS. 
    Use the formula (9/5)*CELSIUS+32 
    to get the Fahrenheit temperature and store is in a variable called FAHRENHEIT.
    */

    double celsius {};
    double fahrenheit {};

    cout << "Give a temperature in celsius:  ";
    cin >> celsius;

    fahrenheit = ((9/5.0) * (celsius + 32));
    cout << "The temperature in Fahrenheit is: " << fahrenheit << endl;

    /*3. Find the value of 2^8 and store it in a variable called POWERTEST.*/
    double powertest {};
    powertest = pow(2,8);
    cout << powertest << endl;

    /*4. Let test1 = 97 and test2 = 90.102 
    and find the average, 
    store it in a variable called AVERAGE, 
    output it correctly to two decimal places. */

    double test1 {97};
    double test2 {90.102};
    double average {};

    average = (test1 + test2) / 2;
    average = roundf(average * 100) / 100;
    cout << average << endl;

    // 5. If A = 4 and B = 3 use the formula to find C (the hypotenuse of the triangle).

    double a {3};
    double b {4};
    double c {};
    c = (pow(3, 2) + pow (4, 2));
    c = pow(c, 0.5);
    cout << "The third side is: " << c << endl;

    // 6. Ask the user to choose 1 or 2, if they say one, output "Hello", if they say 2, output "Good-Bye"
    int res {};
    cout << "Submit 1 for Hello, and submit 2 for Goodbye:  ";
    cin >> res;
    if (res != 1 && res != 2){
        cout << "Please enter a valid response" << endl;
    } else if (res == 1) {
        cout << "Hello" << endl;
    } else if (res == 2) {
        cout << "Goodbye" << endl;
    }

    /*
    7. Ask the user for a number, if it is greater than 10 output the log of the number, 
    if it less than 10 output 2*log(number).
    */
    double numberRes {};
    cout << "Enter a number: ";
    cin >> numberRes;

    if (numberRes == 10) {
        cout << "Please enter a number other than 10" << endl;
    } else if (numberRes > 10) {
        cout << "Log of that number is: " << log(numberRes) << endl;
    } else if (numberRes < 10) {
        cout << "2 times the log of that number is: " << 2*log(numberRes) << endl;
    }

    /* 8. Ask the user for their full name; store it in a variable called FULLNAME. */
    string fullName {};
    cout << "What is your full name:    ";
    getline(cin, fullName);

    /*
    9. Ask the user for their name and age, output their name and age in one line.
    */
    string name {};
    int age {};

    cout << "What is your name: ";
    getline(cin, name);
    cout << "What is your age:  ";
    cin >> age;

    cout << "\nYour name is: " << name << " and your age is " << age << endl;
   /* 10. Ask the user for their favorite letter, output one letter past that (so if they tell you 'b', you should output 'c'). */
    char favoriteLetter {};
    cout << "Input your favorite letter:    ";
    cin >> favoriteLetter;
    char shiftLetter = favoriteLetter + 1;
    cout << shiftLetter << " is one letter past your favorite letter " << favoriteLetter << endl;

    return 0;
}