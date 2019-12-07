#ifndef H_RAPPER
#define H_RAPPER
#include <string>
#include <iostream>
#include <map>
#include "bst.h"

namespace farmingdale {
	class mapWrapper;
}

class farmingdale::mapWrapper {
private:
	std::map<std::string, int> myAwesomeMap;
public:
	status insert(std::string, int);
	status remove(std::string);
	status query(std::string key, int& value);
    inline bool isEmpty() const { return (myAwesomeMap.empty()); }
};

#endif