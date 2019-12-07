// (c) 2019, David S. Gerstl, all rights reserved
#include <iostream>
#include <vector>
#include <algorithm> // std sort
#include <random> // random
#include <limits>
#include "heapSort.h"


bool testOne(int size);
int main() {
	bool result;
	if (false == (result = testOne(1000000))) {
		std::cout << "Test One Failed" << std::endl;
	}
	else {
		std::cout << "Test One Succeeded" << std::endl;
	}
	std::cout << "Where is the \"any\" key?" << std::endl;
	system("pause");
	return (true == result);
}

bool testOne(int size) {
	std::vector<int> myVector(size);
	int * myArray = new int[size];
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);
	for (int i = 0; i < size; ++i) {
		int aRandomNumber = distribution(generator);
		myVector[i] = aRandomNumber;
		myArray[i] = aRandomNumber;
	}
	// check they are identical
	for (int i = 0; i < size; ++i) {
		if (myVector[i] != myArray[i]) {
			std::cerr << "Difference found on line " <<
				__LINE__ << " where i is " << i <<
				" myVector[i] is " << myVector[i] <<
				" and myArray[i] is " << myArray[i] << std::endl;
			return false;
		}
	}
	// sort both
	std::sort(myVector.begin(), myVector.end());
	heapsort(myArray, size);
	// check again 
	for (int i = 0; i < size; ++i) {
		std::cout << "Test passing so far at line number " << i << std::endl;
		if (myVector[i] != myArray[i]) {
			std::cerr << "Difference found on line " <<
				__LINE__ << " where i is " << i << 
				" myVector[i] is " << myVector[i] <<
				" and myArray[i] is " << myArray[i] << std::endl;
			return false;
		}
	}
	return true;
}