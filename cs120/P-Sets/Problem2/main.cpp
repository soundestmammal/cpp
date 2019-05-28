#include <iostream>

using namespace std;

void bravo() {
    int sum {};
    for (int i = 1; i<=10; i++) {
        sum = sum + i;
    }
    cout << sum << endl;

}

int main() {
    bravo();
    return 0;
}