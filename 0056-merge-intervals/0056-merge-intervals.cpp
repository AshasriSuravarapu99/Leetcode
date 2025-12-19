class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1; i < intervals.size(); i++)
        {
            int j = ans.size()-1;
            int start = ans[j][0];
            int end = ans[j][1];
            if(intervals[i][0] >= start && intervals[i][0] <= end){ 
                ans.pop_back();
                ans.push_back({start,intervals[i][1]});
            }
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};