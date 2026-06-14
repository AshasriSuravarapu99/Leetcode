class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        vector<vector<pair<int,int>>>adj(n);
        queue<vector<int>>pq;
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }
        pq.push({0,src,-1});
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        while(!pq.empty()){
            vector<int> v = pq.front();
            pq.pop();
            int u = v[1];
            int d = v[0];
            int s = v[2];
            for(auto it : adj[u]){
                int v = it.first;
                int w = it.second;
                if(d+w < dist[v] && s+1 <= k){
                    dist[v] = d+w;
                    pq.push({d+w,v,s+1});
                }
            }
        }
        if(dist[dst] == INT_MAX)  return -1;
        return dist[dst];

    }
};