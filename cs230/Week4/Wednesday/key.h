#pragma once
#include <iostream>
#include <string>
using namespace std;

class Key {
private:
    int keySize;
    bool* ridges;
    static int counter;
public:
    Key(int kS) {
        counter++;
        keySize = kS;
        ridges = new bool[keySize];
        for (int i = 0; i < keySize; i++) {
            cout << "Set the ridge\t";
            cin >> ridges[i];
        }
        cout << endl;
    }
    Key(const Key &key) {
        counter++;
        keySize = key.keySize;
        ridges = new bool[keySize];
        for (int i = 0; i < keySize; i++)
        {
            ridges[i] = key.ridges[i];
        }   
    }

    void setKeyInfo(int kS) {
        keySize = kS;
        delete[] ridges;
        ridges = new bool[keySize];
        for (int i = 0; i < keySize; i++)
        {
            cout << "Set the ridge\t";
            cin >> ridges[i];
        }
        cout << endl;
    }

    void seeRidges() {
        for (int i = 0; i < keySize; i++)
        {
            cout << ridges[i] << " ";
        }
        cout << endl;
    }

    static void seeCounter() { cout << "The count is: " << counter << endl; }
};