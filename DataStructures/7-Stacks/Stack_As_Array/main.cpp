#include "stackType.cpp"
#include <iostream>

int main() {
    stackType<int> intStack(50);
    stackType<int> tempStack;

    intStack.push(23);
    intStack.push(45);
    intStack.push(38);

    tempStack = intStack;

    while(tempStack.isEmptyStack()) {
        std::cout << tempStack.top()  << " ";
        tempStack.pop();
    }
    std::cout << std::endl;

    std::cout << "The top element of intStack: " << intStack.top() << std::endl;

    return 0;
}