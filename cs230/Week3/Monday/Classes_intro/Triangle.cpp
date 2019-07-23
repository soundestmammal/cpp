#include "Triangle.h"

Triangle::Triangle(double height, double base) {
    this->height = height;
    this->base = base;
}

void Triangle::setBase(double b) { base = b; };
void Triangle::setHeight(double h) { height = h; };
double Triangle::getBase() { return base; };
double Triangle::getHeight() { return height; };

int Triangle::counter = 0;