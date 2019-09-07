#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {
    int num {};
    int rev {};
    cout << "Give me a number and I will reverse it...      ";
    cin >> num;
    while(num > 0) { 
        rev = rev*10 + num%10; 
        num = num/10; 
    } 
    cout << rev << endl;
    return 0;
}