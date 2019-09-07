#include <iostream>
using namespace std;

// Function Prototypes
int factorial(int x);

int main() {
    cout << factorial(-6) << endl;

    return 0;
}

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