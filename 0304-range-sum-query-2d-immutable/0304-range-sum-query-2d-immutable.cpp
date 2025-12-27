class NumMatrix {
public:
    vector<vector<int>>pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=1;j<c;j++){
                matrix[i][j] = matrix[i][j]+matrix[i][j-1];
            }
        }
        for(int i=0;i<c;i++){
            for(int j=1;j<r;j++){
                matrix[j][i] = matrix[j][i]+matrix[j-1][i];
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
        pre = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2][col2] + pre[row1-1][col1-1] - pre[row2][col1-1] - pre[row1-1][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */