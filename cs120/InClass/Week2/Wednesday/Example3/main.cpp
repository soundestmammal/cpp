#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

int main () {
    
    bool warm, raining;

    cout << "Is it hot today?\n";
    cin >> warm;
    cout << "Is it raining today?\n";
    cin >> raining;

    if (warm && raining) {
        cout << "Short sleeve shirt and bring an umbrella." << endl;
    }
    else if (warm && !raining) {
        cout << "Just short sleeves \n";
    }
    else if (!warm && raining) {
        cout << "Long sleeves and an umbrella" << endl;
    }
    else if (!warm && !raining) {
        cout << "Just long sleeves" << endl;
    }
    
    return 0;
}