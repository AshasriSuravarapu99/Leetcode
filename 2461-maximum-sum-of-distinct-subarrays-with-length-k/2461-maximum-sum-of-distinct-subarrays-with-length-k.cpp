class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long sum = 0;
        unordered_map<int,int>m;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            m[nums[i]]++;
        }
        int j = 0;
        if(m.size() == k && ans < sum) ans = sum;
        for(int i=k;i<nums.size();i++){
            sum-=nums[j];
            sum+=nums[i];
            m[nums[j]]--;
            if(m[nums[j]] == 0) m.erase(nums[j]);
            m[nums[i]]++;
            if(m.size() == k && ans < sum) ans = sum;
            j++;
            
        }
        return ans;
    }
};