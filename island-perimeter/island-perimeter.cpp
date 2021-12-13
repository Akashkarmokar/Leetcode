class Solution {
public:
    int dfs(vector<vector<int>>& grid,int curX,int curY){
        if(curX<0 || curY<0 || curX==grid.size() || curY==grid[0].size() || grid[curX][curY] == 0)
            return 1;
        if(grid[curX][curY]==-1) // visited
            return 0;
        grid[curX][curY] = -1; // visit
        return dfs(grid,curX-1,curY) + dfs(grid,curX+1,curY) + dfs(grid,curX,curY-1) + dfs(grid,curX,curY+1) ;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    return dfs(grid,i,j);   
                }
            }
        }
        return 0;
    }
};