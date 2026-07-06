class Solution {
public:
    bool static comp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),comp);
        int s = intervals[0][0];
        int e = intervals[0][1];

        int ans = 1;
        int n = intervals.size();
        for(int i = 1; i < intervals.size(); i++){
            if(s <= intervals[i][0] && intervals[i][1] <= e) continue;
            else{
                ans++;
                e = max(e , intervals[i][1]);
            }
        }

        return ans;
    }
};