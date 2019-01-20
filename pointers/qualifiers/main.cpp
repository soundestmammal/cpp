#include <iostream>

using namespace std;

int main()
{
    // Can qualify a pointer in 3 ways
    // 1. POinters to Constants
    // The data where the pointer is pointing too can not change!
    // POinter can point somewhere else

    int high_score {100};
    int low_score {65};
    const int *int_ptr {&high_score};
    // *int_ptr = 99; // Error! This is a read only variable

     //2. Constant POinters
     // It is the pointer itself that is constant
    // The address of teh pointer can not change
    // The data in the pointer can change
    int reyes {7};
    int wright {5};
    int *const mets_ptr {&reyes};
    

    //3. Constant pointers to constants
    // we have to use the const qualifier in the declaration twice!
    // The address of the pointer can not change and what it points to can not change
    // compiler error if we change the data or the pointer
    int namath {12};
    int hurts {2};
    const int *const bama_ptr {nullptr};

    return 0;
}