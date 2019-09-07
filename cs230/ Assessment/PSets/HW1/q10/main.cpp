#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
void theNumber(string n);
void theNumber(double d);


int main(){

    theNumber("Don't Panic!");
    theNumber(3.14);

    return 0;
}

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