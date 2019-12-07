// (c) 2018 David S. Gerstl, all rights reserved
#ifndef H_PRIORITYQUEUE
#define H_PRIORITYQUEUE
#include <vector>
#include <climits>

namespace farmingdale {
	class priorityQueue;
	enum status { SUCCESS, FAILURE };
	static const int MAX_QUEUE_SIZE = 10000;
}

class farmingdale::priorityQueue {
private:
	// when doing an array version, you are safe making the array : int data[MAX_QUEUE_SIZE];
	int count = 0;
	int inserts = 0; // count of number of calls to inserts
	int findMins = 0; // count of number of calls to findMin
	int deletions = 0; // count of number of calls to deletion
	int moves = 0; // count of number of items moved (for inserts)
	int currentMinVal = __INT_MAX__;
	int currentMinIndex = -1;
	std::vector<int> pq;
public:
	void printStats();
	status insert(int insertMePlease);
	status findMin(int &putTheMinHere);
	status removeMin();
};
#endif