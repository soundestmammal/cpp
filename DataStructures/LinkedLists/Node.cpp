#include "Node.h"
#include <iostream>

// Constructor allows data to be passed during object creation and NULL out the pointer
Node::Node(int data) {
    this->data = data;
    next = NULL;
    std::cout << "This is the node constructor" << std::endl;
}

// Destructor
Node::~Node() {
    std::cout << "This is the node destructor" << std::endl;
}