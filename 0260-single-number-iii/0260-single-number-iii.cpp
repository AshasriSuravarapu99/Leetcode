class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tot_xor = 0;
        for(int i=0; i < nums.size(); i++) tot_xor^= nums[i];
        int pos = 0;
        while(int(tot_xor & (1<<pos)) == 0){
            pos++;
        }
        int left = 0, right = 0;
        for(int i=0; i < nums.size(); i++){
            if(int(nums[i]&(1<<pos))) left^=nums[i];
            else right^=nums[i];
        }
        // cout<<pos;
        return {left,right};
        
    }
};