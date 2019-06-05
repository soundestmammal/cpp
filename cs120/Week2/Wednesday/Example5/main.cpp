#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {

    string personType {};
    cout << "Are you orange or purple:  ";
    cin >> personType;

    int price = (personType == "purple" ? 10 : 20);
    int otherPrice = (personType == "purple" ? 10 : personType == "orange" ? 20 : 100000);

    int dayOfWeek {};
    cout << "What is the numerical day of the week  ";
    cin >> dayOfWeek;

    cout << (dayOfWeek == 1 ? "Sun" : dayOfWeek == 2 ? "Mon" : dayOfWeek == 3 ? "Tues" : dayOfWeek == 4 ? "Wed" : dayOfWeek == 5 ? "Thursday" : dayOfWeek == 6 ? "Friday" : "Saturday") << endl;


    return 0;
}