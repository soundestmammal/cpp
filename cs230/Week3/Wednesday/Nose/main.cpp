#include "Nose.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    Nose n1;
    cout << n1.getType() << endl;
    cout << n1.getSize() << endl;

    Nose n2("Hello", 7);
    cout << n2.getType() << endl;
    cout << n2.getSize() << endl;

    return 0;
}