#include <iostream>
#include <ctime>

class Node {
    public: 
        int data;
        Node *next;
};

int main() {
    srand(time(NULL));
    Node *first, *last, *node; //Create three nodes on the heap
    first = NULL;
    last = NULL;
    int num;

    std::cout << "Give me a number: ";
    std:: cin >> num;

    node = new Node;

    node->data = num;
    node->next = NULL;

    /* I want to populate a linked list with random numbers */
    int counter = 0;
    Node *current, *head;
    while(counter < 10) {
       
        if (first == NULL) {
            first = new Node;
            head = first;
            first->data = rand() % 10 + 1;
            current = first->next;
        } else {
            current = new Node;
            current->data = rand() % 10 + 1;
            current = current->next;
        }
        counter++;
    }

    while (current->next != NULL) {
        current = head;
        std::cout << current->data << std::endl;
        current = current->next;
    }
    // // This is the first time 
    // if (first == NULL) {
    //     first = node;
    // } else {
    //     last->next = node;
    //     last = node;
    // }

    // std::cout << first->data << std::endl;

    return 0;
    
}