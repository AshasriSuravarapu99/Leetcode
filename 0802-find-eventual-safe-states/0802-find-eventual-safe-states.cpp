class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph, vector<int> &vis, vector<int> &check){
        vis[i] = 2;
        for(auto it : graph[i]){
            if(!vis[it]){
                if(dfs(it,graph,vis,check) == false) return false;
            }
            else if(vis[it] == 2) return false;
        }

        check[i] = 1;
        vis[i] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>check(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i,graph,vis,check);
            }
        }
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(check[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};