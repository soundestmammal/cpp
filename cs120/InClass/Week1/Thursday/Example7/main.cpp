#include <iostream>
#include <string>
#include <math.h>
#include <ctime>

using namespace std;

int main() {

    int x = 10;
    x -= 5;
    cout << x << endl;
    x *= 17;
    cout << x << endl;
    x%=3;
    cout << x << endl;

    // Increment at the very end
    cout << x++ << endl;

    // Increment at the beginning
    cout << ++x << endl;

    return 0;
}