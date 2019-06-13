/*
Exception Handling
    - deal with extraordinary situations
    - indicates taht an extraordinary situation has been detected or has occurred
    -program can dead with the extraordinary siuations in a suitable manner
    Should only be used for Synchronous Code.

    Exception
        An object or primitive type that signals that an error has occurred
    
    Throwing an exception (raising an exception)
        your code detects that an error has occurred or will occur
        the place where the error occurred may not know how to handle the error
        code can three an exception describing the error to another part of the program that knows how to handle the error

    Catching an exception (handles the exception)
        code that handles the exception
        may or may not cause the program to terminate

    # Throw
        -throws an exception
        followed by an argument
    #Try { code that may throw an exception }
        -you place code that may throw an exception in a try block
        - if the code throws an exception the try block is exited
        - The thrown

    #catch

    What if we divide by zero?

    What happens if total is zero?

    double average {};
    average = sum / total;
 */


// Section 18
// Miles per Gallon - No Exception Handling 

#include <iostream>

double average {};
try {
    if (total == 0)
        throw 0;
    average = sum / total;
    // use average here
}
catch (int &ex) {
    std::cerr << "can't divide by zero" << std::endl;
}
std::cout << "program continues" << std::endl;