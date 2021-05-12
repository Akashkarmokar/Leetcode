class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;
        for(int i=0;i<m;i++){
            int l = -1 , r = n;
            while(r>l+1){
                int m = (r+l)/2;
                if(grid[i][m]<0){
                    r = m;
                }else{
                    l = m;
                }
            }
            sum+=n-r;
        }
        return sum;
    }
};