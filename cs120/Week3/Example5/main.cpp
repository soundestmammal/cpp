#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    // 0, 1, 1, 2, 3, 5, 8, 13, 21
    // 5. The fibonacci numbers are 1, 1, 2, 3, 5, 8, 13, 21, ... Use a for loop to list the first 20 Fibonacci Numbers
    int first {0};
    int second {1};
    int sum = {};
    for (int a = 1; a<=20; ++a) {
        if (a == 1) cout << "Fibonacci Number 1" << " is:   " << 1 << endl;
        sum = first + second;
        cout << "Fibonacci Number " << a+1 << " is:   " << sum << endl;
        first = second;
        second = sum;
    }

    return 0;
}