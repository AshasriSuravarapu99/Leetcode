class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();
        map<string,int>m;
        for(int i = 0; i < n; i++){
            string s = words[i].substr(0,k);
            m[s]++;
        }
        int ans = 0;
        for(auto it : m){
            if(it.second >= 2) ans++;
        }
        return ans;

    }
};