class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int small = 0;
        int large = 0;
        for(int i=0;i<k;i++) small+=nums[i];
        for (int i = nums.size() - k; i < nums.size(); i++) {
            large += nums[i];
        }
        return abs(small - large);
    }
};