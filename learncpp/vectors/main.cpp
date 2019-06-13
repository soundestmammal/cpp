#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // // vector <char> vowels;    //empty vectos
    // // vector <char> vowels (5); //5 initialized to 0
    // vector <char> vowels {'F', 'L', 'U', 'X'};  //Assigning a vector at declaration
    
    // cout << vowels[0] << endl;
    // cout << vowels[3] << endl;
    // // vector <int> vector_name (number of elements, value initialization)
    // // vector <int> test_scores (3); // 3 elements all initialized to zero
    // // vector <int> test_scores (3, 100);  // 3 elements all initialized to 100
    // vector <int> test_scores {100, 99, 98};
    // cout << "Test scores using array syntax:" << endl;
    // cout << test_scores.at(0) << endl; //100
    // cout << test_scores.at(1) << endl; //99
    // cout << test_scores.at(2) << endl; //98
    // cout << "\nThere are " << test_scores.size() << " scores in the vector" << endl; //3

    // // cin >>  test_scores.at(0);
    // // cin >> test_scores.at(1);
    // // cin >> test_scores.at(2);

    // cout << '\n' << endl;

    // cout << test_scores.at(0) << endl;
    // cout << test_scores.at(1) << endl;
    // cout << test_scores.at(2) << endl; 

    // cout << '\n' << endl;

    // cout << test_scores.size() << endl;

    // // int score_to_add {0};

    // // cout << "Enter a test score to end to the end of the list" << endl;
    // // cin >> score_to_add;
    // // test_scores.push_back(score_to_add);
    // cout << '\n' << endl;
    // cout << test_scores.size() << endl;
    // cout << '\n' << endl;
    // cout << test_scores.at(0) << endl;
    // cout << test_scores.at(1) << endl;
    // cout << test_scores.at(2) << endl;
    // cout << test_scores.at(3) << endl;

    // cout << '\n' << endl;

    // Section 7 Challenge
    vector <int> vector1;
    vector <int> vector2;

    // cin >> vector1.at(0);
    // cin >> vector2.at(1);
    int wait_1a {};
    int wait_1b {};
    cin >> wait_1a;
    cin >> wait_1b;
    vector1.push_back(wait_1a);
    vector1.push_back(wait_1b);
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << vector1.size() << endl;

    int wait_2a {};
    int wait_2b {};
    cin >> wait_2a;
    cin >> wait_2b;

    vector2.push_back(wait_2a);
    vector2.push_back(wait_2b); 

    cout << vector2.at(0) << endl;
    cout << vector2.at(1) << endl;

    cout << '\n' << endl;

    vector <vector <int>> vector_2d
    {

    };

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    cout << vector_2d.at(0).at(0) << endl; 
    cout << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.size() << endl;

    vector1.at(0) = 1000;
    cout << vector_2d.at(0).at(0) << endl;
    cout << vector_2d.at(0).at(1) << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;

    return 0;
}

