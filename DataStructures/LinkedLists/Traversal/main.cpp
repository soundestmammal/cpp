#include <iostream>

using namespace std;

struct nodeType
{
    int info;
    nodeType *link;
};

int main() {
    nodeType *head;
    nodeType *current;

    // Take address of what head is pointing to and give it to current. 
    current = head;
    current = current->link;
    cout << "This is here to be sent to the terminal" << endl;
    return 0;
}