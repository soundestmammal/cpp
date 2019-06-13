#include <iostream>

using namespace std;

int main()
{
    int num{};
    const int min {10};
    const int max {100};
    cout << "Enter a number greater than 10:   ";
    cin >> num;
    if (num >= 10){
        cout << "The number entered " << num << " was larger than the minimum of 10" << endl;
    }
    // Less than equal to 100

    //Between 10 and 100 including 10 and 100
    return 0;
}