Linked List Notes

Eventually, I will learn how to use markdown better, but I will just keep track of the main points here.

Linked Lists offer the advantage (over arrays) in:

1) Insertion and Deletion - Arrays required us to shift all elements up and down positions.
2) Dynamic Size - Arrays are fixed size. 

Memory Allocation Difference:

Memory allocation with Arrays was Contiguous. The addresses of the indexs was sequential, stored in blocks
of memory.

Memory allocation in Linked Lists needs not be contiguous, and often times is not. This is done by using 
pointers to "link" nodes of data to one another.

Chapter Heading! Linked Lists

Def: A linked list is collection of components called nodes.
Every node has the address of the next node (except the last node).
Every Node has at least two components
1) Data - Relevant information to be recorded
2) Link - A pointer to the next node in the list.

Def: Linked List - "A list of nodes, in which the order of the nodes is determined by the address, called the link stored in each variable".

Key: Because each node of a linked list has two components, we need to declare each node as a class or a struct. The data type of the pointer is the node type itself. (why?) because it is going to point at another node!

Values and Syntax Subheading!!!

head (contains the value in memory that points to the beginning of the linked list)
head->info (points to the first node and accesses the value "info" of that node)
head->link (points to the first node and returns the address of the second node)
head->link->info (points to the first node, then points from the first to the second node, and access info for the second node.)

-----------------------------------------------

Bold! Traversing a Linked List

The basic operations of a linked list are:

-Search the list to determine if an item is in the list
-Insert an item in the list
-Delete an item from the list

All of these operations require me to traverse the whole list... 

Why? 

Because when searching the list, we have to walk down the list node by node, and the item
we are looking for can be at the end of the linked list. We will only know if the item is in or
not in the list when we traverse the list one node at a time.

We can not use the head to traverse the list. If we did, we would lose the pointer to the beginning of the list. Thus, we must create a pointer of the same type of the nodes, and use that to walk down the list.

