#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    vector<int> v1(10);

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i); // built in method
    }
    
    vector<int> v2(11);
    
    for (int i = 0; i < v2.size(); i++)
    {
        v2[i] = i*i; // array notation
    };

    // cout << v2.begin() << endl; // returns the beginning element of the vector
    // cout << v2.end() << endl;

    int begin = *v2.begin();
    cout << *v2.begin() << endl;
    cout << *v2.end() << endl;
    

    return 0;
}