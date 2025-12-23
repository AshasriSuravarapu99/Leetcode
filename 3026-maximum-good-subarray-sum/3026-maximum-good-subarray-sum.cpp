class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
         map<int,vector<int>>m;
         int n = nums.size();
         vector<int>pre(n);
         pre[0] = nums[0];
         for(int i=1;i<n;i++) pre[i] = pre[i-1]+nums[i];
         long long ans = LLONG_MIN;
         m[nums[0]].push_back(0);
         for(int i=1; i<n; i++){
            if(m.find(nums[i]+k) != m.end()){
                for(auto it:m[nums[i]+k]){
                    long long sum = 0;
                    if(it == 0) sum = pre[i];
                    else sum = pre[i] - pre[it-1];
                    ans = max(ans, sum);
                }
            }
             if(m.find(nums[i]-k) != m.end()){
                for(auto it:m[nums[i]-k]){
                    long long sum = 0;
                    if(it == 0) sum = pre[i];
                    else sum = pre[i] - pre[it-1];
                    ans = max(ans, sum);
                }
            }
            m[nums[i]].push_back(i);
         }
         return ans;
    }
};