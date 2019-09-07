#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

// Required Function Prototypes:
int Delta(); // Question 4
void Horice(int& x); // Question 9
int Poland(int y); // Question 10

/* Optional Prototypes for testing:
void Alpha(int num); // Question 1
void Bravo(); // Question 2
void Echo(); // Question 5
bool Mike(int num); // Question 6
void November(int grade); // Question 7
void Switch_Them(int& a, int& b); // Question 11
double MaxVal(double a, double b, double c); // Question 12
int MaxVal(int a, int b, int c); // Question 12
*/


int main () {
    
    srand(time(NULL));

    // Question 3:
    const int SIZE = 100;
    int x[SIZE];
    int oddNumbers = 1;

    for (int i = 0; i < SIZE; i++) {
        x[i] = oddNumbers;
        oddNumbers +=2;
    }
    
    // Question 4:
    int ageRes = Delta();
    cout << "You are " << ageRes << " years old!" << endl;

    // Question 8:
    // Box:
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // Triangle:
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    
    // Question 9:
    int someNumber = 7;
    cout << someNumber << endl; // 7
    Horice(someNumber);
    cout << someNumber << endl; // 9

    // Question 10:
    cout << "\n \n \n";
    const int SIZEQ10 = 25;
    int response[SIZEQ10];
    for (int i = 0; i < SIZEQ10; i++)
    {
        response[i] = Poland(i); // Push the return value into an array
    }
    
    /*
    TEST: Output values of array by iterating:

    for (int i = 0; i < SIZEQ10; i++) {
        cout << response[i] << endl;
    }
    */

    return 0;
}

// Question 1: 
void Alpha(int num) {
    int i = 1;
    while(i <= num) {
        cout << i << endl;
        i++;
    }
}

// Question 2:
void Bravo() {
    int total = 0;
    for (int i = 1; i <= 10; i++) {
        total += i;
    }
    cout << total << endl;
}

// Question 4:
int Delta() {
    int age = -1;
    while (age < 0 || age > 100) {
        cout << "Enter your age:    ";
        cin >> age;
    }
    return age;
}

// Question 5:
void Echo() {
    ofstream output;
    output.open("theFile.txt");
    for (int i = 0; i < 20; i++)
    {
        output << rand() % 101 << endl; // 0 - 100
    }
    output.close();
}

// Question 6:
bool Mike(int num) {
    for (int i = 2; i < num; i++) {
        if (!(num%i)) {
            return false;
        }
    }
    return true;  
}

// Question 7:
void November(int grade) {
    if (grade >= 90) {
        cout << "You got an A" << endl;
    } else if (grade >= 80) {
        cout << "You got a B" << endl;
    } else if (grade >= 70) {
        cout << "You got a C" << endl;
    } else {
        cout << "You did not pass" << endl;
    }
}

// Question 9:
void Horice(int& x) {
    x += 2;
}

// Question 10:
int Poland(int y) {
    return y*10;
}

// Question 11
void Switch_Them(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// Question 12: (I eliminated some braces & whitespace for clarity)
double MaxVal(double a, double b, double c) {
    if(a > b)
        if (a > c) return a;
        else return c;
    else // b > a
        if (b > c) return b;
        else return c;
}

int MaxVal(int a, int b, int c) {
    if(a > b)
        if (a > c) return a;
        else return c;
    else // b > a
        if (b > c) return b;
        else return c;
}

