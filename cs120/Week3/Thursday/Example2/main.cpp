#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void addIt(int a, int b);

int main() {
    int one = 12, two = 13;
    addIt(one, two);
    return 0;
}

void addIt(int a, int b) {
    int c = a + b;
    cout << c << endl;
}