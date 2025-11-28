class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int>rem;
        for(int i=0;i<nums.size();i++)
        {
            rem.push_back(nums[i]%k);
        }
        map<int,int>m;
        bool ans = false;
        int sum = 0;
        for(int i=0;i<rem.size();i++)
        {
            sum+=rem[i];
            if(sum == k && i+1>=2) return true;
            if(m.find(sum-k) != m.end() && i-m[sum-k]>=2) return true;
            if(m.find(sum) == m.end()) m[sum] = i; 
        }
        return ans;
    }
};