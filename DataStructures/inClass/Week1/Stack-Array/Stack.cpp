#include "Stack.h"

Stack::Stack() {
    size = 10;
    s = new std::string[size];
    counter = 0;
}

bool Stack::isFull() {
    return (size == counter);
}

bool Stack::isEmpty() {
    return (counter == 0);
}

void Stack::push(std::string item) {
    s[counter] = item;
    counter++;
}

std::string Stack::pop() {
    if(isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        exit(1);
    }
    counter--;
    return s[counter-1];
}

void Stack::peak() {
    if(isEmpty()) {
        exit(1);
    }
    std::cout << s[counter-1] << std::endl;
}

int Stack::getCounter()  { return counter; }



