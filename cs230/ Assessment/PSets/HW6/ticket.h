#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Ticket {
    private:
        int ID;
        string type;
        static int counter;
    public:
        int getID();
        void setID();
        string getType();
        void setType();
        static string toString();
};