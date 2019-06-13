#include <iostream>

using namespace std;

int main()
{
    // If/else statements in c++ are not curly brace like js.
    // no colon like python
    // Has semicolon on the indented line.
    int num {9};
    if(num>10)
        cout << "The num is greater than 10 !" << endl;
    else
        cout << "The num is less than 10 !" << endl;
    return 0;
}