#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Function Headers
void alpha(int x[], int SIZE);
void bravo(int* x, int SIZE);
int* charlie();
double delta(int* array, int SIZE);
void foxtrot(int* array, int SIZE);
void duplicates(int* array, int SIZE);

int main() {
    
    // int y[3] {1, 2, 1};
    // int* ptr3 =  &y[0];

    // double response;
    // response = delta(ptr3, 3);

    // cout << response << endl;

    int x = 20;
    int *ptr = &x;

    cout << "The memory location of x is:     " << &x << endl;
    cout << "The memory location of the pointer:    "  << &ptr << endl;
    cout << "The information the pointer points to:     " << *ptr << endl;

    const int SIZE = 10;
    int Echo[SIZE];

    int* ptr1 = &Echo[0];
    int* ptr2 = &Echo[0];

    for (int &i : Echo) 
    {
         static int count = 1;
         i = count;
         count++;
    }
    
        for (int i = 0; i < 10; i++)
    {
        *(ptr2 + i) = 5;
    }

        for (int i = 0; i < 10; i++)
    {
        cout << *(ptr1 + i) << endl;
    }

    int z[22] {1, 3, 3, 5, 6, 3, 5, 2, 4, 1 ,4, 2, 3, 1, 1, 5, 6, 2, 6, 3, 1, 6};

    int* ptr8 = &z[0];

    duplicates(ptr8, 22);

    return 0;
}

// Function Definitions

void alpha(int x[], int SIZE){
    for (int i = 1; i < SIZE+1; i++) {
        x[i-1] = pow(i, 2);
    }  
}

void bravo(int* x, int SIZE) {
    for (int i = 0; i < SIZE; i++)
    {
        *(x + i) = pow(i, 2);
    }
}

int* charlie() {
    int* newArray = new int[10];
    for (int i = 0; i < 10; i++)
    {
        *(newArray + i) = rand() % 100 + 1;
    }
    return newArray;
}

double delta(int* array, int SIZE) {
    int total = 0;
    double average = 0;
    for (int i = 0; i < SIZE; i++)
    {
        total += *(array + i);
    }
    average = total / double(SIZE); // feel bad doing this to a constant but need to avoid integer division.
    return average;
}

void foxtrot(int array[], int SIZE) {
    ofstream output;
    output.open("quiz2.txt");

    for (int i = 0; i < SIZE; i++)
    {
        output << array[i] << endl;
    }

    output.close();
}

// Time Complexity: (Quadratic) O(Predefined Range * SIZE of search space) ~ n^2
void duplicates(int* array, int SIZE) {
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        count = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if(*(array + j) == i) {
                count++;
            }
        }
        cout << "The number of " << i << " in the array is " << count << endl;
    }
}

// Trying to make it a tad faster...

void hash(int* array, int SIZE) {
    int* hashTable = new int[SIZE];
    int key = NULL;

    // Zero out hash table
    for (int i = 0; i < SIZE; i++)
    {
        *(hashTable + i) = 0;
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        key = (*(array + i) % SIZE);
        hashTable[key]++;
    }
}

int retrieveCount(int num, int SIZE) {
    int key = (num % SIZE);
    *(hashTable[key]);
}