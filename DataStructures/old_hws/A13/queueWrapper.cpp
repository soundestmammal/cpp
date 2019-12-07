#include <iostream>
#include "BCS370_queueBase.h"
#include "queueWrapper.h"

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
    return SUCCESS;
}

 bool farmingdale::queueWrapper::isEmpty() {
    if (stlQueue.empty()) {
        return true;
    }
    return false;
}