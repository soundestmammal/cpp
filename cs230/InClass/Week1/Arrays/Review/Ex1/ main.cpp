#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <vector>

using namespace std;

void seeVect(vector<int>x);

int main () {
    srand(time(NULL));

    vector <int>v(10);

    for (int k : v) {
        &k = rand();
    }
    return 0;
}

void seeVect(vector<int>x) {
    for (int k : x) {
        cout << k << endl;
    }
}