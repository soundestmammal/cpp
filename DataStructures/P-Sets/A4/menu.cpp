#include "stack.h"
#include <iostream>
#include <string>
#include <fstream>
#include <climits>
#include <ctime>
#include <random>


// Function Prototype
int generateZeroToFive();
int generateMinMax();
void randomStream();
void randomStream(std::string filename, int length);
bool testStream(std::string f);

int main() {
    srand(time(NULL));
    // User Instructions
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
        std::cout << "test1" << std::endl;
        std::cout << "Exiting the Menu" << std::endl;
    } else if( response == 2) {
        std::cout << "test2" << std::endl;
        randomStream();
    } else if (response == 3) {
        std::cout << "test3"<< std::endl;
        // Run test stream on a file provided
        // Ask for the file name
        std::string f;
        std::cout << "Enter a file name: ";
        std::cin >> f;
        testStream(f);
        
    } else if (response == 4) {
        std::cout << "test4" << std::endl;
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
            randomStream(f, l);
            // Tell the user if it passed or failed
            if(testStream(f)) {
                std::cout << "congrats! your test stream passed all tests" << std::endl;
            } else {
                std::cout << "Sorry, some tests failed" << std::endl;
            }
        // Run randomStream
        // Run testStream on the filename
        // Tell the user if it passed or failed
    } else {
        std::cerr << "Something is really bad" << std::endl;
        exit(1);
    }



    return 0;
}

bool testStream(std::string f) {
    // Create two stacks
    farmingdale::stack s1;
    farmingdale::stack s2;

    // Which file would you like to read?
	// std::string f;
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
		//std::cout << item << std::endl;

	    if('C' == item[0]) {
		    std::cout << "\tNOTHING: This was a C";
	    } 
        else if('D' == item[0]) {           // This is when I POP!!!
            
            // Create string variables to compare returned values
            std::string a, b, c, d;
            s1.peek(c);
            s2.peek(d);

            // Check if they return failure, or if the peeked values are different.
            if(s1.pop(a) != s2.pop(b)|| a!=b) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            // CONSOLE LOG
            std::cout << "\tStack_1's top is " << c << " popped value is " << a << " Stack_2's top is " << d << " popped value is " << b;

        } else if('E' == item[0]) {
                std::cout << "\tNOTHING: This was an E";
        } else if ('P' == item[0]) {
                // I need to fix this... peek is not really working...
                std::string c;
                std::string d;

            // std::cout << s1.peek(c) << std::endl;

            if(s1.peek(c) != s2.peek(d)) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            s1.peek(c);
            s2.peek(d);

            if(lineNumber == 1) {
                std::cout << "\tPeek an Empty Stack";
            } else {
                std::cout << "\tPEEK: " << c << " is equal to " << d;
            }
            
            if(c != d) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }
        
		    // std::cout << "This was a P" << std::endl; // Peak the stack
	    } else if('S' == item[0]) {
		    std::cout << "\tNOTHING: This was an S";
	    } else {
            std::string value = item.substr(2,100);
            if(farmingdale::FAILURE == s1.push(value) || farmingdale::FAILURE == s2.push(value)) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }
            std::string c;
            std::string d;
            s1.peek(c);
            s2.peek(d);

            // CONSOLE LOG
            std::cout << "\tPUSH: Stack_1 and Stack_2 both push " << value << " the top of the stacks have " << c;
        }
        // FOR CONSOLE
        std::cout << "\n";
	}
    return true;
}
void randomStream() {
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
    randomStream(f, l);
}

void randomStream(std::string filename, int length) {

    int randZeroToFive;
    std::ofstream output;
    output.open(filename);

    for (int i = 0; i < length; i++) {

        randZeroToFive = generateZeroToFive();

        switch(randZeroToFive) {
            case 0:
                output << "A" << " " << generateMinMax() << std::endl;
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

int generateZeroToFive() {
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dis(0, 5);
    // return dis(gen);
    return (rand() % 6);
}

int generateMinMax() {
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dis(INT_MIN, INT_MAX);
    // return dis(gen);
    return (rand() % (rand()-1));
}