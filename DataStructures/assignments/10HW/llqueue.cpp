#include <iostream>
#include "BCS370_queueBase.h"
#include "llqueue.h"
  

bool farmingdale::llqueue::isEmpty() {
    if (data.isEmpty()) {
        return true;
    }
    return false;
}

farmingdale::statusCode farmingdale::llqueue::enqueue(std::string addMe) {
    data.addToBack(addMe);
    return SUCCESS;
}

farmingdale::statusCode farmingdale::llqueue::dequeue(std::string &returnMe) {
    if(isEmpty()) {
        return FAILURE;
    }
    std::string test;
    data.getFront(test);
    returnMe = test;
    data.removeFront();
    return SUCCESS;
}

farmingdale::statusCode farmingdale::llqueue::peek(std::string &returnMe) {
    if(isEmpty()) {
        return FAILURE;
    }
    std::string test;
    data.getFront(test);
    returnMe = test;

    return SUCCESS;
}
