// (c) 2013-2019 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates


// Class farmingdale::stack: General integer stack implementation based on array. 
// We will add dynamic arrays (for unlimited size), templates (to allow multiple types) etc.

// note: This is not thread safe--there are no mutexes or locks on the indexes.

// like #pragma once but more portable
#ifndef H_BCS370_ARRAYBASEDSTACK
#define H_BCS370_ARRAYBASEDSTACK

#include <string>

namespace farmingdale {
	enum statusCode { SUCCESS, FAILURE }; // you will remove these when you create exceptions
};

namespace farmingdale {
	class stack;
};

class farmingdale::stack {
private:
	// PTR changed in dynamic allocation
	static const int INITIAL_STACK_SIZE = 20; // This should remain the initial size of the dynamic array
	std::string *data;	// PTR This should become a dynamic array
	int currentStackSize = INITIAL_STACK_SIZE; // PTR
	int countOfItems; // index of the first empty spot
public: 
	stack(); // default ctor
	stack(const stack& copyMe); // copy ctor -- understand why this is passed by reference 

	// returns the current capacity. Used for testing and using this fixed size version
	inline int stackCapacity() const { return currentStackSize; } // PTR returns the current queue capacity-will change in dynamic
	inline bool isEmpty() const { return (0 == countOfItems); } // know what the const here means
	inline bool isFull() const { return (stackCapacity()==countOfItems); }
	statusCode push(std::string addMe);
	statusCode pop(std::string &returnedElement);
	statusCode peek(std::string &returnedElement) const;
	// Hmmm, perhaps operator== ?
	bool operator==(stack s2);
};

inline bool operator!=(farmingdale::stack s1, farmingdale::stack s2) {
	return !(s1 == s2);
}


#endif // H_BCS370_ARRAYBASEDSTACK