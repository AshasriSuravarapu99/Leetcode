class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<vector<int>> m;
        int r = mat.size();
        int c = mat[0].size();
        vector<int> ans;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                if (i != 0 && j != c - 1) continue;

                vector<int> v;
                int x = i, y = j;   

                v.push_back(mat[x][y]);

                while (x + 1 < r && y - 1 >= 0) {
                    x++;
                    y--;
                    v.push_back(mat[x][y]);
                }

                m.push_back(v);
            }
        }

        int i = 1;
        for (auto &it : m) {
            if(i%2 != 0){
                reverse(it.begin(),it.end());
            }
            for(auto &i:it) ans.push_back(i);
            i++;
            
        }

        return ans;
    }
};
