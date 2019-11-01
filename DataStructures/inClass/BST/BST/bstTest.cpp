// (c) 2018 David Gerstl, all rights reserved

#include <iostream>
#include <set>
#include <random>
#include "bst.h"

bool test1();
int main() {
	int x;
	bool passedSoFar = true;
	passedSoFar = test1();
	if (!passedSoFar) {
		std::cerr << "Failed test 1" << std::endl;
	} else {
		std::cerr << "Passed test 1" << std::endl;
	}

	std::cin >> x;

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
	std::cout << "Checkpoint 1" << std::endl;
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	const int NUM_ITEMS = 10000;
	std::uniform_int_distribution<> dis(1, NUM_ITEMS);
	std::pair<std::set<int>::iterator, bool> ret;
	farmingdale::status status1;
	std::string string1;

	std::cout << "Checkpoint 2" << std::endl;

	for (int i = 0; i < NUM_ITEMS; ++i) {
		// get a random number (between 1 and NUM_ITEMS)
		std::cout << "\nCheckpoint 2a" << std::endl;

		int num = dis(gen);
		std::cout << "\nCheckpoint 2b" << std::endl;
		// insert string representation into bst
		string1 = std::to_string(num);
		std::cout << "\nCheckpoint 2c" << std::endl;


		// This is where I am failing...
		status1 = myBST.insert(string1);
		std::cout << "\nCheckpoint 2d" << std::endl;
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
		std::cout << "Checkpoint 2e" << std::endl;
	}
	std::cout << "\nCheckpoint 3" << std::endl;
	// cheap way of doing this; not very good;
	std::set<int>::iterator myIter = mySet.begin();

	while (mySet.end() != myIter) {
		// look for string rep of -(*myIter) in BST. it should fail
		string1 = std::to_string(-(*myIter));
		std::cout << "\nCheckpoint 3a" << std::endl;
		if (0 != myBST.search(string1)) {
			std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
			return false;
		}
		std::cout << "\nCheckpoint 3b" << std::endl;
		// look for string rep of (*myIter+2*NUM_ITEMS) in BST. it should fail
		string1 = std::to_string((*myIter) + (2 * NUM_ITEMS));
		if (0 != myBST.search(string1)) {
			std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
			return false;
		}
		std::cout << "\nCheckpoint 3c" << std::endl;
		// look for string per of *myIter in BST. This should succeed.
		string1 = std::to_string(*myIter);
		if (0 == myBST.search(string1)) {
			std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
			return false;
		}
		myIter++;
		static int acounter = 0;
		acounter++;
		std::cout << "\nCheckpoint 3z " << acounter << std::endl;
	
	}

	std::cout << "\nCheckpoint 4" << std::endl;
	static int counter4 = 0;
	// remove about NUM_ITEMS/5 from the BST and set. Store somewhere
	std::set<std::string> removedSet;
	std::pair<std::set<std::string>::iterator, bool> retS;
	farmingdale::bstNode *aNode;
	std::uniform_int_distribution<> smallDis(1, 5);
	myIter = mySet.begin();
	std::cout << "\nCheckpoint 4a" << std::endl;
	while (mySet.end() != myIter) {
		int num = smallDis(gen);
		std::cout << "\nCheckpoint 4b" << std::endl;		
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
			std::cout << "\nCheckpoint 4c" << std::endl;
			aNode = myBST.search(string1);
			std::cout << "0 means it is not null     " << (0 == aNode) << std::endl;
			if(NULL != aNode) {
				std::cout << "LEFT	" << (aNode->leftChild == NULL) << std::endl;
				std::cout << "RIGHT	" << (aNode->rightChild == NULL) << std::endl;
			}
			std::cout << "\nCheckpoint 4d" << std::endl;
			if (0 == (aNode = myBST.search(string1)) || farmingdale::FAILURE == myBST.remove(aNode)) {
				std::cerr << "Error at line " << __LINE__ << " removing " << string1 << std::endl;
				return false;
			}
			// std::cerr << "Removed " << string1 << std::endl;
		}
		myIter++;
		counter4++;
		std::cout << "\nCheckpoint 4e" << std::endl;
		std::cout << "This is the 4th counter " << counter4 << std::endl;
	}
	std::cout << "\nCheckpoint 5" << std::endl;

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
