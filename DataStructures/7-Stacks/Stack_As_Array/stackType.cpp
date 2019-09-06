#include "stackType.h"
template<class Type>
void stackType<Type>::initializeStack() {
    stackTop = 0;
}

template<class Type>
void stackType<Type>::destroyStack() {
    stackTop = 0;
}

template<class Type>
bool stackType<Type>::isEmptyStack() {
    if (stackTop == 0) {
        return true;
    } else {
        return false;
    }

    // Nicer Syntax: return(stackTop == 0);
}

template<class Type>
bool stackType<Type>::isFullStack() {
    if (stackTop == maxStackSize) {
        return true;
    } else {
        return false;
    }
    // Nicer Syntax: return(stackTop == maxStackSize);
}

template<class Type>
void stackType<Type>::push(const stackType<Type>& newItem) {
    // if(stackTop == maxStackSize) {
    //     std::cout << "The stack is full, can't add it" << std::endl;
    // } else {
    //     stackTop++;
    //     list[stackTop] = newItem; 
    // }

    // Better way to do this:
    if(!isFullStack()) {
        list[stackTop] = newItem;
        stackTop++;
    } else {
        std::cerr << "Cannot add to a full stack." << std::endl;
    }
}

template<class Type>
Type stackType<Type>::top() {
    // std::assert(stackTop != 0);
    
    return *(list + stackTop - 1);
}

template<class Type>
void stackType<Type>::pop() {
    if(!isEmptyStack()) {
        stackTop--;
    } else {
        std::cerr << "Can not remove from an empty stack." << std::endl;
    }
}

template<class Type>
stackType<Type>::stackType(int stackSize) {
    if(stackSize <= 0) {
        std::cerr << "The size of the array to hold the stack must be positive" << std::endl;
        std::cerr << "Creating a stack of size 100" << std::endl;
        maxStackSize = 100;
    } else {
        maxStackSize = stackSize;
        stackTop = 0;
        list = new Type[maxStackSize];
        // assert(list != null);
    }
}

template<class Type>
stackType<Type>::stackType(const stackType& otherStack) {
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    
    list = new Type[maxStackSize];
    for (int i = 0; i < maxStackSize; i++)
    {
        list[i] = otherStack.list[i];
    }
    
}

template<class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack) {
    if(this != &otherStack) { 
        delete[] list;
        maxStackSize = otherStack.maxStackSize;
        stackTop = otherStack.stackTop;
        list = new Type[maxStackSize];
        for (int i = 0; i < maxStackSize; i++)
        {
            list[i] = otherStack.list[i];
        }
    }
        return *this;
}

template<class Type>
stackType<Type>::~stackType() {
    delete[] list;
}