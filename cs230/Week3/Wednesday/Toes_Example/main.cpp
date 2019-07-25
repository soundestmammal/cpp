#include "toes.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    /*At the top of the file, import the header file of the corresponding Toes class.
    By saying #include "toes.h", this gives main.cpp access to that file.
    When I compile main.cpp, there is no need, to also compile the header file.

     */
    Toes t2(11); // use constructor to create a class with the number of toes (numToes) being 11.
    t2.listToes(); // the syntax to call a method on an instanc eof a class is instance.method()

    return 0;
}