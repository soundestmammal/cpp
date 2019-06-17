#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string getName();
int getAge();

int main() {
    string theName;
    int age;
    theName = getName();
    age = getAge();
    cout << "Hi there " << theName << endl; 
    cout << "You are " << age << " years old." << endl;
    return 0;
}

int getAge() {
    int age = 0;
    while (age <= 0 || age >= 100) {
        cout << "What is your age?\n";
        cin >> age;
    }
    return age;
}

string getName() {
    string n;
    cout << "What is your name?\n";
    cin >> n;
    return n;
}