class Solution {
public:
    void find(int i, vector<int> nums , vector<vector<int>>&ans , vector<int>&sub){
        if(i == nums.size()) 
        {
            if(count(ans.begin(),ans.end(),sub) == 0) ans.push_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        find(i+1,nums,ans,sub);
        sub.pop_back();
        find(i+1,nums,ans,sub);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>sub;
        find(0,nums, ans, sub);
        return ans; 
    }
};