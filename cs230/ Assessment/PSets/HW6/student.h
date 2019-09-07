#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    private:
        string name;
        int ID;
        vector <int> *grades;
    public:
        string getName();
        int getID();
        void setName();
        void setID();
        void setGrades();
        int getGrades();

        Student() {
            
        }
};