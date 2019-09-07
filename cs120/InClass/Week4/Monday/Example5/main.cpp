#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;
bool oddOrEven(int num);

int main() {

    int number = 3;
    cout << oddOrEven(number) << endl;
    return 0;
}

bool oddOrEven(int num) {
    return (num%2 == 0 ? 0 : 1);
}