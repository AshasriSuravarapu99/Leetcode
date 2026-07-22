class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++)
        {
            string sam = strs[i];
            sort(sam.begin(),sam.end());
            m[sam].push_back(strs[i]);
        }
        for(auto it:m)
        {
            ans.push_back(m[it.first]);
        }
       
        return ans;
    }
};