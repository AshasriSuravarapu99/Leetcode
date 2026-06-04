class Solution {
public:
    int path(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(grid[i][j] == 1) return 0;
        if(i == grid.size()-1 && j == grid[0].size()-1){
            return 1;
        }
        if(i > grid.size() || j > grid[0].size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int r = 0, b = 0;
        cout<<i<<" "<<j<<"\n";
        if(j+1 < grid[0].size()) b += path(i,j+1,grid,dp);
        if(i+1 < grid.size()) r += path(i+1,j,grid,dp);

        return dp[i][j] = r+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(),-1));
        return path(0,0,grid,dp);
    }
};