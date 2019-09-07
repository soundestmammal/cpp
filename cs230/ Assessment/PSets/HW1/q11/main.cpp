#include <iostream>
using namespace std;

// Function Prototypes
void lightsOn(bool &lights);
void lightsOff(bool &lights);

int main() {
    bool lights = false;
    cout << lights << endl; // 0

    lightsOff(lights);
    cout << lights << endl; // 0

    lightsOn(lights);
    cout << lights << endl; // 1

    lightsOff(lights);
    cout << lights << endl; // 0

    /*
    
    Outputs:
    0
    0
    1
    0

    */

    return 0;
}

void lightsOn(bool &lights) {
    lights = true;
}

void lightsOff(bool &lights) {
    lights = false;
}