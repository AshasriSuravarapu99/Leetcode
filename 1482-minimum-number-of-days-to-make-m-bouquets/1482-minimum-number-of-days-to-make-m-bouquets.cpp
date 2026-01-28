class Solution {
public:
    int fun(vector<int>& bloomDay, int k, int mid){
        int c = 0;
        int m = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid) c++;
            else c=0;
            if(c == k){
                m++;
                c = 0;
            }
        }
        return m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m*k > n) return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int l = mini, h = maxi;
        int ans = 0;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(fun(bloomDay,k,mid) == m){
                h = mid - 1;
                ans = mid;
            } 
            else l = mid+1;
        }
        return ans;
        
    }
};