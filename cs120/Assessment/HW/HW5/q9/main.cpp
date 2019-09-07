#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

bool checkPrime(int num);
void renderList();

int main() {

    renderList();
    
    return 0;
}

bool checkPrime(int num) {
    for (int i = 2; i < num; i++)
        if(num % i == 0)
            return false;
    return true; 
}

void renderList() {
    for (int i = 0; i < 100; i++)
    {
        if(checkPrime(i)) {
            cout << i << endl;
        }
    }
    
}