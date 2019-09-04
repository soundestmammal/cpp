// (c) 2013-2019 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates


// Class farmingdale::stack: General integer stack implementation based on array. 
// We will add dynamic arrays (for unlimited size), templates (to allow multiple types) etc.

#include <string>
#include "BCS370_arrayBasedStack.h"
farmingdale::stack::stack() 
	:
	countOfItems(0)  // initialization list is preferred over assignment in ctor
{
//	countOfItems = 0; // almost equivalent
	// Ask the system to allocate storage
	data = new std::string[INITIAL_STACK_SIZE];
}
// only a stub. Not written
farmingdale::stack::stack(const stack& copyMe) 
	:
	// Step 1: Copy the count of items
	countOfItems(copyMe.countOfItems),
	currentStackSize(copyMe.currentStackSize)
{
	data = new std::string[currentStackSize];
	// Step 2: Copy the bottom count of items
	for (int i = 0; i < countOfItems; i++)
	{
		data[i] = copyMe.data[i];
	}
}

// Methods
bool farmingdale::stack::operator==(stack s2) {
	// check the counts
	if(countOfItems != s2.countOfItems) {
		return false;
	}
	for (int i = 0; i < countOfItems; i++)
	{
		if(data[i] != s2.data[i]) {
			return false;
		}
	}
	return true;
}

farmingdale::statusCode farmingdale::stack::push(std::string addMe) {

	/*
	This is going to be the new push algorithm, for a stack

	If the truck is not big enough, then we want to get one that is twice the size
	move the stuff into the new truck
	return the old truck
	update the size of our current truck
	put the box in the truck
	increment the box counter

	*/

	if (isFull()) {
		return FAILURE;
	}
	data[countOfItems] = addMe;
	++countOfItems;
	return SUCCESS;
}

farmingdale::statusCode farmingdale::stack::pop(std::string &returnedElement) {
	if (isEmpty()) {
		return FAILURE;
	}
	returnedElement = data[countOfItems - 1];
	--countOfItems;
	return SUCCESS;
}
farmingdale::statusCode farmingdale::stack::peek(std::string &returnedElement) const {
	if (isEmpty()) {
		return FAILURE;
	}
	returnedElement = data[countOfItems - 1];
	return SUCCESS;
}

