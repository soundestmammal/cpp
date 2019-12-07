// (c) 2019 David Gerstl, all rights reserved
#include <iostream> // for cerr
#include <new>
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

farmingdale::statusCode farmingdale::stringLinkedList::insertAtHead(std::string addMe) {
	llStringNode  * temp;
	try {
		temp = new llStringNode;
	} catch (std::bad_alloc) {
		return FAILURE;
	}
	temp->data = addMe;
	// The LL is empty
	if(NULL == tail) {
		temp->next = NULL;
		temp->prev = NULL;
		head = tail = temp;
	} else if (head == tail) {
		head->prev = temp;
		temp->next = head;
		temp->prev = NULL;
		head = temp;
	} else {
		temp->next = head; // if it's empty, then ->next will be null, which is correct
		head->prev = temp;
		temp->prev = NULL;
		head = temp;
		if (0 == tail) {
			// was empty
			tail = temp; // also could be tail = head
		}
	}
	return SUCCESS;
}

#if 1
farmingdale::stringLinkedList::~stringLinkedList() {
	while (0 != head) {
		llStringNode  * temp = head;
		head = head->next;
		delete temp;
	}
	// tail is disappearing, so not really necessary to prevent dangling pointer
	tail = 0;
}

farmingdale::statusCode farmingdale::stringLinkedList::getTail(std::string &returnMe) const {
	if (isEmpty()) {
		return FAILURE;
	}
	returnMe = tail->data;
	return SUCCESS;
}
farmingdale::statusCode farmingdale::stringLinkedList::getHead(std::string &returnMe) const {
	if (isEmpty()) {
		return FAILURE;
	}
	returnMe = head->data;
	return SUCCESS;
}

const farmingdale::stringLinkedList & farmingdale::stringLinkedList::operator=(stringLinkedList copyMe) {
	// copy/swap 
	llStringNode * temp = head;
	head = copyMe.head;
	copyMe.head = temp;
	temp = tail;
	tail = copyMe.tail;
	copyMe.tail = temp;
	return *this;
	// the dtor for copyMe will free our old heap memory here.
}

farmingdale::stringLinkedList::stringLinkedList(const stringLinkedList& copyMe)
	:
	head(0),
	tail(0)
{
	llStringNode *copyMeCurrent = copyMe.head;
	llStringNode* previousNode = NULL;

	while (0 != copyMeCurrent) {
		// do some stuff
			// allocate a new node
		llStringNode * newNode;
		try {
			newNode = new llStringNode;
		}
		catch (std::bad_alloc& e) {
			std::cerr << "Urgh " << e.what() << std::endl;
			return;
		}
		
		// copy the data from copyMeCurrent
		newNode->data = copyMeCurrent->data;
		// newNode's next will be 0
		newNode->next = 0;

		if(copyMe.head->prev == NULL) {
			newNode->prev = NULL;
		} else {
			newNode->prev = previousNode;
		}

		// add newNode to the current output list
		if (isEmpty()) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		// move along little doggie
		previousNode = newNode;
		copyMeCurrent = copyMeCurrent->next;
	}
}

farmingdale::statusCode farmingdale::stringLinkedList::removeAtTail(std::string &valueRemoved) {
	if (isEmpty()) {
		return FAILURE;
	}
	// get the value from tail
	valueRemoved = tail->data;

	// How can I get the new tail?
	if(head == tail) {
		head = NULL;
		delete tail;
		tail = NULL;
		return SUCCESS;
	}
	llStringNode* temp = tail->prev;
	temp->next = NULL;
	delete tail;
	tail = temp;
	return SUCCESS;


	/*
		// get the new tail by traversal with a trailCurrent 
		llStringNode* current = head;
		llStringNode* trailCurrent = 0;
		while (tail != current) {
			trailCurrent = current;
			current = current->next;
		}
		if (head == tail) {
			head = 0;
		} else {
			// set trailCurrent's next to null
			trailCurrent->next = 0;
		}
		// delete the node
		delete tail;
		// set tail to trailcurrent
		tail = trailCurrent;
		return SUCCESS;
	*/
}
farmingdale::statusCode farmingdale::stringLinkedList::insertAfter(llStringNode *insertAfterMe, std::string addMe) {
	llStringNode * newNode;
	try {
		newNode = new llStringNode;
	}
	catch (std::bad_alloc &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return FAILURE;
	}
	newNode->data = addMe;
	newNode->next = insertAfterMe->next;
	newNode->prev = insertAfterMe;
	insertAfterMe->next = newNode;
	newNode->next->prev = newNode;
	if (insertAfterMe == tail) {
		tail = newNode;
	}
	return SUCCESS;
}

// 1 is the first node
farmingdale::llStringNode *farmingdale::stringLinkedList::findAtPostion(int position) const {
	llStringNode * current = head;
	int counter = 1;
	while (0 != current && counter < position) {
		counter++;
		current = current->next;
	}
	return current;
}


farmingdale::statusCode farmingdale::stringLinkedList::insertAtTail(std::string addMe) {
	/* This would be the easy way
	if (isEmpty()) {
		return(insertAtHead(addMe));
	}
	else {
		return(insertAfter(tail, addMe));
	}
	*/
	// make a node 
	llStringNode * newNode;
	try {
		newNode = new llStringNode;
	} catch (std::bad_alloc &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return FAILURE;
	}
	// fill the node
	newNode->data = addMe;
	newNode->next = 0;
	// if its empty
	if (isEmpty()) {
		// the node is head and tail
		head = tail = newNode; // Chaining: same as head = (tail = newNode) which is same as head.operator=(tail.operator=(newNode))
		newNode->prev = NULL;
	}
	else {
		// else
			// point the current tail to the new node
		tail->next = newNode;
		newNode->prev = tail;
			// point tail to the new node
		tail = newNode;
	}
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





farmingdale::statusCode farmingdale::stringLinkedList::remove(llStringNode * removeMePlease) {
	if(head == tail) {
		std::cout << "\n\n\n This is start case 1" << std::endl;

		delete removeMePlease;
		head = tail = NULL;
		std::cout << "\n\n\n This is case 1" << std::endl;
		return SUCCESS;
	} else if (head == removeMePlease) {
		std::cout << "\n\n\n This is start case 2" << std::endl;
		head = head->next;
		head->prev = NULL;
		delete removeMePlease;
		std::cout << "\n\n\n This is case 2" << std::endl;
		return SUCCESS;
	} else if (tail == removeMePlease) {
		std::cout << "\n\n\n This is start case 3" << std::endl;
		tail = tail->prev;
		tail->next = NULL;
		delete removeMePlease;
		std::cout << "\n\n\n This is case 3" << std::endl;
		return SUCCESS;
	} else {
		std::cout << "\n\n\n This is start case 4" << std::endl;
		llStringNode* previous = removeMePlease->prev;
		std::cout << "\n\n\n A" << std::endl;
		llStringNode* nextNode = removeMePlease->next;
		std::cout << "\n\n\n B" << std::endl;
		previous->next = removeMePlease->next;
		std::cout << "\n\n\n C" << std::endl;
		nextNode->prev = removeMePlease->prev;
		delete removeMePlease;
		std::cout << "\n\n\n This is case 4" << std::endl;
		return SUCCESS;
	}
	std::cout << "I should never ever ever get here..." << std::endl;

	return FAILURE;
	/*
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
	*/
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



farmingdale::statusCode farmingdale::stringLinkedList::removeAtHead(std::string &theValueFormerlyKnownAsHead) {
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
