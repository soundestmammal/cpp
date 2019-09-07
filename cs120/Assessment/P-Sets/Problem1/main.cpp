#include <iostream>

using namespace std;

// Create a function called alpha that takes num as a parameter
void alpha(int num) {
    int i {1};
    while(i<=num) {
        cout << i << endl;
        i++;
    }
}

int main() {
    int input {};
    cout << "What number would you like to count up to? ";
    cin >> input;
    alpha(input);

    return 0;
}