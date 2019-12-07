// (c) 2019 David Gerstl, all rights reserved

#include <iostream>
#include <random>
#include <deque>
#include <limits>
#include "linkedList.h"

bool testOne();
bool sortTest();

int main() {
	char x;
	bool failedSoFar = false;
	// comment out the next line for debug messages
	std::cout.setstate(std::ios_base::badbit);
	failedSoFar = testOne();
	std::cout.clear();
	if (!failedSoFar) {
		failedSoFar = sortTest();
	}
	if (failedSoFar) {
		std::cout << "Failed test on line " << __LINE__ << std::endl;
		exit(1);
	} else {
		std::cout << "Passed the test" << std::endl;

	}

	// more portable than system("pause")
	std::cin >> x;
	return 0;
}



bool sortTest() {
	std::deque<std::string> theDeque;
	farmingdale::LinkedList theLL;
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> bigDis(INT_MIN, INT_MAX);
	int min = INT_MAX;
	int max = INT_MIN;
	for (int iteration = 0; iteration < 100000; ++iteration) {
		int theNum = bigDis(gen);
		std::string num = std::to_string(theNum);
		theDeque.push_back(num);
		theLL.addToBack(num);
		if (theNum < min) {
			min = theNum;
		}
		if (theNum > max) {
			max = theNum;
		}
	}
	if (theLL != theDeque) {
		std::cerr << "Failure line " << __LINE__ << std::endl;
		return 1;
	}
	std::cout << "Testing Sort with a list of size " << theDeque.size() <<". Min is "<<  min<<" and max is "<< max << std::endl;
	std::sort(theDeque.begin(), theDeque.end());
	theLL.sort();
	if (theLL != theDeque) {
		std::cerr << "Failure line " << __LINE__ << std::endl;
		return 1;
	}
	else {
		std::cout << "The two are the same. It's ALIVE!!!!" << std::endl;
	}
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
	std::uniform_int_distribution<> bigDis(INT_MIN, INT_MAX);
	int position;
	for (int iteration = 0; iteration < ITERATIONS; ++iteration) {
		int action = dis(gen);
		std::string num = std::to_string(bigDis(gen));
		switch (action) {
		case 1:
			std::cout << "RUNNING CASE 1 \n" << std::endl;
			// add at front
			testDeque.push_front(num);
			myLL.addToFront(num);
			break;
		case 2:
			std::cout << "RUNNING CASE 2 \n" << std::endl;
			// add at middle (after nth item)
		{
			if (testDeque.size() > 1) {
				// not necessary, but good overflow prevention practice
				int max = (testDeque.size() > INT_MAX) ? (INT_MAX) : (int(testDeque.size()) - 1 );
				std::uniform_int_distribution<> posnDis(1, max);
				position = posnDis(gen);
				// note that deque insert makes your item the new X, so inserts before. We insert after
				std::cout << "Inserting at position " << position << ". Deque is currently: ";
				for (std::deque<std::string>::iterator it = testDeque.begin(); it != testDeque.end(); ++it) {
					std::cout << ' ' << *it;
				}

				std::deque<std::string>::iterator insertAfter = testDeque.begin() + (position) - 1;
				farmingdale::Node * nodeAfter = myLL.getByPosition(position);
				std::cout << "\nAdding after our node " << nodeAfter->data << " which stl shows as " << *insertAfter << std::endl;
				++insertAfter;
				testDeque.insert(insertAfter, num);
				myLL.insertAfter(nodeAfter, num);
			}
			std::cout << "This ran when the LL was empty \n" << std::endl;
		}
		break;
		case 3:
			std::cout << "RUNNING CASE 3 \n" << std::endl;
			// add at end
			testDeque.push_back(num);
			myLL.addToBack(num);
			break;
		case 4:
			std::cout << "RUNNING CASE 4 \n" << std::endl;
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
			// remove middle
		{
			std::cout << "RUNNING CASE 5 \n" << std::endl;
			if (testDeque.size() < 3) {
				// there's no remove middle if there's no middle
				continue;
			}
			// not necessary, but good overflow prevention practice
			int max = (testDeque.size() > INT_MAX) ? (INT_MAX) : (int(testDeque.size()) - 2);
			std::uniform_int_distribution<> posnDis(1, max);
			position = posnDis(gen);
			std::deque<std::string>::iterator removeThisItem = testDeque.begin() + (position) - 1;
			farmingdale::Node * nodeRemove = myLL.getByPosition(position);
			std::cout << "Removing node " << nodeRemove->data << " which stl shows as " << *removeThisItem << std::endl;
			testDeque.erase(removeThisItem);
			myLL.remove(nodeRemove);
		}
		break;
		case 6:
			std::cout << "RUNNING CASE 6 \n" << std::endl;
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
			std::cout << "RUNNING CASE 7 \n" << std::endl;
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
			std::cout << "RUNNING CASE 8 \n" << std::endl;
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
			std::cout << "RUNNING CASE 9 \n" << std::endl;
			// read middle
		{
			if (testDeque.size() < 3) {
				// there's no remove middle if there's no middle
				continue;
			}
			// not necessary, but good overflow prevention practice
			int max = (testDeque.size() > INT_MAX) ? (INT_MAX) : (int(testDeque.size()) - 2);
			std::uniform_int_distribution<> posnDis(1, max);
			position = posnDis(gen);
			std::cout << "Removing at position " << position << ". Deque is currently: ";
			for (std::deque<std::string>::iterator it = testDeque.begin(); it != testDeque.end(); ++it) {
				std::cout << ' ' << *it;
			}
			std::deque<std::string>::iterator removeThisItem = testDeque.begin() + (position) - 1;
			farmingdale::Node * nodeRemove = myLL.getByPosition(position);
			std::cout << "\nRemoving node " << nodeRemove->data << " which stl shows as " << *removeThisItem << std::endl;
			if (nodeRemove->data != *removeThisItem) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
		}
		break;
		} // switch
	} // for i = 0...ITERATIONS

	// now test the copy ctor and assignment
	farmingdale::LinkedList ll1(myLL);
	farmingdale::LinkedList ll2;
	farmingdale::LinkedList ll3;

	ll3 = ll2 = myLL;
	if (ll1 != ll2 || ll2 != ll3 || ll2 != myLL) {
		std::cerr << "Failure line " << __LINE__ <<  std::endl;
		return 1;
	}
	if (ll1 != testDeque) {
		std::cerr << "Failure line " << __LINE__ << std::endl;
		return 1;
	}
	return false;
}

// move into their code

