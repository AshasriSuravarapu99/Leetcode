class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        long long pro = 1;
        int i = 0, j = 0;
        int ans = 0;
        while(i < n && j < n){
            pro *= nums[j];
            while(i < n && pro >= k){
                    pro = pro / nums[i];
                    i++;
                }
            
            if(pro < k){
                ans += j-i+1;
            }
            j++;
        }
        return ans;
    }
};