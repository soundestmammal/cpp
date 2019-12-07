
#include "priorityQueue.h"
#include <iostream>
#include <climits>
using namespace farmingdale;

// Please make 4 copies of this project with different names. 
// Implement each algorithm in one copy.

status priorityQueue::insert(int insertMe) {
	++inserts;

	pq.push_back(insertMe);
	return SUCCESS;
	// This method should try to insert "insertMe" into the 
	// priorityQueue, then return SUCCESS. If it cannot, 
	// it should return FAILURE

}

status priorityQueue::findMin(int &putTheMinHere) {
	if(pq.size() != 0) {
		int min = __INT_MAX__;
		// This method should put the minimum value in "putTheMinHere" and
		for (int i = 0; i < pq.size(); i++)
		{
			++findMins;
			if(pq[i] < min) {
				min = pq[i];
			}
		}
		putTheMinHere = min;
		return SUCCESS;
		// return SUCCESS. If it cannot (i.e., if the queue is empty),
		// return FAILURE
	}
	return FAILURE;
}

status priorityQueue::removeMin() {
	if(pq.size() != 0) {
		int min = __INT_MAX__;
		int index = INT_MIN;
		for (int i = 0; i < pq.size(); i++)
		{
			++deletions;
			if(pq[i] < min) {
				min = pq[i];
				index = i;
			}
		}

		// Swap the min item and the last elements
		pq[index] = pq.back();
		pq.pop_back();
		return SUCCESS;

		// return SUCCESS. If it cannot (i.e., if the queue is empty),
		// return FAILURE
	}
	// this should simply remove the min item 
	// and return SUCCESS. If it cannot (i.e., if the queue is empty),
	// return FAILURE
	return FAILURE;
}
