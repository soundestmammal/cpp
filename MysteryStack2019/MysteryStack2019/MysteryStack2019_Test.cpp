// (c) 2013-2019 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates


// Class farmingdale::stack: General integer stack implementation based on array. 
// We will add dynamic arrays (for unlimited size), templates (to allow multiple types) etc.

// very minimal set of tests. 
#include <iostream>
#include <string>
#include "mysteryStack.h"





bool normalTest();
bool copyCtorTest();

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
	getchar();

	return 0;
}

bool normalTest() {
	mystery::stack s1(16);
	for (int i = 0; i < s1.stackCapacity(); ++i) {
		if (mystery::FAILURE == s1.push(std::to_string(i + 1000))) {
			std::cerr << "Error on line " << __LINE__ << std::endl;
			return true;
		}
	}
	if (mystery::SUCCESS == s1.push(std::to_string(s1.stackCapacity() + 1000))) {
		std::cerr << "Error on line " << __LINE__ << std::endl;
		return true;
	}
	std::string j;
	std::string t;
	for (int i = 0; i < s1.stackCapacity(); ++i) {
		if (mystery::FAILURE == s1.peek(t) || mystery::FAILURE == s1.pop(j) ||
			t != j || j != std::to_string(1000 + s1.stackCapacity() - i - 1)) {
			std::cerr << "Error on line " << __LINE__ << " j is " << j << " and i is " << i
				<< " and t is " << t << std::endl;
			return true;
		}
	}
	return false;
}

bool copyCtorTest() {
	mystery::stack s1(16);
	for (int i = 0; i < s1.stackCapacity(); ++i) {
		if (mystery::FAILURE == s1.push(std::to_string(i + 1000))) {
			std::cerr << "Error on line " << __LINE__ << std::endl;
			return true;
		}
	}
	if (mystery::SUCCESS == s1.push(std::to_string(s1.stackCapacity() + 1000))) {
		std::cerr << "Error on line " << __LINE__ << std::endl;
		return true;
	}
	// copy s1 into s2
	mystery::stack s2(s1);
	std::string j;
	std::string t;
	for (int i = 0; i < s2.stackCapacity(); ++i) {
		if (mystery::FAILURE == s2.peek(t) || mystery::FAILURE == s2.pop(j) ||
			t != j || j != std::to_string(1000 + s2.stackCapacity() - i - 1)) {
			std::cerr << "Error on line " << __LINE__ << " j is " << j << " and i is " << i
				<< " and t is " << t << std::endl;
			return true;
		}
	}
	return false;
}