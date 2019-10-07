// (c) 2013-2019 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates


// Class queue: General integer queue implementation. We will add dynamic arrays (for
// unlimited size), templates (to allow multiple types), operator overloading
// (for queue comparisons). 


// Please see the accompanying Powerpoint for some explanation of the 
// design and algorithms. If you come to office hours for explanations, 
// I will expect that you have read them

#include "BCS370_queueBase.h"
#include <iostream>
#include <new>

farmingdale::queue::queue()
	:
	nextInsertIndex(0),
	oldestIndex(0),
	bufferSize(INITIAL_QUEUE_SIZE)
{
	data = new std::string[bufferSize];
}

farmingdale::queue::queue(const queue& copyMe) 
// oldest starts at 0
// nextInsert starts at 0

{
	oldestIndex = copyMe.oldestIndex;
	bufferSize = copyMe.bufferSize;
	nextInsertIndex = 0;

	data = new std::string[bufferSize];

	// loop through copyMe, from oldest to nextInsert
	for (int i = copyMe.oldestIndex; i != copyMe.nextInsertIndex; i = getNextIndex(i)) {
		// put the item in the next slot in data
		data[nextInsertIndex] = copyMe.data[i];
		// advance the index (nextInsert) on data 
		// This actually will never roll over, so could be ++, but we'll leave it
		nextInsertIndex = getNextIndex(nextInsertIndex);
	}
}


// THIS IS NOT CIRCULAR DUDE
farmingdale::statusCode farmingdale::queue::enqueue(std::string addMe) {
	// if full, return FAILURE
	if (isFull()) {
		//return FAILURE;
		std::string *temp;
		try {
			temp = new std::string[bufferSize*2];
		} catch(std::bad_alloc &ba) {
			std::cerr << "There is an allocation problem on line number " << __LINE__ << std::endl;
			std::cerr << ba.what();
			return FAILURE;
		}
		int myCounter = 0;
		// from oldest to nextInsert
		std::cerr << "\n Reallocating buffer-old size= " << bufferSize << " new size= " << bufferSize*2 << std::endl;
		for (int i = oldestIndex; i != nextInsertIndex; i = getNextIndex(i)) {
			// put the item in the next slot in data
				temp[myCounter] = data[i];
				
				// std::cout << "This is the counter in else" << myCounter << std::endl;
			
			std::cout << "Counter " << myCounter << std::endl;
			std::cout << "Eye " << i << std::endl;
			myCounter++;
		}
		// advance the index (nextInsert) on data 
		// This actually will never roll over, so could be ++, but we'll leave it
		bufferSize = bufferSize*2;
		oldestIndex = 0;
		nextInsertIndex = myCounter;
		// nextInsertIndex = getNextIndex(nextInsertIndex);
		delete[] data;
		data = temp;
		data[nextInsertIndex] = addMe;
		nextInsertIndex = getNextIndex(nextInsertIndex);
	
		return SUCCESS;
	}
	// put the item at nextInsertIndex
	data[nextInsertIndex] = addMe;
	// move nextInsert
	nextInsertIndex = getNextIndex(nextInsertIndex);
	// return SUCCESS
	return SUCCESS;
}
farmingdale::statusCode farmingdale::queue::dequeue(std::string &returnedElement) {
	// if empty, return FAILURE
	if (isEmpty()) {
		return FAILURE;
	}
	// get the OLDEST item, put it in returnedElement
	// std::cout << data[oldestIndex] << std::endl;
	returnedElement = data[oldestIndex];
	// move the oldest item pointer to the next oldest item
	oldestIndex = getNextIndex(oldestIndex);
	// return SUCCESS
	return SUCCESS;
}
farmingdale::statusCode farmingdale::queue::peek(std::string &returnedElement) const {
	// if empty, return FAILURE
	if (isEmpty()) {
		return FAILURE;
	}
	// get the OLDEST item, put it in returnedElement
	returnedElement = data[oldestIndex];
	// return SUCCESS
	return SUCCESS;
}
