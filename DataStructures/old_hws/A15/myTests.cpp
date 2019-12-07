#include <iostream>
#include <random>
#include <string>
#include <climits>
#include <fstream>
#include <ctime>
#include "bst.h"
#include "mapWrapper.h"

// Function Prototype
int generateZeroToTwo(std::random_device &seed);
int generateMinMax(std::random_device &seed);
void userInput(std::random_device &seed);
void randomStream(std::string filename, int length,  std::random_device &seed);
std::string * parseFile(std::string f, std::string * data);
std::string randomWordFromFile(std::string theFileName, std::random_device &seed);
std::string randomWordFromFileWithLineNumber(std::string theFileName, std::random_device &seed);

bool myAwesomeTest();
bool testStream(std::string file);

int main () {
    int x;
    bool failed = false;
    std::random_device rd;
    userInput(rd);
    failed = testStream("testnumbatwo");
    if(failed) {
        std::cerr << "Failed the test at line" << __LINE__ << std::endl;
        exit(1);
    }

    std::cout << "HEY you passed, great job yo" << std::endl;
    std::cin >> x;
    return 0;
}

bool myAwesomeTest() {
    farmingdale::mapWrapper map;
    farmingdale::bst myAwesomeBST2;

    

    // DO TESTING THINGS HERRE!!!!!!!


    // Returning false means the test passes!!!
    return false;
}


void userInput(std::random_device &seed) {
    std::string f;
    int l;
    std::cout << "Enter a file name: ";
    std::cin >> f;
    std::cout << "Enter a length:  ";
    std::cin >> l;
    if (l <= 0 || f == "") {
        std::cerr << "This is a problem at line " << __LINE__ << std::endl;
        exit(1);
    }
    // creates a file with the A D P and the words.
    randomStream(f, l, seed);
}

void randomStream(std::string filename, int length,  std::random_device &seed) {

    int randZeroToTwo;
    std::ofstream output;
    output.open(filename);

    for (int i = 0; i < length; ++i) {

        randZeroToTwo = generateZeroToTwo(seed);

        switch(randZeroToTwo) {
            case 0:
                output << "A" << " " << randomWordFromFileWithLineNumber("words.txt", seed) << std::endl;
                break;
            case 1:
                output << "D" << " " << randomWordFromFile("words.txt", seed) << std::endl;
                break;
            case 2:
                output << "P" << " " << randomWordFromFile("words.txt", seed) << std::endl;
                break;
            default:
                output << "Something is wrong!" << std::endl;
                exit(1);
                break;
        }    
    }
    output.close();

}

int generateZeroToTwo(std::random_device &seed) {
    // random_device rd;  // seeding a random number rd
    // Create an object called gen of type mersenne twister engine
    // The constructor accepts a seed or a seed sequence
    std::mt19937 gen(seed());  
    std::uniform_int_distribution<> dis(0, 2); // set bounds of dist
    return dis(gen);
}

int generateRandomNumberDictionary(std::random_device &seed) {
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> dis(1, 1000);
    return dis(gen);
}

std::string randomWordFromFile(std::string theFileName, std::random_device &seed) {
    // Create an fstream object - call it file
    std::fstream file;

    // open the fstream object with the fileName
    file.open(theFileName);

    // Check if the file exists
    if(!file){
        std::cerr << " I was not able to find that file... " << __LINE__ << std::endl;
        exit(1);
    }
    std::string item;
    std::string theWordToReturn;
    int findStuffHere = generateRandomNumberDictionary(seed);
    int currentLineNumber = 0;

    while(getline(file, item)) {
        ++currentLineNumber;
        if(currentLineNumber == findStuffHere) {
            theWordToReturn = item;
            break;
        }
    }
    file.close();
    return theWordToReturn;
}

std::string randomWordFromFileWithLineNumber(std::string theFileName, std::random_device &seed) {
    std::fstream file;
    file.open(theFileName);

    if(!file) {
        std::cerr << "I was not able to locate that file... " << __LINE__ <<  std::endl;
        exit(1);
    }

    std::string item;
    std::string theWordToReturn;

    int findStuffHere = generateRandomNumberDictionary(seed);
    int currentLineNumber = 0;

    // Keep going through the file until
        // I reach the line number
    
    while(getline(file, item)) {
        ++currentLineNumber;
        if(currentLineNumber == findStuffHere) {
            theWordToReturn = item;
            break;
        }
    }

    std::string returnMe = theWordToReturn + " " + std::to_string(currentLineNumber);

    file.close();
    return returnMe;
}

std::string* parseFile(std::string f, std::string * data) {
// Create an fstream object and try and open
	std::fstream file;
	file.open(f);

    // Handle error
	if(!file) {
		std::cerr << "I was not able to locate that file... " << __LINE__ <<  std::endl;
        exit(1);
	}

    // Item is a temp string variable
	std::string item;

    // Counter to track which line number
    int lineNumber = 0;
    int counter = 0;
    // Begin to Parse the file
	while(getline (file, item)) {
        data[counter] = item;
        counter++;
    }


    return data;
}

bool testStream(std::string theFileToTest) {

    farmingdale::bst myBST1;
    farmingdale::bst myBST2;
    farmingdale::mapWrapper map;

    std::fstream file;
    file.open(theFileToTest);
    
    // Create a temporary string variable
    std::string item;
    int counter = 0;
    while(getline(file, item)) {
        std::cout << counter << std::endl;
        ++counter;
        // If it reads A
        if('A' == item[0]) {
            // I want to insert into the tree

            // Create a string and an int
            std::string word;
            std::string temp;
            std::string lineNumber;
            // Parse the line, store string and int in variables
            temp = item.substr(2);
            int positionOfSpace = temp.find(' ');
            word = temp.substr(0, positionOfSpace);
            lineNumber = temp.substr(positionOfSpace+1);
            int number = std::stoi(lineNumber);

            farmingdale::status status1;
            farmingdale::status status2;
            farmingdale::status status3;

            // insert into the tree
            status1 = myBST1.insert(word, number);
            status2 = myBST2.insert(word, number);
            
            // insert into the map
            status3 = map.insert(word, number);

            // check that the return values were the same for the tree
            if (status1 != status2) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return true;
            }

            if (status2 != status3) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return true;
            }

        } 
        else if('D' == item[0]) {
            // I want to delete an element from the tree

            // create a string
            std::string word;
            std::string temp;
            // parse the line, store string in var
            temp = item.substr(2);
            int positionOfSpace = temp.find(' ');
            word = temp.substr(0, positionOfSpace);
            // delete from the tree

            farmingdale::status status1;
            farmingdale::status status2;
            farmingdale::status status3;
            
            // check that return values were the same in the tree
            status1 = myBST1.remove(word);
            status2 = myBST2.remove(word);
            
            // check that the return value for map was the same as tree
            status3 = map.remove(word);
            
            if (status1 != status2) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return true;
            }

            if (status2 != status3) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return true;
            }
            
        } 
        else if('P' == item[0]) {
            // I want to peak an item in the tree.

            // create a string
            std::string word;
            std::string temp;
            // parse the line, store string in var
            temp = item.substr(2);
            int positionOfSpace = temp.find(' ');
            word = temp.substr(0, positionOfSpace);
            // peak the tree
            
            farmingdale::status status1;
            farmingdale::status status2;
            farmingdale::status status3;
            
            int passMeBack1;
            int passMeBack2;
            int passMeBack3;

            // check that return values were the same in the tree
            status1 = myBST1.query(word, passMeBack1);
            status2 = myBST2.query(word, passMeBack2);
            // check that the return value for map was the same as tree
            status3 = map.query(word, passMeBack3);

            if (status1 != status2) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return true;
            }

            if (status2 != status3) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return true;
            }

            // check that the value passed back by reference is the same for the tree and the map
            if(passMeBack1 != passMeBack2) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return true;
            }

            if(passMeBack2 != passMeBack3) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return true;
            }
        }
        else {
            std::cerr << "I should never get to this..." << __LINE__ << std::endl;
        }
    }
    file.close();
    return false;
}