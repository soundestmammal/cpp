// (c) 2018 David Gerstl, all rights reserved

#include <new>
#include "bst.h"


farmingdale::bst::bst() 
    :
    root(NULL)
{}

// For the copy constructor I will traverse the tree and copy node by node
farmingdale::bst::~bst() {
    // Call delete bst
}

farmingdale::status farmingdale::bst::insert(std::string addMe) {
    bstNode* current = root;
    bstNode* trailCurrent = NULL;

    while(0 == current || current->data == addMe) {
        trailCurrent = current;
        current = (addMe < current->data) ? current->leftChild : current->rightChild;
    }

    if(NULL != current) {
        return FAILURE;
    }

    bstNode* newNode = NULL;

    try {
        newNode = new bstNode(addMe);
    } catch(std::bad_alloc) {
        return FAILURE;
    }

    // if the tree is empty, add the node
    if(NULL == root) {
        root = newNode;
    }

    if(addMe < trailCurrent->data) {
        trailCurrent->leftChild = newNode;
    } else {
        trailCurrent->rightChild = newNode;
    }

}

farmingdale::status farmingdale::bst::remove(bstNode* removeMe) {
    // I am going to need to find the parent node to removeMe

    // traverse the tree until currentNode.leftChild or currentNode.rightChild is removeMe
    bstNode* current = root;
    while (removeMe != current->leftChild && removeMe != current->rightChild && current != NULL) {
        // There are three cases for this:
        if(removeMe->data > current->data) {
            current = current->rightChild;
        } else if(removeMe->data < current->data) {
            current = current->leftChild;
        } else {
            std::cout << "There was totally a problem with this!!!" << std::endl;
        }
    }
    // this is when the parent pointer (current) falls off of the bst
    // AKA this is when removeMe is not in the bst
    if (NULL == current) {
        std::cerr << "Ok there is a problem here on Line Number " << __LINE__ << std::endl;
    }
    // At this moment current is pointing to the parent of the node we would like to remove.
    // 1. It is a leaf node
    if(NULL == removeMe->leftChild && NULL == removeMe->rightChild) {
        // Steps for deleting a leaf node

        // 1. First I must have a pointer to the node
        // Check: I have removeMe

        // 2. I must have a pointer to the parent node
        // Check: I have current

        // 3. I will change the parent pointer to NULL.
        if(current->rightChild == removeMe) {
            current->rightChild = NULL;
        } else if (current->leftChild == removeMe) {
                current->leftChild == NULL;
        } else {
            std::cerr << "This broke on line " << __LINE__ << std::endl;
            return FAILURE;
        }


        // 4. I will call delete on removeMe
        delete removeMe;
        return SUCCESS;
    }
    // 2. It only has one child - This is the case where I just sew together
    // One pointer is NULL and one is not NULL
    // So if left is NULL or right is NULL
    if (NULL == removeMe->leftChild || NULL == removeMe->rightChild) {
        // 1. I need a pointer to the parent node
            // Check - I have current!
        // 2 Set parent left or right to removeMe - left or right

        // I need to find out if removeMe is a left or right on parent

        // Lets say removeMe is parent left child
        if (current->rightChild == removeMe) {
            // I should probably check if it is going to be removeMe right
            // or will is be removeMe left
            current->rightChild = removeMe->rightChild;
        }
        // Lets say removeMe is parent's right Child
        else if (current->leftChild == removeMe) {
            current->leftChild = removeMe->leftChild;
        }
        // Let's say removeMe is a left child
        if(NULL != removeMe->leftChild) {
        
        }
    }
    // 3. It has two children


    
}

// SEARCH

farmingdale::bstNode* farmingdale::bst::search(std::string s) const {
    // Do a traversal for the node.
    bstNode* current = root;
    if (current == NULL) {
       return current;
    }

    // When do I want to stop searching?

    // 1. I have found the node

    // 2. I have fallen off of the graph

    // 3. 

    while (current != NULL && current->data != s) {
        // There are three cases for this:
        if(s > current->data) {
            current = current->rightChild;
        } else if(s < current->data) {
            current = current->leftChild;
        } else {
            std::cout << "There was totally a problem with this!!!" << std::endl;
        }
    }

    if(current == NULL) {
        std::cerr << "The pointer fell off of the bst. Error on Line Number " << __LINE__ << std::endl;
        return current;
    }
    
    // I must have found the correct node!
    return current;
}

