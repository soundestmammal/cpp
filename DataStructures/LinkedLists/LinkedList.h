#pragma once
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

class LinkedList {
private:
    int length;
    Node* head;
    Node* tail;
    Node* current;
public:
    LinkedList() {
        length = 0;
        head = NULL;
        tail = NULL;
        current = head;
    }
    ~LinkedList() {
        cout << "This is the linked list destructor" << endl;
    }
    void buildItForward() {
        int res;
        bool flag = true;
        int counter = 0;
        while(counter < 5) {
            cout << "Give the data  ";
            cin >> res;
            if (head == tail) {
                head = new Node(res);
                current = head;
                current->next = NULL;
            } else {
                current->next = new Node(res);
                current = current->next;
                current->next = NULL;
            }
            counter++;
        }
    }

    void traverse() {
        current = head;
        while(current != NULL) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};