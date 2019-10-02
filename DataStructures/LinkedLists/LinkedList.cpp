#include "LinkedList.h"
#include <iostream>

// Constructor
LinkedList::LinkedList() {
    length = 0;
    head = NULL;
    tail = NULL;
    std::cout << "This is the LL constructor" << std::endl;
}

// Destructor
LinkedList::~LinkedList() {
    std::cout << "This is the linked list destructor" << std::endl;
    deleteList();
}

// Returns true if the LinkedLIst isEmpty Returns False if the LL is not empty
bool LinkedList::isEmpty() {
    return (NULL == head ? true : false);
}

// Method to Build the Linked List with user input data
// I should eventually make this take many different types with template thing...
void LinkedList::build(int size) {
    Node* currentNode; // A temporary pointer to the nodes of the Linked List
    int res;
    bool flag = true;
    int counter = 0;
    /*

    This is passing but is just really bad execution of this code...
    UPDATE: Slightly less bad, can now set the size of the linked list
    
    */

    while(counter < size) { 
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
    // Do I need to free up that pointer? Delete the pointer variable but not the object it points to.. hm
    // No I don't need to because I don't call new.
    // It is created on the stack. 
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
    Node* ptr = head;
    while(count != 0) {  
        count--;
  
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

void LinkedList::deleteItem(const Node* item) {

    // Case 1: What if the Linked List is empty?
    if(isEmpty()) {
        std::cerr << "Can not delete an item from an empty list" << std::endl;
        exit(1);
    }

    /*
    Case 2: What if the Item to be deleted is the first item in the linked list.
    Then all we need to do is move pointers.
    If I just create temporary pointer to the head, 
    Move the head pointer up one,
    Delete the temp pointer
    */
    if(item == head) {
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
        std::cout << "The item was the first item in the list, and it has been deleted!" << std::endl;
        return;
    } else {

    /*
    Case 3: The Item we are looking for is in the list
    Create a temporary pointer to traverse the LL and delete the item that we don't need
    I will use a trailing pointer that will allow the linking from a->c
    */
        Node* temp {nullptr};
        Node* trail {nullptr};
        temp = head->next;
        trail = head;
        while(temp != NULL) {
            if(temp == item) {
                trail->next = temp->next; // Have the trail->next point to the correct next node
                length--;
                std::cout << "The item was in the list, and we found it and deleted it!" << std::endl;
                return;
            }
            trail = trail->next;
            temp = temp->next;
        }
    }

    // Case 4: The Item could not be found in the linked list.
    std::cerr << "The item could not be found in the Linked List" << std::endl;
}

void LinkedList::initializeList() {
    deleteList();
}

void LinkedList::insertFirst(int data) {
    Node* temp = head;
    head = new Node(data);
    head->next = temp;
    length++;
}

void LinkedList::removeAtTail() {
    Node* temp;
    while(temp != NULL) {
        if(temp->next->next == NULL) {
            delete tail;
            temp->next = NULL;
            tail = temp;
        }
        temp = temp->next;
    }

}