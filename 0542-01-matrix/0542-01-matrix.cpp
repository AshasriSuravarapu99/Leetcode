class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>>ans(r,vector<int>(c,-1));
        queue<pair<int,int>>q;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j] == 0) {
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        vector<int> dx = {-1,0,0,1};
        vector<int> dy = {0,1,-1,0};
        while(!q.empty()){
            auto [a,b] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = a + dx[i];
                int ny = b + dy[i];

                if(nx >= 0 && nx < r && ny >= 0 && ny < c &&  ans[nx][ny] == -1){
                    ans[nx][ny] = ans[a][b] + 1;
                    q.push({nx,ny});
                } 
            }
        }
        return ans;
    }
};