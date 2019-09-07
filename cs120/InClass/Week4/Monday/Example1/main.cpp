#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

void takeInName(string s);

int main() {
    string theName = "Bob";
    takeInName(theName);

    cout << theName << endl;

    return 0;
}

void takeInName(string s) {
    cout << "Hello there " << s << endl;
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