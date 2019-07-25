#include "clothing.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int Clothing::counter = 0;

int main() { 
    Clothing c[2];
    // c[0].showInfo();
    // c[1].showInfo();

    Clothing::showCounter();
   
    return 0;
}

/*
You are creating an array
The array is of size 2
The data in the array is of type Clothing
Since each element is of type clothing the constructor is invoked

    *   We name the name of clothing this object is about - bandanas
    *   We give the number of different categories of that clothing object - ex sizes
    *   We create arrays of type string with the sizes
    *   We create an array of type int with the quantities
    *   We output the sizes and quantities

for exam

Create and use a class
getters and setters
constructor
shwoInfo
static
this
create an array in a class
create an array of classes

 */