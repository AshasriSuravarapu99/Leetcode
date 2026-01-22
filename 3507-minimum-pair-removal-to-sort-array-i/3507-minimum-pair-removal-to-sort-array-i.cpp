class Solution {
public:
    int minPos(vector<int>nums){
        int minSum = INT_MAX;
        int pos = -1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]+nums[i-1] < minSum){
                minSum = nums[i] + nums[i-1];
                pos = i;
            }
        }
        return pos;
    }
    void merge(vector<int> &nums , int pos){
        nums[pos - 1] += nums[pos];
        nums.erase(nums.begin() + pos);
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n  = nums.size();
        int ans  = 0;
        while(!is_sorted(nums.begin(),nums.end())){
            ans++;
            merge(nums,minPos(nums));
        }
        return ans;
    }
};