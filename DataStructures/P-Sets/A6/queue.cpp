#include "queue.h"

farmingdale::queue::queue() 
:
oldestIndex(0),
nextInsertIndex(0)
{

};

farmingdale::queue::queue(const queue& copyMe) 
:
oldestIndex(0),
nextInsertIndex(0)
{
    
}

farmingdale::statusCode farmingdale::queue::enqueue(std::string addMe) {
    
    // Return failure if the queue is full - need to change for dynamic
    if(isFull()) {
        return FAILURE;
    }

    // Otherwise, I want to enqueue the data
    data[nextInsertIndex] = addMe;

    // Increment the nextInsertIndex
    nextInsertIndex = getNextIndex(nextInsertIndex);

    return SUCCESS;
};

farmingdale::statusCode farmingdale::queue::dequeue(std::string &returnedElement) {
    
    // Return Failure if the queue is empty
    if(isEmpty()) {
        return FAILURE;
    }

    // Otherwise let's dequeue
    returnedElement = data[oldestIndex];

    // Move the oldest index
    oldestIndex = getNextIndex(oldestIndex);

    return SUCCESS;
};

farmingdale::statusCode farmingdale::queue::peek(std::string &returnedElement) {

    // Return Failure if the queue is empty
    if(isEmpty()) {
        return FAILURE;
    }

    // Otherwise, let's peek
    returnedElement = data[oldestIndex];

    return SUCCESS;
};