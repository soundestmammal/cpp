#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    // Question 1
    vector<int> v1{1, 3, 40, 504, 388};
    int counter = 0;
    count_if(v1.begin(), v1.end(), [&counter](int i){
        if(i > 5) {
            return counter++;
        }
    });

    cout << counter << endl; // 3

    // Question 2
    for_each(v1.begin(), v1.end(), [](int i){
        cout << i << endl;
    });

    // Question 3
    function<int(int, int)=""> fxsquare = [](int x, int y) -> int {
        int xsquare = [](int x) { return x*x; }(x);
        int ysquare = [](int y) { return y*y; }(y);
        int twoxy = [](int x, int y) { return 2 * x * y; }(x, y);
        return xsquare + ysquare + twoxy;
    };
    int retValue = fxsquare(5,3);

    /*
    This code takes in two inputs x and y, and returns (x^2 + y^2 +2xy),
    it is cool to see this approach because it composes the solution by using 
    smaller inline functions to build up to the solution. 
     */

    // Question 4
    vector<int> v4(10);
    vector<int> v4a(10);
    generate(v4.begin(), v4.end(), [start = 1]() mutable{
        return start++;
    });

    generate(v4a.begin(), v4a.end(), [start = 1]() mutable{
        return start++;
    });

    for (int i = 0; i < 10; i++)
    {
        cout << v4[i] << endl;
    }
    
    // Question 5
    int counter5 = 0;
    for_each(v4.begin(), v4.end(),[&counter5](int i){
        return counter5 += i;
    });

    cout << counter5 << endl; 

    // Question 6
    for_each(v4.begin(), v4.end(), [](int i){
        if(i %2 == 0) {
            cout << i << endl;
        }
    });

    // Question 7
    vector<int> v7 (10);
    generate(v7.begin(), v7.end(), [start = 0]() mutable{
        start++;
        return pow(start, 2);
    });

    for (int i = 0; i < 10; i++)
    {
        cout << v7[i] << endl;
        cout << endl;
    }
    
    return 0;
}