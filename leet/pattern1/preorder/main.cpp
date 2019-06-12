/*
Source: Leetcode Patterns

Leetcode Pattern Number 1:

    BFS + DFS == 25% of the problems - Part 1

    Notes:

    Uses of BFS and DFS -> Graph, Tree and String Problems

    Tree: A tree can be thought of as a connected acyclic graph with N nodes and N-1 edges.
          Any two vertices are connected by exactly one path.

    Three types of DFS Traversals for Binary Trees:

    1. Postorder (Left, Right, Root)
    2. Inorder   (Left, Root, Right)
    3. Preorder  (Root, Left, Right)

    One type of BFS Traversal

    1. Level Order Traversal (Use a Queue)

----------------------------------------------------------------------------------------------

    Intuition of DFS:

        Main idea: Dive as deep as possible before coming back up to take a subsequent dive.

        Example: Use iterative DFS pattern using a stack that will be used to solve a ton of problems.

        DFS Steps:

            1. Push to Stack
            2. Pop Top
            3. Retrieve unvisted neighbors of top, push them to stack
            4. Repeat 1, 2, 3 while the Stack is not empty.
*/

#include <vector>

class Solution {
    public:
        // Remember the DFS Magic! : Initialize stack and do the following
        // Pop top, retrieve neighbors for top, push unvisited neighbors to stack | repeat while stack not empty
        // Because this is a tree no need to keep track of visited as no cycles possible.

        vector<int> preorderTraversal()
}

int main() {
    

    return 0;
}