#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    srand(time(NULL));
    // vector <int> v1 (100);
    // for (int i = 0; i < 100; i++) {
    //     v1[i] = rand() % 11; // Populate with a random number from 0-10
    // }

    // int greaterThan5 = count_if(v1.begin(), v1.end(), [&greaterThan5](int i) {
    //     if(i > 5) {
    //         greaterThan5++;
    //     }
    // });

    // int counter = 0;
    
    // for (int i = 0; i < 100; i++)
    // {
    //     if(v1[i] > 5){
    //         counter++;
    //     }
    // }
    
    // cout << greaterThan5 << endl;

    // vector <int> v;
    // for (int i = 0; i < 10; i++)
    // {
    //     v.push_back(rand() % 1000 + 1);
    // }
    // int sum = 0;

    // vector <int> k;
    // for_each(v.begin(), v.end(), [](int i){
    //     cout << i << " ";
    // });

    // for_each(v.begin(), v.end(), [](int i){
    //     cout << i << " ";
    // });

    // for_each(v.begin(), v.end(), [&sum](int i){ return sum += i; });
    // cout << "This is the sum" << endl;
    // cout << sum << endl;
    // int newSum = sum;
    // for_each(v.begin(), v.end(), [&newSum](int i){
    //     return newSum -= i;
    // });
    // cout << newSum << endl;

    // for_each(v.begin(), v.end(), [&k](int i){
    //     if(i % 2 == 1) {
    //         k.push_back(i);
    //     }
    // });
    
    // for_each(k.begin(), k.end(), [](int i){ cout << i << endl;});

    // int x = count_if(v.begin(), v.end(), [](int i){
    //     return i%3 == 0;
    // });

    // cout << "Number of numbers that are mod 3: " << x << endl;

    // vector<long> vlong(50);
    // generate(vlong.begin(), vlong.end(), [start = 2]() mutable{
    //     return start++;
    // });

    // for (vector<long>::iterator it = vlong.begin(); it != vlong.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // transform(vlong.begin(), vlong.end(), vlong.begin(),
    // [](long i) {
    //     vector<long> list(i -2);
    //     generate(list.begin(), list.end(), [start = 2]()mutable{return start++; });
    //     if(any_of(list.begin(), list.end(), [i](long var){return i%var == 0; }));
    //     i = 0;
    //     return i;
    // });
    vector <int> avector (10);
    for (int i = 0; i < avector.size(); i++)
    {
        avector[i] = i + 1;
    }
    
    vector<int>::iterator it;

    for (it = avector.begin(); it != avector.end(); it++)
    {
        cout << *it << endl;
    }
    
    cout << endl;
    for_each(avector.begin(), avector.end(), [](int i){ cout << i << endl; });
    


    return 0;
}

/* 
Lambda for exams!!!
Make sure you can use the following functions from algorithm (and numeric): 
    all_of, 
    any_of, If anywhere ever in the list, that is given, whenever it is try, then we should make the i = 0
    for_each, 
    find, 
    find_if, 
    count,
    count_if, 
    copy, 
    generate, 
    sort, 
    accumulate, 
    iota.


 */