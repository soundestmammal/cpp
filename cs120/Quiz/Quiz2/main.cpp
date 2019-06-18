#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;
const double TAX1 = .05;
const double TAX2 = .06;

int setAge(); // Q3
double getAvg(double x, double y, double z); // Q4
double calcTotalCost(double cost); // Q5

int main() {

    // Question 1
    int start = 7, end = 23, total = 0;

    while(start <= end) {
        cout << start << endl;
        total += start;
        start++;
    }

    cout << total << endl;

    // Question 2

    ofstream output;
    output.open("file.txt");

    for (int i = 100; i >= -10; i--)
    {
        output << i << endl;
    }
    
    output.close();

    // Question 3

    int age = setAge();
    cout << "Your age is: " << age << endl;

    // Question 4

    double a, b, c, average;

    cout << "Hey user I am going to ask you three for 3 numbers (it can have decimals) and give you the average:" << endl;
    cout << "Give me number 1: ";
    cin >> a;
    cout << "Give me number 2: ";
    cin >> b;
    cout << "Give me number 3: ";
    cin >> c;

    average = getAvg(a, b, c);
    cout << "The average of " << a << " " << b << " " << c << " is " << average << endl;

    // Question 5

    double response5 = -1.0, totalCost = 0;
    while(response5 < 0) {
        cout << "What is the cost of the item:  ";
        cin >> response5;
    }
    totalCost = calcTotalCost(response5);
    cout << "The total cost of the item is:  " << fixed << setprecision(2) << totalCost << endl;

    // Question 6

    ofstream output6;
    output6.open("friends.txt");

    vector<string> listOfFriends {"Yann Lecun", "Geoff Hinton", "Al Gorithm"};
    
    for (int i = 0; i < listOfFriends.size(); i++) {
        output6 << listOfFriends[i] << endl;
    }

    output6.close();

    return 0;
}

// Question 3
int setAge() {
    int response {0};
    while (response < 10 || response > 20) {
        cout << "What is your age (between 10-20):  ";
        cin >> response;
    }
    return response;
}

// Question 4
double getAvg(double x, double y, double z) {
    return (x+y+z)/3.0;
}

// Question 5
double calcTotalCost(double cost) {
    if (cost <= 100) {
        return cost * (1+TAX1);
    } else {
        return  cost*(1+TAX2);
    }
}