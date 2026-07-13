class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int z = 0, o = 0;
        for(int i = 0; i < s.size(); i++) if(s[i] == '0') z++;
        int ans = INT_MAX;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') z--;
            ans = min(ans , z + o);
            if(s[i] == '1') o++;
        }
        return ans;
    }
};