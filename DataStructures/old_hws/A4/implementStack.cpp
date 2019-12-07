#include <string>
#include <iostream>
#include "stack.h"

farmingdale::stack::stack()
    :
    countOfItems(0)
{
    data = new std::string[currentStackSize];
}

farmingdale::stack::stack(const stack& copyMe)
    :
    // Step 1: Copy the count of items
    countOfItems(copyMe.countOfItems),
    currentStackSize(copyMe.currentStackSize)
{
    data = new std::string[currentStackSize];

    // Step 2: Copy the bottom count of items
    for (int i = 0; i < countOfItems; i++)
    {
        data[i] = copyMe.data[i];
    }
}

// Methods
bool farmingdale::stack::operator==(stack s2) {
    // check the counts
    if(countOfItems != s2.countOfItems) {
        return false;
    }
    for (int i = 0; i < countOfItems; i++) {
        if(data[i] != s2.data[i]){
            return false;
        }
    }
    return true;
}

farmingdale::statusCode farmingdale::stack::push(std::string addMe) {

    if(isFull()){
        // Create a temporary pointer
        std::string *temp;

        // New Size will be 2 * currentStackSize
        int newSize = 2 * currentStackSize;

        // Try - Catch Statement
        try {
            temp = new std::string[newSize];
        } catch(std::bad_alloc &ba) {
            std::cerr << "Allocation failed with error: " << ba.what() << std::endl;
            return FAILURE;
        }

        // move(copy) the stuff into the new truck
        for (int i = 0; i < currentStackSize; i++)
        {
            *(temp + i) = *(data + i);
        }

        // Free up the block of memory the previous array occupied on the heap
        delete[] data;

        // Update the size of our array
        currentStackSize = newSize;

        // Have data point to the bigger array.
        data = temp;

        // return FAILURE
        
    }
    data[countOfItems] = addMe;
    ++countOfItems;
    return SUCCESS;
}