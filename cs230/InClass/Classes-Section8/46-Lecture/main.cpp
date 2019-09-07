#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Circle {
    private:
        double radius;
    public:
        void setRadius(double r) { (r > 0 ? radius = r : radius = 0); }
        double getRadius() { return radius; }
};

int main() {
    Circle c1, c2;
    c1.setRadius(3);
    cout << c1.getRadius() << endl;
    c2.setRadius(10);
    cout << c2.getRadius() << endl;
    return 0;
}

/*
A class is a concept, you can create an object with a class

private: usually the variables

public: member functions accessible by rest of program

Each variable should have a GET and a SET
GET - Accessor - Allows you to see it
SET - Mutator - Allows you to change it

Why private?
We don't want people to directly reassign the variables.
What we want to do is create a setter where we can specify rules that govern the way variables can be mutated.
    Example: Radius in the circle class is a private variable. This is good because we don't want to give people the 
    ability to mutate the radius to any value they want. We want to only permit them to input a positive number for the
    radius. Also, this makes the code much easier to debug, since there is only one gate for modifying the data.
 */