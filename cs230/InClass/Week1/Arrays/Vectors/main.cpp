#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <vector>

using namespace std;

int main() {

    vector <int> v;
    
    for (int i = 0; i < 10; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << v.back() << endl;
        v.pop_back();
    }
    
    return 0;
}

void passInVector(vector <int> &v) {

}