#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int start, end;

    cout << "What are the start and end numbers:" << endl;
    cin >> start >> end;

    while (start <= end) {
        cout << start << " ";
        start++;
    }
    cout << endl;
    return 0;
}