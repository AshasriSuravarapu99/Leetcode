class Solution {
public:
    int find(int i, int j, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i == m-1) return matrix[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int ld = INT_MAX, b = INT_MAX,rd = INT_MAX;
        if(j-1 >= 0) ld = find(i+1,j-1,m,n,matrix,dp);
        if(j+1 < n) rd = find(i+1,j+1,m,n,matrix,dp);
        b = find(i+1,j,m,n,matrix,dp);

        int mini = min(ld,rd);

        return dp[i][j] = matrix[i][j] + min(mini,b);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>>dp(r,vector<int>(c,INT_MAX));
        for(int i = 0; i < c; i++){
            ans = min(ans,find(0,i,r,c,matrix,dp));
        }
        return ans;
    }

};