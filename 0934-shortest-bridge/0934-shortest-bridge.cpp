class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        queue<vector<int>> q1;
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        int flag = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                        auto temp = q.front();
                        q.pop();
                        int a = temp[0];
                        int b = temp[1];
                        q1.push({a,b,0});
                        for(auto i:dir){
                            int x = a+i[0];
                            int y = b+i[1];
                            if(x >= 0 && x < n && y >=0 && y < n && vis[x][y] == 0 && grid[x][y] == 1){
                                q.push({x,y});
                                vis[x][y] = 1;
                            }
                        }
                    }
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) break;
        }

        vector<vector<int>> dist(n,vector<int>(n,10001));
        while(!q1.empty()){
            auto temp = q1.front();
            int a = temp[0];
            int b = temp[1];
            int cnt = temp[2];
            q1.pop();
            if(cnt > dist[a][b]) continue;
            for(auto i:dir){
                int x = a+i[0];
                int y = b+i[1];
                if(x >= 0 && x < n && y >=0 && y < n){
                    if(vis[x][y] == 0 && grid[x][y] == 1){
                        dist[x][y] = min(dist[x][y],cnt);
                    }
                    else if(grid[x][y] == 0 && cnt+1 < dist[x][y]){
                        dist[x][y] = cnt+1;
                        vis[x][y] = 1;
                        q1.push({x,y,cnt+1});
                    }
                }
            }
        }
        int res = INT_MAX;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                        auto temp = q.front();
                        q.pop();
                        int a = temp[0];
                        int b = temp[1];
                        res = min(res,dist[a][b]);
                        for(auto i:dir){
                            int x = a+i[0];
                            int y = b+i[1];
                            if(x >= 0 && x < n && y >=0 && y < n && vis[x][y] == 0 && grid[x][y] == 1){
                                q.push({x,y});
                                vis[x][y] = 1;
                            }
                        }
                    }
                    break;
                }
            }
        }
        return res;
        
    }
};