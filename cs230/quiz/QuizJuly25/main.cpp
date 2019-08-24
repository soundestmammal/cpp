#include <iostream>
#include <ctime> 
#include <cmath>
#include <vector>
#include <string>

using namespace std;

class Bottle {
private:
    int numOunces;
    string bottleColor;
public:
    Bottle(int numOunces = 16, string bottleColor = "clear") {
        this->numOunces = numOunces;
        this->bottleColor = bottleColor;
        cout << "this is the constructor" << endl;
    }

    void setNumOunces(int n) { numOunces = n; };
    void setBottleColor(string c) { bottleColor = c; };
    int getNumOunces() { return numOunces; };
    string getBottleColor() { return bottleColor; };
    ~Bottle() {
        cout << "This is in the destructor" << endl;
    }
};

class Dragon {
private:
    int numTeeth;
    int fireStrength;
    static int counter;
public:
    Dragon(int numTeeth = 100, int fireStrength = 1) {
        counter++;
        this->numTeeth = numTeeth;

        if(fireStrength < 1 || fireStrength > 10) {
            cout << "This is an invalid fire strength, default will be 1, feel free to use setFireStrength to change the fire strength" << endl;
            this->fireStrength = 1;
        } else {
            this->fireStrength = fireStrength;
        }
    }; // end of constructor


    //getters and setters
    int getNumTeeth() { return numTeeth; };
    int getFireStrength() { return fireStrength; };
    void setNumTeeth(int n) { numTeeth = n; };
    void setFireStrength(int f) { 
        if(f < 1 || f > 10) {
            cerr << "This is an invalid fire strength, program terminating..." << endl;
            exit(1);
        } else {
            fireStrength = f;
        }
    };

    // static void showCounter() {
    //     cout << "The current counter is " << counter << endl;
    // }
    void static countDragons() {
        cout << counter << endl;
    }
    ~Dragon() {
        cout << "This is in the destructor" << endl;
    }
};

class Keyboard {
private:
    int size;
    string* inventoryList;
    int* inventoryCount;
public:
    Keyboard(int size = -1) {
        // Get the size of the string array
        while (size < 1) {
            cout << "How many different keyboards do you have in inventory" << endl;
            cin >> size;
            if(size < 0) {
                cout << "The number of Keyboards must be greater than 0" << endl;
            } else {
                this->size = size;
            }
        }
        this->inventoryList = new string[size];
        //inventory = new string[size];
        this->inventoryCount = new int[size];
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the name of Item # " << i+1 << "\t";
            cin >> *(inventoryList + i);
            cout << "Enter the quantity of " << *(inventoryList + i) << "\t";
            cin >> *(inventoryCount + i);
        };
    }
    string getInventoryAtPosition(int i) {
            return *(inventoryList + i);  
    }
    void printInventoryListToConsole() {
        for (int i = 0; i < size; i++)
        {
            cout << *(inventoryList + i) << "\t" << *(inventoryCount + i) << endl;
        }
    }
    void setInventory() {
        string s;
        int n;
        int index;
        cout << "Which item would you like to edit?     ";
        cin >> s;
        for (int i = 0; i < size; i++)
        {
            if(inventoryList[i] == s) {
                index = i;
            }
        }
        cout << "The current inventory of " << s << " is " << *(inventoryCount + index) << endl;
        cout << "What would you like to change the inventory to?    ";
        cin >> n;

        *(inventoryList + index) = n;

        cout << "The new inventory of " << s << " has been changed to " << *(inventoryCount + index) << " items.";
        
    }
    ~Keyboard() {
        cout << "This is in the destructor" << endl;
    }
};

// Function Prototypes
void outputVector(vector<int> x);

int Dragon::counter = 0;

int main() {
    // Question 1
    vector<int> v1(10);
    for (int i = 0; i < 10; i++) {
        v1[i] = i+1;
    }
    outputVector(v1); // outputs 1-10

    // Question 2
    vector<int> v2(10);
    vector<int>::iterator it;
    int counter = 1;
    for(it = v2.begin(); it != v2.end(); it++) {
        *it = counter;
        counter++;
    }

    // Question 3
    outputVector(v2); // outputs 1-10

    // Question 4
    Bottle q4(10, "green");
    // cout << q4.getBottleColor() << endl;
    // cout << q4.getNumOunces() << endl;
    // q4.setBottleColor("red");
    // cout << q4.getBottleColor() << endl;
    // q4.setNumOunces(24);
    // cout << q4.getNumOunces() << endl;

    // Question 5
    
    // Slight problem with the counter initialization... get around to this later
    // int Dragon::counter = 0;

    Dragon d[2];
    cout << d[0].getNumTeeth() << endl;
    cout << d[1].getNumTeeth() << endl;
    cout << d[0].getFireStrength() << endl;
    cout << d[1].getFireStrength() << endl;

    d[0].setFireStrength(8);
    cout << d[0].getFireStrength() << endl;
    Dragon::countDragons(); // hm

    Keyboard k;
    k.printInventoryListToConsole();
    k.setInventory();
    k.printInventoryListToConsole();
    
    return 0;
}

void outputVector(vector<int> x) {
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << endl;
    }
}