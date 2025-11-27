class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int s = target.size();
        int k = 0;
        int num = target[s-1];
        for(int i=1;i<=n;i++)
        {
            if(k>=s) break;
            if(i == target[k]) 
            {
                ans.push_back("Push");
                k++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if(i == num) break;
        }
        return ans;
    }
};