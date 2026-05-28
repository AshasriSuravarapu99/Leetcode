class Solution {
public:
    vector<vector<int>>numRow;
    void getRow(int rowIndex) {
        int row = rowIndex+1;
        vector<int>res;
        res.push_back(1);
        long long ans = 1;
        for(int i = 1; i < row; i++){
            ans = ans * (row - i);
            ans = ans/i;
            res.push_back(ans);
        }
       numRow.push_back(res);
    }

    vector<vector<int>> generate(int numRows) {
        numRow.push_back({1});
        for(int i = 1; i < numRows; i++){
            getRow(i);
        }
        return numRow;
    }
};