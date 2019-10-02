// (c) 2018 David Gerstl, all rights reserved
#include <vector>  // for the STL vector type
#include <iostream>  // for cout
#include <string>  // for operator<<(stream,string)
#include "knapsack.h"

using namespace farmingdale;

void checkAllSubsets(std::vector<item> vect, std::vector<item> empty, std::vector<item> &tempSolution, int &totalValue, int &numConfigsChecked, int capacity, int index = 0);


std::vector<bool> knapsack::knapsackSolve(int capacity, int &totalValue, int &numberOfConfigsChecked) {
	// these two create an STL Vector of the same size as the number of items in "items" all set to false. 
	std::vector<bool> workingVector(items.size());
	std::fill(workingVector.begin(), workingVector.end(), false); // all false so far

	std::vector<bool> submitVector(items.size());
	std::fill(workingVector.begin(), workingVector.end(), false); // all false so far

	totalValue = -1;                    // no value so far
	numberOfConfigsChecked = 0;
	// try some subset of the 2^n posibilities, return the one with the best objective (total value)

	// YOU NEED TO WRITE A SOLVER--EITHER HERE OR A FUNCTION TO CALL
	// It should modify workingVector (you can treat it as an array of bool) to show which to include in the solution
	// and set totalValue and numberOfConfigsChecked
	int currentCapacity = 0;
		std::vector<item> empty;
		std::vector<item> tempSolution;

		
		// Check every subset, passing by reference tempSolution, totalValue, and numberOfConfigsChecked
		checkAllSubsets(items, empty, tempSolution, totalValue, numberOfConfigsChecked, capacity);

		// this is n^2, I can sort in n logn, and then merge, which is just + order n.
		for (int i = 0; i < tempSolution.size(); i++) {
			for (int j = 0; j < items.size(); j++) {
				// If there is a match this will be true
				if (items[j].value == tempSolution[i].value && items[j].weight == tempSolution[i].weight) {
					submitVector[j] = true;
				}
			}
		}

	return submitVector;
}

void checkAllSubsets(std::vector<item> vect, std::vector<item> empty, std::vector<item> &tempSolution, int &totalValue, int &numConfigsChecked, int capacity, int index) {

	// Temporary variables to check value and weight of a subset
	int tempValue = 0;
	int tempWeight = 0;
	
	int sizeOfCurrentVector = vect.size(); 
  
    // base case 
    if (index == sizeOfCurrentVector) {
        for (int i = 0; i < empty.size(); i++) {
        	tempValue += empty[i].value;
			tempWeight += empty[i].weight;	
        }

		// Runs if subset is valid, see if it is the highest totalvalue
		if (tempWeight <= capacity) {
			if (tempValue > totalValue) {
				totalValue = tempValue;
				tempSolution = empty;
			}
		}

		// Passed by reference, counts number of subsets
		numConfigsChecked++;
        return; 
    } 

	empty.push_back(vect[index]);
    checkAllSubsets(vect, empty, tempSolution, totalValue, numConfigsChecked, capacity, index + 1);
    empty.pop_back();
    checkAllSubsets(vect, empty, tempSolution, totalValue, numConfigsChecked, capacity, index + 1);
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

