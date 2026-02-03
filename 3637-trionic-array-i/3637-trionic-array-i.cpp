class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p=-1,q=-1;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                p = i-1;
                break;
            }
        }
        if(p == -1 || p == 0 ) return false;

        for(int i = p+1; i < n; i++){
            if(nums[i] > nums[i-1]){
                q = i-1;
                break;
            }
        }

        if(q == -1 ||  q == n-1) return false;

        for(int i = q+1; i < n; i++){
            if(nums[i] < nums[i-1]) return false;
        }
        return true;
        
    }
};