// (c) 2019 David Gerstl, all rights reserved

#ifndef H_LINKEDLIST
#define H_LINKEDLIST

#include <string>
#include "BCS370_queueBase.h"

namespace farmingdale {
	class Node;
	class LinkedList;
}

// a node of my ll
class farmingdale::Node {
public:
	// Need a default ctor
	std::string data;
	Node* next;
};

class farmingdale::LinkedList {
private:
	Node* head; // first node
	Node* tail; // last node
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList&);
	// not a reference parameter because we use copy/swap
	const LinkedList & operator=(LinkedList);

	statusCode addToFront(std::string); // done
	statusCode removeBack(); // done
	statusCode addToBack(std::string); // done
	statusCode removeFront(); // done

	Node* search(std::string); // done
	Node* getByPosition(int); // done

	statusCode getFront(std::string &); // done
	statusCode getBack(std::string &); // done

	// this can be done inline easily
	inline bool isEmpty() { return (NULL == head); };
	inline bool contains(std::string findMe) { return (0 != search(findMe)); };
	statusCode insertAfter(Node*, std::string); // done
	statusCode removeAfter(Node*); // done
	// O(N) because we need to traverse
	statusCode remove(Node*); // done
	inline statusCode remove(std::string removeMe) {
		Node* nodeToRemove = search(removeMe);
		//		return (remove(nodeToRemove));
				// safest alternative
		return ((0 == nodeToRemove) ? FAILURE : remove(nodeToRemove));
		// or [if remove can take NULL] replace the entire thing with 
//		return(remove(search(removeMe)));
	}
	// delete list items
		void deleteList();
};





#endif