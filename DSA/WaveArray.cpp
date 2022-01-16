#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> wave(vector<int> &A) {
    sort(A.begin(),A.end());
    int arrSize = A.size();

    for(int i= 0;i<arrSize-1;i+=2)
    {
        swap(A[i],A[i+1]);
    }
    return A;
}

int main()
{
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    wave(A);
    for (size_t i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}