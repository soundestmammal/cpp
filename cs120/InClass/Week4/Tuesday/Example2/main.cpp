#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <vector>

using namespace std;

string getName();
void setName();

int main() {

    // Part 1
    string name;
    name = getName();
    cout << name << endl;

    // Part 2
    string name2;
    setName(name2);
    cout << name2 << endl;

    return 0;
}

void setName(string& n) {
    cout << "What is your name?\n";
    cin >> n;
}

string getName() {
    string n;
    cout << "What is your name?\n";
    cin >> n;
    return n;
}