#include <iostream>
#include <string>

using namespace std;

int main()
{   
    int scores[] {100, 95, 87, 63, -1};
    int *score_ptr {scores};

    // while (*score_ptr != -1) {
    //     cout << *score_ptr <<endl;
    //     score_ptr++;
    // }

    while (*score_ptr != -1) {
        // dereference the pointer and then increment it!
        cout << *score_ptr++ << endl;
    }

    string name1 {"Robert"};
    string name2 {"Sam"};
    string name3 {"Robert"};

    string *p1 {&name1};
    string *p2 {&name2};
    string *p3 {&name3};
    string *p4 {&name1};

    cout << (p1 == p2) << endl;  // False different address
    cout << (p1 == p3) << endl; //false different address
    cout << (p1 == p4) << endl; // true same address

    cout << (*p1 == *p3) << endl; // True, dereference value is true, differemt address in memory

    char name[] {"Burundi"};
    char *char_ptr1 {nullptr};
    char *char_ptr2 {nullptr};

    char_ptr1 = &name[1];
    char_ptr2 = &name[5];

    cout << *char_ptr1 << endl;
    cout << *char_ptr2 << endl;
    
    cout << (char_ptr2 - char_ptr1) << endl;
    return 0;
}