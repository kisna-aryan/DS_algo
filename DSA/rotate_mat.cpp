class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matSize = matrix.size();
        vector<vector<int>> tmpMat(matSize,vector<int> (matSize));
        for(int i=0;i<matSize;i++)
        {
            for(int j=0;j<matSize;j++)
            {
                tmpMat[j][matSize-i-1] = matrix[i][j];
                // cout << matrix[i][j];
            }
        }
            
        for(int i=0;i<matSize;i++)
        {
            for(int j=0;j<matSize;j++)
            {
                matrix[i][j] = tmpMat[i][j];
            }
        }
    }
};
