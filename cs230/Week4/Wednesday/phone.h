#include <iostream>
using namespace std;

class Phone{
protected:
    string type;
    bool working;

public:
    Phone(string type = "Samsung", bool working = true) : type(type), working(working) {
        cout << "A phone was created \n";
    }

    Phone(string type = "Samsung", bool working = true){
        this->type = type; 
        this->working = working;
    }

    Phone(const Phone &phone) { // copy constructor
        this->type = phone.type;
        this->working = phone.working;
    }

    Phone& operator=(const Phone &phone) {
        type = phone.type;
        working = phone.working;
        return *this;
    }

    // getters and setters
    void setType(string t) { type = t; }
    void setWorking(bool w) { working = w; }
    string getType() { return type; }
    bool getWorking() { return working; }
};