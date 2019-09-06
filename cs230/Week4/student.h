#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        int SIZE;
        double* grades;
    public:
        Student(int size) {
            this->SIZE = size;
            cout << "Creating a new student" << endl;
            this->grades = new double[SIZE];
            for (int i = 0; i < SIZE; i++) {
                grades[i] = 90;
            }
        } // end of constructor
        void setGrades() {
            for (int i = 0; i < SIZE; i++) {
                cout << "What is the new grade?     " << endl;
                cin >> grades[i];
            }
        }
        void displayGrades() {
            for (int i = 0; i < SIZE; i++) {
                cout << grades[i] << "\t";
            }
            cout << endl;
        }

};
