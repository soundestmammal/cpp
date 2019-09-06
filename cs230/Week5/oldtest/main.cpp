#include <iostream>
#include <vector>
using namespace std;

int main() {
    srand(time(NULL));

    auto sum = [](int a, int b) { return a + b; };
    int num = sum(3, 4);
    int* ptrArray = new int[5];
    for (int i = 0; i < 5; i++)
    {
        *(ptrArray + i) = rand() % 101;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << *(ptrArray + i) << endl;
    }
    cout << "***************" << endl;
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(rand() % 1000);
    }
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << endl;
    }

    vector<int>::iterator it;

    for (it= v1.begin(); it !=v1.end(); it++)
    {
        cout << *it << endl;
    }
    

    generate(v1.begin(), v1.end(), []() { return rand() % 1000; });

    for (it= v1.begin(); it !=v1.end(); it++)
    {
        cout << *it << endl;
    }

    int total = 0;
    for_each(v1.begin(), v1.end(), [&total](int i) {total+= i;});
    cout << total << endl;
    
    return 0;
}

int* createArray(int SIZE) {
    int* x = new int[SIZE];
    return x;
}
