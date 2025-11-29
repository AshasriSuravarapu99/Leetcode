class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int c = nums.size()/3;
       vector<int>ans;
       sort(nums.begin(),nums.end());
       int val = nums[0];
       int count = 1;
       for(int i=1;i<nums.size();i++)
       {
           if(nums[i] == val) count++;
           else
           {
                if(count > c) ans.push_back(val);
                val = nums[i];
                count = 1;
           }
       }
       if(count > c) ans.push_back(val);
       return ans;
    }
};