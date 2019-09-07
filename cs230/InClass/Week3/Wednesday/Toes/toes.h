#pragma once
#include <iostream>
#include <string>

using namespace std;

class Toes {
    private:
        int numToes;
        string *nameToes;
    
    public:
    Toes() { numToes = 10; };

    Toes(int numToes) {
        this->numToes = numToes;
        nameTheToes();
    }

    void nameTheToes() {
        nameToes = new string[numToes];
        for (int i = 0; i < numToes; i++)
        {
            cout << "What is your " << i+1 << " toe's name? \n";
            cin >> nameToes[i]; //Creates an array in the class...
        } 
    }

    void listToes() {
        for (int i = 0; i < 11; i++)
        {
            cout << nameToes[i] << endl;
        } 
    }
};