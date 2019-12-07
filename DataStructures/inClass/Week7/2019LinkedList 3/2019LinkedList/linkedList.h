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
};

class farmingdale::stringLinkedList {
private:
	llStringNode * head; // first node
	llStringNode * tail; // last node
public:
	stringLinkedList(); // default ctor
	~stringLinkedList(); // dtor
	stringLinkedList(const stringLinkedList&); // copy ctor
	// not a reference paramter because we use copy/swap
	const stringLinkedList & operator=(stringLinkedList);

	status insertAtHead(std::string);
	status removeAtTail(std::string &);
	status insertAtTail(std::string);
	status removeAtHead(std::string &);
	llStringNode *search(std::string) const ;
	llStringNode *findAtPostion(int);
	status getHead(std::string &) const;
	status getTail(std::string &) const;
	// this can be done inline easily
	inline bool isEmpty() const { return (0 == head); }
	inline bool contains(std::string findMe) const { return (0 != search(findMe)); };
	status insertAfter(llStringNode *, std::string);
	// status removeAfter(llStringNode *);
	// O(N) because we need to traverse
	status remove(llStringNode *);
	// inefficient because it takes 2 passes
	inline status remove(std::string removeMe) {
		llStringNode * nodeToRemove = search(removeMe);
		// safest alternative
		return ((0 == nodeToRemove) ? FAILURE : remove(nodeToRemove));
	}
	bool operator==(const stringLinkedList&);
	bool operator==(std::deque<std::string>&);
};
bool operator!=(farmingdale::stringLinkedList &lhs, farmingdale::stringLinkedList&rhs) { return (!(lhs == rhs)); }
// FIX THESE IN CLASS
bool operator!=(farmingdale::stringLinkedList &lhs, std::deque<std::string>&rhs) { return (false); }
bool operator!=(std::deque<std::string>&lhs, farmingdale::stringLinkedList &rhs) { return (false); }
bool operator==(std::deque<std::string>&lhs, farmingdale::stringLinkedList &rhs) { return (false); }





#endif