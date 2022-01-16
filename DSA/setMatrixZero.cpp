#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> coloum(A[0].size(), 0);
    vector<int> row(A.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] == 0) {
                row[i] = 1;
                coloum[j] = 1;
            }
        }
    }
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (row[i] == 1 || coloum[j] == 1) {
                A[i][j] = 0;
            }
        }
    }
}


int main()
{
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    setZeroes(A);
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < A[0].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0; 
}
