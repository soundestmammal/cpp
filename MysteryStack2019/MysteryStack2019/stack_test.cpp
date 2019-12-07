#include <iostream>
#include <string>
#include <fstream>
#include "stack.h"
#include "mysteryStack.h"

int testStream();

int main() {
    int response = testStream();
	if(0 == response) {
        std::cout << "congrats! your test stream passed all tests" << std::endl;
    } else {
        std::cout << "Sorry, some tests failed" << std::endl;
        std::cout << response << std::endl;
    }
	return 0;
}

int testStream() {
    // Create two stacks
    farmingdale::stack s1;
    farmingdale::stack s2;
    mystery::stack s3(20);

    // Which file would you like to read?
	std::string f;
	std::cout << "What is the name of the file?  ";
	std::cin >> f;

    // Create an fstream object and try and open
	std::fstream file;
	file.open(f);

    // Handle error
	if(!file) {
		std::cerr << "I was not able to locate that file... " << __LINE__ <<  std::endl;
        return __LINE__;
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

	    } 
        else if('D' == item[0]) {           
            
            // Create string variables to compare returned values
            std::string c, d, e;
            s1.peek(c);
            s2.peek(d);
            s3.peek(e);


            // Check if the peeked values are different.
            if((c != d || d != e)) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return __LINE__;
            }

        } else if('E' == item[0]) {
        } else if ('P' == item[0]) {
                std::string c;
                std::string d;
                std::string e;

            if(farmingdale::statusCode::FAILURE == s1.peek(c) && farmingdale::statusCode::FAILURE != s2.peek(d) && mystery::statusCode::FAILURE != s3.peek(e)) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return __LINE__;
            }

            // s1.peek(c);
            // s2.peek(d);
            // s3.peek(e);

            
            if(c != d || c != e) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return __LINE__;
            }
	    } else if('S' == item[0]) {
		    std::cout << "\tThis was an S";
	    } else {
            std::string value = item.substr(2,100);
            if((farmingdale::FAILURE == s1.push(value) && farmingdale::FAILURE != s2.push(value)) && mystery::FAILURE != s3.push(value)) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return __LINE__;
            }
            std::string c;
            std::string d;
            s1.peek(c);
            s2.peek(d);

        }
	}
    return 0;
}

/* Something totally went wrong here trying to compare all three stacks. I was fine comparing two stacks
but when I needed to see if all three returned the same thing then there became an issue. */