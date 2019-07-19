#include <iostream>

using namespace std;

struct nodeType
{
    int info;
    nodeType *link;
};

int main() {
    nodeType *first, *last, *newNode;
    int num;
    first = NULL;
    last = NULL;

    cin >> num; //read and store a number in num
    newNode = new nodeType; // allocate memory of type nodeType

    newNode->info = num;
    newNode->link = NULL;

    if (first == NULL) {
        first = newNode;
        last = newNode;
    } else {
        last->link = newNode;
        last = newNode;
    }

    cout << first->info << endl;
    return 0;
}