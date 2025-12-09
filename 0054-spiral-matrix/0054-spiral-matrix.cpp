class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0, r = cols - 1, t = 0, b = rows - 1;
        int d = 1;
        vector<int> res;
        while (l <= r && t <= b) {
            if (d == 1) {
                for (int i = l; i <= r; i++) {
                    res.push_back(matrix[t][i]);
                    d = 2;
                }
                t++;
            } else if (d == 2) {
                for (int i = t; i <= b; i++) {
                    res.push_back(matrix[i][r]);
                    d = 3;
                }
                r--;
            } else if (d == 3) {
                for (int i = r; i >= l; i--) {
                    res.push_back(matrix[b][i]);
                    d = 4;
                }
                b--;
            } else if (d == 4) {
                for (int i = b; i >= t; i--) {
                    res.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return res;
    }
};