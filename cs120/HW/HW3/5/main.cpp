#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {

    // 0, 1, 1, 2, 3, 5, 8, 13, 21
    // my approach
    // Currently failing...
    int first {0};
    int second {1};
    int sum = {};
    for (int a = 0; a<=20; ++a) {
        sum = first + second;
        cout << sum << " ";
        first = second;
        second = sum;
    }

    cout << endl;
    // Prof implementation

    int a = 0, b = 1, c;
    int counter = 0;

    cout << a << " " << b << " ";

    while(counter < 20) {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
        counter++;
    }

    cout << endl;

    return 0;
}