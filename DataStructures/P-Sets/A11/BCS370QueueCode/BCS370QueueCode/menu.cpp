#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include <ctime>
#include <random>
#include <queue>
#include "BCS370_queueBase.h"
#include "linkedList.h"
#include "queueWrapper.h"
#include "llqueue.h"

// Function Prototype
int generateZeroToThree(std::random_device &seed);
int generateMinMax(std::random_device &seed);
void userInput(std::random_device &seed, std::string &f);
void randomStream(std::string filename, int length,  std::random_device &seed);
bool testStream(std::string f);

// class farmingdale::queueWrapper {
// public:
//     std::queue<std::string> stlQueue;
//     bool isEmpty();
//     farmingdale::statusCode enqueue(std::string s);
//     farmingdale::statusCode dequeue(std::string &returnElement);
//     farmingdale::statusCode peek(std::string &returnElement);
// };


// // I need to make a node over here
// class farmingdale::Node {
// public:
// 	// Need a default ctor
// 	std::string data;
// 	Node* next;
// };

// // I need to put the Linked List over here!
// class farmingdale::LinkedList {
// public:
// 	Node* head; // first node
// 	Node* tail; // last node
// 	statusCode addToFront(std::string); // done
// 	statusCode removeBack(); // done
// 	statusCode addToBack(std::string); // done
// 	statusCode removeFront(); // done

// 	statusCode getFront(std::string &); // done
// 	statusCode getBack(std::string &); // done

// 	// this can be done inline easily
// 	inline bool isEmpty() { return (NULL == head); };
// 	// O(N) because we need to traverse
	
// 	// delete list items
// };

// // Put the Linked List Methods over here

// // Enqueue is going to be addToBack
// // addToBack
// farmingdale::statusCode farmingdale::LinkedList::addToBack(std::string addMe) {
//     if(isEmpty()){
//         head = new Node;
//         head->data = addMe;
//         head->next = NULL;
//         tail = head;
//         return SUCCESS;
//     }
//     // I need a temp pointer
//     Node* temp = new Node;

//     // try {
//     //     temp->next = new Node;
//     // } catch (std::bad_alloc &ba) {
//     //     ba.what();
//     //     return FAILURE;
//     // }
//     temp->data = addMe;
//     temp->next = NULL;

//     tail->next = temp;
//     tail = temp;

//     return SUCCESS;
// }




// // Dequeue is going to be getFront and remove from front

// // getFront
// farmingdale::statusCode farmingdale::LinkedList::getFront(std::string &returnMe) {
//     // If it is NONempty Return DATA
//     if(!isEmpty()) {
//         returnMe = head->data;
//         return SUCCESS;
//     }
//     return FAILURE;
// }


// // removeFront
// farmingdale::statusCode farmingdale::LinkedList::removeFront() {
//     // Check that the linked list is not empty ?
//     if(isEmpty()) {
//         return FAILURE;
//     }
//     Node* temp = head->next;
//     // returnMe = head->data; not needed, it returns status, call after getFront
//     delete head;
//     head = temp;
//     return SUCCESS;
// }










// // Make the farmingdale Linked List Queue over here.
// class farmingdale::llqueue {
// public:
//     farmingdale::LinkedList data;

//     // isEmpty
//     bool isEmpty();

//     // Enqueue
//     farmingdale::statusCode enqueue(std::string addMe);

//     // Dequeue
//     farmingdale::statusCode dequeue(std::string &returnMe);

//     // Peek
//     farmingdale::statusCode peek(std::string &returnMe);

// };

// bool farmingdale::llqueue::isEmpty() {
//     if (data.isEmpty()) {
//         return true;
//     }
//     return false;
// }

// farmingdale::statusCode farmingdale::llqueue::enqueue(std::string addMe) {
//     data.addToBack(addMe);
//     return SUCCESS;
// }

// farmingdale::statusCode farmingdale::llqueue::dequeue(std::string &returnMe) {
//     if(isEmpty()) {
//         return FAILURE;
//     }
//     data.getFront(returnMe);
//     data.removeFront();
//     return SUCCESS;
// }

// farmingdale::statusCode farmingdale::llqueue::peek(std::string &returnMe) {
//     std::cout << "This logs here" << std::endl;
//     std::cout << returnMe << std::endl;
//     if(isEmpty()) {
//         std::cout << "This should not run!";
//         return FAILURE;
        
//     }
//     std::string work;
//     std::cout << "Work! " << work << std::endl;
//     data.getFront(work);
//     std::cout << "Work! " << work << std::endl;
//     returnMe = work;
//     return SUCCESS;
// }

// bool farmingdale::queueWrapper::isEmpty() {
//     if (stlQueue.empty()) {
//         return true;
//     }
//     return false;
// }
// farmingdale::statusCode farmingdale::queueWrapper::enqueue(std::string pushMe) {
//         stlQueue.push(pushMe);
//         return SUCCESS;
// }
// farmingdale::statusCode farmingdale::queueWrapper::peek(std::string &returnElement) {
//     if (isEmpty()) {
//         return FAILURE;
//     }
//     returnElement = stlQueue.front();
//     return SUCCESS;
// }

// farmingdale::statusCode farmingdale::queueWrapper::dequeue(std::string &returnElement) {
//     std::string test;
//     if(isEmpty()) {
//         return FAILURE;
//     }
//     returnElement = stlQueue.front();
//     stlQueue.pop();
//     test = stlQueue.front();
//     if (returnElement != test) {
//         return SUCCESS;
//     }
//     return FAILURE;
// }


int main() {
    std::random_device rd;
    bool working = true;

    std::cout << "Please select from the following menu options" << std::endl;
    std::cout << "Enter a single digit corresponding to the option" << std::endl;
    std::cout << "Option 1:\tExit\n";
    std::cout << "Option 2:\tRun Random Stream\n";
    std::cout << "Option 3:\tRun Test Stream\n";
    std::cout << "Option 4:\tRun Random Stream & Run Test Stream\n";
    
    int response;
    std::cin >> response;

    // Log error if response is out of bounds
    if(response < 1 || response > 4) {
        std::cerr << "There is an error at line" << __LINE__ << std::endl;
        exit(1);
    }

    std::cout << "I selected " << response << std::endl;

    // Respond to User Response
    if(response == 1) {
        std::cout << "Exiting the Menu" << std::endl;
    } else if( response == 2) {
        std::string f;
        userInput(rd, f);
    } else if (response == 3) {
        // Run test stream on a file provided
        // Ask for the file name
        std::string f;
        std::cout << "Enter a file name: ";
        std::cin >> f;
        working = testStream(f);
        
    } else if (response == 4) {
        // Ask for a file name
            // std::string f;
            // int l;
            // std::cout << "Enter a file name: ";
            // std::cin >> f;
            // std::cout << "Enter a length:  ";
            // std::cin >> l;
            // if (l <= 0 || f == "") {
            //     std::cout << "This is a problem!" << std::endl;
            //     exit(1);
            // }
            std::string f;
            userInput(rd, f);
            // Tell the user if it passed or failed

            working = testStream(f);
            // if(testStream(f)) {
            //     std::cout << "congrats! your test stream passed all tests" << std::endl;
            // } else {
            //     std::cout << "Sorry, some tests failed" << std::endl;
            // }


        // Run randomStream
        // Run testStream on the filename
        // Tell the user if it passed or failed
    } else {
        std::cerr << "Something is really bad" << std::endl;
        exit(1);
    }

    if(!working) {
        std::cerr << "Something is really bad" << " on line number " << __LINE__ << std::endl;
        return 1;
    } else {
        std::cout << "CONGRATS ALL OF YOUR TESTS ARE PASSING! NICE JOB!" << std::endl;
        return 0;
    }

}

bool testStream(std::string f) {
    // Create two Queues
    farmingdale::llqueue q1;
    farmingdale::queueWrapper q2;
    farmingdale::queue q3;

    // Create an fstream object and try and open
	std::fstream file;
	file.open(f);

    // Handle error
	if(!file) {
		std::cerr << "I was not able to locate that file... " << __LINE__ <<  std::endl;
        return false;
	}

    // Item is a temp string variable
	std::string item;

    // Counter to track which line number
    int lineNumber = 0;

    // Begin to Parse the file
	while(getline (file, item)) {

        // Used for displaying output during testing
        lineNumber++;
        std::cout << lineNumber;

	    if('C' == item[0]) {
		    std::cout << "\tNOTHING: This was a C";
	    } 
        /*

            D is for Dequeue!
        */
        else if('D' == item[0]) {           
            
            bool f1 = q1.isEmpty();
            bool f2 = q2.isEmpty();
            bool f3 = q3.isEmpty();


            // Create string variables to compare returned values
            std::string qa, qb, qc, qd, qe, qf;
            q1.peek(qc);
            q2.peek(qd);
            q3.peek(qf);
            // std::cout << std::endl;
            // std::cout << qc << std::endl;
            // std::cout << qd << std::endl;
            // std::cout << std::endl;

            farmingdale::statusCode statTest = q2.dequeue(qb);

            // Check if they return failure, or if the peeked values are different.
            if (q1.dequeue(qa) != statTest || statTest != q3.dequeue(qc) || qc != qd || qa != qb) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            if(f1 || f2 || f3) {
                std::cout << "\tDEQUEUE:  The Queue was empty and both returned FAILURE";
            } else {
                 // CONSOLE LOG
                std::cout << "\tDEQUEUE:  Q1's top is " << qc << " dq value is " << qa << " Q_2's top is " << qd << " dq value is " << qb << " Q_3's top is " << qf << " dq value is " << qc;
            }
        } 
        
        /*
            E is for isEmpty().

            it should call isEmpty() on all three queues. 

            Acceptable cases:
                1. All true
                2. All false
        */
        
        else if('E' == item[0]) {
                if(q1.isEmpty()) {
                    if (!q2.isEmpty() || !q3.isEmpty()) {
                        return false;
                    }
                } 
                else {
                    if(q1.isEmpty()) {
                        if(q2.isEmpty() || q3.isEmpty()) {
                            return false;                            
                        }
                    }
                }
                std::cout << "\tISEMPTY: " << q1.isEmpty() << " " << q2.isEmpty() << " " << q3.isEmpty();
        } 
        
        /*
        Peek: Compare all of the peeks. 
        All of the strings should be the same.
        */
        
        
        else if ('P' == item[0]) {
                // Strings to be returned by qx.peek
                std::string c;
                std::string d;
                std::string e;

            if(q1.peek(c) != q2.peek(d) || q2.peek(d) != q3.peek(e)) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            q1.peek(c);
            q2.peek(d); 
            q3.peek(e);
            
            if (c != d || d != e) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }

            if(q1.isEmpty()) {
                std::cout << "\tPEEK: Unable to peek an empty queue";
            } else {
                std::cout << "\tPEEK: " << c << " " << d << " " << e;
            }
        
		    // std::cout << "This was a P" << std::endl; // Peak the Queue
	    } else if('S' == item[0]) {
		    std::cout << "\tNOTHING: This was an S";
	    }
        
        
        /*
            This is where I enqueue
            Then I should enqueue and all three should return the same status code.
            After Enqueue make sure you are adding and removing from different ends
        */
        
        else {
            std::string value = item.substr(2,100);
            if(farmingdale::FAILURE == q1.enqueue(value) || farmingdale::FAILURE == q2.enqueue(value) || farmingdale::FAILURE == q3.enqueue(value)) {
                std::cerr << "There was an error on line " << __LINE__ << std::endl;
                return false;
            }
            std::string c;
            std::string d;
            std::string e;

            q1.peek(c);
            q2.peek(d);
            q3.peek(e);

            // CONSOLE LOG
            std::cout << "\tEnqueue: Q_1 and Q_2 and Q_3 all push " << value << " the top of the Queues have " << c << " " << d << " " << e << " ";
        }
        // FOR CONSOLE
        std::cout << "\n";
	}
    return true;
}

void userInput(std::random_device &seed, std::string &f) {
    int l;
    std::cout << "Enter a file name: ";
    std::cin >> f;
    std::cout << "Enter a length:  ";
    std::cin >> l;
    if (l <= 0 || f == "") {
        std::cerr << "This is a problem at line " << __LINE__ << std::endl;
        exit(1);
    }
    randomStream(f, l, seed);
}

void randomStream(std::string filename, int length,  std::random_device &seed) {

    int randZeroToFive;
    std::ofstream output;
    output.open(filename);

    for (int i = 0; i < length; i++) {
        
        randZeroToFive = generateZeroToThree(seed);

        // if (i >= 10 && i <= 7500) {
        //     randZeroToFive = 0;
        // }

        // if (i >= 7501 && i <= 16000) {
        //     randZeroToFive = 1;
        // }
        

        switch(randZeroToFive) {
            case 0:
                output << "A" << " " << generateMinMax(seed) << std::endl;
                break;
            case 1:
                output << "D" << std::endl;
                break;
            case 2:
                output << "P" << std::endl;
                break;
            case 3: 
                output << "E" << std::endl;
                break;
            // case 4:
            //     output << "C" << std::endl;
            //     break;
            // case 5:
            //     output << "S" << std::endl;
            //     break;
            default:
                output << "Something is wrong!" << std::endl;
                break;
        }
         
    }
    output.close();

}

int generateZeroToThree(std::random_device &seed) {
    // random_device rd;  // seeding a random number rd
    // Create an object called gen of type mersenne twister engine
    // The constructor accepts a seed or a seed sequence
    std::mt19937 gen(seed());  
    std::uniform_int_distribution<> dis(0, 3); // set bounds of dist
    return dis(gen);
}

int generateMinMax(std::random_device &seed) {
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> dis(INT_MIN, INT_MAX);
    return dis(gen);
}