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
    l.build(5);
    std::cout << l.getLength() << std::endl;
    std::cout << l.getFirst() << std::endl;
    std::cout << l.getLast() << std::endl;


    if (l.isEmpty()) {
            std::cout << "The Linked List is EMPTY" << std::endl;
        } else {
            std::cout << "This linked list contains items" << std::endl;
        }

    // Test if the deleteList method works!
    LinkedList listt;
    listt.build(5);
    std::cout << listt.isEmpty() << std::endl;
    listt.deleteList();
    std::cout << listt.isEmpty() << std::endl; 

    /* ************************************************************************************** */

    // This is to test the search linked list method and the third item methods
    LinkedList listt;
    listt.build(5);
    std::cout << listt.isEmpty() << std::endl; // Should output 0

    Node* item = listt.nthItem(5);
    std::cout << listt.findItem(item) << std::endl; // Should output 1

    listt.deleteList(); // Should output 5 node destructors
    std::cout << listt.isEmpty() << std::endl; // Should output 1
    std::cout << listt.findItem(item) << std::endl; // Should output 0
    
    // Should be a linked list destructor log

    /* ************************************************************************************** */

    LinkedList aList;
    aList.build(5);
    aList.traverse();
    Node* item = aList.nthItem(2);

    aList.deleteItem(item);
    aList.traverse();

    /* ************************************************************************************** */
    // Insert first is working according to this case...
    LinkedList last;
    last.build(4);
    last.traverse();
    last.insertFirst(314);
    last.traverse();

    return 0;        
}