#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    const int SIZE = 10;
    srand(time(NULL));
    int random[SIZE];
    
    for (int i = 0; i < SIZE; i++)
    {
        random[i] = rand() % 100 + 1;
    }

    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << random[i] << endl;
    }
    
    
    return 0;
}