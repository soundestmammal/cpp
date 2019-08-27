#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function Prototypes
void outputArray(vector<int> x);

// Classes

class Dragon {
    private:
        int numTeeth, fireStrength;
        static int counter;
    public:
       void static
            
};

int main(){

    vector<int> v1(10);
    for (int i = 0; i < 10; i++)
    {
        v1[i] = (i+1);
    }
    
    outputArray(v1);

    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v2.push_back(i+1);
    }
    
    outputArray(v2);

    vector<int> v3(10);
    vector<int>::iterator it;
    int counter = 1;
    for(it = v3.begin(); it!= v3.end(); it++) {
        *it = counter;
        counter++;
    }

    outputArray(v3);


    return 0;
}

// Functions

void outputArray(vector<int> x) {
    for (int i = 0; i < 10; i++)
    {
        cout << x[i] << endl;
    }
    
}