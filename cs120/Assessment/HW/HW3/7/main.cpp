#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {

   // 7. Check if a number is prime

    int response {};
    bool ean = true;

    cout << "Give me a number:  ";
    cin >> response;

    for (int i = 2; i <= response/2; i++)
    {
       if ((response % i) == 0) {
           ean = false;
           break;
       } 
    }
    
    if (ean) {
        cout << "The number is prime" << endl;
    } else {
        cout << "Not a prime number" << endl;
    }
    return 0;
}