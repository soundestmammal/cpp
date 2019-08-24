#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

// Constant Variables
const double TAX = 0.0875; // Question 12

// Function Prototypes
void quadraticFormula(int a, int b, int c); // Question 1
int dieRoll(); // Question 2
string FavoriteColor(); // Question 3
void swap(int &firstNum, int &secondNum); // Question 4
void checkSquares(int bottom, int top); // Question 5
void factor(int x); // Question 6
int factorial(int x); // Question 7
double applyTax(double subtotal); // Question 8
void totalCost(); // Question 8
void superRandomNumber(int top); // Question 9
void theNumber(string n); // Question 10
void theNumber(double d); // Question 10
void lightsOn(bool &lights); // Question 11
void lightsOff(bool &lights); // Question 11
double thePrice(int units, double basePrice); // Question 12
void fun1(); // Question 15

int main() {

    srand(time(NULL));

    // Question 1
    quadraticFormula(1, 6, 9); // x1 = -3 x2 = -3

    // Question 2
    ofstream output;
    output.open("DieRollResults.txt");

    for (int i = 0; i < 10; i++) {
        output << dieRoll() << endl;
    }
    
    output.close();

    // Question 3
    string response;
    response = FavoriteColor();
    cout << "The user's favorite color is:  " << response << endl;

    // Question 4
    int a = -105, b = 10;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;

    swap(a, b);

    // Outputs I swapped the two numbers
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;

    // Question 5
    int c = 5;
    int d = 20;
    checkSquares(c, d); // 9, 16

    // Question 6
    factor(100);

    // Question 7
    cout << factorial(5) << endl;

    // Question 8
    for (int i = 0; i < 3; i++) {
        totalCost();
    }

    // Question 9
    superRandomNumber(10);

    // Question 10
    theNumber("Don't Panic!");
    theNumber(3.14);

    // Question 11
    bool lights = false;
    cout << lights << endl; // 0

    lightsOff(lights);
    cout << lights << endl; // 0

    lightsOn(lights);
    cout << lights << endl; // 1

    lightsOff(lights);
    cout << lights << endl; // 0

    // Question 12
    int u1 = 10;
    double bp1 = 99.99;
    cout << thePrice(u1, bp1) << endl;
    int u2 = 30;
    double bp2 = 99.99;
    cout << thePrice(u2, bp2) << endl;

    // Question 13
    int start = 1;
    int end = 1000;
    while (start <= end) {
        if (start % 2) {
            cout << start << endl;
        }
        start++;
    }

    // Question 14
    vector <double> v1 (10000);
    int counter = 0;
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = (rand() % 1001) / 1000.0;
        if(v1[i] >= 0.500) {
            counter++;
        }
    } 
    cout << "Of " << v1.size() << " random numbers " << counter << " are greater than 0.500" << endl;

    // Question 15
    for (int i = 0; i < 10; i++)
    {
        fun1();
        /*
        On the last iteration:
        counter1 is 10
        and 
        counter2 is 0
        because counter1 is defined outside of the funcion scope
        */
    }

    return 0;
}


// Question 1
void quadraticFormula(int a, int b, int c) {
    int discriminant = (b*b) - (4*a*c);
    double x1, x2;
    if (discriminant < 0) {
        cerr << "There was a problem here!" << endl;
        exit(1);
    }

    x1 = (-b + (sqrt(discriminant)))/(2.0*a);
    x2 = (-b - (sqrt(discriminant)))/(2.0*a);

    cout << "X1:    " << x1 << endl;
    cout << "X2:    " << x2 << endl;

}

// Question 2
int dieRoll() {
    return rand() % 6 + 1;
}

// Question 3
string FavoriteColor() {
    string color;
    cout << "What is your favorite color?   ";
    cin >> color;
    return color;
}

// Question 4
void swap(int &firstNum, int &secondNum) {
    int temp;
    if(secondNum > firstNum) {
        temp = firstNum;
        firstNum = secondNum;
        secondNum = temp;
        cout << "I swapped the numbers" << endl;
    } else {
        cout << "I did not swap the numbers" << endl;
    }    
}

// Question 5
void checkSquares(int bottom, int top) {
    int counter = bottom;
    double calc;
    while(counter < top) {
        calc = sqrt(counter);
        if(roundf(calc) == calc) {
            cout << counter << endl;
        }
        counter++;
    }
}

// Question 6
void factor(int x) {
    int low = 1;
    int high = x;

    while(low < high) {
        for (int top = high; top > low; top--)
        {
            if(top * low == x) {
                cout << low << " " << top << endl;
            }
        }
        low++;
    }
}

// Question 7
int factorial(int x) {
    if(x<0)
        exit(1);
    int counter = 1;
    for (int i = x; i > 0; i--)
    {
        counter *= i;
    }
    return counter;
}

// Question 8
double applyTax(double subtotal) {
    cout << "Subtotal:  " << subtotal << endl;
    return subtotal * (1+TAX);
}

void totalCost() {
    int quantity;
    string name;
    double cost;
    double subtotal, total;

    cout << "What is the name of the item   ";
    cin >> name;
    
    cout << "What is the quantity of the item:  ";
    cin >> quantity;

    cout << "What is the cost of the item:  ";
    cin >> cost;

    subtotal = quantity * cost;

    if(quantity >= 300) {
        subtotal = subtotal - (subtotal * 0.2);
    } else if (quantity >= 200) {
        subtotal = subtotal - (subtotal * 0.15);
    } else if (quantity >= 100) {
        subtotal = subtotal - (subtotal * 0.10);
    }
    total = applyTax(subtotal);
    
    // The total cost function should use the apply tax to find the total cost

    // It should output the:
    // Item Name
    cout << "Item Name: " << name << endl;
    // Amount Purchased
    cout << "Quantity:  " << quantity << endl;
    // Total Cost
    cout << "Total Cost:  " << fixed << setprecision(2) << total << endl;

}

// Question 9
void superRandomNumber(int top) {
    ofstream output;
    output.open("theFile.txt");
    for (int i = 0; i < 100; i++) {
        output << rand() % top << endl;        
    }
    output.close();
}

// Question 10
void theNumber(string n) {
    for (int i = 0; i < 10; i++) {
        cout << n << endl;
    }
}

void theNumber(double d) {
    for (int i = 0; i < 10; i++) {
        cout << d << endl;
    }
}

// Question  11
void lightsOn(bool &lights) {
    lights = true;
}

void lightsOff(bool &lights) {
    lights = false;
}

// Question 12
double thePrice(int units, double basePrice) {
    double subtotal;
    if(units > 20) {
        subtotal = ((units*basePrice) * 0.95);
    } else {
        subtotal = (units*basePrice);
    }

    return (subtotal * (1+TAX));
}

// Question 15
void fun1(){
    static int counter1 = 0;
    int counter2 = 0;
    counter1++;
    counter2++;
    cout << counter1 << endl;
    cout << counter2 << endl;
}


/*

Question 16

An incomplete high level overview of a c++ program is as follows:

The programmer writes source code somewhere, think visual studio, or notepad.

The computer does not (directly) understand the source code so it must be compiled into a form the computer can understand.
This is where the compiler transforms the source code into the code understood by the computer.

However, just before compiling the source code, the compiler looks for any preprocessor directives, or 
instructions. These instructions are preceded with a # sign (pound sign, octothorpe). 
So far, we have used examples such as #include when we want the compiler to know we are using
a c++ library such as <iostream>.

We will see this will be useful for also including other user defined files later on in the course.

 */