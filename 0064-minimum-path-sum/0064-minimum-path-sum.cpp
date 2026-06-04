class Solution {
public:
    int pathsum(int i, int j, vector<vector<int>>& grid,
                vector<vector<int>>& dp) {

        if(i == grid.size()-1 && j == grid[0].size()-1)
            return grid[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = INT_MAX;
        int down = INT_MAX;

        if(j + 1 < grid[0].size())
            right = pathsum(i, j + 1, grid, dp);

        if(i + 1 < grid.size())
            down = pathsum(i + 1, j, grid, dp);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return pathsum(0, 0, grid, dp);
    }
};