#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

// Function Header/Prototype Things:
int getAndReplaceMin(int x[], int SIZE);
int* selectionSort(int x[], int SIZE);

using namespace std;

int main() {
    srand(time(NULL));

    int a = 5;

    int* ptra = &a;

    cout << a << endl;
    cout << &a << endl;
    
    cout << ptra << endl;
    cout << *ptra << endl;

    return 0;
}
