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
}
// only a stub. Not written
farmingdale::stack::stack(const stack& copyMe) {
	// uh oh, I should write this
}

farmingdale::statusCode farmingdale::stack::push(std::string addMe) {
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