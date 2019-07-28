#include <iostream>

using namespace std;

// Function Prototypes
void swap(int &firstNum, int &secondNum);

int main () {
    
    int a = -105, b = 10;

    swap(a, b);

    // Outputs I swapped the two numbers
    cout << "a  " << a << endl; // 10
    cout << "b  " << b << endl; // -105

    return 0;
}

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