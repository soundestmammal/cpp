// (c) 2019 David Gerstl, all rights reserved

#ifndef H_LINKEDLIST
#define H_LINKEDLIST

#include <string>
#include <deque>

namespace farmingdale {
	class Node;
	class LinkedList;
	enum status { FAILURE, SUCCESS };
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

	status addToFront(std::string); // done
	status removeBack(); // done
	status addToBack(std::string); // done
	status removeFront(); // done

	Node* search(std::string); // done
	Node* getByPosition(int); // done

	status getFront(std::string &); // done
	status getBack(std::string &); // done

	// this can be done inline easily
	inline bool isEmpty() { return (NULL == head); };
	inline bool contains(std::string findMe) { return (0 != search(findMe)); };
	status insertAfter(Node*, std::string); // done
	status removeAfter(Node*); // done
	// O(N) because we need to traverse
	status remove(Node*); // done
	inline status remove(std::string removeMe) {
		Node* nodeToRemove = search(removeMe);
		//		return (remove(nodeToRemove));
				// safest alternative
		return ((0 == nodeToRemove) ? FAILURE : remove(nodeToRemove));
		// or [if remove can take NULL] replace the entire thing with 
//		return(remove(search(removeMe)));
	}
	bool operator==(const LinkedList&) const; // let you test ll1 == ll2
	bool operator==(const std::deque<std::string>&) const; // let you test ll1 == myDeque
	void sort();
	// delete list items
	void deleteList();
};
	inline bool operator!=(const farmingdale::LinkedList &lhs, const farmingdale::LinkedList&rhs) { return (!(lhs == rhs)); }
	// FIX THESE IN CLASS
	// ll1 != myDeque [uses lhs.operator==(rhs)]
	inline bool operator!=(const farmingdale::LinkedList &lhs, const std::deque<std::string>&rhs) { return (! (lhs == rhs)); }
	// myDeque != ll1
	inline bool operator!=(const std::deque<std::string>&lhs, const farmingdale::LinkedList &rhs) { return (!(rhs == lhs)); }
	// myDeque == ll1
	inline bool operator==(const std::deque<std::string>&lhs, const farmingdale::LinkedList &rhs) { return (rhs == lhs); }

#endif