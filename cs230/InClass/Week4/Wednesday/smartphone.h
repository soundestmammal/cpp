#pragma once
#include "Phone.h"
#include <iostream>
#include <string>
using namespace std;

class SmartPhone : Phone {
    private:
        int internetGrade;
    public:
        SmartPhone(int iG, string type, bool working) : Phone(type, working), internetGrade(iG) {
            cout << "Creating a smartphone...\n";
        }

        void info() {
            cout << internetGrade << "\t" << type << "\t" << working << endl;
        }
};