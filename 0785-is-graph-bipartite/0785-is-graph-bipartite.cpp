class Solution {
public:
    bool bfs(int i,vector<vector<int>>& graph, vector<int> &vis, vector<int> &col){
        vis[i] = 1;
        col[i] = 0;
        queue<pair<int,int>>q;
        q.push({i,0});
        while(!q.empty()){
            auto [node,color] = q.front();
            q.pop();
            for(auto it : graph[node]){
                if(!vis[it]){
                    int c = 0;
                    c = (color == 0) ? 1 : 0;
                    col[it] = c;
                    vis[it] = 1;
                    q.push({it,c});
                }
                else if(color == col[it]){
                    return false;
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>col(n,-1);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(bfs(i,graph,vis,col) == false) return false;
            }
        }
        return true;
    }
};