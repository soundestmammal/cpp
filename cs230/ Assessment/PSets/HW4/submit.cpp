#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void bar(vector<int>& v);
void copyArray(int array1[], int size, int array2[]); // Question 6
void copyVector(vector<int>& v1, vector<int>& v2); // Question 6
int* insertArray(int num, int array[], int size); // Question 7
void insertVector(vector<int> &v, int num); // Question 7


int main () {
    srand(time(NULL));
    vector<int> v1(10);
    bar(v1);
    for (int i = 0; i < 10; i++)
    {
        cout << v1[i] << endl;
    }

    // Question 6


    vector<int> va{1,2,3,4,5,6,7,8,9,10};
    vector<int> vb(10);
    copyVector(va, vb);
    for (int i = 0; i < 10; i++) {
        cout << va[i] << endl;
    }

    for (int i = 0; i < 10; i++) {
        cout << vb[i] << endl;
    }

    const int SIZE = 10;
    int a1[SIZE];
    for (int i = 0; i < 10; i++)
    {
        a1[i] = i+1;
    }
    
    int a2[SIZE];
    copyArray(a1, SIZE, a2);

    for (int i = 0; i < 10; i++)
    {
        cout << a1[i] << endl;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a1[i] << endl;
    }
    
    int* a3 = insertArray(69, a2, SIZE);
    insertVector(va, 89);
    cout << "\nARRAY" << endl;
    cout << a3[11] << endl;
    cout << "\nVECTOR" << endl;
    for (int i = 0; i < va.size(); i++)
    {
        cout << va[i] << endl;
    }
    
    


    return 0;
}

void bar(vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = rand() % 100 + 1;
    } 
}

// Question 6
void copyArray(int array1[], int size, int array2[]) {
    for (int i = 0; i < size; i++)
    {
        *(array2 + i) = *(array1 + i);
    }
}

void copyVector(vector<int>& v1, vector<int>& v2) {
    for (int i = 0; i < v1.size(); i++) {
        v2[i] = v1[i];
    }   
}

int* insertArray(int num, int array[], int size) {
    int* newArray = new int[size+1];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }
    newArray[size+1] = num;
    return newArray;
}

void insertVector(vector<int>& v, int num) {
    v.push_back(num);
}