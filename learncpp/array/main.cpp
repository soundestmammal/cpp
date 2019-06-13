// Why use an array?

// Keep track of 10,000 test scores.
// Collection of elements and give it a specific name

/* 
Characteristics of Array in C++:
* Fixed Size
* Elements are all of the same type
* Stored contiguously in memory
* individual elements can be accessed by their position or index

* There is no bounds checking! This is really important.
* If you tell the computer to go ahead and take an index from
* an array that does not have that index, then
* The computer will return whatever is in memory at that locaiton.

*/

#include <iostream>

using namespace std;

int main()
{
    // How to initialize an array
    // Element_type array_name [# of elements] {init list}
    // int test_scores [5] {100, 95, 99, 85, 87};
    // int second_test [10] {3,5};
    // Declaring an array without an index will count up to it?
    // const double days_in_year {365};
    // This is decaring without setting a number or elements
    // char vowels[] {'a', 'e', 'i', 'o', 'u'};
    // cout << "\nThe last vowel is " << vowels[4] << endl;
    // cout << "\nThe first test score is " << test_scores[0] << endl;
    // cin >> vowels[5]; Do not do this!
    // int grades [5] {100, 90, 80, 70, 60};
    // cout << "The first recorded grade is " << grades[0] << endl;
    // cout << "The second recorded grade is " << grades[1] << endl;
    // cout << "The third recorded grade is " << grades[2] << endl;
    // cout << "The fourth recorded grade is " << grades[3] << endl;
    // cout << "The fifth recorded grade is " << grades[4] << endl;
    // cin >> grades[0];
    // cin >> grades[1];
    // cin >> grades[2];
    // cin >> grades[3];
    // cin >> grades[4];
    // cout << "The first recorded grade is " << grades[0] << endl;
    // cout << "The second recorded grade is " << grades[1] << endl;
    // cout << "The third recorded grade is " << grades[2] << endl;
    // cout << "The fourth recorded grade is " << grades[3] << endl;
    // cout << "The fifth recorded grade is " << grades[4] << endl;
    
    return 0;
}