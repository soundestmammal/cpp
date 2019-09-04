// (c) 2013-2019 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates


// Class farmingdale::stack: General integer stack implementation based on array. 
// We will add dynamic arrays (for unlimited size), templates (to allow multiple types) etc.

// very minimal set of tests. 
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <regex>
#include "BCS370_arrayBasedStack.h"

//using  farmingdale::FAILURE;
//using  farmingdale::SUCCESS;
//using  farmingdale::stack;

bool normalTest();
bool copyCtorTest();
void testStack();
void doSomething(std::string s);

void myMemoryPlayFunction() {
	int* p = new int;
	std::cout << "Give an int room ";
	std::cin >> *p;
	std::cout << *p;
}

int main() {
	bool failed = false;
	failed = normalTest();
	if (!failed) {
		copyCtorTest();
	}
	if (false == failed) {
		std::cout << "Passed the [non-exhaustive] test." << std::endl;
	}

	// more portable method than system("pause");
	// getchar();

	testStack();

	return 0;
}

bool normalTest() {
	farmingdale::stack s1;
	for (int i = 0; i < s1.stackCapacity(); ++i) {
		if (farmingdale::FAILURE == s1.push(std::to_string(i + 1000))) {
			std::cerr << "Error on line " << __LINE__ << std::endl;
			return true;
		}
	}
	if (farmingdale::SUCCESS == s1.push(std::to_string(s1.stackCapacity() + 1000))) {
		std::cerr << "Error on line " << __LINE__ << std::endl;
		return true;
	}
	std::string j;
	std::string t;
	for (int i = 0; i < s1.stackCapacity(); ++i) {
		if (farmingdale::FAILURE == s1.peek(t) || farmingdale::FAILURE == s1.pop(j) ||
			t != j || j != std::to_string(1000 + s1.stackCapacity() - i - 1)) {
			std::cerr << "Error on line " << __LINE__ << " j is " << j << " and i is " << i
				<< " and t is " << t << std::endl;
			return true;
		}
	}
	return false;
}

bool copyCtorTest() {
	farmingdale::stack s1;
	for (int i = 0; i < s1.stackCapacity(); ++i) {
		if (farmingdale::FAILURE == s1.push(std::to_string(i + 1000))) {
			std::cerr << "Error on line " << __LINE__ << std::endl;
			return true;
		}
	}
	if (farmingdale::SUCCESS == s1.push(std::to_string(s1.stackCapacity() + 1000))) {
		std::cerr << "Error on line " << __LINE__ << std::endl;
		return true;
	}
	// copy s1 into s2
	farmingdale::stack s2(s1);
	std::string j;
	std::string t;
	for (int i = 0; i < s2.stackCapacity(); ++i) {
		if (farmingdale::FAILURE == s2.peek(t) || farmingdale::FAILURE == s2.pop(j) ||
			t != j || j != std::to_string(1000 + s2.stackCapacity() - i - 1)) {
			std::cerr << "Error on line " << __LINE__ << " j is " << j << " and i is " << i
				<< " and t is " << t << std::endl;
			return true;
		}
	}
	return false;
}

void testStack() {
	std::string f;
	std::cout << "What is the name of the file?  ";
	std::cin >> f;
	std::fstream file;
	file.open(f);
	if(!file) {
		std::cout << "I was not able to locate that file... " << std::endl;
		exit(1);
	}
	std::string item;
	while(getline (file, item)) {
		std::cout << item << std::endl;
		doSomething(item);
	}
}

void doSomething(std::string s) {
	if('C' == s[0]) {
		std::cout << "This was a C" << std::endl;
	} else if('D' == s[0]) {
		std::cout << "This was a D" << std::endl;
	} else if('E' == s[0]) {
		std::cout << "This was an E" << std::endl;
	} else if ('P' == s[0]) {
		std::cout << "This was a P" << std::endl; // Peak the stack
	} else if('S' == s[0]) {
		std::cout << "This was an S" << std::endl;
	} else {
		// This is when A is the thing... We want to push the numerical value onto the stack
		std::cout << s.substr(2, 100) << std::endl;
	}
}