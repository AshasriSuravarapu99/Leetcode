class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        queue<pair<int,int>> q;      
        queue<pair<int,int>> island; 

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    island.push({i, j});
                    vis[i][j] = 1;
                    found = true;
                }
            }
        }

        while (!island.empty()) {
            auto [x, y] = island.front();
            island.pop();

            q.push({x, y});  

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                if (vis[nx][ny] || grid[nx][ny] == 0)
                    continue;

                vis[nx][ny] = 1;
                island.push({nx, ny});
            }
        }
        int flips = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;

                    if (vis[nx][ny])
                        continue;

                    if (grid[nx][ny] == 1)
                        return flips;

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }

            flips++;
        }

        return -1;
    }
};