#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Function Prototypes
void doubleFillArray(double x[], int size); // Question 1
void outputArrayToFile(double x[], int size); // Question 1
void readTheArray(double x[]); // Question 2
void copyAndInsertArray(int a[], int size1, int b[], int size2, int position, int payload); // Question 3
void deleteValueFromArray(int oldArray[], int size1, int newArray[], int size2, int position); // Question 4
void printToFile(int a[], int b[]); // Question 4
int min(int x[], int size); // Question 5
int max(int x[], int size); // Question 5
double average(int x[], int size); // Question 5
void summaryStats(int x[], int size); // Question 5
void sumOfEntries(int x[][3], int rows, int columns); // Question 6
void sort(int x[], int size); // Question 7
void searchArray(int a[], int size); // Question 8
void askForNames(string x[], int size); // Question 9

int main() {
    srand(time(NULL));

    // Question 1
    const int SIZE1 = 100;
    double x[SIZE1];
    double theNewArray[SIZE1];

    doubleFillArray(x, SIZE1);
    outputArrayToFile(x, SIZE1);

    // Question 2
    readTheArray(theNewArray);

    // Question 3
    const int SIZE3 = 10;
    int emptyArray3[11];
    int original3[SIZE3];

    for (int i = 0; i < SIZE3; i++)
    {
        original3[i] = rand() % 101 + 1;
    }

    copyAndInsertArray(emptyArray3, 11, original3, SIZE3, 5, 69);
    
    ofstream output3;
    output3.open("new3.txt");

    for (int i = 0; i < 11; i++)
    {
        output3 << emptyArray3[i] << endl;
    }
    
    output3.close();

    output3.open("original3.txt");

    for (int i = 0; i < 10; i++)
    {
        output3 << original3[i] << endl;
    }

    output3.close();

    // Question 4

    int emptyArray4[9];
    int original4[10];

    // Populate an array
    for (int i = 0; i < 10; i++)
    {
        original4[i] = rand() % 101 + 1;
    }

    deleteValueFromArray(original4, 11, emptyArray4, 10, 5);

    printToFile(emptyArray4, original4);

    // Question 5

    int original5[100];

    for (int i = 0; i < 100; i++)
    {
        original5[i] = rand() % 100 + 1;
    }

    summaryStats(original5, 100);

    // Question 6
    const int rows = 3, columns = 3;
    int emptyArray6[rows][columns];

    // This is dope!
    int** ptr = new int*[3];
    for (int i = 0; i < 3; i++)
    {
       *(ptr+i) = new int[3];
    }
    
    // Populate an array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
        {
            emptyArray6[i][j] = rand() % 10 + 1;
        }
    }

    sumOfEntries(emptyArray6, rows, columns);

    // Question 7

    const int SIZE7 = 10;
    int emptyArray7[SIZE7];

    // Populate an array
    for (int i = 0; i < SIZE7; i++) {
        emptyArray7[i] = rand() % 100 + 1;
    }

    ofstream output7;
    output7.open("unsorted7.txt");
    for (int i = 0; i < SIZE7; i++)
    {
        output7 << emptyArray7[i] << endl;;
    }

    sort(emptyArray7, SIZE7);

    output7.close();

    output7.open("sorted7.txt");

    for (int i = 0; i < SIZE7; i++)
    {
        output7 << emptyArray7[i] << endl;;
    }
    
    output7.close();

    // Question 8
    const int SIZE8 = 100;
    int list8[SIZE8];

    for (int i = 0; i < SIZE8; i++)
    {
        list8[i] = rand() % 1000 + 1;
    }
    
    for (int i = 0; i < SIZE8; i++)
    {
        cout << list8[i] << endl;
    }
    
    searchArray(list8, SIZE8);

    // Question 9
    const int SIZE9 = 10;
    int emptyArray9[SIZE9];

    // Populate an array
    for (int &i : emptyArray9) {
        i = rand() % 100 + 1;
    }

    // Output array elements
    for(int k : emptyArray9) {
        cout << k << endl;
    }

    // Question 10
    const int SIZE10 = 3;
    string emptyArray10[SIZE10];

    askForNames(emptyArray10, SIZE10);

    return 0;
}

// Functions

// Question 1
void doubleFillArray(double x[], int size) {
    for (int i = 0; i < size; i++)
    {
        x[i] = rand() % 1001 / 1000.0;
    }
}

// Question 1
void outputArrayToFile(double x[], int size) {
    ofstream output1;
    output1.open("thefile2.txt");
    for (int i = 0; i < size; i++)
    {
        output1 << fixed << setprecision(3) << x[i] << endl;
    }
    output1.close();
}

// Question 2
void readTheArray(double x[]) {
    double a;
    int counter = 0;
    ifstream input;
    input.open("thefile2.txt");
    while(input >> a) {
        x[counter] = a;
        counter++;
    }
}

/*
Question 3
    The first array and size is empty.
    The second array and size is the array to be copied.
*/
void copyAndInsertArray(int a[], int size1, int b[], int size2, int position, int payload) {
    for (int i = 0; i < size1; i++)
    {
        if(i == position) {
            a[position] = payload;
        } else if (i < position){
            a[i] = b[i];
        } else {
            a[i] = b[i-1];
        }
    }
}

// Question 4
void deleteValueFromArray(int oldArray[], int size1, int newArray[], int size2, int position) {
    for (int i = 0; i < size2; i++)
    {
        if(i == position-1) {

        } else if( i < position-1) {
            newArray[i] = oldArray[i];
        } else {
            newArray[i-1] = oldArray[i];
        }
    }
    
}

// Question 4
void printToFile(int a[], int b[]) {
    ofstream output4;
    output4.open("new4.txt");

    for (int i = 0; i < 9; i++)
    {
        output4 << a[i] << endl;
    }
    
    output4.close();

    output4.open("original4.txt");

    for (int i = 0; i < 10; i++)
    {
        output4 << b[i] << endl;
    }

    output4.close();
}

// Question 5
int min(int x[], int size) {
    int min = 9999;
    for (int i = 0; i < size; i++)
    {
        if(x[i] < min) {
            min = x[i];
        }
    }
    return min;
}

int max(int x[], int size) {
    int max = -9999;
    for (int i = 0; i < size; i++)
    {
        if(x[i] > max) {
            max = x[i];
        }
    }
    return max;
}

double average(int x[], int size) {
    int total = 0;
    double average;
    for (int i = 0; i < size; i++)
    {
        total += x[i];
    }
    average = (total/double(size));
    return average;
}

void summaryStats(int x[], int size) {
    cout << "MIN:   " << min(x, size) << endl;
    cout << "MAX:   " << max(x, size) << endl;
    cout << "Average:   " << average(x, size) << endl;
}

// Question 6
void sumOfEntries(int x[][3], int rows, int columns) {
    int total = 0;
    ofstream output;
    output.open("sumQ6.txt");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {   
            total += x[i][j];
        }
    }
    output << total << endl;
    output.close();
}

// Question 7
void sort(int x[], int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i; j++)
        {
            if(x[j] < x[j+1]) {
                int temp;
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
        
    }
}

// Question 8
void searchArray(int a[], int size) {
    int response;
    cout << "Give me a number to search for...  ";
    cin >> response;

    int counter = 0;
    while(counter < size) {
        if (a[counter] == response) {
            cout << "The number is in the list!" << endl;
            cout << "It took " << counter << " iterations to find the number" << endl;
            exit(0);
        } 
        counter++;
    }
    cout << "Sorry the number is not in the list..." << endl;
}

// Question 10
void askForNames(string x[], int size) {
    
    // Populate an array
    for (int i = 0; i < size; i++) {
        string bud;
        cout << "What is the name of your friend?   ";
        cout << i+1 << "/" << size << "     ";
        cin >> bud;
        x[i] = bud;
        bud = "";
    }

    // Print to another file
    ofstream output10;
    output10.open("friends.txt");
    for (int i = 0; i < size; i++)
    {
        output10 << x[i] << endl;
    }

    output10.close();
}