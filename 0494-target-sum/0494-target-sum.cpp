class Solution {
public:
    int ans = 0;
    void find(int i, vector<int> &nums, int sum , int target){
        if(i >= nums.size()){
            if(sum == target) ans++;
            return;
        }

        find(i+1,nums,sum+nums[i],target);
        find(i+1,nums,sum-nums[i],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        find(0,nums,0,target);
        return ans;
    }
};