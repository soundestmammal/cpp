#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int Alpha(int bottom, int top);
void Bravo(string &name); 
bool Charlie(int num);
void Delta(int &firstNum, int &secondNum);
double Echo(int units, double base_price);
void Foxtrot(double num);

const double TAX = 0.0875; // Value of TAX should not change

int main() {

    srand(time(NULL));

    // Question 6
    const int SIZE = 10;
    int x[SIZE];

    // Populate the Array
    for (int i = 0; i < SIZE; i++)
    {
        x[i] = rand() % 100 + 1;
    }

    // Output the elements in the array for testing
    for (int i = 0; i < SIZE; i++)
    {
        cout << x[i] << endl;
    }

    // All of the elements of the array are randomly generated numbers.
    
    // Question 7. (NOTE: IT OVERWRITES THE SAME LINE IN THE FILE).
    for (int i = 0; i < 5; i++)
    {
        Foxtrot(5.5);
    }
    
    return 0;
}

int Alpha(int bottom, int top) {
    int total =  0;
    while(bottom <= top) {
        total += bottom;
        bottom++;
    }
    return total;
}

void Bravo(string &name) {
    cout << "Tell me your new name!" << endl;
    cin >> name;
}

bool Charlie(int num) {
    for (int i = 2; i < num; i++)
    {
        if(!(num % i)) { // This Line: if the remainder is zero, the number is not prime
            return false;
        }
    }
    return true;   // If the remainder when mod i is never zero, the number must be prime
}

void Delta(int &firstNum, int &secondNum) {
    if (firstNum > secondNum) {
        cout << "firstNum is the larger number" << endl;
    } else {
        int temp;
        temp = firstNum;
        firstNum = secondNum;
        secondNum = temp;
    }
}

double Echo(int units, double base_price) {
    if(units > 20) {
        int preTax = (units*base_price) * 0.95;
        cout << preTax << endl;
        return preTax * (1+TAX); // Final Price
    } else {
        return (units*base_price) * (1+TAX); // Final Price
    }
}

void Foxtrot(double num){
    ofstream output;
    output.open("Random_Numbers.txt");

    output << num << "\n";
    output.close();
}