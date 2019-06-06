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
    int wins {0};
    int losses {0};
    for (int i= 0; i<100; ++i) {
        // I need to randomly pick one to have the prize
        // Randomly Generate a number 1-3
        srand(time(NULL));
        int doorWithPrize = rand() % 3 + 1;

        // The random number will be the door that has the prize
        cout << "The door with the prize is door number " << doorWithPrize << endl;

        // For example, if 1 is the random number, then door 1 will have the prize.
        int response {doorWithPrize};
        int selection2;
        cout << "Value of selection 2 on line 27:   " << selection2 << endl;

        // The user will choose a door, either 1 OR 2 OR 3
        cout << "Choose a door, your options are 1, 2, 3    ";
        // cin >> response;
        
        // Case A: The user Picks the door that has the prize (1/3 chance)
            // I want to reveal one of the two doors that don't have the prize (pick 1 of 2 doors at random)
        
        // Case B: The user picks the door that doesn't have the prize
            // I want to reveal the other door that doesn't have the prize (only 1 option)

        if (doorWithPrize == response) {
            // I need to pick from one of the two doors that don't have the prize
            int reveal {doorWithPrize};
            while (reveal == doorWithPrize) {
                // generate random number between 1 and 3
                srand(time(NULL));
                reveal = rand() % 3 + 1;
            }

            // output the door that is now opened
            cout << "You chose door number: " << response << endl;
            cout << "Shhhh, the prize is behind door number: " << doorWithPrize << endl;
            cout << "Ok, Door " << reveal << " is revealed to not have the prize." << endl;
            
            // Ask the User if they would like to switch doors
            cout << "Would you like to switch your door? Reply with either a 'Y' OR 'N'     ";
            // Take the answer if they would like to switch doors
            char switchDoorRes {'N'};
            //cin >> switchDoorRes;
            selection2 = reveal;
            if (switchDoorRes == 'Y'){
                // create something called selection2
                // selection2 must be the only remaining closed door
                while(selection2 != reveal && selection2 != response) {
                    srand(time(NULL));
                    selection2 = rand() % 3 + 1;
                }
                cout << "You elected to switch doors. Your selected door is now:    Door " << selection2 << endl; 
            }
            else if (switchDoorRes == 'N') {
                selection2 = response;
                if (selection2 != response) {
                    cout << "There was a problem..." << endl;
                } else {
                    cout << "You chose to not switch doors. Your selected door remains:     Door " << selection2 << endl;
                }
            }
            else {
                cout << "You gave an invalid response to switching doors" << endl;
            }
        }
        cout << endl;
        cout << endl;



        cout << doorWithPrize << endl;
        cout << selection2 << endl;

        // Reveal if they won the prize
        if (doorWithPrize == selection2) {
            cout << "Congratulations, you won the prize!" << endl;
            wins++;

        } else {
            cout << "Sorry you did not win the prize..." << endl;
            losses++;
        }
        cout << "Current tally of wins:     " << wins << endl;
        cout << "Current tally of losses:   " << losses << endl;
    }
    cout << "Number of Wins:    " << wins << endl;
    cout << "Number of Losses:  " << losses << endl;
    return 0;
}

// Suppose Door 2 has the prize
// User picks Door 2

// Lines Hardcoded 56 and 57 and 31