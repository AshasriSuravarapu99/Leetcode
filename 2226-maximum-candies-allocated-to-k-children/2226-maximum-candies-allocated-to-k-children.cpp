class Solution {
public:
    bool fun(vector<int>& candies, long long k, int m){
        long long c = 0;
        for(int i = 0; i < candies.size(); i++){
            c += candies[i]/m;
        }
        return c >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        if(n < k) return 0;
        int maxi = 0;
        for(int i = 0; i < n; i++) maxi = max(maxi, candies[i]);
        int l = 1, h = maxi;
        int ans = 0;
        while(l <= h){
            int mid = l + (h - l)/2;
            if(fun(candies,k,mid)){
                l = mid+1;
                ans = mid;
            }
            else h = mid-1;
        }
        return ans;
    }
};