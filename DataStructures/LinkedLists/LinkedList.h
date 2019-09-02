#pragma once
#include "Node.h"

class LinkedList {
private:
    int length;
    Node* head;
    Node* tail;
public:
    LinkedList(); // Constructor
    ~LinkedList(); // Destructor
    bool isEmpty(); // Checks if the LL is empty
    void buildItForward(); // Method to build LL with user input data
    void traverse(); // Method to traverse LL and print out data to console
    int getLength();  // Get the length of the LL
};