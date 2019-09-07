#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

void listPrimes(int stopNum);
bool isPrime(int n);

int main() {
    int num = 100464;
    listPrimes(num);
    return 0;
}


void listPrimes(int stopNum) {
    for (int i = 2; i <= stopNum; i++) {
        if(isPrime(i)) {
            cout << i << endl;
        }
    }
}

bool isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;  
}