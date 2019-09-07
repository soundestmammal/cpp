#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

// Function Prototypes
int dieRoll();

int main() {

    srand(time(NULL));

    // Question 2
    ofstream output;
    output.open("DieRollResults.txt");

    for (int i = 0; i < 10; i++)
    {
        output << dieRoll() << endl;
    }
    
    output.close();

    return 0;
}

int dieRoll() {
    return rand() % 6 + 1;
}