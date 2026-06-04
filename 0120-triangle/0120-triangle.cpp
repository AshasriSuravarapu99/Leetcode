class Solution {
public:
    int find(int i, int j,vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i == triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int b = INT_MAX, d = INT_MAX;
        b = triangle[i][j] + find(i+1,j,triangle,dp);
        d = triangle[i][j] + find(i+1,j+1,triangle,dp);

        return dp[i][j] = min(b,d);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(), vector<int>(triangle.size(),INT_MAX));
        return find(0,0,triangle,dp);
    }
};