// (c) 2019, David S. Gerstl, all rights reserved
#include "heapSort.h"
// Visualized: https://www.cs.usfca.edu/~galles/visualization/HeapSort.html

inline int indexOfLeftChild(int index) {
	return (index * 2) + 1; 
}
inline int indexOfRightChild(int index) {
	return (index * 2) + 2;
}

void fixOutOfOrderElement(int theArray[], int length, int outOfOrderIndex){
	// assume that the outOfOrder is OK
	int indexOfGreatestOfThree = outOfOrderIndex;
	// Figure out which element is the biggest of outOfOrder and its kids
	// If it has a left child in heap, compare it with left child
	if (indexOfLeftChild(outOfOrderIndex) < length &&
		theArray[indexOfLeftChild(outOfOrderIndex)] > theArray[indexOfGreatestOfThree]) {
		indexOfGreatestOfThree = indexOfLeftChild(outOfOrderIndex);
	}
	// If it has a right child, compare right child with greatest so far.
	if (indexOfRightChild(outOfOrderIndex) < length && 
		theArray[indexOfRightChild(outOfOrderIndex)] > theArray[indexOfGreatestOfThree]) {
		indexOfGreatestOfThree = indexOfRightChild(outOfOrderIndex);
	}
	// If outOfOrderIndex is in place, we're done
	if (indexOfGreatestOfThree == outOfOrderIndex) {
		return;
	}
	// swap outOfOrderIndex and greatestOfThree
	int temp = theArray[outOfOrderIndex];
	theArray[outOfOrderIndex] = theArray[indexOfGreatestOfThree];
	theArray[indexOfGreatestOfThree] = temp;
	// Recursively call down on the one we swapped
	fixOutOfOrderElement(theArray, length, indexOfGreatestOfThree);
}


void heapsort(int sortMePlease[], int length) {
	// Make the array into a heap
		// Starting at end of array i = (length-1) -> i = 0
	for (int i = length - 1; i >= 0; --i) {
		//                           call fixOutOfOrderElement(sortMePlease, length, i)
		fixOutOfOrderElement(sortMePlease, length, i);
	}
	// Now we have a heap. 
	// loop until (length = 1)
	while (length > 1) {
		// swap the last element in the heap with [0]
		int temp = sortMePlease[0];
		sortMePlease[0] = sortMePlease[length - 1];
		sortMePlease[length - 1] = temp;
		// shorten the heap
		--length;
		// call fixOutOfOrderElement(sortMePlease, length, 0)
		fixOutOfOrderElement(sortMePlease, length, 0);
	}
}
