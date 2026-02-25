class Solution {
public:
    bool static comp(pair<int,int> &a, pair<int,int> &b){
        if(a.second == b.second) return a < b;
        return a.second < b.second;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>>v;
        for(int i = 0; i < n; i++){
            int c = __builtin_popcount(arr[i]);
            v.push_back({arr[i],c});
        }
        sort(v.begin(),v.end(),comp);
        vector<int>a;
        for(int i = 0; i < n; i++) a.push_back(v[i].first);
        return a;
    }
};