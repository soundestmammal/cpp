// (c) 2018 David Gerstl, all rights reserved

#include <iostream>
#include <iomanip> // setw
#include <new>
#include "bst.h"

void postorder(std::ostream &theStream, farmingdale::bstNode* p, int indent)
{
	if (p != NULL) {
		if (p->rightChild) {
			postorder(theStream,p->rightChild, indent + 4);
		}
		if (indent) {
			theStream << std::setw(indent) << ' ';
		}
		if (p->rightChild) theStream << " /\n" << std::setw(indent) << ' ';
		theStream << p->data << "\n ";
		if (p->leftChild) {
			theStream << std::setw(indent) << ' ' << " \\\n";
			postorder(theStream,p->leftChild, indent + 4);
		}
	}
}
void farmingdale::bst::printToStream(std::ostream &theStream) {
	postorder(theStream, root,0);
}

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

// delete helper. Returns parent of node
farmingdale::bstNode * findNodesParent(farmingdale::bstNode * root, farmingdale::bstNode *theNode) {
	farmingdale::bstNode * current = root;
	farmingdale::bstNode * trailCurrent = 0;
	while (theNode != current) {
		trailCurrent = current;
		current = (current->data > theNode->data)?  current->leftChild : current->rightChild;
	}
	return trailCurrent;
}
// delete helper. Returns number of kids
int countOfChildren(farmingdale::bstNode * theNode) {
	int numChildren = 0;
	if (0 != theNode->leftChild) {
		++numChildren;
	}
	if (0 != theNode->rightChild) {
		++numChildren;
	}
	return numChildren;
}

// helper function for delete 
void setCorrectChild(farmingdale::bstNode * theNodeToChange, farmingdale::bstNode *childNode, farmingdale::bstNode *newChild) {
	if (theNodeToChange->data > childNode->data) {
		theNodeToChange->leftChild = newChild;
	} else {
		theNodeToChange->rightChild = newChild;
	}
}
// delete helper. given a node, returns the value successor (right then left*). Assumes parameter has 2 children
farmingdale::bstNode * findNodesSuccessor(farmingdale::bstNode *theNode) {
	farmingdale::bstNode * current = theNode->rightChild;
	farmingdale::bstNode * trailCurrent = 0;
	while (0 != current) {
		trailCurrent = current;
		current = current->leftChild;
	}
	return trailCurrent;
}
// we assume that removeMe is in the tree
farmingdale::status farmingdale::bst::remove(bstNode* removeMe) {
	bstNode * parent = 0;
	bstNode * successor = 0;
	std::string theData;
	switch (countOfChildren(removeMe)) {
	case 0:
		// find the parent
		parent = findNodesParent(root, removeMe);
		// if the node is root, set root to 0
		if (removeMe == root) {
			root = 0;
		} else {
			// set the parent's corresponding child pointer to 0
			setCorrectChild(parent, removeMe, 0);
		}
		// delete the node
		delete removeMe;
		break;
	case 1:
		// find the parent
		parent = findNodesParent(root, removeMe);
		// if the node is root, make our only child the root
		if (removeMe == root) {
			root = (0 == removeMe->rightChild)? removeMe->leftChild : removeMe->rightChild;
		} else {
			// set the parent's corresponding child pointer to the only child of the node we're deleting
			setCorrectChild(parent, removeMe, (0 == removeMe->rightChild) ? removeMe->leftChild : removeMe->rightChild);
		}
		// delete the node
		delete removeMe;
		break;
	case 2:
		// this works fine if we're root
		// find the successor
		successor = findNodesSuccessor(removeMe);
		// store the data
		theData = successor->data;
		// delete the successor recursively (recall--it cannot have 2 children)
		remove(successor);
		// put the saved data into the node we were going to remove
		removeMe->data = theData;
		break;
	}


	// return failure since this isn't written
	return SUCCESS;
}


farmingdale::status farmingdale::bst::remove(std::string removeMe) {
	// could be done in about 1/2 the time by actually coding with trailCurrent
	bstNode* temp = search(removeMe);
	if (0 == temp) {
		return FAILURE;
	}
	else {
		return remove(temp);
	}
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