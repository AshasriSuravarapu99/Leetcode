class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& dep) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i = 0; i < dep.size(); i++){
            int u = dep[i][0];
            int v = dep[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        vector<int>topo;
        queue<int>q;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int a = q.front();
            q.pop();
            topo.push_back(a);
            for(auto it : adj[a]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(topo.size() != n) return {};
        return topo;


    }
};