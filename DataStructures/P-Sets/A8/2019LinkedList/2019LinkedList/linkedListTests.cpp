// (c) 2019 David Gerstl, all rights reserved


#include <iostream>
#include <random>
#include <deque>
#include <limits>
#include "linkedList.h"

bool testOne();


int main() {
	char x;
	bool failedSoFar = false;
	failedSoFar = testOne();
	if (failedSoFar) {
		std::cout << "Failed test on line " << __LINE__ << std::endl;
		exit(1);
	}

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
	std::uniform_int_distribution<> dis(1, 6);
	std::uniform_int_distribution<> bigDis(INT_MIN, INT_MIN);
	int position;
	for (int iteration = 0; iteration < ITERATIONS; ++iteration) {
		int action = dis(gen);
		std::string num = std::to_string(bigDis(gen));
		switch (action) {
		case 1:
			// add at front
			testDeque.push_front(num);
			myLL.addToFront(num);
			break;
		case 2:
			// add at middle (after nth item)
		{
			std::uniform_int_distribution<> posnDis(0, testDeque.size() - 1);
			position = posnDis(gen);
			// note that deque insert makes your item the new X, so inserts before. We insert after
			std::deque<std::string>::iterator insertAfter = testDeque.begin() + (position);
			farmingdale::Node * nodeAfter = myLL.getByPostion(position);
			std::cout << "Adding after our node " << nodeAfter->data << " which stl shows as " << *insertAfter << std::endl;
			++insertAfter;
			testDeque.insert(insertAfter, num);
			myLL.insertAfter(nodeAfter, num);
		}
		break;
		case 3:
			// add at end
			testDeque.push_back(num);
			myLL.addToBack(num);
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
			if (farmingdale::FAILURE == myLL.removeFront(out2)) {
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
			if (testDeque.size() < 3) {
				// there's no remove middle if there's no middle
				continue;
			}
			std::uniform_int_distribution<> posnDis(1, testDeque.size() - 2);
			position = posnDis(gen);
			std::deque<std::string>::iterator removeThisItem = testDeque.begin() + (position);
			farmingdale::Node * nodeRemove = myLL.getByPostion(position);
			std::cout << "Removing node " << nodeRemove->data << " which stl shows as " << *removeThisItem << std::endl;
			testDeque.erase(removeThisItem);
			myLL.remove(nodeRemove);
		}
		break;
		case 6:
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
			if (farmingdale::FAILURE == myLL.removeBack(out2)) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			if (out1 != out2) {
				std::cerr << "Failure line " << __LINE__ << " on iteration " << iteration << std::endl;
				return 1;
			}
			break;
		case 7:
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
			// read middle
		{
			if (testDeque.size() < 3) {
				// there's no remove middle if there's no middle
				continue;
			}
			std::uniform_int_distribution<> posnDis(1, testDeque.size() - 2);
			position = posnDis(gen);
			std::deque<std::string>::iterator removeThisItem = testDeque.begin() + (position);
			farmingdale::Node * nodeRemove = myLL.getByPostion(position);
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