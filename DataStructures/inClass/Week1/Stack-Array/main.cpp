#include "Stack.h"
#include <iostream>

int main() {
    Stack instance;
    // instance.pop();
    instance.push("Succeed");
    instance.push("Should");
    instance.push("It");
    instance.peak(); // It
    
    while(!instance.isEmpty()) {
        std::cout << instance.pop() << std::endl;
    }

    return 0;
}