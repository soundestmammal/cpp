#include <iostream>
#include <cmath>

using namespace std;

int main()
{

double num{};
cout << "Enter a number: ";
cin >> num;
cout << "The square root of the number is " << sqrt(num) << endl;
cout << "The cubed root of the number is " << cbrt(num) << endl;

cout << "The sine of " << num << "is: " << sin(num) << endl;
cout << "The cosine of " << num << "is: " << cos(num) << endl;

cout << "The ceiling of " << num << "is: " << ceil(num) << endl;
cout << "The floor of " << num << "is: " << floor(num) << endl;
cout << "The round of " << num << "is: " << round(num) << endl;

return 0;

}