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
   cout << "Give a date in the form Month Day, Year:    ";
   getline(cin, date);
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

    fahrenheit = (9/5)*celsius+32;
    cout << "The temperature in Fahrenheit is: " << fahrenheit << endl;

    /*3. Find the value of 2^8 and store it in a variable called POWERTEST.*/
    double powertest {};
    powertest = pow(2,8);

    /*4. Let test1 = 97 and test2 = 90.102 
    and find the average, 
    store it in a variable called AVERAGE, 
    output it correctly to two decimal places. */

    double test1 {97};
    double test2 {90.102};
    double average {};

    average = (test1 + test2) / 2;
    

    return 0;
}