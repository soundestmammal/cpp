#pragma once

class Node {
public:
    int data;
    Node* next;
    Node(int data = 0);
    ~Node();
};