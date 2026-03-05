class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = 0;
        int c = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0 && s[i] != '1') c++;
            if(i % 2 != 0 && s[i] != '0') c++;
        }
        ans = c;
        c = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0 && s[i] != '0') c++;
            if(i % 2 != 0 && s[i] != '1') c++;
        }
        ans = min(ans, c);
        return ans;

    }
};