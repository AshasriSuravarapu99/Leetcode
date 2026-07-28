class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pre(nums.size());
        pre[0] = nums[0];
        for(int i=1;i<nums.size();i++) pre[i] = pre[i-1]*nums[i];

        vector<int>suf(nums.size());
        suf[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--) suf[i] = suf[i+1]*nums[i];

        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0) ans.push_back(suf[1]);
            else if(i == nums.size()-1) ans.push_back(pre[i-1]);
            else
            {
                ans.push_back(suf[i+1]*pre[i-1]);
            }
        }
    return ans;

    }
};