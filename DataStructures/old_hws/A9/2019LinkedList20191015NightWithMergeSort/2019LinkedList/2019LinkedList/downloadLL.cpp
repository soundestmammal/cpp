// (c) 2019 David Gerstl, all rights reserved

#include "linkedList.h"


void recursiveMergeSort(farmingdale::llStringNode* &begin, farmingdale::llStringNode* &end) {
	// Test for base case
	if (begin == end) {
		// only one item
		return;
	}
	farmingdale::llStringNode * endOfPartI;
	farmingdale::llStringNode *beginingOfPartII;
	// split it in half
	farmingdale::llStringNode *current = begin;
	farmingdale::llStringNode *trailCurrent = begin;
	while (0 != current) {
		current = current->next;
		if (0 != current) {
			current = current->next;
		}
		if (0 != current) {
			trailCurrent = trailCurrent->next;
		}
	}
	endOfPartI = trailCurrent;
	beginingOfPartII = trailCurrent->next;
	endOfPartI->next = 0;
	// Note: Check that the above works correctly on length==2
	// sort the first half
	recursiveMergeSort(begin, endOfPartI);
	// sort the second half
	recursiveMergeSort(beginingOfPartII, end);
	//	merge the two halves
	farmingdale::llStringNode * sortedListHead = 0;
	farmingdale::llStringNode * sortedListTail = 0;
	while (0 != begin && 0 != beginingOfPartII) {
		// compare the two
		if (begin->data < beginingOfPartII->data) {
			// put the smaller one on the output
			if (0 == sortedListHead) {
				sortedListHead = sortedListTail = begin;
			} else {
				sortedListTail->next = begin;
				sortedListTail = begin;
			}
			// advance the pointer for the smaller list
			begin = begin->next;
			// not really necessary
			sortedListTail->next = 0;
		} else {
			// put the smaller one on the output
			if (0 == sortedListHead) {
				sortedListHead = sortedListTail = beginingOfPartII;
			}
			else {
				sortedListTail->next = beginingOfPartII;
				sortedListTail = beginingOfPartII;
			}
			// advance the pointer for the smaller list
			beginingOfPartII = beginingOfPartII->next;
			// not really necessary
			sortedListTail->next = 0;
		}
	}
	// take the one that's not empty, append to output
	if (0 == begin) {
		// list one is exhausted. Append list II to the sorted list
		sortedListTail->next = beginingOfPartII;
		sortedListTail = end;
	} else {
		// list two is exhausted. append list I to the sorted list
		sortedListTail->next = begin;
		sortedListTail = endOfPartI;
	}
	begin = sortedListHead;
	end = sortedListTail;
	// I'm done
}

void farmingdale::stringLinkedList::sort() {
	recursiveMergeSort(head,tail);
}

farmingdale::status farmingdale::stringLinkedList::insertAtHead(std::string addMe) {
	llStringNode  * temp;
	try {
		temp = new llStringNode;
	} catch (std::bad_alloc) {
		return FAILURE;
	}
	temp->data = addMe;
	temp->next = head; // if it's empty, then ->next will be null, which is correct
	head = temp;
	if (0 == tail) {
		// was empty
		tail = temp; // also could be tail = head
	}
	return SUCCESS;
}

#if 0
farmingdale::stringLinkedList::~stringLinkedList() {
	while (0 != head) {
		llStringNode  * temp = head;
		head = head->next;
		delete temp;
	}
	// tail is disappearing, so not really necessary to prevent dangling pointer
	tail = 0;
}

farmingdale::status farmingdale::stringLinkedList::getTail(std::string &returnMe) const {
	if (isEmpty()) {
		return FAILURE;
	}
	returnMe = tail->data;
	return SUCCESS;
}
#endif 
farmingdale::llStringNode* farmingdale::stringLinkedList::search(std::string findMePlease) const {
	// traverse:
	// point to the first choo choo train car
	llStringNode * current = head;
	// while we haven't fallen off the train and we havent found it
	while (0 != current && current->data != findMePlease) {
		// move to the next car
		current = current->next; 
	}
	// return something
	return current;
}



farmingdale::status farmingdale::stringLinkedList::remove(llStringNode * removeMePlease) {
	llStringNode * current = head;
	llStringNode * trailCurrent = 0;
	while (0 != current && current != removeMePlease) {
		// move to the next car
		trailCurrent = current;
		current = current->next;
	}
	// what if we don't find removeMePlease
	if (0 == current) {
		return FAILURE;
	}
	// if we're deleting head
	if (removeMePlease == head) {
		// equivalently: 0 == trailCurrent. 
		head = current->next;
	} else {
		// typical case 
		trailCurrent->next = current->next;
	}
	if (removeMePlease == tail) {
		tail = trailCurrent;
	}
	delete current;
	return SUCCESS;
}



// let you test ll1 == ll2
bool farmingdale::stringLinkedList::operator==(const stringLinkedList& rhs) const {
	// get a pointer to lhs (me) first car
	llStringNode  * leftCurrent = head;
	// get a pointer to rhs first car
	llStringNode * rightCurrent = rhs.head;
	// while I'm pointing to two cars, and the cars contain the same animal
	while (0 != leftCurrent && 0 != rightCurrent && leftCurrent->data == rightCurrent->data) {
		// move on
		leftCurrent = leftCurrent->next;
		rightCurrent = rightCurrent->next;
	}
	// if I'm pointing at both ends (both trains are over), then they are the same. Scream "same"
	if (0 == leftCurrent && 0 == rightCurrent) {
		return true;
	}
	// otherwise scream "different"
	return false;
} 
// let you test ll1 == myDeque
bool farmingdale::stringLinkedList::operator==(const std::deque<std::string>& rhs) const {
	// get a pointer to lhs (me) first car
	llStringNode  * leftCurrent = head;
	// get a pointer to rhs first car
	// since rhs is const, we use const_iterator to make *rightCurrent an Rvalue
	std::deque<std::string>::const_iterator rightCurrent = rhs.begin();
	// while I'm pointing to two cars, and the cars contain the same animal
	while (0 != leftCurrent && rhs.end() != rightCurrent && leftCurrent->data == *rightCurrent) {
		// move on
		leftCurrent = leftCurrent->next;
		rightCurrent++;
	}
	// if I'm pointing at both ends (both trains are over), then they are the same. Scream "same"
	if (0 == leftCurrent && rhs.end() == rightCurrent) {
		return true;
	}
	// otherwise scream "different"
	return false;
}  




// default ctor
farmingdale::stringLinkedList::stringLinkedList() 
	: 
	head(0),
	tail(0)
{
}



farmingdale::status farmingdale::stringLinkedList::removeAtHead(std::string &theValueFormerlyKnownAsHead) {
	if (isEmpty()) {
		return FAILURE;
	}
	// get the value
	theValueFormerlyKnownAsHead = head->data;
	// remove the head
	llStringNode  * temp = head;
	head = head->next;
	delete temp;
	// if we removed the last item, then reset tail
	if (0 == head) {
		tail = 0;
	}
	return SUCCESS;
}
