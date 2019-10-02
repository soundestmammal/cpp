// (c) 2019 David Gerstl, all rights reserved

#ifndef H_LINKEDLIST
#define H_LINKEDLIST

#include <string>

namespace farmingdale {
	struct Node;
	class LinkedList;
	enum status { FAILURE, SUCCESS };
}

// a node of my ll
class farmingdale::Node {
public:
	Node(std::string s) { data = s; }
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
	status removeBack(std::string &returnMe); // done
	status addToBack(std::string); // done
	status removeFront(std::string &returnMe); // done
	Node*search(std::string); // done
	Node*getByPostion(int); // done
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
	// delete list items
		void deleteList();
};





#endif