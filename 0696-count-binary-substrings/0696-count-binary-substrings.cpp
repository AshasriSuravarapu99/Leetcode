class Solution {
public:
    int countBinarySubstrings(string s) {
        int n  = s.size();
        int z = 0, o = 0;
        int ans = 0;
        int i = 0, j = 0;
        while(i < n && j < n){
            if((s[j] == '1' && o == 0) || (j!=0 && s[j]=='1' && s[j-1] == '1')) {
                o++;
                j++;
            }
            else if((s[j] == '0' && z == 0) || (j!=0 && s[j]=='0' && s[j-1] == '0')){
                z++;
                j++;
            } 
            else{
               ans += min(z,o);
               i = j;
               if(s[j] == '0') z = 0;
               else o = 0;
            }
        }
        ans +=min(o,z);
        return ans;
    }
};