class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        int val;
        int ans = 0;
        int c=0;
        int flag = 0;
        for(auto it:m)
        {
            if(flag == 0) 
               {
                    val = it.first;
                    flag = 1;
               }
            else if(it.first-val == 1 || it.first-val == -1) 
            {
                c++;
                val = it.first;
            }
            else
            {
                ans = max(ans,c);
                c=0;
            }
        }
        // for(auto it:m) cout<<it.first<<" "<<it.second<<"\n";
        ans  = max(ans,c)+1;
        if(m.size() == 0 || m.size() == 1) return m.size();
        return ans;
        // return 0;
    }
};