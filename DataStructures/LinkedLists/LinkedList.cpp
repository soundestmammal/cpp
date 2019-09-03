#include "LinkedList.h"
#include <iostream>

// Constructor
LinkedList::LinkedList() {
    length = 0;
    head = NULL;
    tail = NULL;
}

// Destructor
LinkedList::~LinkedList() {
    std::cout << "This is the linked list destructor" << std::endl;
}

bool LinkedList::isEmpty() {
    return (NULL == head && NULL == tail ? true : false);
}

// Method to Build the Linked List with user input data
void LinkedList::buildItForward() {
    Node* currentNode; // A temporary pointer to the nodes of the Linked List
    int res;
    bool flag = true;
    int counter = 0;
    /*

    This is passing but is just really bad execution of this code...
    
    */

    while(counter < 5) { // 5 for now, just for initial setup
        std::cout << "Give the data ";
        std::cin >> res;
        if(NULL == head) {
            head = new Node(res);
            currentNode = head;
            currentNode->next = NULL;
            tail = head;

        } else {
            tail->next = new Node(res);
            tail = tail->next;
            tail->next = NULL;
        }
        counter++;
        length++;
    }
}

void LinkedList::traverse() {
    Node* currentNode = head; // A temporary pointer to walk down the linked list
    while(NULL != currentNode) {
        std::cout << currentNode->data << std::endl;
        currentNode = currentNode->next;
    }
}

int LinkedList::getLength() { return length; }

int LinkedList::getFirst() { 
    if(this->isEmpty()) {
        std::cerr << "There was an error and the program terminated" << std::endl;
        exit(1);
    } else {
        return head->data;
    }
}  
int LinkedList::getLast() { 
    if(this->isEmpty()) {
        std::cerr << "There was an error and the program terminated" << std::endl;
        exit(1);
    } else {
        return tail->data;
    }
}

Node* LinkedList::nthItem(int count) {
    Node* ptr;
    while(count != 0) {  
        count--;
  
        ptr = head;
        ptr = ptr->next;
    }
    return ptr;
}

bool LinkedList::findItem(const Node* item) {
    Node* tempPointer;
    tempPointer = head;
    while(tempPointer != NULL) {
        if(tempPointer == item) {
            return true;
        }
        tempPointer = tempPointer->next;
    }
    return false;
}

// Computational Complexity is 0(n) because the while loop will run n times where n is the length of the LL
void LinkedList::deleteList() {
    Node* temp; // Temp pointer to deallocate memory of Linked List Items
    temp = head; // Begin @ head
    
    // delete the current head node at each iteration until List is Empty
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    // Must reset the values for tail and length since LL is empty
    tail = NULL;
    length = 0;
}