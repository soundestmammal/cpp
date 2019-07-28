#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
string FavoriteColor();

int main() {

    string response;
    response = FavoriteColor();
    cout << "The user's favorite color is:  " << response << endl;

    return 0;
}

string FavoriteColor() {
    string color;
    cout << "What is your favorite color?   ";
    cin >> color;
    
    return color;
}

