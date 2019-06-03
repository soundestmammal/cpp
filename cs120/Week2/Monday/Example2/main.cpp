#include <iostream>
#include <string>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {

    int num;

    cout << "Choose one or two (as a number) \n";
    cin >> num;

    if (num == 1) {
        cout << "You picked 1" << endl;
        cout << "In the IF" << endl;
        int inScopeVar = 1;
        cout << inScopeVar << endl;
    }
    else if (num == 2) {
        cout << "you picked two" << endl;
    }
    else if (num == 3) {
        cout << "you picked three";
    }

    // cout << inScopeVar << endl;

    // Only the next line will be in the if scope
    // if (num == 1)
    //     cout << "Hello" << endl;
    //     cout << "Not in the IF" << endl;
    
    // AND logical operator
    if (num >= 1 && num <= 10) {
        cout << "you picked something between one and ten" << endl;
    }
    
    // OR logical operator
    if (num < 1 || num > 10) {

    }

    return 0;
}
