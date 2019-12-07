#include <iostream>
#include "BCS370_queueBase.h"
#include "linkedList.h"
#include "llqueue.h"
  
bool farmingdale::llqueue::isEmpty() {
    if (data.isEmpty()) {
        return true;
    }
    return false;
}

// Double Linked List - Add to the front in O(1)
farmingdale::statusCode farmingdale::llqueue::enqueue(std::string addMe) {
    data.insertAtHead(addMe);
    return SUCCESS;
}

// Double Linked List - Remove from the tail in O(1)
farmingdale::statusCode farmingdale::llqueue::dequeue(std::string &returnMe) {
    if(isEmpty()) {
        return FAILURE;
    }
    std::string test;
    data.getTail(test);
    returnMe = test;
    data.removeAtTail(returnMe);
    return SUCCESS;
}

farmingdale::statusCode farmingdale::llqueue::peek(std::string &returnMe) {
    if(isEmpty()) {
        return FAILURE;
    }
    std::string test;
    data.getTail(test);
    returnMe = test;

    return SUCCESS;
}
