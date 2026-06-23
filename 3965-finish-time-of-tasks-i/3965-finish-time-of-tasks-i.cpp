class Solution {
public:
    long long dfs(int node, vector<vector<int>>& edges, vector<int>& baseTime, vector<vector<int>>& adj){
        if(adj[node].size() == 0) return baseTime[node];

        long long latest = LLONG_MIN;
        long long earliest = LLONG_MAX;

        for(auto it : adj[node]){
            long long t = dfs(it,edges,baseTime,adj);
            latest = max(latest,t);
            earliest = min(earliest , t);
        }

        long long ans = (latest - earliest) + baseTime[node];
        return ans + latest;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        return dfs(0,edges,baseTime, adj);
    }
};