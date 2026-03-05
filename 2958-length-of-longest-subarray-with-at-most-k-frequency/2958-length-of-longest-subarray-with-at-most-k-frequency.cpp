class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>m;
        int i = 0, j = 0;
        int ans = 0;
        while(j < n){
            m[nums[j]]++;
            if(m[nums[j]] > k){
                ans = max(ans,j-i);
                while(nums[i] != nums[j]){
                    m[nums[i]]--;
                    if(m[nums[i]] == 0) m.erase(nums[i]);
                    i++;
                }
                m[nums[j]]--;
                i++;
            }
            j++;
        }
        ans = max(ans,j-i);
        return ans;
    }
};