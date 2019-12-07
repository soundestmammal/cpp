#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include <ctime>
#include <random>
#include <queue>
#include "BCS370_queueBase.h"
#include "linkedList.h"
#include "queueWrapper.h"
#include "llqueue.h"

// Function Prototype
int generateZeroToThree(std::random_device &seed);
int generateMinMax(std::random_device &seed);
void userInput(std::random_device &seed, std::string &f);
void randomStream(std::string filename, int length,  std::random_device &seed);
bool testStream(std::string f);

int main() {
    std::random_device rd;
    bool working = true;

    std::cout << "Please select from the following menu options" << std::endl;
    std::cout << "Enter a single digit corresponding to the option" << std::endl;
    std::cout << "Option 1:\tExit\n";
    std::cout << "Option 2:\tRun Random Stream\n";
    std::cout << "Option 3:\tRun Test Stream\n";
    std::cout << "Option 4:\tRun Random Stream & Run Test Stream\n";
    
    int response;
    std::cin >> response;

    // Log error if response is out of bounds
    if(response < 1 || response > 4) {
        std::cerr << "There is an error at line" << __LINE__ << std::endl;
        exit(1);
    }

    std::cout << "I selected " << response << std::endl;

    // Respond to User Response
    if(response == 1) {
        std::cout << "Exiting the Menu" << std::endl;
    } else if( response == 2) {
        std::string f;
        userInput(rd, f);
    } else if (response == 3) {
        // Run test stream on a file provided
        // Ask for the file name
        std::string f;
        std::cout << "Enter a file name: ";
        std::cin >> f;
        working = testStream(f);
        
    } else if (response == 4) {

            std::string f;
            userInput(rd, f);

            // Tell the user if it passed or failed
            working = testStream(f);
    } else {
        std::cerr << "Something is really bad" << std::endl;
        exit(1);
    }

    if(!working) {
        std::cerr << "Something is really bad" << " on line number " << __LINE__ << std::endl;
        return 1;
    } else {
        std::cout << "CONGRATS ALL OF YOUR TESTS ARE PASSING! NICE JOB!" << std::endl;
        return 0;
    }
}

bool testStream(std::string f) {
    // Create three Queues
    farmingdale::llqueue q1;
    farmingdale::queueWrapper q2;
    farmingdale::queue q3;

    // Create an fstream object and try and open
	std::fstream file;
	file.open(f);

    // Handle error
	if(!file) {
		std::cerr << "I was not able to locate that file... " << __LINE__ <<  std::endl;
        return false;
	}

    // Item is a temp string variable
	std::string item;

    // Counter to track which line number
    int lineNumber = 0;

    // Begin to Parse the file
	while(getline (file, item)) {

        // Used for displaying output during testing
        lineNumber++;
        std::cout << lineNumber;

	    if('C' == item[0]) {
		    std::cout << "\tNOTHING: This was a C";
	    } 
        /*
            D is for Dequeue!
        */
        else if('D' == item[0]) {           
            
            // Create string variables to compare returned values
            std::string passMeBack1, passMeBack2, passMeBack3;
            farmingdale::statusCode status1, status2, status3;

            // Dequeue all three queues, capture return value and the status
            status1 = q1.dequeue(passMeBack1);
            status2 = q2.dequeue(passMeBack2);
            status3 = q3.dequeue(passMeBack3);

            // All three statuses should be the same
            if (status1 != status2) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            if(status2 != status3) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            // All three should pass back the same value
            if (passMeBack1 != passMeBack2) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            if (passMeBack2 != passMeBack3) {
                std::cout << "The value of q1 is:   " << passMeBack1 << std::endl;
                std::cout << "The value of q2 is:   " << passMeBack2 << std::endl;
                std::cout << "The value of q3 is:   " << passMeBack3 << std::endl;
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;                
            }
            
        } 
                
        else if('E' == item[0]) {
                // If 1 is empty, the other two better be empty!
                if(q1.isEmpty()) {
                    if (!q2.isEmpty() || !q3.isEmpty()) {
                        return false;
                    }
                } 
                else {
                    if(!q1.isEmpty()) {
                        if(q2.isEmpty() || q3.isEmpty()) {
                            return false;                            
                        }
                    }
                }
                // std::cout << "\tISEMPTY: " << q1.isEmpty() << " " << q2.isEmpty() << " " << q3.isEmpty();
        } 
        
        else if ('P' == item[0]) {
            // Create string variables to compare returned values
            std::string passMeBack1, passMeBack2, passMeBack3;
            farmingdale::statusCode status1, status2, status3;

            // PEEK all three queues, capture return value and the status
            status1 = q1.peek(passMeBack1);
            status2 = q2.peek(passMeBack2);
            status3 = q3.peek(passMeBack3);

            // All three statuses should be the same
            if (status1 != status2) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            if (status2 != status3) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            // All three should pass back the same value
            if (passMeBack1 != passMeBack2) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            if (passMeBack2 != passMeBack3) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;                
            }

	    } else if('S' == item[0]) {
		    std::cout << "\tNOTHING: This was an S";
	    }
        
        else {
            std::string value = item.substr(2);
            
            // Create string variables to compare returned values
            // std::string passMeBack1, passMeBack2, passMeBack3;
            farmingdale::statusCode status1, status2, status3;

            // PEEK all three queues, capture return value and the status
            status1 = q1.enqueue(value);
            status2 = q2.enqueue(value);
            status3 = q3.enqueue(value);

            // All three statuses should be the same
            if (status1 != status2) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            if(status2 != status3) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            // CONSOLE LOG
            //std::cout << "\tEnqueue: Q_1 and Q_2 and Q_3 all push " << value << " the top of the Queues have " << passMeBack1 << " " << passMeBack2 << " " << passMeBack3 << " ";
        }
        // FOR CONSOLE
        std::cout << "\n";
	}
    return true;
}

void userInput(std::random_device &seed, std::string &f) {
    int l;
    std::cout << "Enter a file name: ";
    std::cin >> f;
    std::cout << "Enter a length:  ";
    std::cin >> l;
    if (l <= 0 || f == "") {
        std::cerr << "This is a problem at line " << __LINE__ << std::endl;
        exit(1);
    }
    randomStream(f, l, seed);
}

void randomStream(std::string filename, int length,  std::random_device &seed) {

    int randZeroToFive;
    std::ofstream output;
    output.open(filename);

    for (int i = 0; i < length; i++) {
        
        randZeroToFive = generateZeroToThree(seed);

        // if (i >= 10 && i <= 7500) {
        //     randZeroToFive = 0;
        // }

        // if (i >= 7501 && i <= 16000) {
        //     randZeroToFive = 1;
        // }
        

        switch(randZeroToFive) {
            case 0:
                output << "A" << " " << generateMinMax(seed) << std::endl;
                break;
            case 1:
                output << "D" << std::endl;
                break;
            case 2:
                output << "P" << std::endl;
                break;
            case 3: 
                output << "E" << std::endl;
                break;
            // case 4:
            //     output << "C" << std::endl;
            //     break;
            // case 5:
            //     output << "S" << std::endl;
            //     break;
            default:
                output << "Something is wrong!" << std::endl;
                break;
        }
         
    }
    output.close();

}

int generateZeroToThree(std::random_device &seed) {
    // random_device rd;  // seeding a random number rd
    // Create an object called gen of type mersenne twister engine
    // The constructor accepts a seed or a seed sequence
    std::mt19937 gen(seed());  
    std::uniform_int_distribution<> dis(0, 3); // set bounds of dist
    return dis(gen);
}

int generateMinMax(std::random_device &seed) {
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> dis(INT_MIN, INT_MAX);
    return dis(gen);
}
