class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        string l = "abcdefghijklmnopqrstuvwxyz";
        map<char,int>mp;
        for(int i = 0; i < 26; i++) mp[l[i]] = i;
        string ans = "";
        int n = shifts.size();
        long long c = 0;
        for(int i = n-1; i >=0; i--){
            c += shifts[i];
            int val = (mp[s[i]] + c) % 26;
            ans += l[val];
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};