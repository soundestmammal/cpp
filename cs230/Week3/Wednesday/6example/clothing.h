#pragma once
#include <iostream>
#include <string>

using namespace std;

class Clothing {
private:
    string name;
    int numType;
    string* nameType;
    int* countType;
    static int counter;
public:
    Clothing() {
        cout << "What is the name of this class?\n";
        cin >> name;
        cout << "How many types do you have?\n";
        cin >> numType;
        setUpArrays();
        counter++;
    }
    void setUpArrays() {
        nameType = new string[numType];
        countType = new int[numType];

        for (int i = 0; i < numType; i++)
        {
            cout << "What is the name of the product and the count of it \n";
            cin >> *(nameType + i);
            cin >> *(countType + i);
        }
    }
    void showInfo() {
        for(int i = 0; i < numType; i++) {
            cout << *(nameType + i) << "\t" << *(countType + i) << endl;
        }
    }

    void changeCount(string theType, int count) {
        for (int i = 0; i < numType; i++)
        {
            if(theType == nameType[i]) {
                countType[i] = count;
            }
        }
        
    }

    static void showCounter() {
        cout << "The number of instances of the class is " << counter << endl;
    }
};