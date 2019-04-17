#include <iostream>

using namespace std;

struct nodeType
{
    int info;
    nodeType *link;
};

nodeType buildListForward()
    {
        nodeType *first, *last, *newNode, *current;
        int num;

        cout << "Enter a list of numbers to make a linked list with the last number being -999" << endl;
        cin >> num;
        first = NULL;
        
        while(num != -999)
        {
            newNode = new nodeType;
            newNode->info = num;
            newNode->link = NULL;
            
            if (first == NULL) {
                first = newNode;
                last = newNode;
            }
            else {
                last->link = newNode;
                last = newNode;
            }
            cin >> num;
        }
        current = first;
        while (current != NULL)
        {
            cout << current->info << " " << endl;
            current = current->link;
        }
        
    };

int main()
{
    buildListForward();
    return 0;
}