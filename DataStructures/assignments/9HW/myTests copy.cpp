#include <iostream>
#include <random>
#include <list>
#include <limits>
#include <string>
#include "linkedList.h"

bool frontTest();
bool backTest();
bool searchTest();
bool removeTest();
bool removeTest2();

int main() {
    int x;
    bool failing = false;
    failing = frontTest();
    if (failing) {
        std::cerr << "Test failed on line " << __LINE__ << std::endl;
        exit(1);
    }
    std::cout << "Front test is passing" << std::endl;

    failing = backTest();
    if (failing) {
        std::cerr << "Test failed on line " << __LINE__ << std::endl;
        exit(1);
    }
    std::cout << "Back test is passing" << std::endl;

    failing = searchTest();
    if (failing) {
        std::cerr << "Test failed on line " << __LINE__ << std::endl;
        exit(1);
    }
    std::cout << "Search test is passing" << std::endl;

    failing = removeTest();
    if (failing) {
        std::cerr << "Test failed on line " << __LINE__ << std::endl;
        exit(1);
    }
    std::cout << "Remove test is passing" << std::endl;

    failing = removeTest2();
    if (failing) {
        std::cerr << "Test failed on line " << __LINE__ << std::endl;
        exit(1);
    }
    std::cout << "Remove #2 test is passing" << std::endl;
    std::cout << "Congrats your test passes." << std::endl;
    std::cin >> x;
    return 0;
}

// Tests addToFront and getFront against std::forward_list 
bool frontTest() {
    std::list<std::string> ForwardList;
    farmingdale::LinkedList MyLinkedList;

    int iterations = 5;
    for (int i = 0; i < iterations; i++) {
        ForwardList.push_front(std::to_string(iterations - i));    
        MyLinkedList.addToFront(std::to_string(iterations - i)); 
    }

    while(!ForwardList.empty() && !MyLinkedList.isEmpty()) {
        // std::cout << ForwardList.front() << std::endl;
        // std::cout << MyLinkedList.getFront() << std::endl;
        std::string s1, s2;
        s1 = ForwardList.front();
        MyLinkedList.getFront(s2);
        // if (farmingdale::status::FAILURE == testFlag) {
        //     return true;
        // }
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

    int iterations = 5;
    for (int i = 0; i < iterations; i++)
    {
        ForwardList.push_back(std::to_string(i));

        MyLinkedList.addToBack(std::to_string(i));
        // if (farmingdale::status::FAILURE == testFlag) {
        //     return true;
        // }
    }

    while(!ForwardList.empty() && !MyLinkedList.isEmpty()) {
        // std::cout << ForwardList.front() << std::endl;
        // std::cout << MyLinkedList.getFront() << std::endl;
        std::string s1, s2;
        s1 = ForwardList.back();
        MyLinkedList.getBack(s2);
        std::cout << "STL:  " << s1 << std::endl;
        std::cout << "MLL:  " << s2 << std::endl;
        // std::cout << s2.length() << std::endl;

        if(s1 != s2) {
            std::cerr << "There was an error on line " << __LINE__ << std::endl;
            return true;
        }
        ForwardList.pop_back();
        MyLinkedList.removeBack();
        std::cout << "This ran" << std::endl;
    }

    return false;
};

// search test
bool searchTest() {
    const int iterations = 5;
    std::list<std::string> ForwardList;
    farmingdale::LinkedList MyLinkedList;
    // 1. Randomly generate a number [0, Iterations]
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, iterations-1);
    int searchForMe = dis(gen);

    for (int i = 0; i < iterations; i++)
    {
        if(i == searchForMe) {
            ForwardList.push_back("This is the string to find!");
            MyLinkedList.addToBack("This is the string to find!");
        } else {
            ForwardList.push_back(std::to_string(i));
            MyLinkedList.addToBack(std::to_string(i));
        }
    }

    // Perform the search.
        // Strings returned from traversal
        // linked list stl, my linked list
        // Does this still pass if the LL is empty?
        std::string llstl, mll;
        int digit;
        for (std::list<std::string>::iterator it = ForwardList.begin(); it != ForwardList.end(); it++)
        {

            if (*it == "This is the string to find!") {
                llstl = *it;
            }

        }

        std::cout << "The stl list returned...  " << llstl << std::endl;

        farmingdale::Node* temp = MyLinkedList.search("This is the string to find!");

        mll = temp->data;

        std::cout << "My Linked List returned...    " << mll << std::endl;
        
        if(mll != llstl) {
            std::cerr << "There was an error on line " << __LINE__ << std::endl;
            return true;
        }

    return false;
}

// Test for remove a random Node
bool removeTest() {
    std::cout << "\nThis is the remove test *****************" << std::endl;
    const int iterations = 5;
    std::list<std::string> ForwardList;
    farmingdale::LinkedList MyLinkedList;
    // 1. Randomly generate a number [0, Iterations]
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, iterations-1);
    int searchForMe = dis(gen);

    for (int i = 0; i < iterations; i++)
    {
        if(i == searchForMe) {
            ForwardList.push_back("This is the string to remove!");
            MyLinkedList.addToBack("This is the string to remove!");
        }

        ForwardList.push_back(std::to_string(i));
        MyLinkedList.addToBack(std::to_string(i));
    }

    // Perform the search.
        // Strings returned from traversal
        // linked list stl, my linked list
        // Does this still pass if the LL is empty?
        std::string llstl, mll;
        int digit;
        for (std::list<std::string>::iterator it = ForwardList.begin(); it != ForwardList.end(); it++)
        {

            if (*it == "This is the string to remove!") {
                llstl = *it;
                it = ForwardList.erase(it);
            }

        }

        std::cout << "The stl list returned...  " << llstl << std::endl;

        farmingdale::Node* temp = MyLinkedList.search("This is the string to remove!");

        mll = temp->data;

        std::cout << "My Linked List returned...    " << mll << std::endl;
        farmingdale::status flag = MyLinkedList.remove("This is the string to remove!");

        if (flag == farmingdale::status::FAILURE) {
            std::cerr << "There was an error on line " << __LINE__ << std::endl;
            return true;
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
}

// Test for remove a random Node
bool removeTest2() {
    const int iterations = 100;
    std::list<std::string> ForwardList;
    farmingdale::LinkedList MyLinkedList;
    // 1. Randomly generate a number [0, Iterations]
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, iterations-1);
    int searchForMe = dis(gen);

    for (int i = 0; i < iterations; i++)
    {
        if (i == searchForMe) {
            ForwardList.push_back("This is the string to remove!");
            MyLinkedList.addToBack("This is the string to remove!");
        } else {
            ForwardList.push_back(std::to_string(i));
            MyLinkedList.addToBack(std::to_string(i));
        }
    }

    // Perform the search.
        // Strings returned from traversal
        // linked list stl, my linked list
        // Does this still pass if the LL is empty?
        std::string llstl, mll;
        int digit;
        for (std::list<std::string>::iterator it = ForwardList.begin(); it != ForwardList.end(); it++)
        {
            if (*it == "This is the string to remove!") {
                llstl = *it;
                it = ForwardList.erase(it);
            }
        }

        std::cout << "The stl list returned...  " << llstl << std::endl;

        farmingdale::Node* temp = MyLinkedList.search("This is the string to remove!");

        mll = temp->data;

        std::cout << "My Linked List returned...    " << mll << std::endl;
        farmingdale::status flag = MyLinkedList.remove("This is the string to remove!");

        if (flag == farmingdale::status::FAILURE) {
            std::cerr << "There was an error on line " << __LINE__ << std::endl;
            return true;
        }

        while(!ForwardList.empty() && !MyLinkedList.isEmpty()) {
            // std::cout << ForwardList.front() << std::endl;
            // std::cout << MyLinkedList.getFront() << std::endl;
            std::string s1, s2;
            s1 = ForwardList.front();
            MyLinkedList.getFront(s2);
            std::cout << "STL:  " << s1 << std::endl;
            std::cout << "MLL:  " << s2 << std::endl;
            // std::cout << s2.length() << std::endl;

            if(s1 != s2) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return true;
            }
            ForwardList.pop_front();
            MyLinkedList.removeFront();
        }

    return false;
}