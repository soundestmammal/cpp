#include <iostream>
#include <vector>

using namespace std;

// CAN;T change the pointer or the data
// void display(const vector <string> *const v){
//     for(auto str: *v)
//         cout << str << " ";
//     cout << endl;
// };
void anotherdisplay(int *array, int sentinel) {
    while(*array != sentinel)
        cout << *array++ << " ";
    cout << endl;
};
int main()
{
    // vector <string> princess {"Aurora", "Belle", "Cinderella"};
    // display(&princess);
    int scores[] {100, 97, 91, 83, 74, -1};
    anotherdisplay(scores, -1);
    return 0;
}