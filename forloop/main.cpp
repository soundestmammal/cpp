#include <iostream>

using namespace std;

int main()
{
    // Display all of the even number less than (and including) 10.
    for (int i {1}; i<=10; ++i) {
        if (i % 2 == 0)
            cout << i << endl;
    }
    return 0;
}