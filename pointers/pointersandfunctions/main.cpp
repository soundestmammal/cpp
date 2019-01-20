#include <iostream>

using namespace std;

void double_data(int *int_ptr);
    void double_data(int *int_ptr){
        *int_ptr *= 2;
    };
int main()
{
    int value {10};
    cout << value << endl;
    double_data(&value);
    cout << value << endl;
    return 0;
}