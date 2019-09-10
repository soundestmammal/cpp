#include <iostream>
#include <cmath>

using namespace std;

double mean(int x[], double size);

int main() {
    int x[7] = {40, 23, 41, 50, 49, 32, 41};
    cout << mean(x, 7) << endl;
    return 0;
}

// Calculate Sample Variance

double mean(int x[], double size) {
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total = x[i] + total;
    }
    return total/size;
}

double sampleVariance(int) {

}