#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Player {
    // attributes (data)
    string name;
    int health;
    int xp;
    // methods (functions) function prototypes for now
    void talk(string);
    bool is_dead();
};

int main() {
    Player Alvin;
    Player Beto;
    string firstName = "Robert";
    int age = 24;
    // enemy is a pointer to a player
    Player *enemy(nullptr);
    // Create enemy object on the heap
    enemy = new Player;

    delete enemy;
    
    return 0;
}

/* 
    class Class_Name {
       // attributes 
       string name;
       int health;
       int xp;

       // methods
        void talk(string text_to_say)
    };

    We can create an array of account objects
    We can create a vector of account objects
*/

