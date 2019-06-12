#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int age {0};
    int i {0};

    while(age < 1 || age > 100){
        if (i >=3) {
            break;
        }
        i++;
        cout << "What is your age? \n";
        cin >> age;
    }

    return 0;
}