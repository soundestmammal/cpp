#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    // 1. Create Object
    ofstream output;
    // 2. Open the file
    output.open("theFile.txt");
    // 3. Output to a file
    output << "This is how I write to a file" << endl;
    // 4. Close the file
    output.close();

    // Store the Information
    string var {};

    // 1. Create the object
    ifstream input;
    // 2 Create the file
    input.open("theFile.txt");

    getline(input, var);
    
    // 3. Use the variable
    cout << var << endl;

    // 4. Close the file
    input.close();

    // Test 1
    // - - - - - - - - - - - - - - - -
    // If Statements else if else
    // Nested ifs
    // While loops
    // For loops
    return 0;
}