#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

int main() {

    int num = 5;
    cout << num << endl;
    cout << &num << endl;

    int *ptr;
    ptr = &num;
    cout << ptr << endl;
    cout << *ptr << endl;

    return 0;
}