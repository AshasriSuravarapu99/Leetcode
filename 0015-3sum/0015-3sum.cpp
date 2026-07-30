class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i = 0;
        while(i < n-2){
            int j = i+1;
            int k = n-1;
            while(j < k){
                int val = nums[i]+nums[j]+nums[k];
                if(val == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(k > j && nums[k] == nums[k+1]) k--;
                }
                else if(val < 0){
                    j++;
                    while(j < k && nums[j] == nums[j-1]) j++;
                }
                else{
                    k--;
                    while(k > j && nums[k] == nums[k+1]) k--;
                }

            }
            i++;
            while(i < n-2 && nums[i] == nums[i-1]) i++;
        }

        return ans;
    }
};