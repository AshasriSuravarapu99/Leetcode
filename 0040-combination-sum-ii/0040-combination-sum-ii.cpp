class Solution {
public:
    vector<vector<int>>ans;
    void fun(int i, vector<int> &v, vector<int> comb, int target){
        if(i >= v.size()){
            if(target == 0) ans.push_back(comb);
            return;
        }
        if(target == 0){
            ans.push_back(comb);
            return;
        }
        if(target < 0) return;

        comb.push_back(v[i]);
        fun(i+1,v,comb,target-v[i]);
        comb.pop_back();
        i++;
        while(i < v.size() && v[i] == v[i-1]) i++;
        // cout<<i<<"\n";
        fun(i,v,comb,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        vector<int> comb;
        sort(v.begin(),v.end());
        fun(0,v,comb,target);
        return ans;
       
    }
};