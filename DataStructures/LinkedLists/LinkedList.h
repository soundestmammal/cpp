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
    int getFirst(); // Get data from the first item in LL
    int getLast(); // Get data from the last item in LL
    bool findItem(const Node *item); // Search for a given item in the linked list 
    void deleteList(); // Deallocate the memory from the heap that the Linked Lists required
    Node* nthItem(int count); // Return the memory address of the third node
    void deleteItem(const Node* item); // Given an item, delete the item from the list
};