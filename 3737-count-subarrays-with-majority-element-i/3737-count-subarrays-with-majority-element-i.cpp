class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>pre(n,0);
        if(nums[0] == target) pre[0] = 1;
        else pre[0] = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] == target) pre[i] = pre[i-1] + 1;
            else pre[i] = pre[i-1];
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int req = (j-i+1)/2;
                if(i == 0 && pre[j] > req) ans++;
                else if(i != 0 && (pre[j] - pre[i-1] > req)) ans++;
            }
        }

        return ans;
    }
};