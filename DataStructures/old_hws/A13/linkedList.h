// (c) 2019 David Gerstl, all rights reserved


#ifndef H_LINKEDLIST
#define H_LINKEDLIST

#include <string>
#include <deque>
namespace farmingdale {
	struct llStringNode;
	class stringLinkedList;
	enum status { FAILURE, SUCCESS };
}

// a node of my ll
struct farmingdale::llStringNode {
	std::string data;
	llStringNode * next;
	// DLL Assignment: add previous pointer
	llStringNode * prev;
};

class farmingdale::stringLinkedList {
private:
	llStringNode * head; // first node
	llStringNode * tail; // last node
public:
	stringLinkedList(); // default ctor
	// rule of threes: (1) of (3)
	~stringLinkedList(); // dtor
	// rule of threes: (2) of (3)
	// DLL Assignment: make sure to add prev pointers when copy
	stringLinkedList(const stringLinkedList&); // copy ctor // NOT GONNA WRITE IT
    // rule of threes: (3) of (3)
	// not a reference parameter because we use copy/swap
	const stringLinkedList & operator=(stringLinkedList);  // NOT GONNA WRITE IT


	// DLL Assignment: make sure to set new prev, and current head->prev
	status insertAtHead(std::string);


	// DLL Assignment: modify to do remove in O(1)
	status removeAtTail(std::string &);  // NOT GONNA WRITE IT


	// DLL Assignment: set the new node's prev
	status insertAtTail(std::string);  // NOT GONNA WRITE IT



	// DLL Assignment: fix prev on new head
	status removeAtHead(std::string &);



	// returns node with matching data, or null if not present
	llStringNode *search(std::string) const ;



	// Note that position 1 is the first element (head)
	llStringNode *findAtPostion(int) const;  // NOT GONNA WRITE IT
	status getHead(std::string &) const;  // NOT GONNA WRITE IT
	status getTail(std::string &) const;
	// this can be done inline easily
	inline bool isEmpty() const { return (0 == head); }
	inline bool contains(std::string findMe) const { return (0 != search(findMe)); }
	
	// DLL Assignment: fix the prev pointer on new node and on its ->next
	status insertAfter(llStringNode *, std::string);  // NOT GONNA WRITE IT
	
	// status removeAfter(llStringNode *);

	// DLL Assignment: fix all the pointers. Also no traversal now
	// O(N) because we need to traverse
	status remove(llStringNode *);
	// inefficient because it takes 2 passes
	inline status remove(std::string removeMe) {
		llStringNode * nodeToRemove = search(removeMe);
		// safest alternative
		return ((0 == nodeToRemove) ? FAILURE : remove(nodeToRemove));
	}
	bool operator==(const stringLinkedList&) const; // let you test ll1 == ll2
	bool operator==(const std::deque<std::string>&) const; // let you test ll1 == myDeque
	void sort();
};
inline bool operator!=(const farmingdale::stringLinkedList &lhs, const farmingdale::stringLinkedList&rhs) { return (!(lhs == rhs)); }
// FIX THESE IN CLASS
// ll1 != myDeque [uses lhs.operator==(rhs)]
inline bool operator!=(const farmingdale::stringLinkedList &lhs, const std::deque<std::string>&rhs) { return (! (lhs == rhs)); }
// myDeque != ll1
inline bool operator!=(const std::deque<std::string>&lhs, const farmingdale::stringLinkedList &rhs) { return (!(rhs == lhs)); }
// myDeque == ll1
inline bool operator==(const std::deque<std::string>&lhs, const farmingdale::stringLinkedList &rhs) { return (rhs == lhs); }





#endif