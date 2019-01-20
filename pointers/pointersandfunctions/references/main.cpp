#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // int num {100};
    // int &ref {num};
    // cout << num << endl;
    // cout << ref << endl;
    // num = 200;
    // cout << num << endl;
    // cout << ref << endl;
    // num = 300;
    // cout << num << endl;
    // cout << ref << endl;
    vector <string> disney {"Aurora", "Belle", "Cinderella"};
    for (auto str: disney)
        str = "Funny";
    for (auto str: disney)
        cout << str << endl;

    for (auto &str: disney)
        str = "Funny";

    for (auto const &str:disney)
        cout << str << endl;
    cout << endl;
    return 0;
}