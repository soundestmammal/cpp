#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main () {
    srand(time(NULL)); 
    vector<int> v(10);
    vector<int>::iterator it;
    for (it = v.begin(); i != v.end(); i++)
    {
        cout << *it << endl;
    }
    


    return 0;
}

void fillVector1(vector<int> &v) {
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++) {
        *it = rand() % 100;
    }
}

vector <int> fillVector2(vector<int> v) {
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++) {
        *it = rand() % 100;
    }
    return v;
}

/*
How to do static variables...

1. In the header file, declare a variable static type varname
2. Clothing::Counter = 0 assign 0 to the static variable
3. In the constructor have counter++
4. Create a void to show the counter
5. Call it by Counter::showCounter();
 */