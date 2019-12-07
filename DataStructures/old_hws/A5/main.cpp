#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include <ctime>
#include <random>

using namespace std;

// Function Prototype
int generateZeroToFive(random_device &seed);
int generateMinMax( random_device &seed);
void userInput(random_device &seed);
void randomStream(string filename, int length,  random_device &seed);

int main() {
    random_device rd;

    userInput(rd);

    return 0;
}

void userInput(random_device &seed) {
    string f;
    int l;
    cout << "Enter a file name: ";
    cin >> f;
    cout << "Enter a length:  ";
    cin >> l;
    if (l <= 0 || f == "") {
        cerr << "This is a problem at line " << __LINE__ << endl;
        exit(1);
    }
    randomStream(f, l, seed);
}

void randomStream(string filename, int length,  random_device &seed) {

    int randZeroToFive;
    ofstream output;
    output.open(filename);

    for (int i = 0; i < length; i++) {

        randZeroToFive = generateZeroToFive(seed);

        switch(randZeroToFive) {
            case 0:
                output << "A" << " " << generateMinMax(seed) << endl;
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
            default:
                output << "Something is wrong!" << endl;
                break;
        }
         
    }
    output.close();

}

int generateZeroToFive(random_device &seed) {
    // random_device rd;  // seeding a random number rd
    // Create an object called gen of type mersenne twister engine
    // The constructor accepts a seed or a seed sequence
    mt19937 gen(seed());  
    uniform_int_distribution<> dis(0, 3); // set bounds of dist
    return dis(gen);
}

int generateMinMax( random_device &seed) {
    mt19937 gen(seed());
    uniform_int_distribution<> dis(INT_MIN, INT_MAX);
    return dis(gen);
}