#include <iostream>

using namespace std;

    void print(int);
    void print(double);
    void print(string);
    void print(string, string);
    void print(vector<string>);

    void print(int num){
        cout << "Printing int:" << num << endl;
    };
    void print(double num){
        cout << "Print double:" << num << endl;
    };
    void print(string s){
        cout << "Print string:" << s << endl;
    };
    void print(string s, string t){
        cout << "Printing two strings " << s << " and " << t << endl;
    }

int main()
{
    print(100.00);
    return 0;
}