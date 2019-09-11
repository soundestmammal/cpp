// (c) 2013-2019 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates


// Class queue: General integer queue implementation. We will add dynamic arrays (for
// unlimited size), templates (to allow multiple types), operator overloading
// (for queue comparisons). 


// Please see the accompanying Powerpoint for some explanation of the 
// design and algorithms. If you come to office hours for explanations, 
// I will expect that you have read them

// Note: I've ommitted test code to check the proper operation of some methods--don't doubt that they exist

#include <iostream>
#include <string>
#include "BCS370_queueBase.h"

// using  farmingdale::FAILURE;
// using  farmingdale::SUCCESS;
// using  farmingdale::queue;

void streamTest();


int main() {
	farmingdale::queue myq;
	bool failed = false;
	for (int i = 0; i < myq.minQueueSize(); ++i) {
		if (farmingdale::FAILURE == myq.enqueue(std::to_string(i + 1000))) {
			std::cerr << "Error on line " << __LINE__ << std::endl;
			failed = true;
		}
	}
	if (farmingdale::SUCCESS == myq.enqueue(std::to_string(myq.minQueueSize() + 1000))) {
		std::cerr << "Error on line " << __LINE__ << std::endl;
		failed = true;
	}
	std::string j;
	for (int i = 0; i < myq.minQueueSize(); ++i) {
		if (farmingdale::FAILURE == myq.dequeue(j) || j != std::to_string(1000 + i)) {
			std::cerr << "Error on line " << __LINE__ << " j is " << j << " and i is " << i << std::endl;
			failed = true;
		}
	}

	if (false == failed) {
		std::cout << "Passed the initial [non-exhaustive] ordering tests. Moving on to the stream test" << std::endl;
	}
	streamTest();

	// a more portable version of system("Pause");
	getchar();

	return 0;
}

void streamTest() {
	farmingdale::queue myq;
	for (int i = 0; i < myq.minQueueSize(); ++i) {
		if (farmingdale::FAILURE == myq.enqueue(std::to_string(i + 1000))) {
			std::cerr << "Error on line " << __LINE__ << std::endl;
		}
	}
	// test the stream insertion operator
	std::cout << "The next line should be the numbers from 1000 to " << 1000 + myq.minQueueSize() -1 << std::endl;
	std::cout << myq << std::endl;
}