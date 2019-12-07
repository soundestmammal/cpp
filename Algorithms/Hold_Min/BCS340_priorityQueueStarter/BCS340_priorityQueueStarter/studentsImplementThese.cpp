#include "priorityQueue.h"
#include <iostream>
#include <climits>
using namespace farmingdale;

// Please make 4 copies of this project with different names. 
// Implement each algorithm in one copy.

status priorityQueue::insert(int insertMe) {
	++inserts;
	if(pq.size() == 0) {
		pq.push_back(insertMe);
		currentMinVal = insertMe;
		currentMinIndex = 0;
		return SUCCESS;
	} else {
		if(insertMe < currentMinVal) {
			pq.push_back(insertMe);
			currentMinVal = insertMe;
			currentMinIndex = pq.size() - 1;
		} else {
			pq.push_back(insertMe);
		}
	}
	return SUCCESS;
	
	// This method should try to insert "insertMe" into the 
	// priorityQueue, then return SUCCESS. If it cannot, 
	// it should return FAILURE
}

status priorityQueue::findMin(int &putTheMinHere) {
	++findMins;

	putTheMinHere = currentMinVal;

	// This method should put the minimum value in "putTheMinHere" and
	// return SUCCESS. If it cannot (i.e., if the queue is empty),
	// return FAILURE
	return SUCCESS;
}

status priorityQueue::removeMin() {
	++deletions;
	// Can't find the min if it is empty
	if(pq.size() == 0) {
		return FAILURE;
	}

	// This is the min
	pq[currentMinIndex] = pq.back();
	currentMinVal = __INT_MAX__;
	pq.pop_back();
	
	// Now I need to find the next min
	for (int i = 0; i < pq.size(); i++) {
		++findMins;
		if(pq[i] < currentMinVal) {
			currentMinVal = pq[i];
			currentMinIndex = i;
		}
	}
	return SUCCESS;
	// this should simply remove the min item 
	// and return SUCCESS. If it cannot (i.e., if the queue is empty),
	// return FAILURE
}
