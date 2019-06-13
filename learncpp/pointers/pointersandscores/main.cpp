#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int scores[] {100, 97, 85};
    cout << "Value of scores " << scores << endl;
    int *score_ptr = {scores};
    cout << "Value of scores pointer is " << score_ptr << endl;
    cout << "Array subscript notation: -----------------------------------" << endl;
    cout << scores[0] << endl;
    cout << scores[1] << endl;
    cout << scores[2] << endl;

    cout << "POinter subscript notation: ----------------------------------" << endl;;
    cout << score_ptr[0] << endl;
    cout << score_ptr[1] << endl;
    cout << score_ptr[2] << endl;

    cout << "Pointer offset notation: --------------------------------------" << endl;
    cout << *(score_ptr) << endl;
    cout << *(score_ptr + 1) << endl;
    cout << *(score_ptr + 2) << endl;

    cout << "Array offset notation: ------------------------------------------" << endl;
    cout << *scores << endl;
    cout << *(scores + 1) << endl;
    cout << *(scores + 2) << endl;
}