#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void sayHi();
void helloToYou(string name);

int main() {
    string res;
    cout << "What is your name  ";
    cin >> res;

    helloToYou(res);
    return 0;
}

void sayHi() {
    cout << "Hello there" << endl;
}

void helloToYou(string name) {
    cout << "Hello there " << name << endl;
}

/* 
Four components to a function in cpp

1. Function Header
    * Return Type
    * Function Name
    * Inputs
2. Body
    * Code that will run
3. Put Function Prototype above main
4. Invoke the function
 */