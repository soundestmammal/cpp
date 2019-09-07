#include <iostream>
using namespace std;

int main() {
    int start = 1;
    int end = 1000;
    while (start <= end) {
        if (start % 2) {
            cout << start << endl;
        }
        start++;
    }
    return 0;
}