#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{   
    // int *int_ptr {nullptr};
    // int_ptr = new int;
    // cout << int_ptr << endl;

    size_t size {0};
    double *temp_ptr {nullptr};

    cout << "how many temps? ";
    cin >> size;

    temp_ptr = new double[size];
    cout << temp_ptr << endl;
    delete [] temp_ptr;
    return 0;
}