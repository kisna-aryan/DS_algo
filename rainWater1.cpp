#include <iostream>
#include <vector>
using namespace std;

int trap(const vector<int> &A) {
    int left = 0;
    int right = A.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    int result = 0;
    while(left < right)
    {
        if(A[left] < A[right])
        {
            if(A[left] > leftMax)
            {
                leftMax = A[left];
            }
            else
            {
                result += leftMax - A[left];
            }
            left++;
        }
        else
        {
            if(A[right] > rightMax)
            {
                rightMax = A[right];
            }
            else
            {
                result += rightMax - A[right];
            }
            right--;
        }
    }
    return result;


}


int main()
{
    vector<int> A = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(A) << endl;

    return 0; 
}
