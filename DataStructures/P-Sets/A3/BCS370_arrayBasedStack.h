// (c) 2013-2019 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates


// Class farmingdale::stack: General integer stack implementation based on array. 
// We will add dynamic arrays (for unlimited size), templates (to allow multiple types) etc.

// note: This is not thread safe--there are no mutexes or locks on the indexes.

// like #pragma once but more portable
#ifndef H_BCS370_ARRAYBASEDSTACK
#define H_BCS370_ARRAYBASEDSTACK


namespace farmingdale {
	enum statusCode { SUCCESS, FAILURE }; // you will remove these when you create exceptions
};
namespace farmingdale {
	class stack;
};

class farmingdale::stack {
private:
	static const int INITIAL_STACK_SIZE = 20; // This should remain the initial size of the dynamic array
	std::string data[INITIAL_STACK_SIZE];			  // This should become a dynamic array

	int countOfItems; // index of the first empty spot
public: 
	stack(); // default ctor
	stack(const stack& copyMe); // copy ctor -- understand why this is passed by reference 

	// returns the current capacity. Used for testing and using this fixed size version
	inline int stackCapacity() const { return INITIAL_STACK_SIZE; } // returns the current queue capacity-will change in dynamic
	inline bool isEmpty() const { return (0 == countOfItems); } // know what the const here means
	inline bool isFull() const { return (stackCapacity()==countOfItems); }
	statusCode push(std::string addMe);
	statusCode pop(std::string &returnedElement);
	statusCode peek(std::string &returnedElement) const;
	// Hmmm, perhaps operator== ?
};


#endif // H_BCS370_ARRAYBASEDSTACK