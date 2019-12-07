// (c) 2013-2019 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates


// Class farmingdale::stack: General integer stack implementation based on array. 
// We will add dynamic arrays (for unlimited size), templates (to allow multiple types) etc.

// very minimal set of tests. 
#include <iostream>
#include <string>
#include <fstream>
// #include "stack.h"

// using  farmingdale::FAILURE;
// using  farmingdale::SUCCESS;
// using  farmingdale::stack;

// bool normalTest(int testsize);
// bool copyCtorTest();

// void pushAll(std::string s);
// void peakAll();
// void popAll();
// void doSomething(std::string s);
bool testStream();

// int main() {

// 	if(testStream()) {
//         std::cout << "congrats! your test stream passed all tests" << std::endl;
//     } else {
//         std::cout << "Sorry, some tests failed" << std::endl;
//     }

// 	return 0;
// }

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
		    std::cout << "\tThis was a C";
	    } 
        else if('D' == item[0]) {           // This is when I POP!!!
            
            // Create string variables to compare returned values
            std::string a, b, c, d;
            s1.peek(c);
            s2.peek(d);

            // Check if they return failure, or if the peeked values are different.
            if(farmingdale::FAILURE == s1.pop(a) || farmingdale::FAILURE == s2.pop(b) || a != b) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            // CONSOLE LOG
            std::cout << "\tStack_1's top is " << c << " popped value is " << a << " Stack_2's top is " << d << " popped value is " << b;

        } else if('E' == item[0]) {
                std::cout << "\tThis was an E";
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
                std::cout << "\tPeak an Empty Stack";
            } else {
                std::cout << "\t" << c << "is equal to " << d;
            }
            
            if(c != d) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }
        
		    // std::cout << "This was a P" << std::endl; // Peak the stack
	    } else if('S' == item[0]) {
		    std::cout << "\tThis was an S";
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

// void pushAll(std::string s) {
//     std::cout << "This will push the string s into all of the stacks" << std::endl;
// };

// void peekAll() {
//     std::cout << "This will peek into all of the stacks" << std::endl;
// };

// void popAll() {
//     std::cout << "This will pop all of the stacks" << std::endl;
// };

// void doSomething(std::string s) {
// 	if('C' == s[0]) {
// 		std::cout << "This was a C" << std::endl;
// 	} else if('D' == s[0]) {
// 		// std::cout << "This was a D" << std::endl;
//         popAll();
// 	} else if('E' == s[0]) {
// 		std::cout << "This was an E" << std::endl;
// 	} else if ('P' == s[0]) {
//         peakAll();
// 		// std::cout << "This was a P" << std::endl; // Peak the stack
// 	} else if('S' == s[0]) {
// 		std::cout << "This was an S" << std::endl;
// 	} else {
// 		// This is when A is the thing... We want to push the numerical value onto the stack
// 		// std::cout << s.substr(2, 100) << std::endl;
//         std::string value = s.substr(2,100);
//         pushAll(value);
//     }
// }