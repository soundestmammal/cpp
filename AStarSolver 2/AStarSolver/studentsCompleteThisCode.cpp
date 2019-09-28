//(c) 2018 David S.Gerstl, all rights reserved

#include <iostream>
#include <limits>
#include <cfloat>
#include <queue>
#include <vector>
#include "adjacencyList.h"

struct compare {
	bool operator()(const farmingdale::adjNode &a, const farmingdale::adjNode &b){
		return a.calculatedCost > b.calculatedCost;
	}
};

farmingdale::status farmingdale::adjacencyList::computeAStar(int fromNode, int toNode, int &length, int *returnList) {
	// note: the constant DBL_MAX is the max value double
	const double LARGE_DISTANCE = DBL_MAX / 2; // feel free to use as initial distance for all nodes
	length = 0;
	// You should print as you explore each node
	// When you complete, returnList[] should contain the list of nodes in order to get from fromNode to toNode
	// length should contain the full path length
	// and you should return SUCCESS
	std::priority_queue<adjNode, std::vector<adjNode>, compare> pq;

	// Access the first node and print out the adjacent edges
	int currentNode = fromNode;
	while(currentNode != toNode) {

		// Take the weight from the link
		adjLink *currentEdge = list[fromNode].edges;

		int tempConnectsToNumber;
		int tempWeight;
		while(currentEdge != NULL) {
			
			// Identify the node number
			tempConnectsToNumber = currentEdge->connectsToNode;

			// Set the parent
			if(list[tempConnectsToNumber].parent < 0)
			list[tempConnectsToNumber].parent = currentNode;

			// Identify the weight
			tempWeight = currentEdge->weight;

			// What is the euclidian distance
			// list[tempConnectsToNumber]

			if(tempConnectsToNumber == toNode) {
				std::cout << "There is a link to the final node" << std::endl;
				
			}
			
			// traverse the list
			currentEdge = currentEdge->next;

		}

		// After I have traversed all of the edges, I will need to make a decision
		
		// Push all of the edges into the priority queue?

		
		
		
		
		// I need to push the current node into the array

	}

		// Add it to the xcoord and ycoord  euclidian of the adjNode

		// Assign the cc to the adjNode
		// list[list[connectsToNode];
	
	
	// for (int i = 0; i < 5; i++)
	// {	
	// 	int item;
	// 	int* ptr = new int[5];
	// 	std::cout << "Enter first one" << std::endl;
	// 	std::cin >> item;
	// 	*(ptr + i) = item;
	// 	returnList = ptr;
	// }
	// length = 5;
	
	return SUCCESS;
}