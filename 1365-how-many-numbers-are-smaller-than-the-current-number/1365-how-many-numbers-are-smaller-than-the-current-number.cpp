class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> a = nums;             // copy original
        sort(nums.begin(), nums.end());   // sorted array
        vector<int> ans;

        for (int i = 0; i < a.size(); i++) {
            auto lb = lower_bound(nums.begin(), nums.end(), a[i]);
            int count = lb - nums.begin();   // index = number of smaller elements
            ans.push_back(count);
        }
        return ans;
    }
};
