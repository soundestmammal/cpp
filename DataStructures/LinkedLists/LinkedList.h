#pragma once
#include "Node.h"

class LinkedList {
private:
    int length;
    Node* head;
    Node* tail;
    Node* current;
public:
    LinkedList(); // Constructor
    ~LinkedList(); // Destructor
    void buildItForward(); // Method to build LL with user input data
    void traverse(); // Method to traverse LL and print out data to console
    int getLength();  // Get the length of the LL
};