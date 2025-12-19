class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(r,vector<int>(c,0));
        vis[sr][sc] = 1;
        int oriCol = image[sr][sc];
        image[sr][sc] = color;
        q.push({sc,sr});
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            cout<<i<<" "<<j<<"\n";
            if(j-1>=0 && (vis[i][j-1] != 1) && image[i][j-1]==oriCol)
            {
                image[i][j-1] = color;
                q.push({i,j-1});
                vis[i][j-1] = 1;
            }
            if(i-1>=0 && (vis[i-1][j] != 1) && image[i-1][j]==oriCol)
            {
                image[i-1][j] = color;
                q.push({i-1,j});
                vis[i-1][j] = 1;

            }
            if(j+1<c && (vis[i][j+1] != 1) && image[i][j+1]==oriCol)
            {
                image[i][j+1] = color;
                q.push({i,j+1});
                vis[i][j+1] = 1;
            }
            if(i+1<r && (vis[i+1][j] != 1) && image[i+1][j]==oriCol)
            {
                image[i+1][j] = color;
                q.push({i+1,j});
                vis[i+1][j] = 1;
            }
        }
        return image;
    }
};