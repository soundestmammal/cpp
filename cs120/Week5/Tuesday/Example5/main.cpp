#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

// Function Proto
void julliet(int x[], int SIZE);

int main () {
    srand(time(NULL));
    const int SIZE = 10;
    int x[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        x[i] = i*i;
    }

    julliet(x, SIZE);
    return 0;
}

void julliet(int x[], int SIZE) {
    for (int i = 0; i < SIZE; i++)
    {
        if(x[i] % 2) {
            std::cout << "odd" << std::endl;
        } else {
            std::cout << "even" << std::endl;
        }
    }
    
}