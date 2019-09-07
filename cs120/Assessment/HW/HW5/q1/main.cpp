#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

class Car {
    private:
        string year, make;
        int speed;
    public:
        Car(string y, string m, int s) {
            year = y;
            make = m;
            speed = s;
        }

        Car() {
            year = "2000s";
            make = "GM";
            speed = 100;
        }

        void setYear(string y) { year = y; }
        void setMake(string m) { make = m; }
        void setSpeed(int s) { speed = s; }

        string getYear() { return year; }
        string getMake() { return make; }
        int getSpeed() { return speed; }
};

int main() {

    Car waymo("2019", "Chrysler", 25);
    cout << waymo.getYear() << endl;
    cout << waymo.getMake() << endl;
    cout << waymo.getSpeed() << endl;
    
    return 0;
}