// (c) 2013-2019 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates


// Class queue: General integer queue implementation. We will add dynamic arrays (for
// unlimited size), templates (to allow multiple types), operator overloading
// (for queue comparisons). 


// Please see the accompanying Powerpoint for some explanation of the 
// design and algorithms. If you come to office hours for explanations, 
// I will expect that you have read them

#include "BCS370_queueBase.h"

farmingdale::queue::queue()
    : 
    nextInsertIndex(0), 
    oldestIndex(0) 
        {
            
        };

farmingdale::queue::queue(const queue& copyMe) 
    :
    oldestIndex(copyMe.oldestIndex),
    nextInsertIndex(copyMe.nextInsertIndex)
    {
        for (int i = 0; i != copyMe.nextInsertIndex; i = getNextIndex(i)) {
            // put the item in the next slot
            data[nextInsertIndex] = copyMe.data[i];
            // advance the index for the data
            nextInsertIndex++;
        }
    };

farmingdale::statusCode farmingdale::queue::enqueue(std::string addMe) {
    // if full, return failure
    if(isFull()) {
        return FAILURE;
    }

    // enqueue the item into data[nextInsertIndex]
    data[nextInsertIndex] = addMe;

    // increment the nextInsert index
    nextInsertIndex = getNextIndex(nextInsertIndex);

    return SUCCESS;
};

farmingdale::statusCode farmingdale::queue::dequeue(std::string &returnedElement) {
    
    // if empty return failure
    if(isEmpty()){
        return FAILURE;
    }

    // get the oldest item, put it in the returnedElement
    returnedElement = data[oldestIndex];

    // get the OLDEST item, put it in the returnedElement
    oldestIndex = getNextIndex(oldestIndex);

    return SUCCESS;
};
farmingdale::statusCode farmingdale::queue::peek(std::string &returnedElement) const {
    // if empty return failure
    if(isEmpty()) {
        return FAILURE;
    }
    // get the oldest item, put it in the returnedElement
    returnedElement = data[oldestIndex];

    return SUCCESS;
};

// WE will probably not get to this today
// ?
