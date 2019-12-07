#include "linkedList.h"
#include <iostream>
#include <deque>

// Skip the merge sort

// Default Constructor

farmingdale::LinkedList::LinkedList()
    :
    head(NULL),
    tail(NULL)
    {};

// Copy Constructor
farmingdale::LinkedList::LinkedList(const LinkedList &copyMe) 
    :
    head(NULL),
    tail(NULL)
{
    // I need to copy the elements in one list to another.
    Node* temp = NULL;
    Node* moment = head;
    Node* current = copyMe.head;

    // While current doesn't fall off of the List
    while(current != NULL) {
        // This is for the first iteration
        if(current == copyMe.head) {
            head = new Node;
            head->data = copyMe.head->data;
            head->next = NULL;
            tail = head;
        // Otherwise, this is the algorithm that is going to run each time
        } else {
            // Create a new node
            temp = new Node;
            // set the next to null
            temp->next = NULL;
            // set the data to the current copyMe node that we are looking at
            temp->data = current->data;
            // set the current tail's next to the new node we created
            tail->next = temp;
            // Set the tail to point to the new node that we created
            tail = temp;
        }
        // Advance the pointer on the copyMe... s
        current = current->next;
    }
};

// Destructor
farmingdale::LinkedList::~LinkedList() {
    deleteList();
}

// Method for deleting the list
void farmingdale::LinkedList::deleteList() {
    Node* trailCurrent = head;
    Node* current = head;
    while(current != NULL) {
        current = current->next;
        delete trailCurrent;
        trailCurrent = current;
    }
    head = NULL;
    tail = NULL;
}

// getFront
farmingdale::status farmingdale::LinkedList::getFront(std::string &returnMe) {
    if(NULL == head) {
        return FAILURE;
    }

    returnMe = head->data;
    return SUCCESS;
}

// getBack
farmingdale::status farmingdale::LinkedList::getBack(std::string &returnMe) {
    if(NULL == head) {
        return FAILURE;
    }

    returnMe = tail->data;
    return SUCCESS;
}

// addToFront
farmingdale::status farmingdale::LinkedList::addToFront(std::string addMe) {
    if(head == NULL) {
        head = new Node;
        head->data = addMe;
        head->next = NULL;
        tail = head;
        return SUCCESS;
    }

    // use a temp pointer to create a new node and link it to the rest of the list. 

    Node* newNode = NULL;
    newNode = new Node;
    newNode->data = addMe;
    newNode->next = head;
    head = newNode;

    return SUCCESS;
}