class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int w1 = word1.size(), w2 = word2.size();
        int i = 0, j = 0;
        while(i < w1 && j < w2){
            ans+=word1[i++];
            ans+=word2[j++];
        }
        while(i < w1){
            ans+=word1[i++];
        }
        while(j < w2) ans+=word2[j++];
        return ans;
    }
};