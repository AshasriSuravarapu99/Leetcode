class Solution {
public:
    // if we given the row and col number and asked to find the value at that place we can use the formula nCr => (r-1)C(c-1)
    vector<int> getRow(int rowIndex) {
        int row = rowIndex+1;
        vector<int>res;
        res.push_back(1);
        long long ans = 1;
        for(int i = 1; i < row; i++){
            ans = ans * (row - i);
            ans = ans/i;
            res.push_back(ans);
        }
        return res;     
    }
};