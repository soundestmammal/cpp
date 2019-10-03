// (c) 2019 David Gerstl, all rights reserved
#include "linkedList.h"
#include <iostream>

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
farmingdale::status farmingdale::LinkedList::addToFront(std::string addMe) {
    // temp pointer to head
    Node* temp = head;
    // head points to addMe!
    try {
        head = new Node(addMe);
    } catch(std::bad_alloc &ba) {
        ba.what();
        return FAILURE;
    }
        // head next points to the temp pointer
        head->next = temp;

    return SUCCESS;
}

// removeback
farmingdale::status farmingdale::LinkedList::removeBack(std::string &returnMe) {

    // So the tail points to the back

    // But this is a singly linked list but we need to preceeding node.

    // Therefore we need to traverse the whole linked list.
    // Node* nm1 = head;
    // while(nm1->next != tail) {
    //     nm1 = nm1->next;
    // }

    // // We want to point the tail to the n-1 node
    // tail = nm1;

    // // I want to make the n-1 node's next pointer to NULL
    // nm1 = nm1->next;
    // tail->next = NULL;
    // delete nm1;

    return SUCCESS;
}

// addToBack
farmingdale::status farmingdale::LinkedList::addToBack(std::string addMe) {
    // I need a temp pointer
    // Node* temp = tail;

    // try {
    //     temp->next = new Node(addMe);
    // } catch (std::bad_alloc &ba) {
    //     ba.what();
    //     return FAILURE;
    // }
    // tail = temp->next;
    return SUCCESS;
}

// removeFront
farmingdale::status farmingdale::LinkedList::removeFront(std::string &returnMe) {
    // Check that the linked list is not empty ?
    if(isEmpty()) {
        return FAILURE;
    }
    Node* temp = head->next;
    returnMe = head->data;
    delete head;
    head = temp;
    return SUCCESS;
}

// search
// farmingdale::Node * farmingdale::LinkedList::search()
farmingdale::Node * farmingdale::LinkedList::search(std::string) {
    if (isEmpty()){
        return head;
    };
    Node* temp = head;
    return temp;
}

// getByPosition
farmingdale::Node * farmingdale::LinkedList::getByPostion(int position) {
//     Node* temp = head;
//     int count = 0;
//     while(temp != NULL && count < position) {
//         temp = temp->next;
//     }
//     return temp;
        return head;
}


// getFront
farmingdale::status farmingdale::LinkedList::getFront(std::string &returnMe) {
    // // If it is NONempty Return DATA
    // if(!isEmpty()) {
    //     returnMe = head->data;
    //     return SUCCESS;
    // }
    return FAILURE;
}

// getBack
farmingdale::status farmingdale::LinkedList::getBack(std::string &returnMe) {
    // if(isEmpty()) {
    //     returnMe = tail->data;
    //     return SUCCESS;
    // }
    return FAILURE;
}

farmingdale::status farmingdale::LinkedList::insertAfter(Node* afterMe, std::string addMe) {
    return FAILURE;
}

farmingdale::status farmingdale::LinkedList::removeAfter(Node* afterMe) {
    return FAILURE;
}

farmingdale::status farmingdale::LinkedList::remove(Node* removeMe) {
    return FAILURE;
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

