// (c) 2019 David Gerstl, all rights reserved

#include "linkedList.h"

void recursiveMergeSort(farmingdale::llStringNode * &begin, farmingdale::llStringNode * &end){
	// Test for base case
	if (begin == end) {
		// only one item
		return;
	}
	//split it in half


	// sort the first half
	recursiveMergeSort(begin, endOfPartI);

	// sort the second half
	recursiveMergeSort(beginningOfPartII, end);

	// merge the two halves
	while(NULL != begin && NULL != beginningOfPartII) {
		// compare the two
		if (begin->data < beginningOfPartII->data) {
			if(0 == sortedListHead) {
				sortedListHead = sortedListTail = begin;
			} else {
				sortedListTail->next = begin;
				sortedListTail = begin;
			}
			begin = begin->next;
			// not necessary?
			sortedListTail->next = 0;
			// This is all wrong there is something that needs to be changed
		} else {
			// Put the smaller one on the output
			if(0 == sortedListHead) {
				sortedListHead = sortedListTail = beginingOfPartII;
			} else {
				sortedListTail->next = beginingOfPartII;
				sortedListTail = beginingOfPartII;
			}
			// advance the pointer for the smaller list
			beginingOfPartII = beginingOfPartII->next;
			// not necessary???
			sortedListTail->next = 0;
		}
	}
	if(NULL == begin) {
		// list one is exhausted. Append list II to the sorted list
		sortedListTail->next = beginingOfPartII;
		sortedListTail = end;
	} else {
		// list two is exhausted. append list I to the sorted list
		sortedListTail->next = begin;
		sortedListTail = endOfPartI;
	}

	begin =  sortedListHead;
	end = sortedListTail;
}

// default ctor
farmingdale::stringLinkedList::stringLinkedList() 
	: 
	head(0),
	tail(0)
{
}

farmingdale::stringLinkedList::~stringLinkedList() {
	while (0 != head) {
		llStringNode  * temp = head;
		head = head->next;
		delete temp;
	}
	// tail is disappearing, so not really necessary to prevent dangling pointer
	tail = 0;
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
