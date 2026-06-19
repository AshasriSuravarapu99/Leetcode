class Solution {
public:
    // int fun(int i1, int i2, string &text1, string &text2, vector<vector<int>> &dp){
    //     if(i1 == 0 || i2 == 0) return 0;

    //     if(dp[i1][i2] != -1) return dp[i1][i2];

    //     if(text1[i1-1] == text2[i2-1]){
    //         return dp[i1][i2] = 1 + fun(i1-1,i2-1,text1, text2,dp);
    //     }

    //     return dp[i1][i2] = max(fun(i1-1,i2,text1,text2,dp) , fun(i1,i2-1,text1,text2,dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return fun(m,n,text1,text2,dp);
        for(int i = 0; i <= m; i++) dp[i][0] = 0;
        for(int j = 0; j <= n; j++) dp[0][j] = 0;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }       
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
};