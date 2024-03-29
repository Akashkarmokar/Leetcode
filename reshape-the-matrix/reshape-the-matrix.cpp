class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        
        
        if((r*c<n*m) || (r*c>n*m)){
            return mat;
        }
        
        int k=0;
        int l=0;
        vector<vector<int>> ans(r,vector<int>());
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // ans[k][l]=(mat[i][j]);
                ans[k].push_back(mat[i][j]);
                l++;
                if(l==c){
                    k++;
                    l=0;
                }
            }
        }
        return ans;
    }
};