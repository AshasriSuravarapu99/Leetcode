class Solution {
public:
    // int ans = 0;
    void fun(int i, vector<int> &nums, int xorr,int &ans){
        if(i == nums.size()){
            ans+=xorr;
            return;
        }

        fun(i+1,nums,xorr^nums[i],ans);
        fun(i+1,nums,xorr,ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int xorr = 0;
        fun(0,nums,xorr,ans);
        return ans;
    }
};