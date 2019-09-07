#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

void fillItIn(string x[], int SIZE);

int main() {
    const int SIZE = 4;
    string books[SIZE];
    fillItIn(books, SIZE);

    return 0;
}

void fillItIn(string x[], int SIZE) {
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Please tell me the name of your book: ";
        cin >> x[i];
    }
    
}