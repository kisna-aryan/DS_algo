#include <iostream>
#include <vector>

using namespace std;

class Solution
{

    public:
    int largestRectangleArea(vector<int> &A);

};


int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    
    int height;

    left[0] = -1;
    right[n - 1] = n;
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && A[j] >= A[i]) {
            j = left[j];
        }
        left[i] = j;
    }
    for (int i = n - 2; i >= 0; i--) {
        int j = i + 1;
        while (j < n && A[j] >= A[i]) {
            j = right[j];
        }
        right[i] = j;
    }
    int max_area = 0;
    for (int i = 0; i < n; i++) {
        height = A[i];
        max_area = max(max_area, height * (right[i] - left[i] - 1));
    }
    return max_area;
}

int main() {
    vector<int> A = {2, 1, 5, 6, 2, 3};
    Solution s;
    cout << s.largestRectangleArea(A) << endl;
    return 0;
}