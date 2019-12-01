#include <string>
#include <iostream>
#include <climits>
#include <fstream>
#include <random>
#include "BCS370_arrayBasedStack.h"


// Function Prototypes
int generateZeroToFive(std::random_device &seed);
int generateMinMax(std::random_device &seed);
std::string userInput(std::random_device &seed);
void randomStream(std::string filename, int length,  std::random_device &seed);
bool testStream(std::string fileName);

int main() {
	// Create a seed
    std::random_device rd;
	// Create a bunch of operations for the stack.
    std::string file = userInput(rd);

	bool failed = false;

	failed = testStream(file);

	if(failed) {
		std::cerr << "This failed inside of main at line number " << __LINE__ << std::endl;
		exit(1);
	}

	std::cout << "This passed the tests for this assignment" << std::endl;

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

bool testStream (std::string fileName) {
	std::fstream file;
	file.open(fileName);
	if(!file) {
		std::cerr << "I was not able to locate that file... error on line number " << __LINE__ << std::endl;
		return true;
	}
	std::string item;

	// Create the three Stacks
	farmingdale::stack s1;
	farmingdale::stack s2;
	farmingdale::stack s3;

	// int for line number of file.
	int lineNumber = 0;
	while(getline (file, item)) {
		++lineNumber;
		// std::cout << item << std::endl;

		if('C' == item[0]) {
			//std::cout << "This was a C" << std::endl;
		} else if('D' == item[0]) {
			std::cout << "This was a D" << std::endl;
		} else if('E' == item[0]) {
			// std::cout << "This was an E" << std::endl;
		} else if ('P' == item[0]) {
			std::cout << "This was a P" << std::endl; // Peek the stack
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
				return true;
			}

			// At this point, status1 and status2 are the same, compare the third status to status of first two stacks.
			// Can use either status1 or status2
			if(status2 != status3) {
				std::cerr << "There was an error on line " << __LINE__ << std::endl;
				std::cerr << "The line number from the instruction file is " << lineNumber << std::endl;
				return true;
			}
		} // Else-block (push method)
	} // while loop
	file.close();
	return false;
} // teststream