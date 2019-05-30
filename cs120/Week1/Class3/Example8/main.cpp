#include <iostream>
#include <string>
#include <math.h>
#include <ctime>

using namespace std;

int main() {

    int x = 10;
    int a = 4;
    x *= a - 6;
    cout << x << endl;

    // Don't do this at all - be careful when using (++, --)
    // cout << (x++ - (++a + ++a) * (x/a++)) << endl;

    return 0;
}