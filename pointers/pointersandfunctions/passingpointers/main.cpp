#include <iostream>
#include <vector>
#include <string>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x {100}, y {200};
    cout << x << endl;
    cout << y << endl;
    swap(&x, &y);
    cout << x << endl;
    cout << y << endl;
    return 0;
}