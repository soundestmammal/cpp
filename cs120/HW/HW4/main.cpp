#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;
void itCounts(int start, int end);
void cubeRoots(int start, int end);
int main() {

/*
Question 1

Q: Create a while loop that counts from 10 to -10. 
A: Declare an variable of type int and assign it 10
   Output the current "count"
   Decrement the current "count"
   Repeat: Until the count = -11, in which case the loop terminates.
 */
    int count {10};
    while(count >= -10) {
        cout << "Count: " << count << endl;
        --count;
    }
    itCounts(20, 34);


/*
Question 2

Q: Create a for loop that outputs the cube root of the numbers 5 to 20.
A: Use a counter variable "i" from 5 to 20 and pass "i" to the cbrt method.
*/

    for (int i = 5; i <= 20; i++) {
        cout << "The cube root of "<< i << " is "<< cbrt(i) << endl;
    }
    cubeRoots(5, 20);
/*
Question 3

Q: Create a for loop that outputs 20 random numbers between 0 and 1.
A: Mod 101 ->  A number between 0-100, divide by 100.0 to move decimal over two spaces. Then output the number.
 */
    double randomNumber {};
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        randomNumber = rand() % 101 / 100.0;
        cout << "Random Number # " << i + 1 << ":   " << randomNumber << endl;
    }

/*
Question 4

Use a while loop to ask the user for their age until they give an age between 0 and 100
*/
    int age {};
    bool flag = false;
    while(!flag) {
        cout << "What is your age:   ";
        cin >> age;
        if (age > 0 && age < 100) {
            cout << "Thank you " << age << " is a valid age " << endl;
            flag = true;
        } 
    }

/*
Question 5

Ask the user to input an item's cost, use a while loop to ensure that the cost is greater than 0.
*/
    double cost {};
    // onOff - Boolean initialized to false and I flip the sign to run until onOff becomes true.
    // Same idea as previous quesiton, but renamed to avoiding namespace collisions
    bool onOff = false;
    while(!onOff) {
        cout << "Enter the item's cost:     ";
        cin >> cost;
        if (cost > 0) {
            cout << "Thank you $" << fixed << setprecision(2) << cost << " is a valid cost " << endl;
            onOff = true;
        }
    }
    return 0;
}

void itCounts(int start, int end) {
    while (start <= end) {
        cout << start++ << endl;
    }
}

void otherItCounts(int start, int end) {
    int total = 0;
    while (start <= end) {
        total += start;
        start++;
    }
    cout << "The total is " << total << endl;
}

void cubeRoots(int start, int end) {
    for (int i = start; i <= end; i++)
    {
        cout << pow(i, .333) << endl;
    }
    
}