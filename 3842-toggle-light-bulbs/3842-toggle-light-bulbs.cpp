class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();
        map<int,int>m;
        for(int i = 0; i < n; i++) m[bulbs[i]]++;
        vector<int>ans;
        for(auto it : m) {
            if(it.second % 2 != 0) ans.push_back(it.first);
        }
        return ans;

    }
};