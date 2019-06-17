#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string getName();

int main() {
    string theName;
    theName = getName();
    cout << "Hi there " << theName << endl;
    return 0;
}

string getName() {
    string n;
    cout << "What is your name?\n";
    cin >> n;
    return n;
}