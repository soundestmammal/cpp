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
	//std::cout.setstate(std::ios_base::badbit);
	failedSoFar = testOne();
	//std::cout.clear();
	if (!failedSoFar) {
		failedSoFar = sortTest();
	}
	if (failedSoFar) {
		std::cout << "Failed test on line " << __LINE__ << std::endl;
		system("pause");
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
	farmingdale::stringLinkedList theLL;
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> bigDis(INT_MIN, INT_MAX);
	int min = INT_MAX;
	int max = INT_MIN;
	for (int iteration = 0; iteration < 100000; ++iteration) {
		int theNum = bigDis(gen);
		std::string num = std::to_string(theNum);
		theDeque.push_back(num);
		theLL.insertAtTail(num);
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
	farmingdale::stringLinkedList myLL;
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
			std::cout << "this is the first case1" << std::endl;
			// add at front
			testDeque.push_front(num);
			myLL.insertAtHead(num);
			std::cout << "Do I even get here1 " << std::endl;

			break;
		case 2:
			// add at middle (after nth item)
		{
			if (testDeque.size() > 1) {
				// not necessary, but good overflow prevention practice
				int max = (testDeque.size() > INT_MAX) ? (INT_MAX) : (int(testDeque.size()) - 1 );
				std::uniform_int_distribution<> posnDis(1, max);
				position = posnDis(gen);
				// note that deque insert makes your item the new X, so inserts before. We insert after
				std::deque<std::string>::iterator insertAfter = testDeque.begin() + (position)  - 1;
				farmingdale::llStringNode * nodeAfter = myLL.findAtPostion(position);
				std::cout << "Adding after our node " << nodeAfter->data << " which stl shows as " << *insertAfter << std::endl;
				++insertAfter;
				testDeque.insert(insertAfter, num);
				myLL.insertAfter(nodeAfter, num);
						std::cout << "Do I even get here2 " << std::endl;

			}
		}
		break;
		case 3:
			// add at end
			testDeque.push_back(num);
			myLL.insertAtTail(num);
			std::cout << "Do I even get here 3" << std::endl;

			break;
		case 4:
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
			if (farmingdale::FAILURE == myLL.removeAtHead(out2)) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			if (out1 != out2) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			std::cout << "Do I even get here 4" << std::endl;

			break;
		case 5:
			// remove middle
			std::cout << "This was the last one to run" << std::endl;

		{
			if (testDeque.size() < 3) {
				// there's no remove middle if there's no middle
				continue;
			}
			// not necessary, but good overflow prevention practice
			int max = (testDeque.size() > INT_MAX) ? (INT_MAX) : (int(testDeque.size()) - 2);
			std::uniform_int_distribution<> posnDis(1, max);
			position = posnDis(gen);
			std::deque<std::string>::iterator removeThisItem = testDeque.begin() + (position) - 1;
			farmingdale::llStringNode * nodeRemove = myLL.findAtPostion(position);
			std::cout << "Removing node " << nodeRemove->data << " which stl shows as " << *removeThisItem << std::endl;
			testDeque.erase(removeThisItem);
			farmingdale::status stat = myLL.remove(nodeRemove);
			if (stat == farmingdale::SUCCESS) {
				std::cout << "Success" << std::endl;
			} else {
				std::cout << "Failure" << std::endl;
			}
			std::cout << "********************************************?" << std::endl;
		}
		break;
		case 6:
			std::cout << "This is the beginning of case 6" << std::endl;
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
			if (farmingdale::FAILURE == myLL.removeAtTail(out2)) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			if (out1 != out2) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			break;
		case 7:
			std::cout << "This is the beginning of case 7" << std::endl;
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
			if (farmingdale::FAILURE == myLL.getTail(out2)) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			if (out1 != out2) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			break;
		case 8:
			std::cout << "This is the beginning of case 8" << std::endl;
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
			if (farmingdale::FAILURE == myLL.getHead(out2)) {
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
			std::cout << "This is the beginning of case 9" << std::endl;
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
			std::deque<std::string>::iterator removeThisItem = testDeque.begin() + (position) - 1;
			farmingdale::llStringNode * nodeRemove = myLL.findAtPostion(position);
			std::cout << "Removing node " << nodeRemove->data << " which stl shows as " << *removeThisItem << std::endl;
			if (nodeRemove->data != *removeThisItem) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
		}
		break;
		} // switch
	} // for i = 0...ITERATIONS

	// now test the copy ctor and assignment
	farmingdale::stringLinkedList ll1(myLL);
	farmingdale::stringLinkedList ll2;
	farmingdale::stringLinkedList ll3;

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

