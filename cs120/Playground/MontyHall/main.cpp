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
void doorLogger(int firstSelection, int doorWithPrize, int reveal, int finalSelection);
void firstReveal(int firstSelection, int& reveal, vector<int>& doors);

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


// int toReveal(vector<int> &doors) {
//     int count {};
//     for (int i = 0; i<doors.size(); ++i) {
//         if(doors[i] == 0) {
//             count++;
//         }
//     }
//     // Will only execute if it is odd
//     // AKA they didn't pick the correct door
//     // Aka there is only one valid option
//     // if (count % 2) {
        
//     // }
// }

int main() {
    int wins {};
    int losses {};
        // Randomly Generate a number 0-2 to determine which door has the prize
        srand(time(NULL));
        int doorWithPrize = rand() % 3 ;
        vector <int> doors {0, 0, 0};
        doors[doorWithPrize] = 1;

        // The random number will be the door that has the prize
        cout << "The door with the prize is door number " << doorWithPrize << endl;

        for (int i = 0; i < doors.size(); ++i) {
            cout << "The value behind door" << i << " is " << doors[i] << endl;
        }

        int firstSelection {};
        int finalSelection = -1;

        cout << "Choose a door, your options are 0, 1, 2    ";
        cin >> firstSelection;
        
        // This runs when they select door with the prize
        if (doorWithPrize == firstSelection) {
            int reveal {};

           // A function that passes reveal by reference to be modified.
           firstReveal(firstSelection, reveal, doors);

            // Log out the status of the doors
            doorLogger(firstSelection, doorWithPrize, reveal, finalSelection);


            /*What am I trying to do?
            1. Ask them if they would like to switch doors
                a. If yes, they will change their selected door
                b. If no, they will keep the door they have
             */
            
            string switchDoorRes {};
            cout << "Would you like to switch your door? Reply with either yes OR no     ";
            // Take the answer if they would like to switch doors
            cin >> switchDoorRes;
            if (switchDoorRes == "yes"){
                // finalSelection must be the only remaining closed door
                for (int i = 0; i < doors.size(); i++)
                {
                    if(doors[i] == 0) {
                        finalSelection = i;
                        cout << finalSelection << endl;
                    }
                }
            }
            else if (switchDoorRes == "no") {
                finalSelection = firstSelection;
            }
            else {
                cout << "You gave an invalid firstSelection to switching doors" << endl;
            }
            doorLogger(firstSelection, doorWithPrize, reveal, finalSelection);
        } else {
            // They chose the door that doesn't have the prize
            // This is the case where I need to show them the only remaining door
            doors[firstSelection] = 2;
            int toReveal {};
            for (int i = 0; i < doors.size(); i++)
            {
                if (doors[i] == 0) toReveal = i;
            }
            

            doorLogger(firstSelection, doorWithPrize, toReveal, finalSelection);

            // Ask them if they would like to change doors:
            string switchDoorRes {};
            cout << "Would you like to switch your door? Reply with either yes OR no     ";
            // Take the answer if they would like to switch doors
            cin >> switchDoorRes;
            if (switchDoorRes == "yes"){
                /* If they want to switch doors:
                    They must have chosen the incorrect door initially. 
                    ex. door 0 has prize, they chose 1, I open 2
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
            doorLogger(firstSelection, doorWithPrize, toReveal, finalSelection);
        }

        // Reveal if they won the prize
        if (doorWithPrize == finalSelection) {
            cout << "Congratulations, you won the prize!" << endl;
            wins++;

        } else {
            cout << "Sorry you did not win the prize..." << endl;
            losses++;
        }
        cout << "Current tally of wins:     " << wins << endl;
        cout << "Current tally of losses:   " << losses << endl;
    // }
    cout << "Number of Wins:    " << wins << endl;
    cout << "Number of Losses:  " << losses << endl;
    
    return 0;
}

void doorLogger(int firstSelection, int doorWithPrize, int reveal, int finalSelection) {
    cout << endl;
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Your first door choice was: " << firstSelection << endl;
    cout << "The prize is behind door number: " << doorWithPrize << endl;
    cout << "The gameshow host opens door: "<< reveal << endl;
    cout << "The final selection is:    " << finalSelection << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
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













// Suppose Door 2 has the prize
// User picks Door 2

// Lines Hardcoded 56 and 57 and 31

/*

Scenario 1:
    Prize behind door # 1
    Choose # 1
Scenario 2:
    Prize behind door # 1
    Choose # 2

*/




//        cout << "Value of selection 2 on line 27:   " << finalSelection << endl;

        // Case A: The user Picks the door that has the prize (1/3 chance)
            // I want to reveal one of the two doors that don't have the prize (pick 1 of 2 doors at random)
        
        // Case B: The user picks the door that doesn't have the prize
            // I want to reveal the other door that doesn't have the prize (only 1 option)