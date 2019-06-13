#include <iostream>

using namespace std;

void double_data(int *int_ptr);
void double_data(int *int_ptr){
    *int_ptr *= 2;
};
int main()
{
    int value {10};
    int *int_ptr {nullptr};
    cout << "The first value is " << value << endl; //10
    double_data(&value);
    cout << "The second value is " << value << endl; //20
    int_ptr = &value;
    cout << int_ptr << endl; //address
    double_data(int_ptr);
    cout << "Value: " << value << endl; // 40
    return 0;
}