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
    void build(int size); // Method to build LL with user input data
    void traverse(); // Method to traverse LL and print out data to console
    int getLength();  // Get the length of the LL
    int getFirst(); // Get data from the first item in LL
    int getLast(); // Get data from the last item in LL
    bool findItem(const Node *item); // Search for a given item in the linked list 
    void deleteList(); // Deallocate the memory from the heap that the Linked Lists required
    Node* nthItem(int count); // Return the memory address of the third node
    void deleteItem(const Node* item); // Given an item, delete the item from the list
    void initializeList(); // Reset the Linked List to an empty state
    void insertFirst(int data);
    void removeAtTail();
};

/*

[x] isEmptyList
[x] Default Constructor
[x] destroyList
[x] initializeList
[x] length
[x] front
[x] back
[x] search
[ ] insertFirst
[ ] insertLast
[x] deleteNode
[ ] copyList
[x] Destructor
[ ] Copy Constructor
[ ] Overloading the assignment operator
[ ] Overloading the stream insertion operator

*/