class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int tot = 0;
        int ans = 0;
        
        for(int i=0;i<apple.size();i++) tot+=apple[i];
        // cout<<tot;
        for(int i=0;i<capacity.size();i++){
            if(tot <= 0){
                break;
            }
            ans++;
            tot-=capacity[i];
            // cout<<tot<<" ";
        }
        return ans;
    }
};