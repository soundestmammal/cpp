#include <iostream>

using namespace std;

// Calculate the area of a room in Square Feet

int main()
{
    double length {};
    double width {};
    cout << "What is the length of the room? " << endl;
    cin >> length;
    cout << "What is the width of the room? " << endl;
    cin >> width;
    double area = length*width;
    cout << "The area of the room is " << area << " Square Meters" << endl;

    return 0;
}

