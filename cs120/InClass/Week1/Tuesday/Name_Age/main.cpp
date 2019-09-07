// Preprocesor directive
#include <iostream>
#include <string>

using namespace std;

int main() {

    cout << "What is your name? ";
    string name {};
    cin >> name;
    cout << "Hey, " << name << ". Welcome!" << endl;

    cout << "How old are you? ";
    int age {};
    cin >> age;
    cout << "Nice, it must be cool to be " << age << " years old!" << endl;
    cout << "Would you like to know how old you are in minutes? For yes, respond y, for no, respond n." << endl;
    char response {};
    cin >> response;
    if (response == 'y') {
        int minutes {};
        minutes = age * 365 * 24 * 60;
        cout << "Your age in minutes is: " << minutes << " old." << endl;
    } else {
        cout << "No problem, have a good day." << endl;
    }

    return 0;
}