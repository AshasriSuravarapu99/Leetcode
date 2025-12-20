class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int lands = 0;
        int shared = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 1) {
                    lands++;

                    if(i > 0 && grid[i-1][j] == 1)
                        shared++;

                    if(j > 0 && grid[i][j-1] == 1)
                        shared++;
                }
            }
        }
        return lands * 4 - shared * 2;
    }
};
