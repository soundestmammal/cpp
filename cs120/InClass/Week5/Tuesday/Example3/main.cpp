#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

// Function Proto
std::string india1(int num);
std::string india1(double num);

int main () {
    srand(time(NULL));

    return 0;
}

std::string india1(int num) {
    if(num%2) {
        return "odd";
    } else {
        return "even";
    }
}

std::string india1(double num) {
    if(int(num) %2) {
        return "odd";
    } else {
        return "even";
    }
}