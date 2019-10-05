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
    // I need a temp pointer
    Node* temp = new Node;

    // try {
    //     temp->next = new Node;
    // } catch (std::bad_alloc &ba) {
    //     ba.what();
    //     return FAILURE;
    // }
    temp->data = addMe;
    temp->next = NULL;

    tail->next = temp;
    tail = temp;

    return SUCCESS;
}

// removeFront
farmingdale::status farmingdale::LinkedList::removeFront() {
    // Check that the linked list is not empty ?
    if(isEmpty()) {
        return FAILURE;
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
    int counter = 0;
    Node* temp = head;
    while(temp != NULL) {
        if (counter == position) {
            return temp;
        }
        counter++;
        temp = temp->next;
    }
    std::cerr << "This should not run it is on line " << __LINE__ << std::endl;
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
    if(!isEmpty()) {
        returnMe = tail->data;
        return SUCCESS;
    } 
    return FAILURE;
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
    return SUCCESS;

    return FAILURE;
}

farmingdale::status farmingdale::LinkedList::removeAfter(Node* afterMe) {
    return FAILURE;
}

farmingdale::status farmingdale::LinkedList::remove(Node* removeMe) {
    Node* temp = head;
    bool flag = true;
    while(flag) {
        if(temp->next == removeMe) {
            temp->next = removeMe->next;
            delete removeMe;
            return SUCCESS;
        } else if (temp == NULL) {
            flag = false;
            return FAILURE;
        }
        temp = temp->next;
    }
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

