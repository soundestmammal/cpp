#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

// Function Prototype Stuff
void firstReveal(int firstSelection, int& reveal, vector<int>& doors);
int automatedDoorSelection();
string stickWithFirstDoor();
string alwaysSwitchDoors();
void determineWinOrLoss(int& wins, int& losses, int doorWithPrize, int finalSelection);

int main() {

    // Variables
    int wins {};
    int losses {};
    int firstSelection {};
    int finalSelection = -1;
    int reveal {};
    bool alwaysSwitch = false; // true -> 66% ; false -> 33%
    string switchDoorRes {};

    // Randomly Generate a number 0-2 to determine which door has the prize
    srand(time(NULL));

    for (long i = 0; i < 10000; i++) {
        int doorWithPrize = rand() % 3;
        vector <int> doors {0, 0, 0};
        doors[doorWithPrize] = 1;

        firstSelection = automatedDoorSelection();
        
        // This runs when they select door with the prize
        if (doorWithPrize == firstSelection) {
            
           // A function that passes reveal by reference to be modified.
           firstReveal(firstSelection, reveal, doors);

            if (alwaysSwitch) {
                switchDoorRes = alwaysSwitchDoors();
            } else {
                switchDoorRes = stickWithFirstDoor();
            }

            if (switchDoorRes == "yes") {
                // finalSelection must be the only remaining closed door
                for (int i = 0; i < doors.size(); i++) {
                    if (doors[i] == 0) finalSelection = i;
                }
            } else if (switchDoorRes == "no") {
                finalSelection = firstSelection;
            }
        }   else {
            // They chose the door that doesn't have the prize
            // This is the case where I need to show them the only remaining door
            doors[firstSelection] = 2;
            int toReveal {};
            for (int i = 0; i < doors.size(); i++) {
                if (doors[i] == 0) toReveal = i;
            }

            if (alwaysSwitch) {
                switchDoorRes = alwaysSwitchDoors();
            } else {
                switchDoorRes = stickWithFirstDoor();
            }
             
            if (switchDoorRes == "yes"){
                /* If they want to switch doors:
                    They must have chosen the incorrect door initially
                    therefore if they switch, they must switch to the one that has the prize
                    if they don't switch, then final <- first
                 */
                finalSelection = doorWithPrize;
            }
            else if (switchDoorRes == "no") {
                finalSelection = firstSelection;
            }
            else {
                cout << "You gave an invalid firstSelection to switching doors" << endl;
            }
        }

        // Compare doors and increment appropriate W/L counter
        determineWinOrLoss(wins, losses, doorWithPrize, finalSelection);
    }
    cout << "Number of Wins:    " << wins << endl;
    cout << "Number of Losses:  " << losses << endl;
    
    return 0;
}


/*
Possible Cases
    1. They pick the left door, and they pick the prize
    2. They pick the center door, and they pick the prize
    3. They pick the right door, and they pick the prize
*/

void firstReveal(int firstSelection, int& reveal, vector<int>& doors) {
    switch(firstSelection) {
        case 0: {
            reveal = rand() % 2 + 1;
            break;
        };
        case 1: {
        int choice =  rand() % 2;
            if (choice) {
                reveal = 2;
            } else {
                reveal = 0;
            }
            break;
        };
        case 2: {
            reveal = rand() % 2;
            break;
        };
        default: 
        cout << "The default ran this shouldn't happen" << endl;
        break;
    }
    doors[reveal] = -1;
}

void determineWinOrLoss(int& wins, int& losses, int doorWithPrize, int finalSelection) {
    if (doorWithPrize == finalSelection) {
            wins++;
        } else {
            losses++;
        }
        cout << "Current tally of wins:     " << wins << endl;
        cout << "Current tally of losses:   " << losses << endl;
}

string automatedSwitchDoor() {
    int num = rand() % 2;
    if(num) {
        return "yes";
    } else {
        return "no";
    }
}

int automatedDoorSelection() {
    int num = rand() % 3;
    return num;
}

string alwaysSwitchDoors() {
    return "yes";
}

string stickWithFirstDoor() {
    return "no";
}






        // Case A: The user Picks the door that has the prize (1/3 chance)
            // I want to reveal one of the two doors that don't have the prize (pick 1 of 2 doors at random)
        
        // Case B: The user picks the door that doesn't have the prize
            // I want to reveal the other door that doesn't have the prize (only 1 option)

            /*
What is the problem solving approach?

    0. Ask the user to pick one of the three doors

Either:

    A. They Pick the door with the prize
        a. Randomly reveal one of the other two doors (Switch Statement)
    B. They Pick the door without the prize
        a. Reveal the only possible door

Then
    3. Ask if they would like to switch

        a. They switch
        b. They don't switch

*/