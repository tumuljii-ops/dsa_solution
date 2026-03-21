class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, int count, int total) {
        int n = grid.size();
        int m = grid[0].size();

        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == -1) {
            return 0;
        }

        if (grid[row][col] == 2) {
            if (count == total) {
                return 1;
            }
            return 0;
        }

        int temp = grid[row][col];
        grid[row][col] = -1;

        int ans = 0;

        ans += dfs(grid, row + 1, col, count + 1, total);
        ans += dfs(grid, row - 1, col, count + 1, total);
        ans += dfs(grid, row, col + 1, count + 1, total);
        ans += dfs(grid, row, col - 1, count + 1, total);

        grid[row][col] = temp;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int startRow = 0;
        int startCol = 0;
        int total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != -1) {
                    total++;
                }

                if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
            }
        }

        return dfs(grid, startRow, startCol, 1, total);
    }
};