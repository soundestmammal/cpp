#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int num {1};
    while (num < 10) {
        // Print Odd
        if (num%2) {
            cout << num << " ";
        }
        num++;
    }
    cout << endl;

    int i {1};
    while (i < 10) {
        // Print Even
        if(!(i%2)) {
            cout << i << " ";
        }
        i++;
    }
    cout << endl;

    return 0;
}
