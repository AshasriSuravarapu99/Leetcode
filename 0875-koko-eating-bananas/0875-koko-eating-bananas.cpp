class Solution {
public:
    bool fun(vector<int>& piles, int h, long long k){
        long long c= 0;
        for(int i = 0; i < piles.size(); i++) c+=ceil(piles[i]/(k*1.0));
        if(c <= h) return true;
        else return false;
    } 
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = 0;
        for(int i = 0; i < n; i++) maxi = max(piles[i],maxi);
        int l = 1, high = maxi;
        int ans = 0;
        while(l<=high){
            long long mid = l + (high-l)/2;
            if(fun(piles,h,mid)){
                high = mid-1;
                ans = mid;
            }
            else l = mid + 1;
        }
        return ans;
    }
};