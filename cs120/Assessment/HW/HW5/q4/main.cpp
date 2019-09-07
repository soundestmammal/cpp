#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <ctime>
#include <time.h>

using namespace std;

void deeEmVee(string& name, string& plate);

int main() {
    string name, plate;
    cout << name << endl;
    cout << plate << endl;
    deeEmVee(name, plate);
    cout << name << endl;
    cout << plate << endl;

    return 0;
}

void deeEmVee(string& name, string& plate) {
    cout << "What is your name?\n";
    cin >> name;
    cout << "What is your license plate?\n";
    cin >> plate;
}