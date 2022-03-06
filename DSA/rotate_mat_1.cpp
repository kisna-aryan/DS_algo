class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matSize = matrix.size();
        vector<vector<int>> tmpMat(matSize,vector<int> (matSize));
        for(int i=0;i<matSize;i++)
        {
            for(int j=i;j<matSize;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
                // cout << matrix[i][j];
            }
        }
            
        for(int i=0;i<matSize;i++)
        {
                reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
