#ifndef H_STACKWRAPPER
#define H_STACKWRAPPER
#include <string>
#include <iostream>
#include <stack>
#include "BCS370_arrayBasedStack.h"

namespace farmingdale {
    //enum statusCode { SUCCESS, FAILURE }; // you will remove these when you create exceptions
	class stackWrapper;
}

class farmingdale::stackWrapper {
private:
    std::stack<std::string> stlStack;
public:
    statusCode push(std::string s);
    statusCode pop(std::string &returnElement);
    statusCode peek(std::string &returnElement);
    bool isEmpty();
};

#endif // H_STACK_WRAPPER