#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

// Function Prototypes:
void lockup(int& age); // question 7
void eta(int num, bool& isPrime); // question 9

int main () {

    int age = -1;
    cout << "The old value of age is " << age << endl; // outputs -1 to the console
    lockup(age);
    cout << "The new value of age is " << age << endl; // outputs new value of age

    int testNum = 71;
    bool isItAPrime;
    eta(testNum, isItAPrime);
    cout << isItAPrime << endl; // true

    return 0;
}

// Question 1:
int alpha() {
    int i = -1;
    while (i < 1 || i > 20) {
        cout << "Give me a whole number between 1 and 20: ";
        cin >> i;
    }
    return i*2;
}

// Question 2:
string beta(int x) {
    if (x%2) {
        return "Odd";
    } else {
        return "Even";
    }
}

// Question 3:
double gamma(double a, double b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Question 4:
void delta(int k) {
    double upperBound;
    upperBound = cbrt(k);

    for (int i = 1; i < upperBound/1; i++)
    {
        cout << pow(i, 3) << endl;
    }
    
}

// Question 5:
// I would have srand(time(NULL)) in main above this function call
void charlie() {
    for (int i = 0; i < 20; i++)
    {
        cout << rand() % 101 + 1 << endl;
    }
    
}

// Question 6:
void foxtrot(string word) {
    if (word == "box") {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
        
    } else if (word == "triangle") {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    } else {
        cout << "Sorry - invalid" << endl;
    }
}

// Question 7
void lockup(int& age) {
    while (age < 1 || age > 100) {
        cout << "Give me your age:  ";
        cin >> age;
    }
}

// Question 8

void alice() {
    cout << "Hi I'm Alice" << endl;
}

void bob() {
    cout << "Hi I'm Bob" << endl;
}

void ellis() {
    cout << "Hi I'm Ellis, Alice and Bob say hello." << endl;
    alice();
    bob();
}

// Question 9

void eta(int num, bool& isPrime) {
    // Assume the number is prime, until proven otherwise
    isPrime = true;
    for (int i = 2; i < num; i++)
    {
        // If it has a remainder of zero, then it must not be prime
        // Flip the bool and exit the function 
        if(!(num%i)) {
            isPrime = false;
        }
    }
}


