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
    Question 3: Passing
    Question 4: Passing
    Question 5: Passing
    Question 6: Passing
    Question 7: Passing
    Question 8: Passing
    Question 9: Passing
    Question 10: Passing
    */

// 1. Create a while loop that counts even numbers from 2 to 10
    int i = 2;
    while (i <= 10) {
        if (!(i%2)) cout << i << endl;
        ++i;
    }
// 2. Create a for loop that counts by five (0, 5, 10, ...) from 0 to 100
    for (int j = 0; j<=100; ++j) {
        if (j == 0) {
            cout << j << endl;
        } else if ((j%5) == 0) {
            cout << j << endl;
        }
    }
// 3. Ask for a person's age and give them three tries to give you a correct act (between 0 and 100)
    int age {0};
    int counter {0};
    
    while ((age < 1 || age > 100) && counter < 3) {
        counter++;
        cout << "What is your age?";
        cin >> age;
        if (counter >= 3) cout << "Sorry you exceeded the number of attempts. Goodbye" << endl;
    }

// 4. Use a for loop to list celsius and fahrenheit temperatures. The "C" should be from -20 to 20 and the f should be shown correspondingly.
    // F = (9/5)*C + 32
    double fahrenheit {};
    for (int c = -20; c<=20; ++c) {
        fahrenheit = (9/5.0) * double(c) +32;
        cout << "Celsius:   " << c << "\t" << "Fahrenheit   " << fahrenheit << endl;
    }

// 5. The fibonacci numbers are 1, 1, 2, 3, 5, 8, 13, 21, ... Use a for loop to list the first 20 Fibonacci Numbers

    int a = 0, b = 1, c;
    int counter = 0;

    cout << a << " " << b << " ";

    while(counter < 20) {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
        counter++;
    }

    cout << endl;

// 6. Create a triangle using 2 for loops and the "*"

for (int i = 0; i < 10; i++)
    {
        for (int j = i; j < 10; j++)
        {
            cout << "*";
        }
        cout << endl;
        
    }

// 7. Check if a number is prime

    int response {};
    bool ean = true;

    cout << "Give me a number:  ";
    cin >> response;

    for (int i = 2; i <= response/2; i++)
    {
       if ((response % i) == 0) {
           ean = false;
           break;
       } 
    }
    
    if (ean) {
        cout << "The number is prime" << endl;
    } else {
        cout << "Not a prime number" << endl;
    }

// 8. Output a list of numbers from 100 to 1 (using a for loop) to a file

    ofstream output8;
    output8.open("eight.txt");

    for (int i = 100; i > 0; i--)
    {
        output8 << i << " " << endl;
    }
    
    output8.close();
    

// 9. Use a loop to output all the squares to a file

    ofstream output9;
    output9.open("theFile.txt");
    for (int i = 0; i <= 10; i++)
    {
        output9 << i * i << endl;
    }
    
    output9.close();

    

// 10. Take a number such as 47321 and output it backwards to get 12374
    int num {};
    int rev {};
    cout << "Give me a number and I will reverse it...      ";
    cin >> num;
    while(num > 0) { 
        rev = rev*10 + num%10; 
        num = num/10; 
    } 
    cout << rev << endl;

    /* 
    I'm usually pretty good at these things but problem 10 stumped me. I wasn't able to figure it out on my own.
    The approach I would want to do is to store the numbers in an array and iterate through them
    And push_back the nth element in the 0th spot in the array, n-1 in the 1st index, ... n-ith element in the ith spot.

    Source for problem 10: https://www.tutorialspoint.com/cplusplus-program-to-reverse-a-number 
    This is a really clever solution. 
     */
    
    return 0;
}