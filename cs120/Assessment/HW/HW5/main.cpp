#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

/*
Q1: Passing
Q2: Passing
Q3: Passing
Q4: Passing
Q5: Check
Q6: Check
Q7: Check
Q8: Passing
Q9: Passing
Q10: Passing
Q11: Check
Q12: Check...
Q13: Check
Q14: Check
Q15: Check
Q16: Check
 */

using namespace std;

// Function Prototypes
void deeEmVee(string& name, string& plate); // Question 4
bool isOdd(int num); // Question 5
double max(double a, double b); // Question 15

// Question 1
class Car {
    private:
        string year, make;
        int speed;
    public:
        Car(string y, string m, int s) {
            year = y;
            make = m;
            speed = s;
        }

        Car() {
            year = "2000s";
            make = "GM";
            speed = 100;
        }

        void setYear(string y) { year = y; }
        void setMake(string m) { make = m; }
        void setSpeed(int s) { speed = s; }

        string getYear() { return year; }
        string getMake() { return make; }
        int getSpeed() { return speed; }
};


int main() {

    /*2. Create a while loop that asks:
    for a person's age and only accepts an age between 1 and 100.
    */
   int age {0};
   while (age < 1 || age > 100) {
       cout << "What is your age ";
       cin >> age;
   }
    cout << "Your age is:   " << age << endl;

    /*3. Create a for loop that:
    adds together all the numbers from 1 to 10. */
    int total {0};
    for (int i = 1; i <= 10; i++)
    {
        total += i;
    }
    cout << "The total is:  " << total << endl;

    // Question 4

    string driversName, licensePlate;
    deeEmVee(driversName, licensePlate);
    cout << driversName << endl;
    cout << licensePlate << endl;

    /*5. Create a double function that:
    takes in a number
    and outputs: 
        true if it is even
        false if it is odd. 
    */
   int res {};
   cout << "Give me a number and I will tell you if it is odd or even " << endl;
   cin >> res;
   bool isOdd(res);

   // 

/* 7. Create a random number between 0 and 99. 
Use a while loop to let the computer guess the random number. 
The user should tell the computer if the guess is HIGH of LOW 
and the computer should adjust accordingly, until it figures out the number. */

    srand(time(NULL));
    int randomNumber = rand() % 100;
    int randomGuess = -1;
    char resp {};
    cout << "The random number is:      " << randomNumber << endl;
    cout << "Ready? (y/n)   ";
    cin >> resp;

    while (randomNumber != randomGuess) {
        if (randomGuess > randomNumber) {
            cout << "Guess was too high" << randomGuess << "    " << randomNumber << endl;
        } else {
            cout << "Guess was too low " << randomGuess << "     " << randomNumber <<  endl;
            randomGuess++;
        }
    }


    // Question 8
    // Box of stars
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << "* ";
        }
        cout << endl;
        
    }
    // Triangle of stars
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // Question 9





    
    // Question 13
    for (int i = 0; i < 25; i++)
    {
        bar(i);
    }
    

   /*
   15. Create a function that returns the max of two numbers.
   */

    double a, b, largerNum;
    cout << "I am going to ask you for two numbers, and I will give you the max" << endl;
    cout << "First number:   ";
    cin >> a;
    cout << "Second number:   ";
    cin >> b;
    largerNum = max(a, b);
    cout << "The larger number is " << largerNum << endl;
    

    return 0;
}

// Question 4

void deeEmVee(string& name, string& plate) {
    cout << "What is your name?\n";
    cin >> name;
    cout << "What is your license plate?\n";
    cin >> plate;
}

// Question 5
bool isOdd(int num) {
    if (num%2) {
        cout << "The number " << num << " is odd." << endl;
        return true;
    } else {
        cout << "The number " << num << " is even." << endl;
        return false;
    }
}

// Question 6

double price (double price, int quantity) {
    double total = price * quantity;
    double discount;

    if (quantity > 20) {
        discount = total * (.2);
        return total - discount;
    } else if (quantity > 10) {
        discount = total * (.15);
        return total - discount;
    } else {
        discount = total * (.1);
        return total - discount;
    }

}

// Question 7

// Question 9

bool checkPrime(int num) {
    for (int i = 2; i < num; i++)
        if(num % i == 0)
            return false;
    return true; 
}

void renderList() {
    for (int i = 0; i < 100; i++)
    {
        if(checkPrime(i)) {
            cout << i << endl;
        }
    }
    
}

// Question 10

void bob() {
    cout << "Bob" << endl;
}

void alice() {
    cout << "Alice" << endl;
    bob();
}

// Question 11

void foo(int& x) {
    x = x + 2;
}

// Question 12

void repeat(int x) {
    for (int i = 0; i < x; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << j << endl;
        }   
    }   
}

// Question 13

void bar (double x) {
    cout << 10*x << endl;
}

// Question 14

void swap(int& a, int& b) {
    int temp;
    temp = b;
    b = a;
    a = temp;
}

// Question 15
double max(double a, double b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

// Question 16

int rollDice() {
    return rand() & 6 + 1;
}

void snake() {
    int roll1 = -1;
    int roll2 = -2;
    int counter = 0;

    while (roll1 != 1 && roll2 != 1) {
        roll1 = rollDice();
        roll2 = rollDice();
        counter ++;
    }
    cout << "It took " << counter << " rolls to get snake eyes" << endl;

}