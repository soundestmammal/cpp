#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {

    // I need to create three Doors
    int door1, door2, door3;

    // I need to randomly pick one to have the prize
    // Randomly Generate a number 1-3
    srand(time(NULL));
    int doorWithPrize = rand() % 3 + 1;

    // The random number will be the door that has the prize
    cout << "The door with the prize is door number " << doorWithPrize << endl;

    // For example, if 1 is the random number, then door 1 will have the prize.
    
    // The user will choose a door, either 1 OR 2 OR 3
    
    // Case A: The user Picks the door that has the prize (1/3 chance)
        // I want to reveal one of the two doors that don't have the prize (pick 1 of 2 doors at random)
    
    // Case B: The user picks the door that doesn't have the prize
        // I want to reveal the other door that doesn't have the prize (only 1 option)

    // Ask the User if they would like to switch doors

    // Take the answer if they would like to switch doors

    // Reveal if they won the prize


    return 0;
}