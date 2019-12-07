#include <iostream>

#include "BCS370_queueBase.h"

farmingdale::statusCode farmingdale::queueWrapper::enqueue(std::string s) {
    stlQueue.push(s);
    return SUCCESS;
}

farmingdale::statusCode farmingdale::queueWrapper::peek(std::string &s) {
    if (isEmpty()) {
        return FAILURE;
    }
    s = stlQueue.front();
    return SUCCESS;
}

farmingdale::statusCode farmingdale::queueWrapper::dequeue(std::string &s) {
    std::string test;
    if(isEmpty()) {
        return FAILURE;
    }
    s = stlQueue.front();
    stlQueue.pop();
    test = stlQueue.front();
    if (s != test) {
        return SUCCESS;
    }
    return FAILURE;
}

