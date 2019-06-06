#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

// I need to create three Doors
enum { door1 = 1, door2 = 2, door3 = 3 };

int main() {

    // I need to randomly pick one to have the prize
    // Randomly Generate a number 1-3
    srand(time(NULL));
    int doorWithPrize = rand() % 3 + 1;

    // The random number will be the door that has the prize
    cout << "The door with the prize is door number " << doorWithPrize << endl;

    // For example, if 1 is the random number, then door 1 will have the prize.
    int response {};

    // The user will choose a door, either 1 OR 2 OR 3
    cout << "Choose a door, your options are 1, 2, 3    ";
    cin >> response;
    
    // Case A: The user Picks the door that has the prize (1/3 chance)
        // I want to reveal one of the two doors that don't have the prize (pick 1 of 2 doors at random)
    
    // Case B: The user picks the door that doesn't have the prize
        // I want to reveal the other door that doesn't have the prize (only 1 option)

    if (doorWithPrize == response) {
        // I need to pick from one of the two doors that don't have the prize
    int reveal {2};
        // output the door that is now opened
        cout << "Ok, Door " << reveal << " is revealed to not have the prize." << endl;
        
        // Ask the User if they would like to switch doors
        cout << "Would you like to switch your door? Reply with either a 'Y' OR 'N'     ";
        // Take the answer if they would like to switch doors
        string switchDoorRes {};
        cin >> switchDoorRes;
    }



    // Reveal if they won the prize

    return 0;
}