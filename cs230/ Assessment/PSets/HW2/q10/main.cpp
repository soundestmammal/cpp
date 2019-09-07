#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Function Header/Prototype Things:
void askForNames(string x[], int size);

int main() {
    const int SIZE10 = 3;
    string emptyArray10[SIZE10];

    askForNames(emptyArray10, SIZE10);
    
    return 0;
}

void askForNames(string x[], int size) {
    
    // Populate an array
    for (int i = 0; i < size; i++) {
        string bud;
        cout << "What is the name of your friend?   ";
        cout << i+1 << "/" << size << "     ";
        cin >> bud;
        x[i] = bud;
        bud = "";
    }

    // Print to another file
    ofstream output10;
    output10.open("friends.txt");
    for (int i = 0; i < size; i++)
    {
        output10 << x[i] << endl;
    }

    output10.close();
}
