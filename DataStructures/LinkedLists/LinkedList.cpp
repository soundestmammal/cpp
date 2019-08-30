#include "LinkedList.h"
#include <iostream>

// Constructor
LinkedList::LinkedList() {
    length = 0;
    head = NULL;
    tail = NULL;
    current = head;
}

// Destructor
LinkedList::~LinkedList() {
    std::cout << "This is the linked list destructor" << std::endl;
}

// Method to Build the Linked List with user input data
void LinkedList::buildItForward() {
    int res;
    bool flag = true;
    int counter = 0;
    while(counter < 5) { // 5 for now, just for initial setup
        std::cout << "Give the data ";
        std::cin >> res;
        if(head == tail) {
            head = new Node(res);
            current = head;
            current->next = NULL;
        } else {
            current->next = new Node(res);
            current = current->next;
            current->next = NULL;
        }
        counter++;
        length++;
    }
}

void LinkedList::traverse() {
    current = head;
    while(current != NULL) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

int LinkedList::getLength() { return length; }