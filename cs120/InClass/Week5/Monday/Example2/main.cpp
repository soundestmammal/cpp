#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    const int SIZE = 4;
    string friends[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "What is your friend's name?\n";
        cin >> friends[i];
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        cout << friends[i] << endl;
    }
    
    return 0;
}