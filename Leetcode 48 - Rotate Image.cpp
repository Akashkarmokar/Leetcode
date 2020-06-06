class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i;j<matrix.size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        int k;
        for(int i=0;i<matrix.size();i++)
        {
            k=matrix.size()-1;
            for(int j=0;j<k;j++)
            {
                swap(matrix[i][j],matrix[i][k]);
                k--;
            }
        }
    }
};
