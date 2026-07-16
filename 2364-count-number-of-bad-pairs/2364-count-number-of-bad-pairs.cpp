class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1LL * n * (n-1) / 2;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            int val = nums[i] - i;
            mp[val]++;
        }
        long long val = 0;
        for(auto it : mp){
            long long a = it.second;
            if(a > 1){
                val += (a * (a-1)) / 2;
            }
        }
        return ans - val;
    }
};