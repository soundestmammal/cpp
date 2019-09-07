#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

// Function Proto
int golf();
void hotel();

int main () {
    srand(time(NULL));

    hotel();
    return 0;
}

int golf() {
    return rand() % 6 + 1;
}

void hotel() {
    int counter = 0;
    int roll1 = -1, roll2 = -2;

    while (roll1 != roll2) {
        roll1 = golf();
        roll2 = golf();
        counter++;
    }
    std::cout << "The number of rolls it took was:  " << counter << std::endl;
    std::cout << "The value of roll1 is:    " << roll1 << std::endl;
    std::cout << "The value of roll2 is:    " << roll2 << std::endl;
}