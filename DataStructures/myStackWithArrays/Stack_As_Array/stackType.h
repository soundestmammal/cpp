#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>

template<class Type>
class stackType {
private:
    int maxStackSize; //variable to store the max stack size
    int stackTop; // variable to point to the top of the stack
    Type *list; // Pointer to the array that holds that stack elements
    void copyStack(const stackType<Type> & otherStack);
        // Function to make a copy of otherStack
        // Postcondition: A copy of otherStack is created and assigned to this stack.
    
public:
    const stackType<Type> & operator=(const stackType<Type> &);
        // Overloading the Assignment Operator

    void initializeStack();
        // Function to initialize the stack to an empty state
        // Postcondition: stackTop = 0;

    bool isEmptyStack();
        // Function to determine whether the stack is empty.
        // Postcondition: Returns true if the stack is empty; otherwise returns false

    bool isFullStack();
        // Function to determine whether the stack is full.
        // Postcondition: Returns true if the stack is full; otherwise returns false

    void destroyStack();
        // Function to remove all the elements from the stack.
        // Postcondition: stackTop = 0;

    void push(const stackType<Type>& newItem);
        // Function to return add new item to the stack.
        // Precondition: The stack exists and is not full
        // Postcondition: The stack is changed and new item is added to the top of the stack

    Type top();
        // Function to return the top element of the stack.
        // Precondition: The stack exists and is not empty.
        // Postcondition: If the stack is empty, the program terminates;
            // otherwise, the top element of the stack is returned.

    void pop();
        // Function to remove the top element of the stack.
        // Precondition: The stack exists and is not empty
        // Postcondition: The stack is changed and the top element si removed from the stack

    stackType(int stackSize = 100);
        // Constructor that sets the default stack size to 100
        // Creates an array of the size stackSize to hold the address of the array; stacktop = 0; and 
        //  maxStackSize = stackSize;
    
    stackType(const stackType& otherStack);
        // Copy Constructor
    
    ~stackType();
        // Destructor
        // Removes all the elements from the stack
        // Postcondition: The array holding the stack elements is deleted 
};

#endif