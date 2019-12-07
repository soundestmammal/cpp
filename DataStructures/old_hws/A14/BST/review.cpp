// (c) 2018 David Gerstl, all rights reserved

#include <iostream>
#include <iomanip> // setw
#include <new>
#include "bst.h"

void removeAndReclaimNode(farmingdale::bstNode * deleteMe) {
	if (0 == deleteMe) {
		return;
	}
	// do a postfix traversal. Delete the node after deleting the children
	// If deleteMe has a leftChild, process that node
	removeAndReclaimNode(deleteMe->leftChild);
	// At this point, left child and all descendants on that side are dead
	// If deleteMe has a rightChild, process that node
	removeAndReclaimNode(deleteMe->rightChild);
	// now, deleteMe must be childless, delete it
	// postfix traversal--process node after its children
	delete deleteMe;

}

void removeAndReclaimNode(farmingdale::bstNode *deleteMe) {
    if(0 == deleteMe) {
        return;
    }

    removeAndReclaimNode(deleteMe->leftChild);

    removeAndReclaimNode(deleteMe->rightChild);

    delete deleteMe;
}

farmingdale::bst::~bst()
{
	removeAndReclaimNode(root);
	root = 0;
}


farmingdale::bst::bst()
	:
	root(0)
{}

farmingdale::bstNode * copyTree(const farmingdale::bstNode * copyNode) {
	if (0 == copyNode) {
		return 0;
	}
    
	farmingdale::bstNode * newNode;
	// prefix traversal--process node before its children
	try {
		// . is the member access operator for a struct or object
		// -> is the member access operator for a pointer to struct or object
		// so copyNode->data is equivalent to (*copyNode).data
		newNode = new farmingdale::bstNode(copyNode->data);
	} catch (std::bad_alloc) {
		return 0;
	}
	newNode->leftChild = copyTree(copyNode->leftChild);
	newNode->rightChild = copyTree(copyNode->rightChild);
	return newNode;
}

farmingdale::bst::bst(const bst &copyMe) {
	root = copyTree(copyMe.root);
}

farmingdale::bst & farmingdale::bst::operator=(bst copyMe) {
	// use copy/swap
	bstNode * temp = root;
	root = copyMe.root;
	copyMe.root = temp;
	return *this;
}

farmingdale::status farmingdale::bst::insert(std::string addMe) {
	bstNode* current = root;
	bstNode* trailCurrent = 0;
	while (0 != current && current->data != addMe) {
		trailCurrent = current;
		current = (addMe < current->data) ? current->leftChild : current->rightChild;
	}
	// check if we stopped because of a duplicate:
	if (0 != current) {
		// there is a duplicate
		return FAILURE;
	}
	// create a new node. Find a really original name for it
	bstNode * newNode;
	try {
		newNode = new bstNode(addMe);
	}
	catch (std::bad_alloc) {
		return FAILURE;
	}
	// if the tree is empty, add the node
	if (0 == root) {
		root = newNode;
		return SUCCESS;
	}
	// now we'll add the node at trailcurrent
	if (addMe < trailCurrent->data) {
		trailCurrent->leftChild = newNode;
	}
	else {
		trailCurrent->rightChild = newNode;
	}
	return SUCCESS;
}

// returns true if the two subtrees anchored at one and tewo are the same
bool recursiveTheSame(farmingdale::bstNode * one, farmingdale::bstNode * two) {
	// if one and two are both null, return true
	if (0 == one && 0 == two) {
		return true;
	}
	// if only one is equal, return false
	if (0 == one || 0 == two) {
		return false;
	}
	// compare the data, if it's different, return false
	if (one->data != two->data) {
		return false;
	}
	// call ourselves on the left children. if that returns false, return false
	if (!recursiveTheSame(one->leftChild, two->leftChild)) {
		return false;
	}
	// call oursselves on the right children. If that returns false, return false
	if (!recursiveTheSame(one->rightChild, two->rightChild)) {
		return false;
	}
	return true;
}

// defined as identical in both structure and content
bool farmingdale::bst::operator==(const bst& otherTree) const {
	return (recursiveTheSame(root, otherTree.root));
}

farmingdale::bstNode * farmingdale::bst::search(std::string findMe) const {
	// set current the root
	bstNode * current = root;
	// traverse the bst: termination condition:  (1) we fall off (2) we find findMe
	while (0 != current && current->data != findMe) {
		if (findMe < current->data) {
			current = current->leftChild;
		} else {
			current = current->rightChild;
		}
	}
	// return current
	return current;
}