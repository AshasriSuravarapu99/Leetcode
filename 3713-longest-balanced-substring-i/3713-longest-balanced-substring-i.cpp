class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            map<char,int>m;
            for(int j = i; j < n; j++){
                m[s[j]]++;
                int val = -1;
                int flag = 1;
                for(auto it : m){
                    if(val == -1 ) val = it.second;
                    else if(val != -1 && it.second != val) {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1) ans = max(ans,(j-i)+1);
                }
        }
        return ans;
    }
};