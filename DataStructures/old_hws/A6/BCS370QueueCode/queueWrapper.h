#ifndef H_QUEUEWRAPPER
#define H_QUEUEWRAPPER
#include <string>
#include <ostream>
#include <queue>

namespace farmingdale {
	enum statusCode { SUCCESS, FAILURE }; // you will remove these when you create exceptions
	class queue;
	class queueWrapper;
}

class farmingdale::queueWrapper {
private:
    std::queue<std::string> stlQueue;
public:
    statusCode enqueue(std::string s);
    statusCode dequeue(std::string &returnElement);
    statusCode peek(std::string &returnElement);
    bool isEmpty();

};

#endif // H_Q_WRAPPER