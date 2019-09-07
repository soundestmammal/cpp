#pragma once
#include "phone.h"
#include <string>
#include <iostream>
using namespace std;
 
class Talker{
    private:
        int minutesTalked;
        Phone phone;
    public:
        Talker(int mT, string type, bool working) : minutesTalked(mT) {
            Phone p(type, working);
            phone = p; // phone.operator=(p);
        }
};