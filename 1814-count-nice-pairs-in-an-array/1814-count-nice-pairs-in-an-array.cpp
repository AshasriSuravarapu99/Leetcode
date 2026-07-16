class Solution {
public:
    int reverse(int val){
        int reversedNum = 0;
        while (val != 0) {
            int remainder = val % 10;         
            reversedNum = reversedNum * 10 + remainder; 
            val /= 10;                   
        }
        return reversedNum;
    };
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int mod =  1e9 + 7;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            int val = nums[i];
            int rev = reverse(val);
            int dif = val - rev;
            ans += mp[dif];
            mp[dif]++;
        }
        return ans % mod;
    }
};