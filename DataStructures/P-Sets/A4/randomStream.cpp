#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include <ctime>
#include <random>

using namespace std;

// Function Prototype
int generateZeroToFive();
int generateMinMax();
void randomStream();
void randomStream(string filename, int length);

void randomStream() {
    string f;
    int l;
    cout << "Enter a file name: ";
    cin >> f;
    cout << "Enter a length:  ";
    cin >> l;
    if (l <= 0 || f == "") {
        cout << "This is a problem!" << endl;
        exit(1);
    }
    randomStream(f, l);
}

void randomStream(string filename, int length) {

    int randZeroToFive;
    ofstream output;
    output.open(filename);

    for (int i = 0; i < length; i++) {

        randZeroToFive = generateZeroToFive();

        switch(randZeroToFive) {
            case 0:
                output << "A" << " " << generateMinMax() << endl;
                break;
            case 1:
                output << "D" << endl;
                break;
            case 2:
                output << "P" << endl;
                break;
            case 3: 
                output << "E" << endl;
                break;
            case 4:
                output << "C" << endl;
                break;
            case 5:
                output << "S" << endl;
                break;
            default:
                output << "Something is wrong!" << endl;
                break;
        }
         
    }
    output.close();


}

int generateZeroToFive() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 5);
    return dis(gen);
}

int generateMinMax() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(INT_MIN, INT_MAX);
    return dis(gen);
}