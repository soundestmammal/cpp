#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Keyboard {
    private:
        // Private variables are the infomation and size of the array
        int keyboardSize;
        string* inventory;
    public:
        Keyboard(int keyboardSize = 10) : keyboardSize(keyboardSize) {
            inventory = new string[keyboardSize];
        }
        Keyboard(const Keyboard &k) {
            keyboardSize - k.keyboardSize;
            inventory = new string[keyboardSize];
            for (int i = 0; i < keyboardSize; i++)
            {
                inventory[i] = k.inventory[i];
            }
        }
        Keyboard() { delete[] inventory; }
};