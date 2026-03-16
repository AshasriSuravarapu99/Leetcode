class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        map<int,int>m1;
        for(int i = 0; i < nums1.size(); i++) 
        {
            m[nums1[i]]++;
            m1[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size(); i++) m[nums2[i]]++;

        int ans = 0;
        for(auto it : m){
            if(it.second%2 != 0) return -1;
            int v = it.second/2;
            if(v != m1[it.first]){
                ans+=abs(v - m1[it.first]);
            }
        } 

        return ans/2;
    }
};