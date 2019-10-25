// (c) 2019 David Gerstl, all rights reserved
#include "linkedList.h"
#include <iostream>
#include <deque>

// Merge Sort - In class
void recursiveMergeSort(farmingdale::Node* &begin, farmingdale::Node* &end) {
	// Test for base case
	if (begin == end) {
		// only one item
		return;
	}
	farmingdale::Node * endOfPartI;
	farmingdale::Node *beginingOfPartII;
	// split it in half
	farmingdale::Node *current = begin;
	farmingdale::Node *trailCurrent = begin;
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
	farmingdale::Node * sortedListHead = 0;
	farmingdale::Node * sortedListTail = 0;
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

void farmingdale::LinkedList::sort() {
	recursiveMergeSort(head,tail);
}

// Default Constructor
farmingdale::LinkedList::LinkedList() 
    :
    head(NULL),
    tail(NULL)
{
};

farmingdale::LinkedList::LinkedList(const LinkedList &copyMe) 
    :
    head(NULL),
    tail(NULL)
{
    Node* temp = NULL;
    Node* moment = head;
    Node* current = copyMe.head;
    while(current != NULL) {
        if(current == copyMe.head) {
            head = new Node;
            head->data = copyMe.head->data;
            head->next = NULL;
            tail = head;
        } else {
            temp = new Node;
            temp->next = NULL;
            temp->data = current->data;
            tail->next = temp;
            tail = temp;
        }
        current = current->next;
    }
};

// Destructor
farmingdale::LinkedList::~LinkedList() {
    deleteList();
}

// Operator =
const farmingdale::LinkedList & farmingdale::LinkedList::operator=(LinkedList copyMe) {
    // 1. Ok so I am going to use copy swap...

    // Since I am passing here by value, here will be a copy of LinkedList.

    // I have access to this

    // What am I going to swap... 

    // Temp is the address of the old head.
    Node* tempHead = this->head;
    Node* tempTail = this->tail;
    this->head = copyMe.head;
    this->tail = copyMe.tail;

    copyMe.head = tempHead;
    copyMe.tail = tempTail;

    // copy/swap
    // Node * temp = head;
    // head = copyMe.head;
    // copyMe.head = temp;
    // temp = tail;
    // tail = copyMe.tail;
    // copyMe.tail = temp;
    // return *this;

    return *this;
}

// addToFront
farmingdale::status farmingdale::LinkedList::addToFront(std::string addMe) {
    // try {
    //     head = new Node;
    // } catch(std::bad_alloc &ba) {
    //     ba.what();
    //     return FAILURE;
    // }   
        if(isEmpty()) {
            head = new Node;
            head->data = addMe;
            head->next = NULL;
            tail = head;
            return SUCCESS;
        }
        // temp pointer to head
        Node* temp = new Node;
        temp->data = addMe;
        temp->next = head;
        head = temp;

    return SUCCESS;
}

// removeback
farmingdale::status farmingdale::LinkedList::removeBack() {
    if(isEmpty()) {
        std::cerr << "There was an error on line " << __LINE__ << std::endl;
        return FAILURE;
    }

    // There is only one item in the linked list
    if(NULL == head->next) {
        delete head;
        head = NULL;
        tail = NULL;
        return SUCCESS;
    }


    Node* nm1 = head;
    while(nm1->next != tail) {
        nm1 = nm1->next;
    }

    // We want to point the tail to the n-1 node
    tail = nm1;

    // I want to make the n-1 node's next pointer to NULL
    nm1 = nm1->next;
    tail->next = NULL;
    delete nm1;

    /* 
        if(isEmpty()) 
            return failure;

        VALUEREMOVED = tail->data
        Node* current = head;
        Node* trailCurrent = 0;
        while(tail!=current)
    */

    return SUCCESS;
}

// addToBack
farmingdale::status farmingdale::LinkedList::addToBack(std::string addMe) {
    if(isEmpty()){
        head = new Node;
        head->data = addMe;
        head->next = NULL;
        tail = head;
        return SUCCESS;
    }
    // 1. I need a temp pointer 
    Node* temp;

    try {
        temp = new Node;
    } catch (std::bad_alloc &ba) {
        ba.what();
        return FAILURE;
    }
    // 2. Fill it in
    temp->data = addMe;
    temp->next = NULL;

    // 3. Next
    tail->next = temp;
    // 4. The new node is the tail
    tail = temp;

    return SUCCESS;
}

// removeFront
farmingdale::status farmingdale::LinkedList::removeFront() {
    // Check that the linked list is not empty ?
    if(isEmpty()) {
        return FAILURE;
    }
    if(head->next == NULL) {
        delete head;
        head = NULL;
        tail = NULL;
        return SUCCESS;
    }
    Node* temp = head->next;
    // returnMe = head->data; not needed, it returns status, call after getFront
    delete head;
    head = temp;
    return SUCCESS;
}

// search
// farmingdale::Node * farmingdale::LinkedList::search()
farmingdale::Node* farmingdale::LinkedList::search(std::string findMe) {
    if (isEmpty()){
        std::cerr << "There was an error on line " << __LINE__ << std::endl;
        return 0;
    };
    Node* temp = head;
    while(NULL != temp) {
        // I have found it
        if(findMe == temp->data) {
            return temp;
        }
        temp = temp->next;
    }
    return 0;
}

// getByPosition
farmingdale::Node * farmingdale::LinkedList::getByPosition(int position) {
    if (isEmpty()) {
        std:: cerr << "The list is empty!!! error on line " << __LINE__ << std::endl;
        return 0;
    }
    int counter = 1;
    Node* temp = head;
    while(temp != NULL) {
        if (counter == position) {
            return temp;
        }
        counter++;
        temp = temp->next;
    }
    std::cerr << "There was a problem" << " Position " << position << "\n counter " << counter << "This should not run it is on line " << __LINE__ << std::endl;
    if (counter < position) {
        std::cerr << "The provided position is beyond the size of the list" << std::endl;
        return 0;
    }
    return 0;
}
// getFront
farmingdale::status farmingdale::LinkedList::getFront(std::string &returnMe) {
    // If it is NONempty Return DATA
    if(!isEmpty()) {
        returnMe = head->data;
        return SUCCESS;
    }
    return FAILURE;
}

// getBack
farmingdale::status farmingdale::LinkedList::getBack(std::string &returnMe) {
    if(isEmpty()) {
        return FAILURE;
    } 
    returnMe = tail->data;
    return SUCCESS;
}

farmingdale::status farmingdale::LinkedList::insertAfter(Node* afterMe, std::string addMe) {
    /*
    Insert after head
    Insert after a middle node
    Insert at the end;
    */

    // Ok so I am given a node that I need to remove the afterMe->next
    Node* temp = new Node;
    temp->data = addMe;
    temp->next = afterMe->next;
    afterMe->next = temp;
    /*
    5 cases
    empty
    single node LL
    (4 node LL)
        first
        middle (L or R)
        Last
    */
    return SUCCESS;

    return FAILURE;
}

farmingdale::status farmingdale::LinkedList::removeAfter(Node* afterMe) {

    return FAILURE;
}

farmingdale::status farmingdale::LinkedList::remove(Node* removeMe) {
    // Node* temp = head;
    // bool flag = true;
    // while(flag) {
    //     if(temp->next == removeMe) {
    //         temp->next = removeMe->next;
    //         delete removeMe;
    //         return SUCCESS;
    //     } else if (temp == NULL) {
    //         flag = false;
    //         return FAILURE;
    //     }
    //     temp = temp->next;
    // }
    // return FAILURE;

    // Gerstls code from class
    	Node * current = head;
	Node * trailCurrent = 0;
	while (0 != current && current != removeMe) {
		// move to the next car
		trailCurrent = current;
		current = current->next;
	}
	// what if we don't find removeMePlease
	if (0 == current) {
		return FAILURE;
	}
	// if we're deleting head
	if (removeMe == head) {
		// equivalently: 0 == trailCurrent. 
		head = current->next;
	} else {
		// typical case 
		trailCurrent->next = current->next;
	}
	if (removeMe == tail) {
		tail = trailCurrent;
	}
	delete current;
	return SUCCESS;
}

void farmingdale::LinkedList::deleteList() {
    Node* temp = head;

    // Use temp as a trailing pointer to delete Nodes
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
}

// bool farmingdale::LinkedList::operator==(const farmingdale::LinkedList & rhs) const {
//     // get a pointer to lhs
//     Node* left = head;
//     //get a pointer to rhs
//     Node* right = rhs->head;

//     // while I am pointing to two cars, and the cars contain the same animal
//     while(left != NULL && right != NULL && left->data == right->data) {
//         left = left->next;
//         right = right->next;
//     }
//     if( NULL == left && NULL == right) {
//         return true;
//     }
//     return false;
//         // move on
//     // if i'm poining at both ends
// }

// let you test ll1 == ll2
bool farmingdale::LinkedList::operator==(const LinkedList& rhs) const {
	// get a pointer to lhs (me) first car
	Node  * leftCurrent = head;
	// get a pointer to rhs first car
	Node * rightCurrent = rhs.head;
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

bool farmingdale::LinkedList::operator==(const std::deque<std::string>& rhs) const {
	// get a pointer to lhs (me) first car
	Node  * leftCurrent = head;
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