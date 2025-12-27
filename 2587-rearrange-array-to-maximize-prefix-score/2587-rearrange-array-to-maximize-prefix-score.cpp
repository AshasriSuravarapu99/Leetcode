class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int ans = 0;
        if(nums[0] > 0) ans++;
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i-1]+nums[i];
            if(nums[i] > 0) ans++;
        }
        return ans;
    }
};