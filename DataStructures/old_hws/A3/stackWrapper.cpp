#include <string>
#include "BCS370_arrayBasedStack.h"
#include "stackWrapper.h"

bool farmingdale::stackWrapper::isEmpty() {
    return (stlStack.empty());
}

farmingdale::statusCode farmingdale::stackWrapper::push(std::string s) {
    stlStack.push(s);
    return SUCCESS;
}

farmingdale::statusCode farmingdale::stackWrapper::peek(std::string &returnMe) {
    if (isEmpty()) {
        return FAILURE;
    }
    returnMe = stlStack.top();
    return SUCCESS;
}

farmingdale::statusCode farmingdale::stackWrapper::pop(std::string &returnMe) {
    if (isEmpty()) {
        return FAILURE;
    }
    returnMe = stlStack.top();
    stlStack.pop();
    return SUCCESS;
}
