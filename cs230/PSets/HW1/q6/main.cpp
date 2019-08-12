#include <iostream>

using namespace std;

// Function Prototypes
void factor(int x);

int main () {

    factor(100);
    /*
    Output:

    1 100
    2 50
    4 25
    5 20
    
     */

    return 0;
}

void factor(int x) {
    int low = 1;
    int high = x;

    while(low < high) {
        for (int top = high; top > low; top--)
        {
            if(top * low == x) {
                cout << low << " " << top << endl;
            }
        }
        low++;
    }
}