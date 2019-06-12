#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 10-i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}