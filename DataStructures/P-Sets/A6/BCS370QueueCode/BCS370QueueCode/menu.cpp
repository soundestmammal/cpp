#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include <ctime>
#include <random>
#include "BCS370_queueBase.h"

// Function Prototype
int generateZeroToThree(std::random_device &seed);
int generateMinMax(std::random_device &seed);
void userInput(std::random_device &seed);
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
        userInput(rd);
    } else if (response == 3) {
        // Run test stream on a file provided
        // Ask for the file name
        std::string f;
        std::cout << "Enter a file name: ";
        std::cin >> f;
        working = testStream(f);
        
    } else if (response == 4) {
        // Ask for a file name
            std::string f;
            int l;
            std::cout << "Enter a file name: ";
            std::cin >> f;
            std::cout << "Enter a length:  ";
            std::cin >> l;
            if (l <= 0 || f == "") {
                std::cout << "This is a problem!" << std::endl;
                exit(1);
            }
            userInput(rd);
            // Tell the user if it passed or failed

            working = testStream(f);
            // if(testStream(f)) {
            //     std::cout << "congrats! your test stream passed all tests" << std::endl;
            // } else {
            //     std::cout << "Sorry, some tests failed" << std::endl;
            // }


        // Run randomStream
        // Run testStream on the filename
        // Tell the user if it passed or failed
    } else {
        std::cerr << "Something is really bad" << std::endl;
        exit(1);
    }

    if(!working) {
        std::cerr << "Something is really bad" << " on line number " << __LINE__ << std::endl;
        return 1;
    } else {
        return 0;
    }

}

bool testStream(std::string f) {
    // Create two Queues
    farmingdale::queue q1;
    farmingdale::queue q2;
    farmingdale::queue q3;

    // Which file would you like to read?
	// std::cout << "What is the name of the file?  ";
	// std::cin >> f;

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
        lineNumber++;
        std::cout << lineNumber;
		// std::cout << "LOOK TO HERE TO SEE WHAT THE CONTENTS OF THE LINE WERE!!!     " << item << std::endl;

	    if ('C' == item[0]) {
		    std::cout << "\tNOTHING: This was a C";
	    } 

        /*
            D is for Dequeue!

            Top/Peek - Compare all three queues.

            It should only pass if all three are the same.

            I need to Dequeue from all three queues.

            
        */

        else if('D' == item[0]) {           
            
            // Create string variables to compare returned values
            std::string qa, qb, qc, qd, qe, qf;
            q1.peek(qc);
            q2.peek(qd);
            q3.peek(qf);

            // Check if they return failure, or if the peeked values are different.
            if (q1.dequeue(qa) != q2.dequeue(qb) || qa != qb) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            if(q1.isEmpty()) {
                std::cout << "\tDEQUEUE:  The Queue was empty and both returned FAILURE";
            } else {
                 // CONSOLE LOG
                std::cout << "\tQueue_1's top is " << qc << " queue value is " << qa << " Queue_2's top is " << qd << " dequeue value is " << qb;
            }
        } 
        
        
      
        
        /*
            E is for isEmpty().

            it should call isEmpty() on all three queues. 

            Acceptable cases:

                1. All true
                2. All false
        */
        
        
        
        
        else if('E' == item[0]) {
                if(q1.isEmpty()) {
                    if (!q1.isEmpty() || !q2.isEmpty()) {
                        return false;
                    }
                } 
                else {
                    if(q1.isEmpty() || q2.isEmpty()) {
                        return false;
                    }
                }
                std::cout << "\tISEMPTY: " << q1.isEmpty() << " " << q2.isEmpty();
        } 
        
        /*

        Peek: Compare all of the peeks. 

        All of the strings should be the same.


        */
        
        
        else if ('P' == item[0]) {
                // I need to fix this... peek is not really working...
                std::string c;
                std::string d;

            // std::cout << s1.peek(c) << std::endl;

            if(q1.peek(c) != q2.peek(d)) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            q1.peek(c);
            q2.peek(d);
            
            if(c != d) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            if(q1.isEmpty()) {
                std::cout << "\tPEEK: Unable to peek an empty queue";
            } else {
                std::cout << "\tPEEK: " << c << " " << d;
            }
        
		    // std::cout << "This was a P" << std::endl; // Peak the Queue
	    } else if('S' == item[0]) {
		    std::cout << "\tNOTHING: This was an S";
	    }
        
        
        /*
            This is where I enqueue

            I should do a is full to see if they are all the same

            Then I should enqueue and all three should return the same status code.

        */
        
        else {
            std::string value = item.substr(2,100);
            if(farmingdale::FAILURE == q1.enqueue(value) || farmingdale::FAILURE == q2.enqueue(value)) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }
            std::string c;
            std::string d;

            q1.peek(c);
            q2.peek(d);


            // CONSOLE LOG
            std::cout << "\tEnqueue: Q_1 and Q_2 both push " << value << " the top of the Queues have " << c << " " << d;
        }
        // FOR CONSOLE
        std::cout << "\n";
        //std::cout << s1.QueueCapacity() << std::endl;
	}
    return true;
}

void userInput(std::random_device &seed) {
    std::string f;
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

        if (i >= 10 && i <= 75) {
            randZeroToFive = 0;
        }

        if (i >= 76 && i <= 145) {
            randZeroToFive = 1;
        }
        

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