#include <iostream>
#include <vector>

using namespace std;

// int *largest_int(int *int_ptr1, int *int_ptr2) {
//     if (*int_ptr1 > *int_ptr2)
//         return int_ptr1;
//     else
//         return int_ptr2;
// }

int *create_array(size_t size, int init_value = 0){
    int *new_storage {nullptr};
    new_storage = new int[size];
    for (size_t i{0}; i < size; ++i)
        *(new_storage + i) = init_value;
    return new_storage;
}
void display(const int *const array, size_t size){
    for (size_t i{0}; i < size; ++i)
        cout << array[i] << ' ';
    cout << endl;
}
int main()
{
    // int a {100};
    // int b {200};
    // int *largest_ptr {nullptr};
    // largest_ptr = largest_int(&a, &b);
    // cout << *largest_ptr << endl;
    int *my_array {nullptr};
    size_t size;
    int init_value {};

    cout << "How many integers would you like to allocate: ";
    cin >> size;
    cout << "What value would you like to initialize to: ";
    cin >> init_value;

    my_array = create_array(size, init_value);
    display(my_array, size);
    delete [] my_array;
    return 0;
}