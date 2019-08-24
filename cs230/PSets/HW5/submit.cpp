#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
using namespace std;

class Rectangle{
    private:
        int length;
        int width;
    public:
    Rectangle(int length = 1, int width = 1) {
        if(length > 0 && width > 0) {
            this->length = length;     
            this->width = width;
        } else {
            this->length = 1;
            this->width = 1;
        }
    }
    ~Rectangle() {
        cout << "Destructor" << endl;
    }

    void setLength(int l) { length = l; }
    int getLength() { return length; }
    void setWidth(int w) { width = w; }
    int getWidth() { return width; }

};

class Person{
    private:
        string name;
        int age;
    public:
        Person(string name1, int age1) {
            name = name1;
            age = age1;
        }
        int getAge() {
            return age;
        }
        string getName() { return name; }

};

class Eve {
    private:
        int* array;
    public:
        Eve() {
            array = new int[10];
            for (int i = 0; i < 10; i++)
            {
                *(array + i) = i + 1;
            }
        }
        void outputArray() {
            for (int i = 0; i < 10; i++)
            {
                cout << *(array+i) << endl;
            }
        }
};

class Student {
    private:
        string name;
        int age;
        string* courses;
    public:
        Student(string name = "Al Gorithm", int age = 18) {
            courses = new string[3];
        }
        string getName() { return name; }
        void setName(string n) { name = n; }
        int getAge() { return age; }
        void setAge(int a) { age = a; }
        void getCourses() {
            for (int i = 0; i < 3; i++)
            {
                cout << *(courses + i ) << endl;
            }
        }
        void setCourses() {
            for (int i = 0; i < 3; i++)
            {
                cout << "COURSE ";
                cin >> *(courses + i);
            }
            
        }
};

// Function Prototypes
void alice(int* x, int SIZE); // Question 1
int* bob(int SIZE); // Question 2
int* fillIt(int num); // Question 10


int main() {
    srand(time(NULL));

    // Question 1
    const int size1 = 10;
    int* array1 = new int[size1];
    alice(array1, size1);

    for (int i = 0; i < size1; i++)
    {
        cout << *(array1 + i) << endl;
    }

    // Question 2
    int* ptr2 = bob(10);
    for (int i = 0; i < 10; i++)
    {
        cout << *(ptr2 + i) << endl;
    }

    // Question 3

    int x3 = 5;
    int* ptr3 = &x3;
    cout << ptr3 << endl; // Address
    cout << &ptr3 << endl; // Address of Pointer
    cout << *ptr3 << endl; // Indirection Operator

    // Question 4
    Rectangle* ptr4 = new Rectangle[5];
    for (int i = 0; i < 5; i++)
    {
        ptr4[i].setLength(10);
    }
    
    for (int i = 0; i < 5; i++)
    {
        cout << ptr4[i].getLength() << endl;
    }
    
    // Question 5
    Person* ptr5 = new Person("Mallory", 95);
    cout << ptr5->getName() << endl;
    cout << ptr5->getAge() << endl;

    // Question 6
    Eve e;
    e.outputArray();

    /*
    Question 7

    Dynamic memory is when the program allocates memory on the heap during run time. That block of memory that was allocated can be located
    anywhere, and it is convention to use a pointer to maintain the address where the block of memory exists. For example, we could go around
    and allocate memory for arrays and lose track of the position of it, but that would create a memory leak since we would not have a way
    to get back to the memory location.

    A regular pointer is just a variable that holds a memory address. The pointer can have a type, that allows the programmer to better understand
    the data that the memory address that the pointer is holding looks like. A regular pointer can be used to iterate through an array, or it can be used as
    a way to serve as a gate to information similar to a reference.
    
    
     */

    // Question 8
    cout << "This is question 8" << endl;
    int chuck[10];
    for (int i = 0; i < 10; i++)
    {
        chuck[i] = i+1;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << chuck[i] << endl;
    }

    int* ptr8a = &chuck[0];
    int* ptr8b = &chuck[0];

    for (int i = 0; i < 10; i++)
    {
        *(ptr8b + i) = 5;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << *(ptr8a + i) << endl;
    }

    // Question 9
    Student s1;
    s1.setCourses();
    s1.getCourses();

    // Question 10
    int* ptr10 = fillIt(2);
    for (int i = 0; i < 5; i++)
    {
        cout << *(ptr10 + i) << endl;
    }
    
    return 0;
}

void alice(int* x, int SIZE) {
    for (int i = 0; i < SIZE; i++)
    {
        *(x + i) = pow(i+1, 3);
    }
}

int* bob(int SIZE) {
    int* array2 = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        *(array2 + i) = rand() % 1000 + 1;
    }
    return array2;
}

int* fillIt(int num) {
    int counter = 0;
    int iter = 0;
    while (counter < 20) {
        counter = pow(num, iter);
        iter++; 
    }
    int* array = new int[iter + 1];
    for (int i = 0; i < iter + 1; i++)
    {
        *(array + i) = pow(num, i);
    }
    return array;
}