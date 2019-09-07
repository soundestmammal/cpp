#include <iostream>

int main() {

    const int SIZE = 4;
    int A[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        std::cin >> A[i];
    }
    for (int spot : A) {
        std::cout << spot << std::endl;
    }
    

    return 0;
}
