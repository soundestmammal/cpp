#pragma once
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    
    Node(int data = 0) {
        this->data = data;
        next = NULL;
    }
    ~Node() {
        std::cout << "This is the destructor" << std::endl;
    }
};