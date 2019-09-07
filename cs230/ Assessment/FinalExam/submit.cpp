#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

/*
Q1 ~ Done
Q2 - Done
Q3 - Done
Q4 - Done
Q5 - Done
Q6 -  Ran out of time
Q7 - Done
Q8 - Done
Q9 - Done
Q10 - Done
Q11 - Done
Q12 - DONE
 */

// Classes
class Box{
    private:
        int length;
        int width;
        int height;
        static int counter;
    public:
        Box() {
            length = 1;
            width = 1;
            height = 1;
            counter++;
        }
        Box(int l, int w, int h) {
            // If any of them are negative just default all to 1
            // Because I want them to have to reset all of the values

            if(l < 1 || w < 1 || h < 1) {
                length = 1;
                width = 1;
                height = 1;
                counter++;
            } else {
                length = l;
                width = w;
                height = h;
                counter++;
            }
        }
        ~Box() {
            cout << "Destructor" << endl;
        }

        int getLength() { return length; }
        int getWidth() { return width; }
        int getHeight() { return height; }
        void setLength(int l) { length = l; }
        void setWidth(int w) { width = w; }
        void setHeight(int h) { height = h; }
        static int showCount() { return counter; }
};

int Box::counter = 0;

// Question 5
class Squares {
    private:
        int* sqArray;
        int size;
    public:
        Squares(int s = 11) {
            if(s < 1) {
                cout << "Give a valid size of numbers next time, giving you 10 squares" << endl;
                size = 11; 
            } else {
                this->size = s;
            }
            sqArray = new int[size];
            for (int i = 0; i < size; i++)
            {
                *(sqArray + i) = pow(i, 2);
            }     
        }
        Squares(const Squares &s) {
            size = s.size;
            sqArray = &s.sqArray[0];
        }
        ~Squares() {
            cout << "Squares destructor" << endl;
        }

        int getSize() { return size; }

        void resetSize(int s) {
            if(s < 1) {
                cout << "Give a valid size of numbers next time, giving you 10 squares" << endl;
                this->size = 11; 
            } else {
                this->size = s;
            }
            int* tempArray = new int[s];
            for(int i = 0; i < s; i++)
            {
                *(tempArray + i) = pow(i, 2);
            }
            delete[] sqArray;
            sqArray = tempArray;
            delete[] tempArray;
        }

        int getSquare(int num) {
            return *(sqArray + num);
        }

        void showList() {
            for (int i = 0; i < size; i++)
            {   
                // cout << "This is i" << i << endl;
                cout << sqArray[i] << endl;
            }  
        }

};



// Question 12

class Person {
    protected:
        string name;
    public:
        Person() {
            name = "Al Gorithm";
        }
        ~Person() {
            cout << "Person Destructor" << endl;
        }
        string getName() { return name; }
        void setName(string n) { name = n; }
};

class Student : public Person {
    private:
        int gpa;
    public:
        Student() {
            gpa = 100;
        }
        ~Student() {
            cout << "Student Destructor" << endl;
        }
        int getGPA() { return gpa; }
        void setGPA(int g) { gpa = g; } 
};

// Function Prototypes
int* charlie(int size);

int main () {
    // Question 1
    const int SIZE1 = 10;
    int alpha[SIZE1];
    int counter1 = 1;
    for (int i = 0; i < SIZE1; i++)
    {
        *(alpha + i) = counter1;
        counter1 = counter1 + 2;
    }
    for (int i = 0; i < SIZE1; i++)
    {
        cout << *(alpha + i) << endl;
    }
    
    
   
    // Question 2
    int bravo [SIZE1];
    int counter = 1;
    for(int &i : bravo) {
        i = counter;
        counter++;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << bravo[i] << endl;
    }

    // Question 3
    int* ptr3 = charlie(20); // Pass it back to main
    for (int i = 0; i < 20; i++)
    {
        cout << *(ptr3 + i) << endl;
    }
    
    // Question 4
    cout << "Question 4" << endl;
    Box* epsilon = new Box[3];

    // Both output 3
    cout << epsilon[2].showCount() << endl;
    cout << Box::showCount() << endl;

    // Question 5
    cout << "\nQuestion 5" << endl;

    Squares sq1;
    cout << sq1.getSize() << endl;
    sq1.showList();

    // Answer for Question 5
    Squares sq2(sq1); // Copy constructor

    cout <<"Square 2" << endl;
    cout << sq2.getSize() << endl;
    sq2.showList();

    // Question 6 - Darn ran out of time
    cout << "\nQuestion 6" << endl;
    vector<double> v6 { 10.5, 20.5, 30.5, 40.5 ,50.5};

    auto edgar = [](vector<double> v) {
        count(v.begin(), v.end(), [](int i){
        return i;
    })-> [i, v.size()](){
        return double(i/v.size);
    };




    // Quesiton 7 { Greater than 12 : There are 5 greater than 12}
    cout << "Question 7" << endl;
    vector <int> v7 {1, 5, 10, 15, 105, 1058, 3845, 3849}; 
    int counter7 = 0;
    for_each(v7.begin(), v7.end(), [&counter7](int i) {
        if(i > 12) {
            return counter7++;
        }
    });
    
    // Correctly outputs 5
    cout << "The number of elements greater than 12:    " << counter7 << endl;

    // Question 8
    vector <int> v8 (17);
    for (int i = 0; i < 17; i++)
    {
        v8[i] = i+1;
    }
    for_each(v8.begin(), v8.end(), [](int i){
        cout << i << endl;
    });

    // Question 9
    cout << "\nQuestion 9" << endl;

    vector <int> v9 (10);
    generate(v9.begin(), v9.end(), [start = 1]() mutable{
        return start++;
    });
    for_each(v9.begin(), v9.end(), [](int i){
        cout << i << endl;
    });

    // Question 10
     cout << "\nQuestion 10" << endl;
    for_each(v9.begin(), v9.end(), [](int i) {
        if(i%2 == 1) {
            cout << i << endl;
        }
    });

    // Question 11
     cout << "\nQuestion 11" << endl;

    int x11 = 12;
    int* ptr11 = &x11;
    cout << ptr11 << endl; // Memory location of "x"
    cout << &ptr11 << endl; // Memory location of Pointer
    cout << *ptr11 << endl; // Infomation located at address which the pointer points to

    // Question 12
     cout << "\nQuestion 12" << endl;

    Student s1;
    cout << "The name for object s1 is:     " << s1.getName() << endl;
    s1.setName("May Trix");
    cout << "The new name for object s1 is:     " << s1.getName() << endl;
    cout << "GPA is:    " << s1.getGPA() << endl;
    
    return 0;
}

int* charlie(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; i++)
    {
        *(array + i) = size - i;
    }
    return array;
    
}
