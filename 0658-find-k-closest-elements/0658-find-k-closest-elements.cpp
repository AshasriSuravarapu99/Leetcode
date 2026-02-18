class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        vector<int>ans;
        int l,r;
        if(idx < n && arr[idx] == x){
            ans.push_back(x);
            k--;
            l = idx - 1;
            r = idx + 1;
        }
        else{
            l = idx -1;
            r = idx;
        }
        while(k > 0 && l >= 0 && r < n){
            if(abs(arr[l]-x) <= abs(arr[r]-x)){
                ans.push_back(arr[l]);
                l--;
            }
            else ans.push_back(arr[r++]);
            k--;
        }
        while(k > 0 && l >= 0){
            ans.push_back(arr[l--]);
            k--;
        }
        while(k > 0 && r < n){
            ans.push_back(arr[r++]);
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};