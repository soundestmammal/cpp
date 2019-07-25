#pragma once

#include <iostream>
#include <string>
using namespace std;

class WorkerBees {
    private:
        int numWorkers;
        string* workerNames;
        int* workerHours;
    
    public:
        WorkerBees(int numWorkers) {
            this->numWorkers = numWorkers;
            workerNames = new string[numWorkers];
            workerHours = new int[numWorkers];
        
            for (int i = 0; i < numWorkers; i++) {
                cout << "What is the name and hours worked? \n";
                cin >> workerNames[i];
                cin >> workerHours[i];
            }
        }

        ~WorkerBees() {
            delete[] workerHours;
            delete[] workerNames;
        }

        void showInfo() {
            for(int i = 0; i < numWorkers; i++) {
                cout << workerNames[i] << " " << workerHours[i] << "\t" << endl;
            }
        }
};