// Section 6
// Global and Local Variables

#include <iostream>

using namespace std;

// Age is a global variable
int age {16};

int main()
{
    // Age is a local variable
    // Can be used within the main function
    // Local variables have priority in c++
    int age {12};
    cout << age << endl;
    return 0;
}