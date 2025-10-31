class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n =nums.size();
        map<int,int>m;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            if(m[nums[i]] == 2) ans.push_back(nums[i]);
            if(ans.size() == 2) break;
        }
        return ans;
    }
};