// (c) 2019 David Gerstl, all rights reserved

#include <iostream>
#include <random>
#include <deque>
#include <limits>
#include "linkedList.h"

bool testOne();
// bool testRemoveBack();

int main() {
	int x;
	bool failedSoFar = false;
	failedSoFar = testOne();
	if (failedSoFar) {
		std::cout << "Failed test on line " << __LINE__ << std::endl;
		exit(1);
	}
	std::cout << "Test passes" << std::endl;
	// more portable than system("pause")
	std::cin >> x;
	return 0;
}

// compare the deque and ll with a variety of operations
// this has not been tested, so may have errors. Once ll is done, we can debug.
bool testOne() {
	const int ITERATIONS = 10000;
	std::deque<std::string> testDeque;
	std::string out1, out2; // for holding output
	farmingdale::LinkedList myLL;
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, 9);
	std::uniform_int_distribution<> bigDis(INT_MIN, INT_MIN);
	int position;
	int counterHere = 0;
	for (int iteration = 0; iteration < ITERATIONS; ++iteration) {
		std::cout << "Counter:	" << counterHere << std::endl;
		counterHere++;
		int action = dis(gen); // [1,6]
		std::string num = std::to_string(bigDis(gen));
		switch (action) {
		case 1:
			std::cout << "It ran case 1" << std::endl;
			// add at front
			testDeque.push_front(num);
			myLL.addToFront(num);
			break;
		case 2:
			std::cout << "It ran case 2" << std::endl;
			// add at middle (after nth item)
		// {
		// 	std::uniform_int_distribution<> posnDis(0, testDeque.size() - 1);
		// 	position = posnDis(gen);
		// 	// note that deque insert makes your item the new X, so inserts before. We insert after
		// 	std::deque<std::string>::iterator insertAfter = testDeque.begin() + (position);
		// 	farmingdale::Node * nodeAfter = myLL.getByPosition(position);
		// 	std::cout << "Adding after our node " << nodeAfter->data << " which stl shows as " << *insertAfter << std::endl;
		// 	++insertAfter;
		// 	testDeque.insert(insertAfter, num);
		// 	myLL.insertAfter(nodeAfter, num);
		// }
		break;
		case 3:
			std::cout << "It ran case 3" << std::endl;
			// add at end
			testDeque.push_back(num);
			myLL.addToBack(num);
			break;
		case 4:
			std::cout << "It ran case 4" << std::endl;
			// remove front
			if (true == testDeque.empty()) {
				// both better be
				if (!myLL.isEmpty()) {
					std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
					return 1;
				}
				continue;
			} // empty
			out1 = testDeque.front();
			testDeque.pop_front();
			if (farmingdale::FAILURE == myLL.getFront(out2)) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			if (farmingdale::FAILURE == myLL.removeFront()) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			if (out1 != out2) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			break;
		case 5:
			std::cout << "It ran case 5" << std::endl;
			// remove middle
		{
			if (testDeque.size() < 3) {
				// there's no remove middle if there's no middle
				continue;
			}
			std::uniform_int_distribution<> posnDis(1, testDeque.size() - 2);
			position = posnDis(gen);
			std::deque<std::string>::iterator removeThisItem = testDeque.begin() + (position);
			farmingdale::Node * nodeRemove = myLL.getByPosition(position);
			std::cout << "Removing node " << nodeRemove->data << " which stl shows as " << *removeThisItem << std::endl;
			testDeque.erase(removeThisItem);
			myLL.remove(nodeRemove);
		}
		break;
		case 6:
			std::cout << "It ran case 6" << std::endl;
			// remove end
			if (true == testDeque.empty()) {
				// both better be
				if (!myLL.isEmpty()) {
					std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
					return 1;
				}
				continue;
			} // empty
			out1 = testDeque.back();
			testDeque.pop_back();
			if (farmingdale::FAILURE == myLL.getBack(out2)) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			if (farmingdale::FAILURE == myLL.removeBack()) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			if (out1 != out2) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			break;
		case 7:
			std::cout << "It ran case 7" << std::endl;
			// read rear
			if (true == testDeque.empty()) {
				// both better be
				if (!myLL.isEmpty()) {
					std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
					return 1;
				}
				continue;
			} // empty
			out1 = testDeque.back();
			if (farmingdale::FAILURE == myLL.getBack(out2)) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			if (out1 != out2) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			break;
		case 8:
			std::cout << "It ran case 8" << std::endl;
			// read front
			if (true == testDeque.empty()) {
				// both better be
				if (!myLL.isEmpty()) {
					std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
					return 1;
				}
				continue;
			} // empty
			out1 = testDeque.front();
			if (farmingdale::FAILURE == myLL.getFront(out2)) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			if (out1 != out2) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			break;
			break;
		case 9:
			std::cout << "It ran case 9" << std::endl;
			// read middle
		{
			if (testDeque.size() < 3) {
				// there's no remove middle if there's no middle
				continue;
			}
			std::uniform_int_distribution<> posnDis(1, testDeque.size() - 2);
			position = posnDis(gen);
			std::deque<std::string>::iterator removeThisItem = testDeque.begin() + (position);
			farmingdale::Node * nodeRemove = myLL.getByPosition(position);
			std::cout << "Removing node " << nodeRemove->data << " which stl shows as " << *removeThisItem << std::endl;
			if (nodeRemove->data != *removeThisItem) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
		}
		break;
		} // switch
	} // for i = 0...ITERATIONS
	return false;
}

bool myTest() {
	farmingdale::LinkedList ll;
	farmingdale::status flag = ll.addToFront("Number 1");
	if(farmingdale::SUCCESS != flag) {
		std::cerr << "There is a problem on line " << __LINE__ << std::endl;
		exit(1);
	}
	ll.addToFront("Number 2");
	ll.addToFront("Number 3");
	ll.addToFront("Number 4");
	ll.addToFront("Number 5");
	ll.addToFront("Number 6");

	std::string s1, s2, s3, s4, s5, s6;

	//  flag = ll.removeFront(s1);
	//  flag = ll.removeFront(s2);
	//  flag = ll.removeFront(s3);
	//  flag = ll.removeFront(s4);
	//  flag = ll.removeFront(s5);
	//  flag = ll.removeFront(s6);

	// std::cout << s1 << std::endl;
	// std::cout << s2 << std::endl;
	// std::cout << s3 << std::endl;
	// std::cout << s4 << std::endl;
	// std::cout << s5 << std::endl;
	// std::cout << s6 << std::endl;

	return true;
}
/*
// Test for Checking removing from the back
bool testRemoveBack() {

	// Create two linked lists - to replace with a deque later.
	farmingdale::LinkedList ll1, ll2;

	int iterations = 1000;

	// To catch the return values and compare
	farmingdale::status addStat1, addStat2;

	// Fill up my linked list
	for (int i = 0; i < iterations; i++) {

		// These return the farmingdale status
		addStat1 = ll1.addToFront("Add string to Linked List");
		addStat2 = ll2.addToFront("Add string to Linked List");

		// If either of them return failure then we fail this test by returning false
		if(farmingdale::status::FAILURE == addStat1 || farmingdale::status::FAILURE == addStat2) {
			return false;
		}
	}

	// Now I should begin to remove the front values
	for (int i = 0; i < iterations; i++)
	{
		std::string s1, s2;
		farmingdale::status stat1, stat2;
		stat1 = ll1.removeFront(s1);
		stat2 = ll2.removeFront(s2);

		std::cout << s1 << "	is equal to		" << s2 << std::endl;

		// If either of them fail, return false
		if(farmingdale::status::FAILURE == stat1 || farmingdale::status::FAILURE == stat2) {
			return true;
		}

		if(s1 != s2) {
			std::cerr << "There was an error on " << __LINE__ << std::endl;
			return true;
		}


	}
	return false;
}
*/
/*


What Kind of tests should I be running if I want to be testing a linked list.

Can you add to a linked list to the front.

Call addToFront (Method 1/4)

Deque will add to the front.
LL will add to the front.

I should addItems to both of the structures.

After about 10000 insertions. I will traverse the list and compare the data.

The data must be identical. On the last insertion both of the structures should have no nodes. 

So 1001 operations

	For some loop 1<i<100000
		insert into the structure
	
	While both not NULL:
		compare the data
		count the iterations to tell where the test fails!!! was it the first iteration or the 10000???



1000 inserts



*/