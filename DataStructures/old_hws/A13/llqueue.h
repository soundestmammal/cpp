#ifndef __LLQUEUE_H_INCLUDED__
#define __LLQUEUE_H_INCLUDED__
#include "linkedList.h"

namespace farmingdale {
    class llqueue;
}

class farmingdale::llqueue {
public:
    farmingdale::stringLinkedList data;

    // isEmpty
    bool isEmpty();

    // Enqueue
    farmingdale::statusCode enqueue(std::string addMe);

    // Dequeue
    farmingdale::statusCode dequeue(std::string &returnMe);

    // Peek
    farmingdale::statusCode peek(std::string &returnMe);

};

#endif