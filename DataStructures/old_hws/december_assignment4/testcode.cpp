#include <string>
#include <iostream>
#include <climits>
#include <fstream>
#include <random>
#include "BCS370_arrayBasedStack.h"
#include "stackWrapper.h"


// Function Prototypes
int generateZeroToFive(std::random_device &seed); // Generates a random number [0,5], used to generate random streams file
int generateMinMax(std::random_device &seed); // Generates a random number for the A case ex. "A 4579375433"
std::string userInput(std::random_device &seed); // Handles user input then calls random stream, aka set of operations, returns filename (string)
void randomStream(std::string filename, int length,  std::random_device &seed); // Generates a random streams file
int testStream(std::string fileName); // function for the test code, tests three stacks
void viewOutput(std::string a, std::string b, std::string c); // used for testing, uncomment in code to see the console output


int main() {

	bool flag = true;
	
	// Create a seed
    std::random_device rd;

	while(flag) {
		std::cout << "\n";
		std::string response;
		std::cout << "Please select from the following menu options" << std::endl;
		std::cout << "1:\tExit\n";
		std::cout << "2:\tRun Random Stream\n";
		std::cout << "3:\tRun Test Stream\n";
		std::cout << "4:\tRun Random Stream & Run Test Stream\n";
		std::cin >> response;
		
		if("1" == response) {
			flag = false;
		}

		else if ("2" == response) {
			userInput(rd);
		}
		
		else if ("3" == response) {
			int result = 0;
			std::string f;
			std::cout << "Enter a file name: ";
			std::cin >> f;
			result = testStream(f);
			if(0 != result) {
				std::cout << "The test failed" << std::endl;
			} else {
				std::cout << "The test passed" << std::endl;
			}
		}

		else if ("4" == response) {
			int result = 0;
			std::string fileToRun; 
			fileToRun = userInput(rd);
			result = testStream(fileToRun);
			if(0 != result) {
				std::cout << "The test failed" << std::endl;
			} else {
				std::cout << "The test passed" << std::endl;
			}
		}
	}
    return 0;
}

std::string userInput(std::random_device &seed) {
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
	return f;
}

void randomStream(std::string filename, int length,  std::random_device &seed) {

    int randZeroToFive;
    std::ofstream output;
    output.open(filename);

    for (int i = 0; i < length; i++) {

        randZeroToFive = generateZeroToFive(seed);

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
            case 4:
                output << "C" << std::endl;
                break;
            case 5:
                output << "S" << std::endl;
                break;
            default:
                output << "Something is wrong!" << std::endl;
                break;
        }
         
    }
    output.close();

}

int generateZeroToFive(std::random_device &seed) {
    // random_device rd;  // seeding a random number rd
    // Create an object called gen of type mersenne twister engine
    // The constructor accepts a seed or a seed sequence
    std::mt19937 gen(seed());  
    std::uniform_int_distribution<> dis(0, 5); // set bounds of dist
    return dis(gen);
}

int generateMinMax(std::random_device &seed) {
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> dis(INT_MIN, INT_MAX);
    return dis(gen);
}

void doSomething(std::string s) {
	if('C' == s[0]) {
		// std::cout << "This was a C" << std::endl;
	} else if('D' == s[0]) {
		std::cout << "This was a D" << std::endl;
	} else if('E' == s[0]) {
		// std::cout << "This was an E" << std::endl;
	} else if ('P' == s[0]) {
		std::cout << "This was a P" << std::endl; // Peak the stack
	} else if('S' == s[0]) {
		// std::cout << "This was an S" << std::endl;
	} else {
		// This is when A is the thing... We want to push the numerical value onto the stack
		std::cout << s.substr(2) << std::endl;
	}
}

void viewOutput(std::string a, std::string b, std::string c) {
	std::cout << "A is: " << a << std::endl;
	std::cout << "B is: " << b << std::endl;
	std::cout << "C is: " << c << std::endl;
	if(a == b && b == c) {
		std::cout << "They are all the same \n\n\n\n\n" << std::endl;
	}

}

int testStream (std::string fileName) {

	std::fstream file;
	file.open(fileName);
	if(!file) {
		std::cerr << "I was not able to locate that file... error on line number " << __LINE__ << std::endl;
		return __LINE__;
	}
	std::string item;

	// Create the three Stacks
	farmingdale::stack s1;
	farmingdale::stack s2;
	farmingdale::stackWrapper s3;

	// int for line number of file.
	int lineNumber = 0;
	while(getline (file, item)) {
		++lineNumber;
		// std::cout << lineNumber << std::endl;
		// std::cout << item << std::endl;

		if('C' == item[0]) {
			//std::cout << "This was a C" << std::endl;
		} else if('D' == item[0]) {
			// std::cout << "This was a D" << std::endl;

			// Create three ref parameters
			std::string passMeBack1;
			std::string passMeBack2;
			std::string passMeBack3;

			// Create three status variables
			farmingdale::statusCode status1;
			farmingdale::statusCode status2;
			farmingdale::statusCode status3;

			// Peek all three stacks
			status1 = s1.pop(passMeBack1);
			status2 = s2.pop(passMeBack2);
			status3 = s3.pop(passMeBack3);

			// That all three status variables are the same
			if(status1 != status2) {
				std::cerr << "There was an error on line " << __LINE__ << std::endl;
				std::cerr << "The line number from the instruction file is " << lineNumber << std::endl;
				return lineNumber;
			}

			// At this point, status1 and status2 are the same, compare the third status to status of first two stacks.
			// Can use either status1 or status2
			if(status2 != status3) {
				std::cerr << "There was an error on line " << __LINE__ << std::endl;
				std::cerr << "The line number from the instruction file is " << lineNumber << std::endl;
				return lineNumber;
			}

			// At this point, status 1, 2, 3 are the same
			// If the stack was able to peek bc it wasn't empty, then I should check reference parameters.
			if (farmingdale::SUCCESS == status1) {
				if(passMeBack1 != passMeBack2) {
					std::cerr << "There was an error on line " << __LINE__ << std::endl;
					std::cerr << "The line number from the instruction file is " << lineNumber << std::endl;
					return lineNumber;
				}

				// At this point, status1 and status2 are the same, compare the third status to status of first two stacks.
				// Can use either status1 or status2
				if(passMeBack2 != passMeBack3) {
					std::cerr << "There was an error on line " << __LINE__ << std::endl;
					std::cerr << "The line number from the instruction file is " << lineNumber << std::endl;
					return lineNumber;
				}
			}
			// std::cout << "POP" << std::endl;
			// viewOutput(passMeBack1, passMeBack2, passMeBack3);	
		} else if('E' == item[0]) {
			// std::cout << "This was an E" << std::endl;
		} else if ('P' == item[0]) {
			// std::cout << "This was a P" << std::endl; // Peek the stack

			// Create three ref parameters
			std::string passMeBack1;
			std::string passMeBack2;
			std::string passMeBack3;

			// Create three status variables
			farmingdale::statusCode status1;
			farmingdale::statusCode status2;
			farmingdale::statusCode status3;

			// Peek all three stacks
			status1 = s1.peek(passMeBack1);
			status2 = s2.peek(passMeBack2);
			status3 = s3.peek(passMeBack3);

			// That all three status variables are the same
			if(status1 != status2) {
				std::cerr << "There was an error on line " << __LINE__ << std::endl;
				std::cerr << "The line number from the instruction file is " << lineNumber << std::endl;
				return lineNumber;
			}

			// At this point, status1 and status2 are the same, compare the third status to status of first two stacks.
			// Can use either status1 or status2
			if(status2 != status3) {
				std::cerr << "There was an error on line " << __LINE__ << std::endl;
				std::cerr << "The line number from the instruction file is " << lineNumber << std::endl;
				return lineNumber;
			}

			// At this point, status 1, 2, 3 are the same
			// If the stack was able to peek bc it wasn't empty, then I should check reference parameters.
			if (farmingdale::FAILURE != status1) {
				if(passMeBack1 != passMeBack2) {
					std::cerr << "There was an error on line " << __LINE__ << std::endl;
					std::cerr << "The line number from the instruction file is " << lineNumber << std::endl;
					return lineNumber;
				}

				// At this point, status1 and status2 are the same, compare the third status to status of first two stacks.
				// Can use either status1 or status2
				if(passMeBack2 != passMeBack3) {
					std::cerr << "There was an error on line " << __LINE__ << std::endl;
					std::cerr << "The line number from the instruction file is " << lineNumber << std::endl;
					return lineNumber;
				}
			}
			// std::cout << "PEEK" << std::endl;
			// viewOutput(passMeBack1, passMeBack2, passMeBack3);	
		} else if('S' == item[0]) {
			//std::cout << "This was an S" << std::endl;
		} else {
			// This is when A is the thing... We want to push the numerical value onto the stack
			std::string value = item.substr(2);

			// Create Three Statuses
			farmingdale::statusCode status1;
			farmingdale::statusCode status2;
			farmingdale::statusCode status3;

			// Push the value onto stack 1
			status1 = s1.push(value);

			// Push the value onto stack 2
			status2 = s2.push(value);

			// Push the value onto stack 3
			status3 = s3.push(value);

			// I need to compare the three statuses

			// Check that the first two statuses are the same
			if(status1 != status2) {
				std::cerr << "There was an error on line " << __LINE__ << std::endl;
				std::cerr << "The line number from the instruction file is " << lineNumber << std::endl;
				return lineNumber;
			}

			// At this point, status1 and status2 are the same, compare the third status to status of first two stacks.
			// Can use either status1 or status2
			if(status2 != status3) {
				std::cerr << "There was an error on line " << __LINE__ << std::endl;
				std::cerr << "The line number from the instruction file is " << lineNumber << std::endl;
				return lineNumber;
			}
		} // Else-block (push method)
	} // while loop
	file.close();
	return 0;
} // teststream