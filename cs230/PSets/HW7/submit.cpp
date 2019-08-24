#include <iostream>
using namespace std;

// Question 1
class Register {
    private:
        double* transactions;
        int* IDnum;
        int size;
        int counter;
    public:
        Register() {
            size = 100;
            transactions = new double[size];
            IDnum = new int[size];
            counter = 0;
        }
        Register(int s = 100) {
            transactions = new double[s];
            IDnum = new int[s];
            size = s;
            counter = 0;
        }
        Register(const Register &r) {
            transactions = r.transactions;
            IDnum = r.IDnum;
            size = r.size;
            counter = r.counter;
        }
        Register& operator=(const Register &r) {
            if(this != &r) {
                size = r.size;
                int* IDs = new int[size];
                for (int i = 0; i < size; i++) {
                    IDs[i] = r.IDnum[i];
                }
                delete[] IDnum;

                double* tempTransactions = new double[size];
                for (int i = 0; i < size; i++)
                {
                    tempTransactions[i] = r.transactions[i];
                }
                delete[] transactions;
                IDnum = IDs;
                transactions = tempTransactions;
                counter = r.counter;

                return *this; 
            }
        }

        void doTransaction() {
            int tempID;
            double temp;
            cout << "What is the amount of the transaction?    ";
            cin >> temp;
            transactions[counter] = temp;
            cout << "What is the ID of this transaction?    ";
            cin >> tempID;
            IDnum[counter] = tempID;
            counter++;
        }

        void printSpot(int spot) {
            cout << "Cost of transaction " << transactions[spot] << endl;
            cout << "ID number is " << IDnum[spot] << endl;
        }

        ~Register() {
            cout << "Destructor" << endl;
        }


};

int main() {
    // Question 1
    Register object1(100);
    object1.doTransaction();
    object1.doTransaction();
    object1.doTransaction();
    
    object1.printSpot(0);
    object1.printSpot(1);
    object1.printSpot(2);

    Register object2(object1);
    Register object3(3);
    object3 = object1;

    object1.doTransaction();
    object1.doTransaction();
    object1.doTransaction();

    object2.printSpot(0);
    object2.printSpot(1);
    object2.printSpot(2);
    object2.printSpot(3);
    object2.printSpot(4);
    object2.printSpot(5);

    object3.printSpot(0);
    object3.printSpot(1);
    object3.printSpot(2);
    object3.printSpot(3);
    object3.printSpot(4);
    object3.printSpot(5);

    // Question 2

    return 0;
}

/*
Question 5:

Fraction& operator=(const Fraction &f)

This is an example of overloading the assignment operator. c++ permits the assignment operator to be used
when assigning literals to variables as we have seen in 120. However, we can redefine the meaning of the "="
for a specific class. In this case, if the left and right side of the assignement operator are of the class
Fraction, then it will copy the values of the rhs over to the lhs. This is an example of sugar, and makes the code
easier to read and makes logical sense. The reason there are "&" is because it is a reference to a Fraction object
that we are going to be assigning the values to, that is the left hand side. We use & in the parens
because it is a reference to an object that we would like to copy, since we have the address, we can access the private
variables and members of the object. In order to prevent the programmer or others from mutating the values
we pass it in as a const so the values of the rhs are safe from being corrupted since we need only copy them.

Question 6:

What is a shallow copy and what is a deep copy in c++?

A shallow copy is when we only copy over the addresses of the private variables. This is called shallow because we are only
assigning the pointers of a second object to point to the same data that another object is pointing at. This is fast
and useful under certain circumstances since we may not need to copy over all of the data. One example of this is in the first 
example, where the copy constructor is used. Object 2 was shallow copied and whenever the transactions of the first object
are modified, they are also modified in object2. This is because the pointers are pointing at the same memory addresses. When the 
program does not contain data created on the heap, this is a good approach. Usually bad for things like arrays.

A deep copy is when we copy over the data rather that just copying over the pointers. For example, in example number 1 above,
when I overloaded the operator and assigned object 3 to object 1, it did not just copy over the pointers. It deleted the
data that was in object 3, and replaced it with the copied values from object 1. This was done by iterating through the array and 
copying each value one at a time. This is the way you would want to copy over the items that were created on the heap at runtime such as
arrays.

Question 7:

M& M::operator=(const M &d) {
    if(this != d) { <-------------------------
        delete[] entryList; <----------------------
        maxSize = d.maxSize;
        currentsize = d.currentsize;
        entryList = new Entry[d.maxsize];
        for(int i = 0; i < currentsize; i++) {
            entryList[i] = d.entryList[i];
        }

        return *this; <---------------------------------
    }
}
 */