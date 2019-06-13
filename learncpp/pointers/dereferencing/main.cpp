#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
    // int score {100};
    // int score_ptr {&score};
    // cout << *score_ptr << endl;

    // *score_ptr = 200;
    // cout << *score_ptr << endl;
    // cout << score << endl;

    // int high_temp {102};
    // int low_temp {87};
    // int *temp_ptr {&high_temp};
    // cout << *temp_ptr << endl;
    // temp_ptr = &low_temp;
    // cout << *temp_ptr << endl;

    // string name {"Robert"};
    // string *str_ptr {&name};
    // cout << *str_ptr << endl;
    // name = "Samantha";
    // cout << *str_ptr << endl;

    vector <string> stooges {"Larry", "Moe", "Curly"};
    vector <string> *vector_ptr {nullptr};

    vector_ptr = &stooges;

    cout << "First stooge " << (*vector_ptr).at(0) << endl;
    cout << "Stooges: " << endl;
    for (auto stooge: *vector_ptr)
        cout << stooge << " ";
    cout << endl;
    cout << endl;
    return 0;
}