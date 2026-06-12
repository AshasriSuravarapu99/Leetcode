class Solution {
public:
    int find(int i, vector<int> &coins,int amount, vector<vector<int>> &dp){
        if(i == 0){
            if(amount % coins[i] == 0) return amount/coins[i];
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int take = INT_MAX;
        if(coins[i] <= amount){
            take = 1 + find(i,coins,amount-coins[i],dp);
        }
        int nt = find(i-1,coins,amount,dp);

        return dp[i][amount] = min(take,nt);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans =  find(n-1,coins,amount,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};