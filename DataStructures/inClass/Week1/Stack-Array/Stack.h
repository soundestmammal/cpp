#pragma once
#include <string>
#include <iostream>

class Stack {
private:
    int size;
    int counter;
    std::string* s;
public:
    Stack();

    Stack(const Stack& copyMe);

    bool isFull();

    bool isEmpty();

    void push(std::string s);

    std::string pop();

    void peak();

    int getCounter();
};