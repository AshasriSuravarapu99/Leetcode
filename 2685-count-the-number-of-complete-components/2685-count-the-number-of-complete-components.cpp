class Solution {
public:
    bool bfs(int i , vector<int> &vis, vector<vector<int>>& adj){
        vector<int>subGraph;
        queue<int>q;
        vis[i] = 1;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            subGraph.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        int s = subGraph.size();
        // for(auto i : subGraph){
        //     cout<<i<<" ";
        //     // if(adj[i].size() != s-1) return false;
        // }
        // cout<<"\n";
        for(auto i : subGraph){
            if(adj[i].size() != s-1) return false;
        }
        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                if(bfs(i,vis,adj)) ans++;
            }
        }
        return ans;
    }
};