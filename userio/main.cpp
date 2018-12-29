// Challenge #1
// Task: User input number, store integer in favorite_number, return string and integer
// Status: Running
#include <iostream>

int main()
{
    int favorite_number;
    std::cout << "Enter your favorite number between 1 and 10:";
    std::cin >> favorite_number;
    std::cout << "No way! " << favorite_number << " is my favorite number too!" <<std::endl;
    return 0;
}