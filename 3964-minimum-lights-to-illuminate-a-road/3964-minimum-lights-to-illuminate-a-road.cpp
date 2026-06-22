class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int>vis(n,0);
        for(int i = 0; i < n; i++){
            if(lights[i] > 0){
                int s = max(0,i-lights[i]);
                int e = min(n-1,i + lights[i]);
                vis[s]++;
                if(e != n-1) vis[e+1]--;
            }
        }
        for(int i = 1; i < n; i++){
            vis[i] += vis[i-1];
        }
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                cnt++;
            }
            else{
                ans += ceil(cnt/3.0);
                cnt = 0; 
            }
        }
        if(cnt != 0) ans += ceil(cnt/3.0);
        return ans;
    }
};