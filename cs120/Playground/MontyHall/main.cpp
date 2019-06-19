#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

// Function Prototypes
void doorLogger(int firstSelection, int doorWithPrize, int reveal);

/*
What is the problem solving approach?

    0. Ask the user to pick one of the three doors

Either:

    1. They Pick the door with the prize
        a. Randomly reveal one of the other two doors (Switch Statement)
    2. They Pick the door without the prize
        a. Reveal the only possible door

Then
    3. Ask if they would like to switch

        a. They switch
        b. They don't switch
    

*/

// I need to create three Doors
// enum { door1 = 1, door2 = 2, door3 = 3 };

int toReveal(vector<int> &doors) {
    int count {};
    for (int i = 0; i<doors.size(); ++i) {
        if(doors[i] == 0) {
            count++;
        }
    }
    // Will only execute if it is odd
    // AKA they didn't pick the correct door
    // Aka there is only one valid option
    // if (count % 2) {
        
    // }
}

int main() {
    int wins {};
    int losses {};
    // for (int i= 0; i<100; ++i) {
        // Randomly Generate a number 1-3 to determine which door has the prize
        srand(time(NULL));
        int doorWithPrize = rand() % 3 ;

        vector <int> doors {0, 0, 0};
        doors[doorWithPrize] = 1;

        // The random number will be the door that has the prize
        cout << "The door with the prize is door number " << doorWithPrize << endl;

        for (int i = 0; i < doors.size(); ++i) {
            cout << doors[i] << endl;
        }

        // For example, if 1 is the random number, then door 1 will have the prize.
        int firstSelection {};
        int finalSelection {};

        // cout << "Value of selection 2 on line 27:   " << finalSelection << endl;

        // The user will choose a door, either 1 OR 2 OR 3
        cout << "Choose a door, your options are 0, 1, 2    ";
        cin >> firstSelection;
        
        // This runs when they select door with the prize
        if (doorWithPrize == firstSelection) {

            // I need to pick from one of the two doors that don't have the prize
            int reveal {doorWithPrize};
            while (reveal == doorWithPrize) {
                // generate random number [0 - 2]
                srand(time(NULL));
                reveal = rand() % 3;
            }

            // Use a switch statement

            // What are the options

            /*
            Possible Cases
                1. They pick the left door, and they pick the prize
                2. They pick the center door, and they pick the prize
                3. They pick the right door, and they pick the prize
            */

            switch(firstSelection) {
                 case 0: {
                     break;
                 };
                 case 1: {
                     break;
                 };
                 case 2: {
                     break;
                 };
            }

            // output the door that is now opened

            // Log out the status of the doors
            // doorLogger(firstSelection, doorWithPrize, reveal);
            
            // Ask the User if they would like to switch doors
            cout << "Would you like to switch your door? Reply with either a 'Y' OR 'N'     ";
            // Take the answer if they would like to switch doors
            char switchDoorRes {'N'};
            //cin >> switchDoorRes;
            finalSelection = reveal;
            if (switchDoorRes == 'Y'){
                // finalSelection must be the only remaining closed door
                while(finalSelection != reveal && finalSelection != firstSelection) {
                    srand(time(NULL));
                    finalSelection = rand() % 3 + 1;
                }
                cout << "You elected to switch doors. Your selected door is now:    Door " << finalSelection << endl; 
            }
            else if (switchDoorRes == 'N') {
                finalSelection = firstSelection;
                if (finalSelection != firstSelection) {
                    cout << "There was a problem..." << endl;
                } else {
                    cout << "You chose to not switch doors. Your selected door remains:     Door " << finalSelection << endl;
                }
            }
            else {
                cout << "You gave an invalid firstSelection to switching doors" << endl;
            }
        } else {
            // They chose the door that doesn't have the prize
            // This is the case where I need to show them the only remaining door
            int toReveal {};
            for (int i = 0; i < doors.size(); i++)
            {
                if(doors[i] == 0) {
                    toReveal = i;
                }
            }

            // Ask them if they would like to change doors:


            

        }
        cout << endl;
        cout << endl;

        cout << doorWithPrize << endl;
        cout << finalSelection << endl;

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

void doorLogger(int firstSelection, int doorWithPrize, int reveal) {
    cout << "You chose door number: " << firstSelection << endl;
    cout << "Shhhh, the prize is behind door number: " << doorWithPrize << endl;
    cout << "Ok, Door " << reveal << " is revealed to not have the prize." << endl;
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