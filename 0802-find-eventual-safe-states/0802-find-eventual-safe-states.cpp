class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> revGraph(n);
        vector<int> indegree(n, 0);

        // Reverse the graph and store original outdegree
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;

        // Terminal nodes
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int parent : revGraph[node]) {
                indegree[parent]--;

                if (indegree[parent] == 0)
                    q.push(parent);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};