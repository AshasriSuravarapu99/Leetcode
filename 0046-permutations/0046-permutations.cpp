class Solution {
public:
    vector<vector<int>>ans;
    void fun(int i, vector<int> &nums){
        if(i >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++){
            swap(nums[i],nums[j]);
            fun(i+1,nums);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        fun(0,nums);
        return ans;
    }
};