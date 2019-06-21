#include <iostream>
#include <iomanip>

double calc_cost(double base_cost, double tax_rate = 0.06, double shipping = 3.50);

int main() {

    double cost {};
    cost = calc_cost(100.0, 0.08, 4.25); // willl use no defaults 100 + 8 + 4.25

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Cost is: " << cost << std::endl;


    return 0;
}

double calc_cost(double base_cost, double tax_rate, double shipping) {
    return base_cost += (base_cost * tax_rate) + shipping;
}