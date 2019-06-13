// // Section 16
// // Using Base Class Pointers

// #include <iostream>
// #include <vector>

// // This class uses Dynamic Polymorphism for the new withdraw method

// class Account {
//     class Checking: public Account {}
//     class Saving: public Account {}
//     class Trust: public Account {}
// }

// int main() {
//     std::cout << "\n---Pointers---" << std::endl;
//     Account *p1 = new Account();
//     Account *p2 = new Checkng();
//     Account *p3 = new Savings();
//     Account *p4 = new Trust();

//     p1->withdraw(1000);
//     p2->withdraw(1000);
//     p3->withdraw(1000);
//     p4->withdraw(1000);

//     Account *array [] = {p1,p2,p3,p4};
//     for(auto)
// }