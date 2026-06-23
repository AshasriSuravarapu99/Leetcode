class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        vector<vector<long long>> dist(
            n,
            vector<long long>(k + 1, LLONG_MAX)
        );

        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1}); // cost, node, streak

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            long long cost = curr[0];
            int node = curr[1];
            int streak = curr[2];

            if(cost > dist[node][streak]) continue;

            for(auto &[v, wt] : adj[node]) {

                int newStreak;

                if(labels[node] == labels[v])
                    newStreak = streak + 1;
                else
                    newStreak = 1;

                if(newStreak > k) continue;

                long long newCost = cost + wt;

                if(newCost < dist[v][newStreak]) {
                    dist[v][newStreak] = newCost;
                    pq.push({newCost, v, newStreak});
                }
            }
        }

        long long ans = LLONG_MAX;

        for(int s = 1; s <= k; s++) {
            ans = min(ans, dist[n - 1][s]);
        }

        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};