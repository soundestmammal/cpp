// (c) 2018 David Gerstl, all rights reserved

#include <new>
#include <stack>
#include "bst.h"

farmingdale::bst::bst() 
    :
    root(NULL)
{}

farmingdale::bstNode* copyTree(const farmingdale::bstNode * copyNode) {
    if (0 == copyNode) {
        return 0;
    }
    farmingdale::bstNode* newNode = NULL;
    try {
        newNode = new bstNode(copyNode->data)
    } catch(std::bad_alloc) {
        return 0;
    }

    newNode->leftChild = copyTree(copyNode->leftChild);
    newNode->rightChild = copyTree(copyNode->rightChild);

    return newNode;
}

farmigndale::bst::bst(const bst &copyMe) {
    root = copyTree(copyMe.root);
}

void removeAndReclaimNode(farmingdale::bstNode* deleteMe) {
    if(0 == deleteMe) {
        return;
    }
}
// For the copy constructor I will traverse the tree and copy node by node
farmingdale::bst::~bst() {
    // Call delete bst
}

farmingdale::status farmingdale::bst::insert(std::string addMe) {
    
    bstNode* newNode = NULL;    
    
    // if the tree is empty, add the node
    if(NULL == root) {
        try {
            newNode = new bstNode(addMe);
        } catch(std::bad_alloc) {
            return FAILURE;
        }
        root = newNode;
        return SUCCESS;
    }

    bstNode* current = root;
    std::cout << "Current is NULL... " << (current == NULL) << std::endl;
    bstNode* trailCurrent = current;
    std::cout << "I totally should get up to here!!!" << std::endl;
    std::cout << "This is going to be the addMe " << addMe << std::endl;
    std::cout << "This better be false " << (current->data == addMe) << std::endl;

    // I want to continue to traverse until
    // 1.The current becomes NULL (I fall off of the tree)
    // 2. If the currentNode's data is the same as add Me
    // In this case current won't be null
    while(NULL != current && current->data != addMe) {
        // std::cout << "This should not run!" << std::endl;
        trailCurrent = current;
        current = (addMe < current->data) ? current->leftChild : current->rightChild;
    }
    std::cout << "Hm did I break yet" << std::endl;

    // this is when there is a duplicate node in the tree
    if(NULL != current) {
        return FAILURE;
    }

    try {
        newNode = new bstNode(addMe);
    } catch(std::bad_alloc) {
        return FAILURE;
    }

    if(addMe < trailCurrent->data) {
        trailCurrent->leftChild = newNode;
    } else {
        trailCurrent->rightChild = newNode;
    }
    return SUCCESS;
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
        } else if (removeMe == current->leftChild) {
                current->leftChild = NULL;
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

        // How can I do this:

        /* 
            I need to delete the node.

            It is going to have to have two children.

            So what I am going to do is make sure 

        */

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

    /*
    Ok, if the node 
    */
    bstNode* finder = removeMe->rightChild;
    bstNode* trailFinder = removeMe;



    while(finder->leftChild != NULL) {
        trailFinder = finder;
        finder = finder->leftChild;
    }

    if(current->rightChild == removeMe) {
        current->rightChild = finder;
    }

    // Set the left to NULL
    trailFinder->leftChild = NULL;



    return SUCCESS;
}

// SEARCH

farmingdale::bstNode* farmingdale::bst::search(std::string s) const {
    // Do a traversal for the node.
    bstNode* current = root;
    if (current == NULL) {
       return current;
    }

    while (current != NULL && current->data != s) {
        // There are three cases for this:
        if(s > current->data) {
            // Traverse to the right
            current = current->rightChild;
        } else if (s < current->data) {
            // Traverse to the left
            current = current->leftChild;
        } else {
            std::cout << "There was totally a problem with this!!!" << std::endl;
            exit(1);
            return current;
        }
    }

    if(current == NULL) {
        // std::cerr << "The pointer fell off of the bst. Error on Line Number " << __LINE__ << std::endl;
        std::cout << "I couldn't find the node!" << std::endl;
        return current;
    }
    
    // I must have found the correct node!
    // return current;
    return current;
    std::cerr << "There was a problem with the search on line number " << __LINE__ << std::endl;
    exit(1);

}


// In order traversal that uses a stack and does it iteratively
std::vector<std::string> farmingdale::bst::inOrder(bstNode* root) {
    std::vector<std::string> returnMe;
    std::stack<bstNode*> nodes;

    if(NULL == root) return returnMe;

    while(NULL != root || !nodes.empty()) {
        // push left children if available
        while(root!=NULL) {
            nodes.push(root);
            root = root->leftChild;
        }

        // retrieve top node and store its right child if exists

        root = nodes.top();
        nodes.pop();
        returnMe.push_back(root->data);
        root = root->rightChild;
    }
    return returnMe;
}

// Validate if a Tree is a BST

// For a binary Tree to be a BST, the inorder has to be in sorted order.

bool farmingdale::bst::isValidBST(bstNode* root) {
    if(root == NULL) return true;

    std::stack<bstNode*> s;

    bstNode* prev = NULL;

    while(root != NULL || !s.empty()) {
        while(root != NULL) {
            s.push(root);
            root = root->leftChild;
        }

        root = s.top();
        s.pop();
        if(prev != NULL && prev->data >= root->data) return false;
        prev = root;
        root = root->rightChild;
    }

    return true;
}

// How to find the kth smallest element in the BST

// Use inorder traversal of the BST to give the sorted order o f the items in it.

// A simple inorder breaking off at the keth item would give us our answer.

farmingdale::status farmingdale::bst::kthSmallest(std::string& returnMe, int k) {
    std::stack<bstNode*> s;

    while(NULL != root || !s.empty()) {
        while(NULL != root) {
            s.push(root);
            root = root->leftChild;
        }

        root = s.top();
        s.pop();
        if(--k == 0) {
            // I need to return the string value!
            returnMe = root->data;
            return SUCCESS;
        }

        root = root->rightChild;
    }
    return FAILURE;
}

