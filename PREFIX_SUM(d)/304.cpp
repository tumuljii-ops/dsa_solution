class NumMatrix {
public:
    vector<vector<int>> ans;

    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        ans.resize(row, vector<int>(col, 0));
        ans[0][0] = matrix[0][0];

        for (int j = 1; j < col; j++) {
            ans[0][j] = ans[0][j-1] + matrix[0][j];
        }

        for (int i = 1; i < row; i++) {
            ans[i][0] = ans[i-1][0] + matrix[i][0];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                ans[i][j] = ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = ans[row2][col2];
        int up = (row1 > 0) ? ans[row1 - 1][col2] : 0;
        int left = (col1 > 0) ? ans[row2][col1 - 1] : 0;
        int addBack = (row1 > 0 && col1 > 0) ? ans[row1 - 1][col1 - 1] : 0;

        return total - up - left + addBack;
    }
};