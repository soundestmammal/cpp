#include <iostream>
#include "LinkedList.h"

int testCode() {

    LinkedList empty;
        if (empty.isEmpty()) {
            std::cout << "The Linked List is EMPTY" << std::endl;
        } else {
            std::cout << "This linked list contains items" << std::endl;
        }
    std::cout << empty.getLast() << std::endl;

    LinkedList l;
    l.buildItForward();
    std::cout << l.getLength() << std::endl;
    std::cout << l.getFirst() << std::endl;
    std::cout << l.getLast() << std::endl;


    if (l.isEmpty()) {
            std::cout << "The Linked List is EMPTY" << std::endl;
        } else {
            std::cout << "This linked list contains items" << std::endl;
        }

    return 0;        
}