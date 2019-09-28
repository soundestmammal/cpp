//(c) 2018 David S.Gerstl, all rights reserved

#include <iostream>
#include <limits>
#include <cfloat>
#include <queue>
#include <vector>
#include "adjacencyList.h"

struct compare {
	bool operator()(const farmingdale::adjLink &a, const farmingdale::adjLink &b){
		return a.calcCost > b.calcCost;
	}
};

farmingdale::status farmingdale::adjacencyList::computeAStar(int fromNode, int toNode, int &length, int *returnList) {
	std::vector<int> ans;
	// note: the constant DBL_MAX is the max value double
	const double LARGE_DISTANCE = DBL_MAX / 2; // feel free to use as initial distance for all nodes
	length = 0;
	// You should print as you explore each node
	// When you complete, returnList[] should contain the list of nodes in order to get from fromNode to toNode
	// length should contain the full path length
	// and you should return SUCCESS
	std::priority_queue<adjLink, std::vector<adjLink>, compare> pq;

	int currentNode = fromNode;

	while(currentNode != toNode) {
		std::cout << "Currently exploring node number:	" << currentNode << std::endl;
		adjLink *currentEdge = list[currentNode].edges;


		while(currentEdge != NULL) {
			//std::cout << "This is the number of the currentNode: " << currentNode << std::endl;
			//std::cout << "This is the weight of the currentEdge" << currentEdge->weight << std::endl;
			std::cout << "This is the connects to node" << currentEdge->connectsToNode << std::endl;


			if(list[currentNode].distanceFromSource == 0) {
				currentEdge->calcCost = currentEdge->weight + slDistance(currentEdge->connectsToNode, toNode);
				list[currentEdge->connectsToNode].distanceFromSource = currentEdge->weight;
			} else {
				currentEdge->calcCost = list[currentNode].distanceFromSource + currentEdge->weight + slDistance(currentEdge->connectsToNode, toNode);
				list[currentEdge->connectsToNode].distanceFromSource = currentEdge->calcCost - slDistance(currentEdge->connectsToNode, toNode);
			}

			// I need to update the distanceFromSource of the child nodes or currentEdge->connectsToNode->DISTANCE... = current-
			list[currentEdge->connectsToNode].parent = currentNode;

			std::cout << "I am currently exploring node " << currentNode << " edges. " << std::endl;
			std::cout << currentNode << " goes to " << currentEdge->connectsToNode << std::endl;
			std::cout << "Therefore, the parent of " << list[currentEdge->connectsToNode].parent << " should equal " << currentNode << std::endl;
			std::cout << "About to push into the Queue" << std::endl;
			pq.push(*currentEdge);

			currentEdge = currentEdge->next;
		}

		//while(!pq.empty()) {
			currentNode = pq.top().connectsToNode;
			if(currentNode == toNode) {
				// std::cout << list[currentNode].parent << std::endl;
				ans.push_back(toNode);
				int currentParent = toNode;
				while(currentParent != 0) {
					currentParent = list[currentParent].parent;
					std::cout << "Going to push: " << currentParent;
					std::cout << "\n";
					ans.push_back(currentParent);
				}
			}
			std::cout << "This is the min calc cost	" << pq.top().calcCost << std::endl;

			pq.pop();
		//}
		std::cout << "\n\n\n";
	}
	for (int i = 0; i < ans.size(); i++)
	{
		std::cout << ans.at(i) << "\t";
	}
	
	length = ans.size();
	for (int i = 0; i < ans.size(); i++)
	{
		*(returnList + i) = ans[4-i];
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << *(returnList + i) << std::endl;
	}
	
	std::cout << std::endl;
	

	
	return SUCCESS;
}

/*
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

	*/