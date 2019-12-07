#pragma once

#include <string>

namespace farmingdale {
    enum statusCode { SUCCESS, FAILURE };
};

namespace farmingdale {
    class queue;
};

class farmingdale::queue {
private:
static const int INITIAL_QUEUE_SIZE = 16;
std::string data[INITIAL_QUEUE_SIZE]; // I will need to make this dynamic

int oldestIndex; // index of the oldest element
int nextInsertIndex; // index of the first spot

inline int queueCapacity() const { return INITIAL_QUEUE_SIZE; } // return the current queue capacity
inline int getNextIndex(int index) const { return((index + 1) % queueCapacity()); }

public:

    // Default Constructor
    queue();
    // Copy Constructor
    queue(const queue& copyMe);
    // Destructor
    ~queue();
    // isEmpty
    inline bool isEmpty() { return (oldestIndex == nextInsertIndex); }
    
    // isFull
    inline bool isFull() { return (getNextIndex(nextInsertIndex) == oldestIndex); }

    // Enqueue
    statusCode enqueue(std::string addMe);

    // Dequeue
    statusCode dequeue(std::string &returnedElement);

    // Peek
    statusCode peek(std::string &returnedElement);
    
};