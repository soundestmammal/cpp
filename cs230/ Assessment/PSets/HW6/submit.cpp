#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Student {
    private:
        string name;
        int ID;
        int* grades;
    public:
        Student(string name = "Al Gorithm") {
            this->ID = rand() % 100 + 1;
            this->name = name;
            grades = new int[4];
            for (int i = 0; i < 4; i++)
            {
                *(grades + i) = 0;
            }
        }
        ~Student() {
            cout << "Student Destructor" << endl;
        }
        string getName() { return name; }
        void setName(string n) { name = n; }
        int getID() { return ID; }
        void setID(int id) { ID = id; }
        void getGrades() {
            for (int i = 0; i < 4; i++)
            {
                cout << *(grades + i) << endl;
            }
        }
        void setGrades() {
            for (int i = 0; i < 4; i++)
            {
                cout << "ENTER A GRADE" << endl;
                cin >> *(grades + i);
            }
        }
};

class Ticket {
    private:
        int ID;
        string type;
        static int counter;
    public:
        Ticket() {

            cout << "What is the ID of the ticket" << endl;
            cin >> this->ID;
            cout << "What kind of violation was it: 1. Parking, 2. Moving, 3. General." << endl;
            cout << "Please enter the number to indicate the violation:     ";
            int temp;
            cin >> temp;
            if(temp == 1) {
                this->type = "Parking Violation";
            } else if (temp == 2) {
                this->type = "Moving Violation";
            } else if(temp == 3) {
                this->type = "General Misconduct";
            } else {
                this->type = "Not available";
            }
            counter++;
        }
        ~Ticket() {
            cout << "Ticket Destructor" << endl;
        }
        int getID() { return ID; }
        void setID(int id) { ID = id; }
        string getType() { return type; }
        void setType() {
            cout << "What kind of violation was it: 1. Parking, 2. Moving, 3. General." << endl;
            cout << "Please enter the number to indicate the violation:     ";
            int temp;
            cin >> temp;
            if(temp == 1) {
                this->type = "Parking Violation";
            } else if (temp == 2) {
                this->type = "Moving Violation";
            } else if(temp == 3) {
                this->type = "General Misconduct";
            } else {
                this->type = "Not available";
            }
        }
        static int getCounter() {
            return counter;
        }
        static void toString() {
            cout << "Parking Violation: 10 dollars" << endl;
            cout << "Moving Violation: 20 dollars" << endl;
            cout << "General Misconduct: 30 dollars" << endl;
        }
};

int Ticket::counter = 0;


int main() {

    Student s1("Rob");
    Student s2("Vin");
    s1.setGrades();
    s2.setGrades();
    cout << "Rob's grades" << endl;
    s1.getGrades();
    cout << "Vin's grades" << endl;
    s2.getGrades();

    Ticket t1;
    Ticket t2;
    cout << Ticket::getCounter() << endl;
    Ticket::toString();

    return 0;
}