#include <iostream>
#include <random>
#include <list>
#include <limits>
#include <string>
#include "linkedList.h"

bool frontTest();
bool backTest();

int main() {
    int x;
    bool failing = false;
    failing = frontTest();
    if (failing) {
        std::cerr << "Test failed on line " << __LINE__ << std::endl;
        exit(1);
    }
    failing = backTest();
    if (failing) {
        std::cerr << "Test failed on line " << __LINE__ << std::endl;
        exit(1);
    }
    std::cout << "Congrats your test passes." << std::endl;
    std::cin >> x;
    return 0;
}

// Tests addToFront and getFront against std::forward_list 
bool frontTest() {
    std::list<std::string> ForwardList;
    farmingdale::LinkedList MyLinkedList;

    int iterations = 100000;
    for (int i = 0; i < iterations; i++)
    {
        ForwardList.push_front(std::to_string(iterations + i));    
        MyLinkedList.addToFront(std::to_string(iterations + i)); 
    }

    while(!ForwardList.empty() && !MyLinkedList.isEmpty()) {
        // std::cout << ForwardList.front() << std::endl;
        // std::cout << MyLinkedList.getFront() << std::endl;
        std::string s1, s2;
        s1 = ForwardList.front();
        MyLinkedList.getFront(s2);
        std::cout << s1 << std::endl;
        std::cout << s2 << std::endl;
        // std::cout << s2.length() << std::endl;

        if(s1 != s2) {
            std::cerr << "There was an error on line " << __LINE__ << std::endl;
            return true;
        }
        ForwardList.pop_front();
        MyLinkedList.removeFront();
    }

    return false;
};

// Tests addToBack and getBack against std::list 
bool backTest() {
    std::list<std::string> ForwardList;
    farmingdale::LinkedList MyLinkedList;

    int iterations = 50000;
    for (int i = 0; i < iterations; i++)
    {
        ForwardList.push_back(std::to_string(iterations + i));    
        MyLinkedList.addToBack(std::to_string(iterations + i)); 
    }

    while(!ForwardList.empty() && !MyLinkedList.isEmpty()) {
        // std::cout << ForwardList.front() << std::endl;
        // std::cout << MyLinkedList.getFront() << std::endl;
        std::string s1, s2;
        s1 = ForwardList.back();
        MyLinkedList.getBack(s2);
        std::cout << s1 << std::endl;
        std::cout << s2 << std::endl;
        // std::cout << s2.length() << std::endl;

        if(s1 != s2) {
            std::cerr << "There was an error on line " << __LINE__ << std::endl;
            return true;
        }
        ForwardList.pop_back();
        MyLinkedList.removeBack();
    }

    return false;
};

// search test

/*
    How would I test such a thing? 

    Ok. I need to push a bunch of nodes

    1. Randomly generate a number [0, 1000] which will node we look for

    2. I will add nodes to the front

    3. if ( i == randomNumber) => insert the searching string into the linked list

    4. I will now have a LL with one node that is flagged for searching

    5. Perform the search.

    Upon Finding the NODE Perform these steps:
        6. Count the number of traversal steps
        7. Number of traversal steps should be the same.
        8. The Data should be the same. 
        9. The successor should be the same.
*/

/* 
    Then I can test removing the node:

        11. Remove the node from both data structures
        12. Call search on the LL and List
        13. Both the search() => 0
            exit(1) if they are not equal.
*/
