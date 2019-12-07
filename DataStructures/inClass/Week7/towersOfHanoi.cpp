#include <iostream>

void solveLucas(int numberOfDisks, char startPole, char destPole, char auxiliaryPole);

int main() {
    int x;
    
    // How many disks
    // startPole
    // destPole

    solveLucas(30, 'A', 'C', 'B');

    std::cin >> x;
    return 0;
}

void solveLucas(int numberOfDisks, char startPole, char destPole, char auxiliaryPole) {
    // always start with the base case
    if (1 == numberOfDisks) {
        std::cout << "Yo. Move one ring from " << startPole << " to " << destPole << std::endl;
    } else {
        // move n-1 items from startPole to auxiliary pole
        solveLucas(numberOfDisks-1, startPole, auxiliaryPole, destPole);
        // move 1 pole from start pole to destination
        solveLucas(1, startPole, destPole, auxiliaryPole);
        // move n-1 items from auxiliaryPole to destPole
        solveLucas(numberOfDisks-1, auxiliaryPole, destPole, startPole);        
    }
}