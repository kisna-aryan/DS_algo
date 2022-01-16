#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:
    int trap(const vector<int> &A);

};

int Solution::trap(const vector<int> &A) {
    int n = A.size();
    vector<int> maxLeft(n, 0);
    vector<int> maxRight(n, 0);
    maxLeft[0] = A[0];
    maxRight[n-1] = A[n-1];
    for(int i=1;i<n;i++)
    {
        maxLeft[i] = max(maxLeft[i-1], A[i]);
        maxRight[n-i-1] = max(maxRight[n-i], A[n-i-1]);
    }
    int res = 0;
    for(int i=0;i<n;i++)
    {
        res += min(maxLeft[i], maxRight[i]) - A[i];
    } 
    return res;
}

int main(){
    Solution s;
    vector<int> A = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(A) << endl;
    return 0;
}