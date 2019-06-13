#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){
    // double var;

    // var = 5.0 / 2;
    // cout << var << endl;

    int change {};
    int q, d, n, p;

    cout << "How much change are you owed (in cents)? " << endl;
    cin >> change;

    // How many quarters do we need?
    q = change / 25;
    // What is the remainder of change after dispensing the quarters
    change = change % 25;

    d = change / 10;
    change = change % 10;

    n = change / 5;
    change = change % 5;

    p = change;

    cout << "You will recieve: \n" <<
        q << " quarters \n" <<
        d << " dimes \n" <<
        n << " nickels \n" << 
        p << " pennies \n" << endl;

    return 0;
}