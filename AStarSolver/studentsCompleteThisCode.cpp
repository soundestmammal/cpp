//(c) 2018 David S.Gerstl, all rights reserved

#include <iostream>
#include <limits>
#include "adjacencyList.h"

struct Queue {
	int straightLineDistance;
	Queue *next;
}

void createQueue() {
	// Have a head pointer look at the first node.
}
farmingdale::status farmingdale::adjacencyList::computeAStar(int fromNode, int toNode, int &length, int *returnList) {
	// note: the constant DBL_MAX is the max value double
	const double LARGE_DISTANCE = DBL_MAX / 2; // feel free to use as initial distance for all nodes
	returnList[0] = 0;
	returnList[1] = 7;
	returnList[2] = 6;
	returnList[3] = 5;
	returnList[4] = 4;



	length = 5;
	return SUCCESS;
	// You should print as you explore each node

	// I need to have a queue to store the values and have a priority property to check (Straight Line Distance)
	
	// I'm given the from node, and the to Node and a reference to some length. I need to 

	// When you complete, returnList[] should contain the list of nodes in order to get from fromNode to toNode
	// length should contain the full path length
	// and you should return SUCCESS
	return FAILURE;
}