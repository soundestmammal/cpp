#ifndef __LLQUEUE_H_INCLUDED__
#define __LLQUEUE_H_INCLUDED__

#include "BCS370_queueBase.h"
#include "linkedList.h"

namespace farmingdale {
    class llqueue;
}

class farmingdale::llqueue {
public:
    farmingdale::LinkedList data;

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