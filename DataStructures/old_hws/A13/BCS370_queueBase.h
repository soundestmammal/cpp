// (c) 2013-2019 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates

// Class farmingdale::queue: General integer queue implementation. We will add dynamic arrays (for
// unlimited size), templates (to allow multiple types)

// like #pragma once but more portable
#ifndef H_BCS370_QUEUEBASE
#define H_BCS370_QUEUEBASE
#include <string>
#include <ostream>

namespace farmingdale {
	enum statusCode { SUCCESS, FAILURE }; // you will remove these when you create exceptions
	class queue;
	class queueWrapper;
	class Node;
	class LinkedList;
}

class farmingdale::queue {
private:
	int INITIAL_QUEUE_SIZE = 16; // This should remain the initial size of the dynamic array
	std::string *data;			  // This should become a dynamic array

	int oldestIndex;		// index of the oldest element in the queue
	int nextInsertIndex;	// index of the first empty spot
	int bufferSize;

	inline int queueCapacity() const { return bufferSize; } // returns the current queue capacity-will change in dynamic
	inline int getNextIndex(int index) const { return((index + 1) % queueCapacity()); } // give the address of the next index
public:
	queue();
	// not really necessary without dynamic array, but gives you a clue for operators and for copying into new memory
	queue(const queue& copyMe);

	// returns the minimum size without a reallocation of memory. Used for testing, but otherwise useless
	inline int minQueueSize() { return queueCapacity() - 1; }
	inline bool isEmpty() const { return (oldestIndex == nextInsertIndex); }
	inline bool isFull() { return (getNextIndex(nextInsertIndex) == oldestIndex); }
	statusCode enqueue(std::string addMe);
	statusCode dequeue(std::string &returnedElement);
	statusCode peek(std::string &returnedElement) const;
	// Some cool fun (I'll explain in class)

	friend std::ostream& operator<<(std::ostream& stream, const queue& rhs) {
		for (int i = rhs.oldestIndex; i != rhs.nextInsertIndex; i = rhs.getNextIndex(i)) {
			stream << rhs.data[i] << " ";
		}
		return stream;
	}

};


#endif // H_BCS370_QUEUEBASE