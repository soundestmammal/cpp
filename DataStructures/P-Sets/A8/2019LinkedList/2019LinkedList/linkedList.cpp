// (c) 2019 David Gerstl, all rights reserved
#include "linkedList.h"

// Default Constructor
farmingdale::LinkedList::LinkedList() 
    :
    head(NULL),
    tail(NULL)
{
};

// Destructor
farmingdale::LinkedList::~LinkedList() {
    deleteList();
}

// addToFront

// removeback

// addToBack

// removeFront

// search

// getByPosition

// getFront

// getBack



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

