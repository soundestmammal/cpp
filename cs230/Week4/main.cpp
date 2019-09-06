#include "student.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    Student s1(3);
    Student s2(s1);


    s2.setGrades();
    s1.displayGrades();
    s2.displayGrades();

    return 0;
}