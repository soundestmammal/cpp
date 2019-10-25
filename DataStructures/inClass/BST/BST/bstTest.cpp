// (c) 2018 David Gerstl, all rights reserved

#include <iostream>
#include <set>
#include <random>
#include "bst.h"

bool test1();
int main() {
	bool passedSoFar = true;
	passedSoFar = test1();
	if (!passedSoFar) {
		std::cerr << "Failed test 1" << std::endl;
	} else {
		std::cerr << "Passed test 1" << std::endl;
	}

	system("pause");

	return 0;
}

std::ostream & operator<<(std::ostream & theStream, std::set<std::string> & theSet) {
	std::set<std::string>::iterator currentIt = theSet.begin();
	while (currentIt != theSet.end()) {
		theStream << *currentIt << " ";
		++currentIt;
	}
	return theStream;
}
// This test code is untested...
bool test1() {
	farmingdale::bst myBST;
	std::set<int> mySet;

	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	const int NUM_ITEMS = 10000;
	std::uniform_int_distribution<> dis(1, NUM_ITEMS);
	std::pair<std::set<int>::iterator, bool> ret;
	farmingdale::status status1;
	std::string string1;

	for (int i = 0; i < NUM_ITEMS; ++i) {
		// get a random number (between 1 and NUM_ITEMS)
		int num = dis(gen);
		// insert string representation into bst
		string1 = std::to_string(num);
		status1 = myBST.insert(string1);
		// insert into set
		ret = mySet.insert(num);
		// if bst returned FAILURE, it better be that set returned pair::second  == false
		// if bst returned SUCCESS, it better be that set returned pair::second  == true
		if (farmingdale::FAILURE == status1 && false != ret.second) {
			std::cerr << "Error at line " << __LINE__ << " iteration " << i << std::endl;
			return false;
		} else if (farmingdale::SUCCESS == status1 && true != ret.second) {
			std::cerr << "Error at line " << __LINE__ << " iteration " << i << std::endl;
			return false;
		}
	}
	// cheap way of doing this; not very good;
	std::set<int>::iterator myIter = mySet.begin();
	while (mySet.end() != myIter) {
		// look for string rep of -(*myIter) in BST. it should fail
		string1 = std::to_string(-(*myIter));
		if (0 != myBST.search(string1)) {
			std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
			return false;
		}
		// look for string rep of (*myIter+2*NUM_ITEMS) in BST. it should fail
		string1 = std::to_string((*myIter) + (2 * NUM_ITEMS));
		if (0 != myBST.search(string1)) {
			std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
			return false;
		}
		// look for string per of *myIter in BST. This should succeed.
		string1 = std::to_string(*myIter);
		if (0 == myBST.search(string1)) {
			std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
			return false;
		}
		myIter++;
	}
	// remove about NUM_ITEMS/5 from the BST and set. Store somewhere
	std::set<std::string> removedSet;
	std::pair<std::set<std::string>::iterator, bool> retS;
	farmingdale::bstNode *aNode;
	std::uniform_int_distribution<> smallDis(1, 5);
	myIter = mySet.begin();
	while (mySet.end() != myIter) {
		int num = smallDis(gen);
		if (2 == num) {
			// store this item in removedSet, and remove from myBST
			string1 = std::to_string(*myIter);
			retS = removedSet.insert(string1);
			// This can't be a duplicate, so  it better be that set returned pair::second  == true
			if (false == retS.second) {
				std::cerr << "Error at line " << __LINE__ << " inserting " << string1 << " into removedSet" << std::endl;
				// std::cerr << "RemovedSet is " << removedSet << std::endl;
				return false;
			}
			if (0 == (aNode = myBST.search(string1)) || farmingdale::FAILURE == myBST.remove(aNode)) {
				std::cerr << "Error at line " << __LINE__ << " removing " << string1 << std::endl;
				return false;
			}
			// std::cerr << "Removed " << string1 << std::endl;
		}
		myIter++;
	}
	// check the item are not in BST
	myIter = mySet.begin();
	while (mySet.end() != myIter) {
		string1 = std::to_string(*myIter);
		if (removedSet.end() == removedSet.find(string1)) {
			// should be there
			if (0 == myBST.search(string1)) {
				std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
				return false;
			}
		} else {
			// was removed
			if (0 != myBST.search(string1)) {
				std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
				return false;
			}
		}
		++myIter;
	}
	// didn't fail
	return true;
}