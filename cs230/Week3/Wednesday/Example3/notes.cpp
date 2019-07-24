#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3 = {1, 2, 3, 4, 5, 6};

    vector<int>::iterator it;

    for(it = v3.begin(); it < v3.end(); it++) {
        
        *it = 7;
        cout << *it << "\t";
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    for (int i = 0; i < v2.size(); i++)
    {
        v2[i] = i*i;
    }


    
    

    return 0;
}

/* Vectors: Inserting into vectors as well as iterating through vectors
    to output the elements that are in the array....

    Things to know:

    begin
    end
    at
    insert
    pushback
    popback
    erase
    empty
    size
 */