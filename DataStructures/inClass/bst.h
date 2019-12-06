// (c) David Gerstl, All rights reserved
#ifndef H_BST
#define H_BST
#include <string>
#include <iostream>


namespace farmingdale {
	struct bstNode;
	class bst;
	enum status {SUCCESS, FAILURE};
}

struct farmingdale::bstNode {
	std::string data;
	bstNode *leftChild;
	bstNode *rightChild;
	bstNode(const std::string &s) :
		data(s),
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
	status insert(std::string); // rewrite (T)
	status remove(bstNode*);
	status remove(std::string);
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