// (c) 2018 David S. Gerstl, all rights reserved

#include "priorityQueue.h"
#include <iostream>
using namespace farmingdale;


// written. Please make sure you update the "moves" counter in your insert() code.
void priorityQueue::printStats() {
	std::cout << "Hello there friend. Some stats on the queue so far:\n";
	std::cout << "\tCalls to insert(): " << inserts << "\n";
	std::cout << "\tCalls to deleteMinimum(): " << deletions << "\n";
	std::cout << "\tCalls to findMinimum(): " << findMins << "\n";
	std::cout << "\tNumber of moved items: " << moves << std::endl;

}
