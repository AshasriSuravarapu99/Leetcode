class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        map<int,int>val;
        map<int,int>fre;
        for(int i = 0; i < n; i++) val[nums[i]]++;
        for(auto it: val) fre[it.second]++;
        for(int i = 0; i < n; i++){
            if(fre[val[nums[i]]] == 1) return nums[i];
        }
        return -1;
    }
};