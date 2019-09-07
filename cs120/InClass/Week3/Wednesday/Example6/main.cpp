#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int main() {

    string friendName = "";
    int counter = 0;

    ofstream output;
    output.open("friends.txt");

    while (counter < 3) {
        cout << "What is your friend's name? \n";
        getline(cin, friendName);
        output << friendName;
        counter++;
    }

    output.close();

    return 0;
}