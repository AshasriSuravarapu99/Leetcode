class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 2){
                swap(nums[i],nums[j++]);
            }
        }
        j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 1 && nums[i] != 2){
                swap(nums[i],nums[j++]);
            }
        }
    }
};