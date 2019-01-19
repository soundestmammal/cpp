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

    int high_temp {102};
    int low_temp {87};
    int *temp_ptr {&high_temp};
    cout << *temp_ptr << endl;
    temp_ptr = &low_temp;
    cout << *temp_ptr << endl;
    return 0;
}