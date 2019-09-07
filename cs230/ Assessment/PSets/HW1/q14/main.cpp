#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    srand(time(NULL));
    vector <double> v1 (10000);
    int counter = 0;
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = (rand() % 1001) / 1000.0;
        if(v1[i] >= 0.500) {
            counter++;
        }
        cout << counter << endl;
    }
    cout << "Of " << v1.size() << " random numbers " << counter << " are greater than 0.500" << endl;

    return 0;
}