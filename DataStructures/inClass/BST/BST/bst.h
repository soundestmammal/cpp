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
	bstNode(std::string s) 
	:
	leftChild(NULL),
	rightChild(NULL),
	data(s)
	{
	}
};

class farmingdale::bst {
private:
	bstNode *root;
public:
	// system methods
	bst(); // done
	~bst(); 
	bst(bst const &);
	bst & operator=(bst);
	// user methods
	status insert(std::string); // done
	status remove(bstNode*); 
	status remove(std::string removeMe) {
		bstNode* temp = search(removeMe);
		if (0 == temp) {
			return FAILURE;
		} 
		else {
			remove(temp);
		}
	}
	void printToStream(std::ostream &);
	// if item is not there, return 0
	// const indicates this is an accessor
	bstNode* search(std::string) const; // done
	// const indicates this is an accessor
	inline bool isEmpty() const { return (0 == root); }
};

// does an inorder traversal and prints the output
inline std::ostream & operator<<(std::ostream & lhs, farmingdale::bst & rhs) { 
	rhs.printToStream(lhs); 
	return lhs;
}

#endif