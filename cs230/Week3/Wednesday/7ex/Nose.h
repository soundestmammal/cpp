#pragma once
#include <iostream>
#include <string>
using namespace std;

class Nose {
    private:
        string type;
        int size;
    public:
        Nose() { type = "A"; size = 1; }
        Nose(string t, int s) : type(t), size(s) {
            cout << "In the constructor" << endl;
        }
    
    // setters
    void setType(string t) { type = t; };
    void setSize(int s) { size = s; };

    // getters
    string getType() { return type; };
    int getSize() { return size; };
};