#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const double TAX = 0.0875;

// Function Prototypes
double applyTax(double subtotal);
void totalCost();

int main(){

    // Run total cost 3 times in a loop prompting the use for different information
    for (int i = 0; i < 3; i++)
    {
        totalCost();
    }
    

    return 0;
}

double applyTax(double subtotal) {
    cout << "Subtotal:  " << subtotal << endl;
    return subtotal * (1+TAX);
}

void totalCost() {
    int quantity;
    string name;
    double cost;
    double subtotal, total;

    cout << "What is the name of the item   ";
    cin >> name;
    
    cout << "What is the quantity of the item:  ";
    cin >> quantity;

    cout << "What is the cost of the item:  ";
    cin >> cost;

    subtotal = quantity * cost;

    if(quantity >= 300) {
        subtotal = subtotal - (subtotal * 0.2);
    } else if (quantity >= 200) {
        subtotal = subtotal - (subtotal * 0.15);
    } else if (quantity >= 100) {
        subtotal = subtotal - (subtotal * 0.10);
    }
    total = applyTax(subtotal);
    
    // The total cost function should use the apply tax to find the total cost

    // It should output the:
    // Item Name
    cout << "Item Name: " << name << endl;
    // Amount Purchased
    cout << "Quantity:  " << quantity << endl;
    // Total Cost
    cout << "Total Cost:  " << fixed << setprecision(2) << total << endl;

}