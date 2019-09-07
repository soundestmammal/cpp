#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main() {


    vector<int> v;
    vector<double> v1(5);

    v.push_back(4);
    v.push_back(2);
    v.push_back(1);

    for (int i = 0; i < 3; i++)
    {
        cout << v.at(i) << endl;
    }

    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }


    
    return 0;
}