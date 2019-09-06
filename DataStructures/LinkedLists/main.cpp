#include <iostream>
#include "LinkedList.h"

int main() {
    
    LinkedList last;
    last.build(4);
    last.traverse();
    std::cout<<last.getLength()<<std::endl;
    last.insertFirst(314);
    last.traverse();
    std::cout<<last.getLength()<<std::endl;    

    return 0;
}

