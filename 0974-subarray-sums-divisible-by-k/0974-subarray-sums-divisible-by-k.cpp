class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        int pre = 0;
        int res = 0;
        m[0] = 1;
        for(int i = 0;i < n;i++){
            pre += nums[i];
            res += m[((pre % k)+k) % k];
            m[((pre % k)+k) % k]++;
        }
        return res;
    }
};