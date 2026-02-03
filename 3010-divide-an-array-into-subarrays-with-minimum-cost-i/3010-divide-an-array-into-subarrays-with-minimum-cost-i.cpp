class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int mini1 = 100 , mini2 = 100;
        for(int i = 1; i < n; i++){
            if(nums[i] < mini1) {
                if(mini1 < mini2) mini2 = mini1;
                mini1 = nums[i];
            }
            else if(nums[i] < mini2) mini2 = nums[i];
        }
        return nums[0] + mini1 + mini2;
    }
};