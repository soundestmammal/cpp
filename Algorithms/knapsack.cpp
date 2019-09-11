// (c) 2018 David Gerstl, all rights reserved
#include <vector>  // for the STL vector type
#include <iostream>  // for cout
#include <string>  // for operator<<(stream,string)
#include "knapsack.h"

using namespace farmingdale;


std::vector<bool> knapsack::knapsackSolve(int capacity, int &totalValue, int &numberOfConfigsChecked) {
	// these two create an STL Vector of the same size as the number of items in "items" all set to false. 
	std::vector<bool> workingVector(items.size());
	std::fill(workingVector.begin(), workingVector.end(), false); // all false so far

	std::vector<bool> submitVector(items.size());
	std::fill(workingVector.begin(), workingVector.end(), false); // all false so far

	totalValue = 0;                    // no value so far
	numberOfConfigsChecked = 0;
	// try some subset of the 2^n posibilities, return the one with the best objective (total value)

	// YOU NEED TO WRITE A SOLVER--EITHER HERE OR A FUNCTION TO CALL
	// It should modify workingVector (you can treat it as an array of bool) to show which to include in the solution
	// and set totalValue and numberOfConfigsChecked
	int currentCapacity = 0;
		for(int i = items.size()-1; i >= 0; i--) {
			if((currentCapacity + items[i].weight) > capacity) {
				return workingVector;
			} else {
				workingVector[i] = true;
				totalValue += items[i].value;
				currentCapacity += items[i].weight;
				std::cout << totalValue << std::endl;
			}
			numberOfConfigsChecked++;
		}

		// If the totalvalue for this instance is greater than in the past,


		// I want to copy the values from workingVector to submitVector
		// for (int i = 0; i < workingVector.size(); i++)
		// {
		// 	submitVector[i] = workingVector[i];
		// }
		


	return workingVector;
}



// These methods are written already

status knapsack::addItem(int weight, int value) {
	item thisItem;
	thisItem.value = value;
	thisItem.weight = weight;
	items.push_back(thisItem);
	return SUCCESS;
}




void knapsack::print(std::vector<bool> included) {
	std::cout << "\tValue\t\tWeight\t\tIncluded?\n";
	int count = 0;
	for (std::vector<item>::iterator iIter = items.begin(); iIter != items.end(); ++iIter) {
		std::string thisInc = (0 == included.size()) ? "No" : ((included[count]) ? "Yes" : "No");
		std::cout << "\t" << iIter->value << " \t\t" << iIter->weight << " \t\t" << thisInc << std::endl;
			++count;
	} // for (std::vector<item>::iterator
}