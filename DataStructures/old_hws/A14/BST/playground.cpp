#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include <ctime>
#include <random>

// Function Prototype
int generateZeroToTwo(std::random_device &seed);
int generateMinMax(std::random_device &seed);
void userInput(std::random_device &seed);
void randomStream(std::string filename, int length,  std::random_device &seed);
std::string * parseFile(std::string f, std::string * data);
std::string randomWordFromFile(std::string theFileName, std::random_device &seed);
std::string randomWordFromFileWithLineNumber(std::string theFileName, std::random_device &seed);


int main() {
    int x;
    /*
    Yo remember that the array starts at zero, and I will need to incremene thte line number by 1
    so if i have something on line 1 then I need to output index+1
    The item on line number 1 resides in slot 0 in the array
    I didn't change the counter, I just need to shift by one...
    */
    std::string FILE = "words.txt";
    std::random_device rd;
    userInput(rd);

  // Create a string and an int
            std::string item = "A orange 351";
            std::string word;
            std::string temp;
            std::string lineNumber;
            // Parse the line, store string and int in variables
            temp = item.substr(2);
            int positionOfSpace = temp.find(' ');
            word = temp.substr(0, positionOfSpace);
            lineNumber = temp.substr(positionOfSpace+1);

            std::cout << item << std::endl;
            std::cout << word << std::endl;
            std::cout << lineNumber << std::endl;


    // std::string * dictionaryWords = new std::string[1000];
    // dictionaryWords = parseFile(FILE, dictionaryWords);
    // std::cout << "Here Here Here" << std::endl;
    //std::random_device rd;

    // for(int i = 0; i < 1000; i++) {
    //     std::cout << dictionaryWords[i] << std::endl;
    // }
    std::cout << "You should see this" << std::endl;
    std::cin >> x;
    return 0;
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







    std::fstream file;
    file.open(theFileToTest);
    
    // Create a temporary string variable
    std::string item;
    while(getline(file, item)) {

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

            // insert into the tree

            // insert into the map

            // check that the return values were the same for the tree

            // check that the return value for map was same as tree


        } 
        else if('D' == item[0]) {
            // I want to delete an element from the tree

            // create a string
            std::string word;
            std::string temp;
            std::string lineNumber;
            // parse the line, store string in var
            temp = item.substr(2);
            int positionOfSpace = temp.find(' ');
            word = temp.substr(0, positionOfSpace+1);
            // delete from the tree

            // check that return values were the same in the tree

            // check that the return value for map was the same as tree

        } 
        else if('P' == item[0]) {
            // I want to peak an item in the tree.

            // create a string

            // parse the line, store string in var

            // peak the tree

            // check that return values were the same in the tree

            // check that the return value for map was the same as tree

            // check that the value passed back by reference is the same for the tree and the map
        }
        else {
            std::cerr << "I should never get to this..." << __LINE__ << std::endl;
        }
    }
    return true;
}