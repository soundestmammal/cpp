#include "priorityQueue.h"
#include <iostream>
#include <climits>
using namespace farmingdale;

// Please make 4 copies of this project with different names. 
// Implement each algorithm in one copy.

status priorityQueue::insert(int insertMe) {
	++inserts;
	if(minHeapPQ.size() == 0) {
		minHeapPQ.push_back(insertMe);
		currentMinVal = insertMe;
		currentMinIndex = 0;
		return SUCCESS;
	} else {
		if(insertMe < currentMinVal) {
			minHeapPQ.push_back(insertMe);
			currentMinVal = insertMe;
			currentMinIndex = minHeapPQ.size() - 1;
		} else {
			minHeapPQ.push_back(insertMe);
		}
	}
	return SUCCESS;
	
	// This method should try to insert "insertMe" into the 
	// priorityQueue, then return SUCCESS. If it cannot, 
	// it should return FAILURE
}

status priorityQueue::findMin(int &putTheMinHere) {
	++findMins;

	// I want to index the 0th value in the array.
	// array[0]

	putTheMinHere = currentMinVal;

	// This method should put the minimum value in "putTheMinHere" and
	// return SUCCESS. If it cannot (i.e., if the queue is empty),
	// return FAILURE
	return SUCCESS;
}

status priorityQueue::removeMin() {
	++deletions;
	// Can't find the min if it is empty
	if(minHeapPQ.size() == 0) {
		return FAILURE;
	}

	// The min is in the index. Swap with the length - 1 item.
	// Bubble down
	// I find the next min in logn time.

	// This is the min
	minHeapPQ[currentMinIndex] = minHeapPQ.back();
	currentMinVal = __INT_MAX__;
	minHeapPQ.pop_back();
	
	// Now I need to find the next min
	for (int i = 0; i < minHeapPQ.size(); i++) {
		++findMins;
		if(minHeapPQ[i] < currentMinVal) {
			currentMinVal = minHeapPQ[i];
			currentMinIndex = i;
		}
	}
	return SUCCESS;
	// this should simply remove the min item 
	// and return SUCCESS. If it cannot (i.e., if the queue is empty),
	// return FAILURE
}
