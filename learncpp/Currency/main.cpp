#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const double usd_per_euro {1.14};
    cout << "Welcome to the EUR->USD Conversion Calculator!" << endl;
    cout << "Enter the amount in EUR:";
    double euro {};
    cin >> euro;
    double response {};
    response = euro*usd_per_euro;
    cout << response << " Dollars"<< endl;
    return 0;
}

