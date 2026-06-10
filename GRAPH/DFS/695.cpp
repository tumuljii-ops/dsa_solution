class Solution {
public:

    int dfs(vector<vector<int>>& grid,
            vector<vector<bool>>& visited,
            int row,
            int col) {

        int n = grid.size();
        int m = grid[0].size();

        if (row < 0 || row >= n ||
            col < 0 || col >= m ||
            grid[row][col] == 0 ||
            visited[row][col]) {
            return 0;
        }

        visited[row][col] = true;

        int area = 1;

        area += dfs(grid, visited, row + 1, col);
        area += dfs(grid, visited, row - 1, col);
        area += dfs(grid, visited, row, col + 1);
        area += dfs(grid, visited, row, col - 1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(
            n, vector<bool>(m, false));

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 &&
                    visited[i][j] == false) {

                    int area = dfs(
                        grid,
                        visited,
                        i,
                        j
                    );

                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};