#include <iostream>
#include <string>
#include <math.h>
#include <ctime>

using namespace std;

double test2(double fahrenheit) {
    double cel = (5/9.0) * fahrenheit - (32 * (5/9.0));
    return cel;
}

int main() {

    // 1.
    string name {};
    int age {};
    cout << "Hey user, what is your name:   ";
    cin >> name;
    cout << "Also, what is your age (in whole years, ex: 24):    ";
    cin >> age;
    cout << "Hey " << name << " I know your age... " << "you are " << age << " years old!" << endl;
    // Output: Hey Rob I know your age... you are 24 years old!



    // 2.
    double celsius {};
    double fahrenheit {};
    cout << "Give me a temperature in celsius:  ";
    cin >> celsius;
    fahrenheit = (9/5.0) * celsius + 32;
    cout << "Ok, I converted that to fahrenheit for you:    " << fahrenheit << " degrees (F)" << endl;
    // Output:    Give me a temperature in celsius:  100
                //Ok, I converted that to fahrenheit for you:    212 degrees (F)
    
    // Test            
    double testCelsius = test2(fahrenheit);
    cout << testCelsius << endl;
    cout << celsius << endl;

    if (testCelsius == celsius) {
        cout << "The inverse transformation is correct" << endl;
    } else {
        cout << "The inverse transformaion is incorrect" << endl;
    }
    


    // 3. Find the average
    double alpha = pow(2, 10);
    double beta = pow(3, 0.5);
    double avg = (alpha + beta) / 2;
    cout << "The average of alpha and beta is:  " << avg << endl;
    // Output: 512.866




    // 4. 
    double test1 {97.1234};
    double test2 {90.1020};
    double mult = (test1 * test2) * 100.0;
    mult = round(mult) / 100.0;
    cout << "The result from multiplying " << test1 << " by " << test2 << " is:     " << mult << endl;
    // Output: 8751.01



    // 5.
    int res {}; 
    cout << "Choose 1 for Hello OR Choose 2 for Good-bye:   ";
    cin >> res;
    if (res != 1 && res != 2) {
        cout << "Sorry, I don't know what that means. My master didn't tell me how to respond to that." << endl;
    } else if (res == 1) {
        cout << "Hello" << endl;
    } else {
        cout << "Good-bye" << endl;
    }

    return 0;
}