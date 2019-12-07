// (c) 2018 David S. Gerstl, all rights reserved

#include <iostream>
#include <queue> // STL Priority Queue
#include <random> // uniform int distribution
#include <vector> // for STL container
#include <functional> // for std::greater
#include "priorityQueue.h"

using namespace farmingdale;

status testComp1();

int main() {
	status soFar = SUCCESS;
	if (SUCCESS == soFar) {
		soFar = testComp1();
	}
	if (SUCCESS == soFar) {
		std::cout << "Passed\n";
	}
	char x;
	std::cin >> x;
}

status testComp1() {
	priorityQueue farmingdaleQ;
	// create an STL priority queue to compare with. This is smallest first.
	std::priority_queue<int, std::vector<int>, std::greater<int> > stlQ;

	// set up a random number generator with mersenne twister seed
	std::random_device rd;  
	std::mt19937 gen(rd()); 
	// random number between INT_MIN and INT_MAX
	std::uniform_int_distribution<> dis(INT_MIN, INT_MAX);

	// insert some ramdom number of items into the two queues >= MAX_QUEUE_SIZE
	std::uniform_int_distribution<> howManyDis(MAX_QUEUE_SIZE/2,MAX_QUEUE_SIZE);
	int count = howManyDis(gen);
	for (int i = 0; i < count; ++i) {
		int nextInsert = dis(gen);
		// note that by definition, our insert can fail- we check to make sure it doesn't.
		if (FAILURE == farmingdaleQ.insert(nextInsert)) {
			std::cerr << __FILE__ << ":" << __LINE__ <<
				"Hmm, on iteration " << i << " which is less than MAX_QUEUE_SIZE (" <<
				MAX_QUEUE_SIZE << ") the insert failed. Please fix this." << std::endl;
			return FAILURE;
		}
		stlQ.push(nextInsert);
	} // for i
	// now start removing and check they return the same list
	for (int i = 0; i < count; ++i) {
		if (stlQ.empty()) {
			std::cerr << __FILE__ << ":" << __LINE__ <<
				"Hmm, on iteration " << i << " which is less than MAX_QUEUE_SIZE (" <<
				MAX_QUEUE_SIZE << ") the STL queue reported it's empty. This is worrying..." << std::endl;
			return FAILURE;
		}
		// get the next STL number
		int stlResult = stlQ.top();
		// remove that item
		stlQ.pop();
		int farmingdaleResult;
		// get our number and remove it
		if (FAILURE == farmingdaleQ.findMin(farmingdaleResult) ||
			FAILURE == farmingdaleQ.removeMin()) {
			std::cerr << __FILE__ << ":" << __LINE__ <<
				"Hmm, on iteration " << i << "which is less than MAX_QUEUE_SIZE (" <<
				MAX_QUEUE_SIZE << ") the farmingdale queue reported it's empty. Fix this please." << std::endl;
			return FAILURE;
		}
		// compare them
		if (farmingdaleResult != stlResult) {
			std::cerr << __FILE__ << ":" << __LINE__ <<
				"Hmm, on iteration " << i << "which is less than MAX_QUEUE_SIZE (" <<
				MAX_QUEUE_SIZE << ") the farmingdale queue returned " << farmingdaleResult << 
				" but the STL queue returned " << stlResult <<". Fix this please." << std::endl;
			return FAILURE;
		}
	} // for i
	// print some stats
	farmingdaleQ.printStats();
	return SUCCESS;
}