#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector <vector <double>> matrix [3][3];

    vector <double> row0 {1, 0, 0};
    vector <double> row1 {0, 1, 0};
    vector <double> row2 {0, 0, 1};

    // for (int i = 0; i < 3; i++)
    // {
    //     // The ith entry of the matrix should contain the ith row 

        
    // }1

    /* What is really happening:
        Is matrix[0] able to handle a vector of doubles without a known size during execution?
        row0 is the address of the first item in the vector? 
    */

   for (int i = 0; i < 1; i++)
   {
    //    for (int j = 0; j < 3; j++)
    //    {
    //        cout << "Do I get ehre" << endl;
    //        matrix[0][j] = row0[j];
    //        cout << "Do I get 2 here ?" << endl;

    //    }
       
   }

    //        for (int j = 0; j < 3; j++)
    //    {
    //        cout << "Do I get ehre" << endl;
    //        matrix[0][j] = row0[j];
    //        cout << "Do I get 2 here ?" << endl;

    //    }

   for (int i = 0; i < 3; i++)
   {
       //cout << matrix[0][i] << endl;
   }
   
   
    // matrix[0] = row0;
    // matrix[1] = row1;
    // matrix[2] = row2;
    
    // cout << matrix[0][0] << endl;

    return 0;
}

void validColumn(vector <double> row) {
    // This will check if a column vector is in rref (there should only be zeros below the pivot position)


}


/*
Given a matrix restricted to size n x n, return a matrix of size n x n in reduced row echelon form.

The rows of the matrix will be stored as row vectors of size n.

What needs to happen?

Each pivot column should be a leading 1
All entries below the pivot entry should be a 0.

 -            -
|   1   0   0  | 
|   0   1   0  |
|   0   0   1  |
_             -


Valid Row operations:

1. Scale a row by a non-zero constant
2. Add to another row i, a scaled version of another row j
3. Swap rows (What edge case would I really want to do this?) Well, what if there is a 0 in the A11 spot...
    So I may want to do a 0{n} sweep of the pivot positions

Step 0: Create a dummy 3x3 matrix
    * I've never done multidimensional arrays/vectors in cpp, my syntax is off...
    * Try and push the vectors into the matrix of type vector<double>
    * I should be consistent with zero based indexing
Step 1: Make A[0][0] == 1;

Step 2: Loop through A[i][0], and multiply A11 (in this case) by the negative value I want to eliminate...

Think about it... There is something wrong with this vector syntax/ I don't understand how it is storing the data structure

 */