// (c) David Gerstl, All rights reserved
#ifndef H_BST
#define H_BST
#include <string>
#include <iostream>

namespace farmingdale {
	struct bstNode;
	class bst;
	enum status { SUCCESS, FAILURE };
}

struct farmingdale::bstNode {
	std::string key;
	int value;
	bstNode *leftChild;
	bstNode *rightChild;
	bstNode(std::string s, int v) :
		key(s),
		value(v),
		leftChild(0),
		rightChild(0)
	{}
};

class farmingdale::bst {
private:
	bstNode *root;
public:
	// system methods
	bst();
	~bst(); // write (T)
	bst(const bst  &);
	bst & operator=(bst);
	// defined as identical in both structure and content
	bool operator==(const bst&) const;
	// user methods
	// status insert(std::string, int payload); // rewrite (T)

	status insert(std::string, int);
	status remove(bstNode*);
	status remove(std::string);
	status query(std::string key, int& value);
	void printToStream(std::ostream &);
	// if item is not there, return 0
	// const indicates this is an accessor
	bstNode* search(std::string) const; // write (T)
	// const indicates this is an accessor
	inline bool isEmpty() const { return (0 == root); }
};

inline bool operator!=(const farmingdale::bst& lhs, const farmingdale::bst& rhs) {
	return !(rhs==lhs);
}

// does an inorder traversal and prints the output
inline std::ostream & operator<<(std::ostream & lhs, farmingdale::bst & rhs) { 
	rhs.printToStream(lhs); 
	return lhs;
}

#endif