#include <iostream>

void myMemoryPlayFunction() {
	int* p = new int;
	std::cout << "Give an int room ";
	std::cin >> *p; // Whatever integer the user provides, go to the address stored in p and put the int in there
	std::cout << "\n" << *p << std::endl;
    std::cout << "The address of the room is:   " << p << std::endl;
    delete p;
    std::cout << "The address of the room is:   " << p << std::endl;    
    std::cout << "\n" << *p << std::endl;

    
    double* q;
    double res;
    q = new double[3];
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Give a double:    ";
        std::cin >> res;
        *(q + i) = res;
    }
    
    std::cout << "The location is  " << q << " " << q+1 << " " << q+2 << std::endl;
    delete q;
    
}

int main() {
    myMemoryPlayFunction();
    return 0;
}