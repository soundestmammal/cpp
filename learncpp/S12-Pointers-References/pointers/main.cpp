#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // int num {10};
    // cout << num << endl;
    // cout << sizeof num << endl;
    // cout << &num << endl;

    // int *p;
    // cout << p << endl; //garbage data
    // cout << &p << endl; //hex address
    // cout << sizeof p << endl; //4

    // p = nullptr;
    // cout << p << endl;

    // int *p1 {nullptr};
    // double *p2 {nullptr};
    // unsigned long long *p3 {nullptr};
    // vector<string> *p4 {nullptr};
    // string *p5 {nullptr};

    // cout << sizeof p1 << endl;
    // cout << sizeof p2 << endl;
    // cout << sizeof p3 << endl;
    // cout << sizeof p4 << endl;
    // cout << sizeof p5 << endl;

    int score {100};
    double temp_h {100.7};

    int *score_ptr {nullptr};
    score_ptr = &score;
    cout << score << endl;
    cout << &score << endl;
    cout << score_ptr << endl;

    score_ptr = &temp_h;
    
    return 0;
}