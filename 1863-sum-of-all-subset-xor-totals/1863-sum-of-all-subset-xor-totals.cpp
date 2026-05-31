class Solution {
public:
    // int ans = 0;
    void fun(int i, vector<int> &nums, vector<int> &xorr,int &ans){
        if(i == nums.size()){
            int tot = 0;
            for(int i = 0; i < xorr.size(); i++){
                tot = tot ^ xorr[i];
            }
            ans+=tot;
            return;
        }

        xorr.push_back(nums[i]);
        fun(i+1,nums,xorr,ans);
        xorr.pop_back();
        fun(i+1,nums,xorr,ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        vector<int>xorr;
        fun(0,nums,xorr,ans);
        return ans;
    }
};